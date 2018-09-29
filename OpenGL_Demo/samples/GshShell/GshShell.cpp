// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

#include "Common.hpp"
#include <stdexcept>
using namespace std;

//-----------------------------------------------------------------------------
#define N "\n"
namespace {
const char* Vsh() {
    return OGL_SHADER_BEGIN(150)
        N  "uniform int Resolution = 60;"
        N  "in float Dummy;"
        N  "void main() {"
        N  "    vec2 parametric = vec2(gl_VertexID % Resolution, gl_VertexID / Resolution) / Resolution;"
        N  "    gl_Position = vec4(parametric, 0, 1.0);"
        N  "}";
}
const char* Gsh() {
    return OGL_SHADER_BEGIN(150)
        N  "layout(points) in;"
        N  "layout(triangle_strip, max_vertices = 4) out;"
        N  "uniform mat4 ModelView;"
        N  "uniform mat4 ModelViewProj;"
        N  "uniform int Resolution;"
        N  "uniform float A = 0.4;"
        N  "uniform float B = 1.0;"
        N  "uniform float C = 0.2;"
        N  "uniform float N = 2;"
        N  "const float PI2 = 6.28318530;"
        N  "out vec3 Color;"
        N  "vec3 Shell(float s, float t) {"
        N  "    t = t * 0.8;"
        N  "    return vec3("
        N  "        A * (1 - t / PI2) * cos(N * t) * (1 + cos(s)) + C * cos(N * t),"
        N  "        B * t / PI2 + A * (1 - t / PI2) * sin(s),"
        N  "        A * (1 - t / PI2) * sin(N * t) * (1 + cos(s)) + C * sin(N * t));"
        N  "}"
        N  "void GenVertex(float s, float t) {"
        N  "    vec3 p = Shell(s, t);"
        N  "    float delta = PI2 / (Resolution * 4);"
        N  "    vec3 dpds = (Shell(s + delta, t) - p) / delta;"
        N  "    vec3 dpdt = (Shell(s, t + delta) - p) / delta;"
        N  "    vec3 n = cross(dpds, dpdt);"
        N  "    n = normalize((ModelView * vec4(n, 0)).xyz);"
        N  "    gl_Position = ModelViewProj * vec4(p, 1);"
        N  "    Color = vec3(p.x, p.y / B, p.z) * (vec3(0.15) + vec3(dot(n, normalize(vec3(1)))));"
        N  "    EmitVertex();"
        N  "}"
        N  "void main() {"
        N  "    float s = gl_in[0].gl_Position.x * PI2;"
        N  "    float t = gl_in[0].gl_Position.y * PI2;"
        N  "    float S = PI2 / (Resolution * 2);"
        N  "    GenVertex(s - S, t + S);"
        N  "    GenVertex(s - S, t - S);"
        N  "    GenVertex(s + S, t + S);"
        N  "    GenVertex(s + S, t - S);"
        N  "    EndPrimitive();"
        N  "}";
}
const char* Fsh() {
    return OGL_SHADER_BEGIN(150)
        N  "uniform bool Wireframe;"
        N  "in vec3 Color;"
        N  "out vec4 FinalColor;"
        N  "void main() {"
        N  "    if (Wireframe) {"
        N  "        FinalColor = vec4(vec3(0.1), 1);"
        N  "    } else {"
        N  "        FinalColor = vec4(Color, 1);"
        N  "    }"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// GshShell
//-----------------------------------------------------------------------------
class GshShell {
public:
    GshShell() : mWindow(NULL), mGLContext(NULL), mProgram(0), mVAO(0), mVBO(0) {}
    ~GshShell();

    void Run();
    
private:
    void Init();
    bool ProcessEvents();
    void Update();

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    GLuint mProgram;
    GLuint mVAO, mVBO;

    ArcBall mArcBall;
    float mZoom;
    float mA, mB, mC, mN;
    int mResolution;
    int mTriCount;
    bool mWireframe;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
GshShell::~GshShell() {
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteProgram(mProgram);
    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void GshShell::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void GshShell::Init() {
    // window
    const int w = 800, h = 800;
    mWindow = new GLWindow("Geometry Shader Shell", w, h);
    
    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.2 functions
    gl::LoadCommandPointers(32);

    // create program
    mProgram = gl::BuildProgram(Vsh(), Gsh(), Fsh());
    glGetUniformfv(mProgram, glGetUniformLocation(mProgram, "A"), &mA);
    glGetUniformfv(mProgram, glGetUniformLocation(mProgram, "B"), &mB);
    glGetUniformfv(mProgram, glGetUniformLocation(mProgram, "C"), &mC);
    glGetUniformfv(mProgram, glGetUniformLocation(mProgram, "N"), &mN);
    glGetUniformiv(mProgram, glGetUniformLocation(mProgram, "Resolution"), &mResolution);
    mTriCount = mResolution * mResolution * 2;

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float), NULL, GL_STATIC_DRAW);

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 0, 0);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glPolygonOffset(0, -1000.0f);
    glEnable(GL_POLYGON_OFFSET_LINE);

    mWireframe = true;
    mZoom = 1.0f;
    mArcBall.SetWindowSize(w, h);

    TwInit(TW_OPENGL, NULL);
    TwWindowSize(w, h);
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='240 220'");
    TwDefine("Menu fontresizable=false resizable=false");
    
    TwAddVarRW(bar, "A", TW_TYPE_FLOAT, &mA, "step=0.025 min=0.3 max=1");
    TwAddVarRW(bar, "B", TW_TYPE_FLOAT, &mB, "step=0.025 min=1 max=4");
    TwAddVarRW(bar, "C", TW_TYPE_FLOAT, &mC, "step=0.025 min=0 max=1");
    TwAddVarRW(bar, "N", TW_TYPE_FLOAT, &mN, "step=0.025 min=1 max=5");
    TwAddVarRW(bar, "Resolution", TW_TYPE_INT32, &mResolution, "step=3 min=10 max=708");
    TwAddVarRW(bar, "Wireframe", TW_TYPE_BOOLCPP, &mWireframe, "");
    TwAddVarRO(bar, "TriCount", TW_TYPE_INT32, &mTriCount, "label='Triangles'");

    TwAddSeparator(bar, NULL, NULL);
    TwAddButton(bar, "usage", NULL, NULL, "label='Usage:'");
    TwAddButton(bar, "help0", NULL, NULL, "label='  - mouse with LB down to rotate'");
    TwAddButton(bar, "help1", NULL, NULL, "label='  - [ Z ] to zoom'");
    TwAddButton(bar, "help2", NULL, NULL, "label='  - [ SHIFT+Z ] to unzoom'");

    mLastTime = SDL_GetTicks();
}
//-----------------------------------------------------------------------------
bool GshShell::ProcessEvents() {
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
            mZoom = glm::clamp(mZoom, 0.7f, 2.5f);
            break;
        }
    }

    return true;
}
//-----------------------------------------------------------------------------
void GshShell::Update() {
    const Uint32 now = SDL_GetTicks();
    const float dt = (now - mLastTime) * 0.001f;
    mLastTime = now;

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_Z] && (keyState[SDL_SCANCODE_LSHIFT] || keyState[SDL_SCANCODE_RSHIFT])) {
        mZoom -= mZoom * dt;
    }
    else if (keyState[SDL_SCANCODE_Z]) {
        mZoom += mZoom * dt;
    }

    mZoom = glm::clamp(mZoom, 0.7f, 2.5f);

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const glm::mat3 model = mArcBall.Rotation() * glm::mat3(glm::scale(glm::vec3(mZoom)));
    const glm::mat4 modelView = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::mat4(model);
    const glm::mat4 modelViewProj = glm::perspective(45.0f, 1.0f, 0.1f, 10.0f) * modelView;

    glUseProgram(mProgram);
    glUniformMatrix4fv(glGetUniformLocation(mProgram, "ModelView"), 1, GL_FALSE, glm::value_ptr(modelView));
    glUniformMatrix4fv(glGetUniformLocation(mProgram, "ModelViewProj"), 1, GL_FALSE, glm::value_ptr(modelViewProj));
    glUniform1f(glGetUniformLocation(mProgram, "A"), mA);
    glUniform1f(glGetUniformLocation(mProgram, "B"), mB);
    glUniform1f(glGetUniformLocation(mProgram, "C"), mC);
    glUniform1f(glGetUniformLocation(mProgram, "N"), mN);
    glUniform1i(glGetUniformLocation(mProgram, "Resolution"), mResolution);
    mTriCount = mResolution * mResolution * 2;

    glBindVertexArray(mVAO);
    
    glUniform1i(glGetUniformLocation(mProgram, "Wireframe"), 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_POINTS, 0, mResolution * mResolution);

    if (mWireframe) {
        glUniform1i(glGetUniformLocation(mProgram, "Wireframe"), 1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_POINTS, 0, mResolution * mResolution);
    }

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
        GshShell gshShell;
        gshShell.Run();
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