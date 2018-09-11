// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

#include "Common.hpp"
#include <stdexcept>
#include <vector>
using namespace std;

//-----------------------------------------------------------------------------
#define N "\n"
namespace {
const char* VshFractalFlame() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform mat4 ProjView;"
        N  "uniform mat4 Trans[3];"
        N  "in vec4 Position;"
        N  "in uint Seed;"
        N  "out float Texcoord;"
        N  "uint Rand(inout uint r) {"
        N  "    return r = r * 196314165u + 907633515u;"
        N  "}"
        N  "vec4 Swirl(vec4 p, float r, float theta) {"
        N  "    return vec4(r * cos(theta + r), r * sin(theta + r), p.z, p.w);"
        N  "}"
        N  "void main() {"
        N  "    float c = 0;"
        N  "    vec4 p = Position;"
        N  "    uint r = Seed;"
        N  "    for (int i = 0; i < 10; ++i) {"
        N  "        int ri = int(Rand(r) % 3u);"
        N  "        c = (c + float(ri)) * 0.5;"
        N  "        p = Trans[ri] * p;"
        N  "        float radius = length(p);"
        N  "        float theta = atan(p.y, p.x);"
        N  "        p = Swirl(p, radius, theta);"
        N  "    }"
        N  "    gl_Position = ProjView * p;"
        N  "    Texcoord = c;"   
        N  "}";
}
const char* FshFractalFlame() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform sampler1D Palette;"
        N  "in float Texcoord;"
        N  "out vec4 Color;"
        N  "void main() {"
        N  "    Color = vec4(0.02) * texture(Palette, Texcoord);"
        N  "}";
}
const char* VshQuad() {
    return OGL_SHADER_BEGIN(130)
        N  "in vec4 Position;"
        N  "out vec2 Texcoord;"
        N  "void main() {"
        N  "    gl_Position = Position;"
        N  "    Texcoord = (Position.xy + 1.0) * 0.5;"
        N  "}";
}
const char* FshQuad() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform sampler2D Tex;"
        N  "in vec2 Texcoord;"
        N  "out vec4 Color;"
        N  "void main() {"
        N  "    vec4 c = texture(Tex, Texcoord);"
        N  "    Color = pow(c, vec4(0.5));"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// Random
//-----------------------------------------------------------------------------
class Random {
public:
    static unsigned int Gen() {
        return mSeed = mSeed * 196314165 + 907633515;
    }
    static float GenRange(float min, float max) {
        float zeroToOne = Gen() * 2.3283064365387e-10f;
        return min + (max - min) * zeroToOne;
    }
    static void ResetSeed() {
        mSeed = SEED;
    }

private:
    const static unsigned int SEED = 23232323;
    static unsigned int mSeed;
};
unsigned int Random::mSeed = Random::SEED;
//-----------------------------------------------------------------------------
// Transform
//-----------------------------------------------------------------------------
class Transform {
public:
    Transform() : t(0.0f, 0.0f, 0.0f), s(1.0f, 1.0f, 1.0f), r(0.0f, 0.0f, 0.0f) {}
    Transform(const glm::vec3& t, const glm::vec3& s, const glm::vec3& r) : t(t), s(s), r(r) {}

    glm::mat4 GetMatrix() const {
        glm::mat4 mt = glm::translate(t);
        glm::mat4 ms = glm::scale(s);
        glm::mat4 mr = glm::eulerAngleYXZ(glm::radians(r.x), glm::radians(r.y), glm::radians(r.z));

        return mt * mr * ms;
    }
    void Random() {
        t = glm::vec3(Random::GenRange(-1.4f, 1.4f), Random::GenRange(-1.4f, 1.4f), Random::GenRange(-1.4f, 1.4f));
        s = glm::vec3(Random::GenRange(0.3f, 1.0f), Random::GenRange(0.3f, 1.0f), Random::GenRange(0.3f, 1.0f));
        r = glm::vec3(Random::GenRange(0.0f, 359.0f), Random::GenRange(0.0f, 359.0f), Random::GenRange(0.0f, 359.0f));
    }

    glm::vec3 t, s, r;
};
//-----------------------------------------------------------------------------
// AnimTransform
//-----------------------------------------------------------------------------
class AnimTransform {
public:
    AnimTransform() : mTime(0.0f), mSpeed(0.5f) {}

