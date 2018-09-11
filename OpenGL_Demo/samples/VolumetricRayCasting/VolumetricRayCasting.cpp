// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

#include "Common.hpp"
#include <stdexcept>
#include <vector>
#include <fstream>
using namespace std;

//-----------------------------------------------------------------------------
#define N "\n"
namespace {
const char* VshPosition() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform mat4 ModelViewProj;"
        N  "in vec4 PositionIn;"
        N  "out vec4 Position;"
        N  "void main() {"
        N  "    gl_Position = ModelViewProj * (PositionIn - vec4(0.5, 0.5, 0.5, 0));"
        N  "    Position = PositionIn;"
        N  "}";
}
const char* FshPosition() {
    return OGL_SHADER_BEGIN(130)
        N  "in vec4 Position;"
        N  "out vec4 Color;"
        N  "void main() {"
        N  "    Color = vec4(Position.xyz, 1);"
        N  "}";
}
const char* FshVolume() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Resolution = vec2(800, 800);"
        N  "uniform sampler2D BackFaceTex;"
        N  "uniform sampler3D VolumeTex;"
        N
        N  "uniform float StepSize = 0.002;"
        N  "uniform float AlphaFactor = 0.1;"
        N  "uniform int Iterations = 1000;"
        N  "uniform float Brightness = 1.0;"
        N
        N  "in vec4 Position;"
        N  "out vec4 Color;"
        N
        N  "void main() {"
        N  "    vec2 p = gl_FragCoord.xy / Resolution.xy;"
        N  "    vec3 dir = normalize(texture(BackFaceTex, p).xyz - Position.xyz);"
        N  "    vec3 pos = Position.xyz;"
        N  "    vec4 dst = vec4(0), src;"
        N
        N  "    for (int i = 0; i < Iterations; ++i) {"
        N  "        src = vec4(texture(VolumeTex, pos).r);"
        N
        N  "        src.a *= AlphaFactor;"
        N  "        src.rgb *= src.a;"
        N  "        dst += (1.0 - dst.a) * src;"
        N
        N  "        if (dst.a >= 0.95) {"
	    N  "            break;"
        N  "        }"
        N
		N  "        pos += dir * StepSize;"
		N  "        if (pos.x > 1 || pos.y > 1 || pos.z > 1 || pos.x < 0 || pos.y < 0 || pos.z < 0) {"
	    N  "            break;"
        N  "        }"
        N  "    }"
        N
        N  "    Color = Brightness * dst;"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// VolumetricRayCasting
//-----------------------------------------------------------------------------
class VolumetricRayCasting {
public:
    VolumetricRayCasting() :
        mWindow(NULL), mGLContext(NULL),
        mPositionProg(0), mVolumeProg(0), mVAO(0), mVBO(0), mEBO(0),
        mBackFaceTex(0), mFBO(0), mVolumeTex(0) {}
    ~VolumetricRayCasting();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    Window* mWindow;
    SDL_GLContext mGLContext;

    GLuint mPositionProg, mVolumeProg;
    GLuint mVAO, mVBO, mEBO;
    GLuint mBackFaceTex, mFBO;
    GLuint mVolumeTex;

    float mStepSize;
    float mAlphaFactor;
    int mIterations;
    float mBrightness;

    ArcBall mArcBall;
    float mZoom;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
VolumetricRayCasting::~VolumetricRayCasting() {
    glDeleteTextures(1, &mVolumeTex);
    glDeleteFramebuffers(1, &mFBO);
    glDeleteTextures(1, &mBackFaceTex);
    glDeleteBuffers(1, &mEBO);
    glDeleteBuffers(1, &mVBO);
    glDeleteVertexArrays(1, &mVAO);
    glDeleteProgram(mVolumeProg);
    glDeleteProgram(mPositionProg);
    glUseProgram(0);

    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void VolumetricRayCasting::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void VolumetricRayCasting::Init() {
    // window
    mWindow = new Window("Volumetric Ray Casting", 800, 800);
    
    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    // programs
    mPositionProg = gl::BuildProgram(VshPosition(), FshPosition());

    mVolumeProg = gl::BuildProgram(VshPosition(), FshVolume());
    glUseProgram(mVolumeProg);
    glUniform1i(glGetUniformLocation(mVolumeProg, "BackFaceTex"), 0);
    glUniform1i(glGetUniformLocation(mVolumeProg, "VolumeTex"), 1);

    glGetUniformfv(mVolumeProg, glGetUniformLocation(mVolumeProg, "StepSize"), &mStepSize);
    glGetUniformfv(mVolumeProg, glGetUniformLocation(mVolumeProg, "AlphaFactor"), &mAlphaFactor);
    glGetUniformiv(mVolumeProg, glGetUniformLocation(mVolumeProg, "Iterations"), &mIterations);
    glGetUniformfv(mVolumeProg, glGetUniformLocation(mVolumeProg, "Brightness"), &mBrightness);

    // VBO
    const glm::vec3 vertices[8] = {
        glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)
    };

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // EBO
    const GLushort indices[36] = {
        2, 3, 0, 0, 3, 1, // bottom
        0, 1, 4, 4, 1, 5, // left
        6, 2, 4, 4, 2, 0, // rear
        6, 7, 2, 2, 7, 3, // right
        3, 7, 1, 1, 7, 5, // front
        4, 5, 6, 6, 5, 7, // top
    };

    glGenBuffers(1, &mEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);

    // back face texture
    glGenTextures(1, &mBackFaceTex);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mBackFaceTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, mWindow->Width(), mWindow->Height(), 0, GL_RGBA, GL_FLOAT, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);

