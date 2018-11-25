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
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Translation = vec2(0.7, 0.3);"
        N  "uniform float Zoom = 2;"
        N  "in vec2 Position;"
        N  "out vec2 C;"
        N  "void main() {"
        N  "    gl_Position = vec4(Position, 0, 1);"
        N  "    C = (Position * vec2(1.5 / Zoom, 1.0 / Zoom)) - Translation;"
        N  "}";
}
const char* Fsh() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform float Bailout = 256;"
        N  "uniform float Scale = 1.2;"
        N  "in vec2 C;"
        N  "out vec4 Color;"
        N  "vec2 ComplexMul(vec2 a, vec2 b) {"
        N  "    return vec2(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);"
        N  "}"
        N  "vec2 ComplexSq(vec2 a) {"
        N  "    return vec2(a.x * a.x - a.y * a.y, 2 * a.x * a.y);"
        N  "}"
        N  "float CalcDistance() {"
        N  "    vec2 z = vec2(0, 0);"
        N  "    vec2 dz = vec2(1, 0);"
        N  "    float m2;"
        N  "    for (int i = 0; i < int(Bailout); ++i) {"
        N  "        dz = 2 * ComplexMul(z, dz) + vec2(1, 0);"
        N  "        z = ComplexSq(z) + C;"
        N  "        m2 = dot(z, z);"
        N  "        if (m2 > 100) {"
        N  "            return sqrt(m2 / dot(dz, dz)) * 0.5 * log(m2);"
        N  "        }"
        N  "    }"
        N  "    return 0.0;"
        N  "}"
        N  "void main() {"
        N  "    float d = Scale * pow(CalcDistance(), 0.3);"
        N  "    Color = vec4(d);"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// Mandelbrot
//-----------------------------------------------------------------------------
class Mandelbrot {
public:
    Mandelbrot() : mWindow(NULL), mGLContext(NULL), mVAO(0), mVBO(0), mProgram(0) {}
    ~Mandelbrot();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    GLuint mVAO, mVBO, mProgram;

    // uniform locations
    GLint mTranslationLoc, mZoomLoc, mBailoutLoc, mScaleLoc;

    // uniforms
    glm::vec2 mTranslation;
    float mZoom;
    float mBailout;
    float mScale;

    bool mMouseDown;
    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
Mandelbrot::~Mandelbrot() {
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteProgram(mProgram);
    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void Mandelbrot::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void Mandelbrot::Init() {
    // window
    const int w = 1200, h = 800;
    mWindow = new GLWindow("Mandelbrot", w, h);

    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    const float data[] = { -1, -1, 1, -1, -1, 1, 1, 1 };
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    // program
    mProgram = gl::BuildProgram(Vsh(), Fsh());

    mTranslationLoc = glGetUniformLocation(mProgram, "Translation");
    mZoomLoc = glGetUniformLocation(mProgram, "Zoom");
    mBailoutLoc = glGetUniformLocation(mProgram, "Bailout");
    mScaleLoc = glGetUniformLocation(mProgram, "Scale");

    glGetUniformfv(mProgram, mTranslationLoc, glm::value_ptr(mTranslation));
    glGetUniformfv(mProgram, mZoomLoc, &mZoom);
    glGetUniformfv(mProgram, mBailoutLoc, &mBailout);
    glGetUniformfv(mProgram, mScaleLoc, &mScale);

    mMouseDown = false;

    TwInit(TW_OPENGL, NULL);
    TwWindowSize(w, h);
    TwDeleteAllBars();

    TwBar *bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='275 210'");
    TwDefine("Menu fontresizable=false resizable=false valueswidth=100");

    TwAddVarRO(bar, "Re", TW_TYPE_FLOAT, &mTranslation[0], "label='Re'");
    TwAddVarRO(bar, "Im", TW_TYPE_FLOAT, &mTranslation[1], "label='Im'");
    TwAddVarRW(bar, "Bailout", TW_TYPE_FLOAT, &mBailout, "label='Iterations'");
    TwAddSeparator(bar, NULL, NULL);
    TwAddButton(bar, "usage", NULL, NULL, "label='Usage:'");
    TwAddButton(bar, "help0", NULL, NULL, "label='  - arrow keys to move'");
    TwAddButton(bar, "help1", NULL, NULL, "label='  - mouse with LB down to move'");
    TwAddButton(bar, "help2", NULL, NULL, "label='  - [ Z ] to zoom'");
    TwAddButton(bar, "help3", NULL, NULL, "label='  - [ SHIFT+Z ] to unzoom'");
    TwAddButton(bar, "help4", NULL, NULL, "label='  - [ X ] to increase brightness'");
    TwAddButton(bar, "help5", NULL, NULL, "label='  - [ SHIFT+X ] to decrease brightness'");

    mLastTime = SDL_GetTicks();
}
//-----------------------------------------------------------------------------
bool Mandelbrot::ProcessEvents() {
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
                mMouseDown = true;
                return true;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (evt.button.button == SDL_BUTTON_LEFT) {
                mMouseDown = false;
                return true;
            }
            break;

        case SDL_MOUSEMOTION:
            if (mMouseDown) {
                const float dx = evt.motion.xrel * 0.005f;
                const float dy = -evt.motion.yrel * 0.005f;
                mTranslation += glm::vec2(dx / mZoom, dy / mZoom);
                return true;
            }
            break;
        }
    }

    return true;
}
//-----------------------------------------------------------------------------
void Mandelbrot::Update() {
    const Uint32 now = SDL_GetTicks();
    const float dt = (now - mLastTime) * 0.001f;
    mLastTime = now;

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_LEFT]) {
        mTranslation.x += dt / mZoom;
    }
    else if (keyState[SDL_SCANCODE_RIGHT]) {
        mTranslation.x -= dt / mZoom;
    }
    if (keyState[SDL_SCANCODE_UP]) {
        mTranslation.y -= dt / mZoom;
    }
    else if (keyState[SDL_SCANCODE_DOWN]) {
        mTranslation.y += dt / mZoom;
    }

    if (keyState[SDL_SCANCODE_Z] && (keyState[SDL_SCANCODE_LSHIFT] || keyState[SDL_SCANCODE_RSHIFT])) {
        mZoom -= mZoom * dt;
        mZoom = glm::max(1.0f, mZoom);
    }
    else if (keyState[SDL_SCANCODE_Z]) {
        mZoom += mZoom * dt;
        mZoom = glm::max(1.0f, mZoom);
    }

    if (keyState[SDL_SCANCODE_X] && (keyState[SDL_SCANCODE_LSHIFT] || keyState[SDL_SCANCODE_RSHIFT])) {
        mScale -= dt;
    }
    else if (keyState[SDL_SCANCODE_X]) {
        mScale += dt;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(mProgram);

    glUniform2fv(mTranslationLoc, 1, glm::value_ptr(mTranslation));
    glUniform1f(mZoomLoc, mZoom);
    glUniform1f(mBailoutLoc, mBailout);
    glUniform1f(mScaleLoc, mScale);

    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

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
        Mandelbrot mandelbrot;
        mandelbrot.Run();
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