    void AddTime(float dt) {
        if (mTime >= 1.0f) {
            mTime = 0.0f;
            mT0 = mT1;
            mT1.Random();
        }
        mTime += dt * mSpeed;
    }
    void Random() {
        mT0.Random();
        mT1.Random();
    }
    Transform GetTransform() const {
        float st = glm::smoothstep(0.0f, 1.0f, mTime);
        glm::vec3 t = glm::mix(mT0.t, mT1.t, st);
        glm::vec3 s = glm::mix(mT0.s, mT1.s, st);
        glm::vec3 r = glm::mix(mT0.r, mT1.r, st);
        return Transform(t, s, r);
    }
    void SetSpeed(float s) { mSpeed = s; }

private:
    float mTime;
    float mSpeed;
    Transform mT0, mT1;
};
//-----------------------------------------------------------------------------
GLuint CreatePaletteTexture(const char* filename) {
    int w, h, n;
    unsigned char* data = stbi_load(filename, &w, &h, &n, 0);
    if (!data) {
        throw runtime_error(string("failed to load ") + filename);
    }
    
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_1D, tex);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB8, w, 0, n == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
    return tex;
}
//-----------------------------------------------------------------------------
// FractalFlames
//-----------------------------------------------------------------------------
class FractalFlames {
public:
    FractalFlames() : mWindow(NULL), mGLContext(NULL), mFramebuffer(0), mRenderTarget(0) {
        SDL_zero(mPaletteTexture);
    }
    ~FractalFlames();

    void Run();
    
private:
    void Init();
    bool ProcessEvents();
    void Update();

    Window* mWindow;
    SDL_GLContext mGLContext;

    struct DrawResources {
        DrawResources() : program(0), vao(0), vbo(0) {}
        void Delete() {
            glDeleteBuffers(1, &vbo);
            glDeleteVertexArrays(1, &vao);
            glDeleteProgram(program);
        }

        GLuint program;
        GLuint vao;
        GLuint vbo;
    };
    struct Point {
        glm::vec3 p;
        glm::uint seed;
    };
    static const int POINT_COUNT = 2000000;
    static const int PALETTE_COUNT = 5;

    DrawResources mFractalFlame;
    DrawResources mQuad;
    GLuint mPaletteTexture[PALETTE_COUNT];
    GLuint mFramebuffer;
    GLuint mRenderTarget;

    Transform mTrans[3];
    AnimTransform mAnimTrans[3];
    ArcBall mArcBall;

    int mPaletteIdx;
    bool mAnimate;
    float mZoom;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
FractalFlames::~FractalFlames() {
    glDeleteTextures(1, &mRenderTarget);
    glDeleteFramebuffers(1, &mFramebuffer);
    mFractalFlame.Delete();
    mQuad.Delete();
    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void FractalFlames::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void FractalFlames::Init() {
    // window
    const int w = 800, h = 800;
    mWindow = new Window("Fractal Flames", w, h);
    
    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    // fractal flame
    mFractalFlame.program = gl::BuildProgram(VshFractalFlame(), FshFractalFlame());

    Random::ResetSeed();
    vector<Point> points(POINT_COUNT);
    for (size_t i = 0; i < POINT_COUNT; ++i) {
        points[i].p = glm::vec3(Random::GenRange(-1.0f, 1.0f), Random::GenRange(-1.0f, 1.0f), Random::GenRange(-1.0f, 1.0f));
        points[i].seed = Random::Gen();
    }

    glGenVertexArrays(1, &mFractalFlame.vao);
    glBindVertexArray(mFractalFlame.vao);

    glGenBuffers(1, &mFractalFlame.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, mFractalFlame.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Point) * POINT_COUNT, &points[0], GL_STATIC_DRAW);

    GLint loc = glGetAttribLocation(mFractalFlame.program, "Position");
    glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, sizeof(Point), 0);
    glEnableVertexAttribArray(loc);

    loc = glGetAttribLocation(mFractalFlame.program, "Seed");
    glVertexAttribIPointer(loc, 1, GL_UNSIGNED_INT, sizeof(Point), reinterpret_cast<void*>(sizeof(glm::vec3)));
    glEnableVertexAttribArray(loc);

    // textures
    mPaletteTexture[0] = CreatePaletteTexture("../../media/palette_muted.png");
    mPaletteTexture[1] = CreatePaletteTexture("../../media/palette_fire.png");
    mPaletteTexture[2] = CreatePaletteTexture("../../media/palette_purple.png");
    mPaletteTexture[3] = CreatePaletteTexture("../../media/palette_rainbow.png");
    mPaletteTexture[4] = CreatePaletteTexture("../../media/palette_sky.png");