    // FBO
    glGenFramebuffers(1, &mFBO);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFBO);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mBackFaceTex, 0);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    mZoom = 1.5f;
    mArcBall.SetWindowSize(mWindow->Width(), mWindow->Height());

    // GUI
    TwInit(TW_OPENGL, NULL);
    TwWindowSize(mWindow->Width(), mWindow->Height());
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='240 180'");
    TwDefine("Menu fontresizable=false resizable=false");
    TwAddVarRW(bar, "StepSize", TW_TYPE_FLOAT, &mStepSize, "label='Step Size' min=0.001 max=0.01 step=0.001");
    TwAddVarRW(bar, "AlphaFactor", TW_TYPE_FLOAT, &mAlphaFactor, "label='Alpha Factor' min=0.01 max=1 step=0.01");
    TwAddVarRW(bar, "Iterations", TW_TYPE_INT32, &mIterations, "label='Iterations' min=100 max=5000 step=10");
    TwAddVarRW(bar, "Brightness", TW_TYPE_FLOAT, &mBrightness, "label='Brightness' min=0.1 max=10 step=0.1");

    TwAddSeparator(bar, NULL, NULL);
    TwAddButton(bar, "usage", NULL, NULL, "label='Usage:'");
    TwAddButton(bar, "help0", NULL, NULL, "label='  - mouse with LB down to rotate'");
    TwAddButton(bar, "help1", NULL, NULL, "label='  - [ Z ] to zoom'");
    TwAddButton(bar, "help2", NULL, NULL, "label='  - [ SHIFT+Z ] to unzoom'");

    // volume data
    ifstream volFile("../../media/foot.raw", ios::binary | ios::in);
    if (!volFile) {
        throw runtime_error("failed to load volume file");
    }

    const int volSize = 256 * 256 * 256;
    vector<GLubyte> volData(volSize);
    volFile.read(reinterpret_cast<char*>(&volData[0]), volSize);

    glGenTextures(1, &mVolumeTex);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, mVolumeTex);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);
    glTexImage3D(GL_TEXTURE_3D, 0, GL_R8, 256, 256, 256, 0, GL_RED, GL_UNSIGNED_BYTE, &volData[0]);
    glBindTexture(GL_TEXTURE_3D, 0);

    mLastTime = SDL_GetTicks();
}
//-----------------------------------------------------------------------------
bool VolumetricRayCasting::ProcessEvents() {
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            return false;
        }

        if (ProcessAntTweakBarEvent(evt)) continue;
        if (ProcessCommonEvent(evt)) continue;

        switch (evt.type) {
        case SDL_MOUSEBUTTONDOWN:
            if (evt.button.button == SDL_BUTTON_LEFT) {
                mArcBall.Begin(evt.button.x, evt.button.y);
                return true;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (evt.button.button == SDL_BUTTON_LEFT) {
                mArcBall.End();
                return true;
            }
            break;

        case SDL_MOUSEMOTION:
            mArcBall.Drag(evt.motion.x, evt.motion.y);
            break;

        case SDL_MOUSEWHEEL:
            mZoom += evt.wheel.y * 0.001f;
            mZoom = glm::clamp(mZoom, 0.1f, 3.0f);
            break;
        }
    }

    return true;
}
//-----------------------------------------------------------------------------
void VolumetricRayCasting::Update() {
    const Uint32 now = SDL_GetTicks();
    const float dt = (now - mLastTime) * 0.001f;
    mLastTime = now;

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_Z] && (keyState[SDL_SCANCODE_LSHIFT] || keyState[SDL_SCANCODE_RSHIFT])) {
        mZoom -= mZoom * dt;
        mZoom = glm::max(1.0f, mZoom);
    }
    else if (keyState[SDL_SCANCODE_Z]) {
        mZoom += mZoom * dt;
        mZoom = glm::max(1.0f, mZoom);
    }

    const glm::mat4 model = glm::mat4(mArcBall.Rotation() * glm::mat3(glm::scale(glm::vec3(mZoom))));
    const glm::mat4 modelView = glm::lookAt(glm::vec3(0.0f, 0.0f, 4.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * model;
    const glm::mat4 modelViewProj = glm::perspective(45.0f, 1.0f, 0.1f, 10.0f) * modelView;

    // render back faces to the texture
    glUseProgram(mPositionProg);
    glUniformMatrix4fv(glGetUniformLocation(mPositionProg, "ModelViewProj"), 1, GL_FALSE, &modelViewProj[0][0]);
    
    glCullFace(GL_FRONT);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFBO);
    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);

    // render volume
    glUseProgram(mVolumeProg);
    glUniformMatrix4fv(glGetUniformLocation(mVolumeProg, "ModelViewProj"), 1, GL_FALSE, &modelViewProj[0][0]);
    glUniform1f(glGetUniformLocation(mVolumeProg, "StepSize"), mStepSize);
    glUniform1f(glGetUniformLocation(mVolumeProg, "AlphaFactor"), mAlphaFactor);
    glUniform1i(glGetUniformLocation(mVolumeProg, "Iterations"), mIterations);
    glUniform1f(glGetUniformLocation(mVolumeProg, "Brightness"), mBrightness);

    glCullFace(GL_BACK);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mBackFaceTex);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, mVolumeTex);

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
   
    // draw GUI
    glUseProgram(0);
    glBindVertexArray(0);
    TwDraw();

    mWindow->Swap();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
        DisplayErrorMessage("main", "SDL_Init failed");
        return 0;
    }

    try {
        VolumetricRayCasting volumetricRayCasting;
        volumetricRayCasting.Run();
    }
    catch (const exception& ex) {
        DisplayErrorMessage("main", ex.what());
    }
    catch (...) {
        DisplayErrorMessage("main", "undefined exception");
    }

    SDL_Quit();
    return 0;
}
//-----------------------------------------------------------------------------