    // float render target
    glGenTextures(1, &mRenderTarget);
    glBindTexture(GL_TEXTURE_2D, mRenderTarget);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, w, h, 0, GL_RGBA, GL_FLOAT, NULL);

    glGenFramebuffers(1, &mFramebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, mFramebuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mRenderTarget, 0);

    // quad
    mQuad.program = gl::BuildProgram(VshQuad(), FshQuad());

    glGenVertexArrays(1, &mQuad.vao);
    glBindVertexArray(mQuad.vao);

    glGenBuffers(1, &mQuad.vbo);
    const float data[] = { -1, -1, 1, -1, -1, 1, 1, 1 };
    glBindBuffer(GL_ARRAY_BUFFER, mQuad.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    // app state
    mPaletteIdx = 0;
    mAnimate = false;
    mZoom = 1.0f;
    mArcBall.SetWindowSize(w, h);

    mAnimTrans[0].Random();
    mAnimTrans[1].Random();
    mAnimTrans[2].Random();

    mTrans[0] = mAnimTrans[0].GetTransform();
    mTrans[1] = mAnimTrans[1].GetTransform();
    mTrans[2] = mAnimTrans[2].GetTransform();

    mAnimTrans[0].SetSpeed(0.3f);
    mAnimTrans[1].SetSpeed(0.3f);
    mAnimTrans[2].SetSpeed(0.3f);

    // gui
    TwInit(TW_OPENGL, NULL);
    TwWindowSize(w, h);
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='240 150'");
    TwDefine("Menu fontresizable=false resizable=false");

    TwAddVarRW(bar, "Animate", TW_TYPE_BOOLCPP, &mAnimate, "");

    TwEnumVal v[] = { { 0, "muted" }, { 1, "fire" }, { 2, "purple" }, { 3, "rainbow" }, { 4, "sky" } };
    TwType type = TwDefineEnum("colors", &v[0], 5);
    TwAddVarRW(bar, "Colors", type, &mPaletteIdx, "");

    TwAddSeparator(bar, NULL, NULL);
    TwAddButton(bar, "usage", NULL, NULL, "label='Usage:'");
    TwAddButton(bar, "help0", NULL, NULL, "label='  - mouse with LB down to rotate'");
    TwAddButton(bar, "help1", NULL, NULL, "label='  - [ Z ] to zoom'");
    TwAddButton(bar, "help2", NULL, NULL, "label='  - [ SHIFT+Z ] to unzoom'");

    mLastTime = SDL_GetTicks();
}
//-----------------------------------------------------------------------------
bool FractalFlames::ProcessEvents() {
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
void FractalFlames::Update() {
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

    glm::mat4 proj = glm::perspective(60.0f, 1.0f, 0.1f, 50.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(3.0f, 3.0f, 15.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 world = glm::mat4(mArcBall.Rotation());
    glm::mat4 projViewWorld = proj * view * world * glm::scale(mZoom, mZoom, mZoom);

    if (mAnimate) {
        mTrans[0] = mAnimTrans[0].GetTransform();
        mTrans[1] = mAnimTrans[1].GetTransform();
        mTrans[2] = mAnimTrans[2].GetTransform();

        mAnimTrans[0].AddTime(dt);
        mAnimTrans[1].AddTime(dt);
        mAnimTrans[2].AddTime(dt);
    }

    glm::mat4 matrix[3];
    matrix[0] = mTrans[0].GetMatrix();
    matrix[1] = mTrans[1].GetMatrix();
    matrix[2] = mTrans[2].GetMatrix();

    glUseProgram(mFractalFlame.program);
    glUniformMatrix4fv(glGetUniformLocation(mFractalFlame.program, "ProjView"), 1, GL_FALSE, glm::value_ptr(projViewWorld));
    glUniformMatrix4fv(glGetUniformLocation(mFractalFlame.program, "Trans"), 3, GL_FALSE, glm::value_ptr(matrix[0]));

    glBindFramebuffer(GL_FRAMEBUFFER, mFramebuffer);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_ONE, GL_ONE);

    glBindTexture(GL_TEXTURE_1D, mPaletteTexture[mPaletteIdx]);
    glBindVertexArray(mFractalFlame.vao);
    glDrawArrays(GL_POINTS, 0, POINT_COUNT);
    
    glDisable(GL_BLEND);

    glUseProgram(mQuad.program);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, mRenderTarget);
    glBindVertexArray(mQuad.vao);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

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
        FractalFlames fractalFlames;
        fractalFlames.Run();
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