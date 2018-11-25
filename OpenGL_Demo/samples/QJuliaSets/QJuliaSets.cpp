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
        N  "in vec4 Position;"
        N  "void main() {"
        N  "    gl_Position = Position;"
        N  "}";
}
const char* Fsh() {
    return OGL_SHADER_BEGIN(130)
        N  "const float BOUNDING_RADIUS_2 = 3.0;"
        N  "const float ESCAPE_THRESHOLD = 1e1;"
        N  "const float DEL = 1e-4;"
        N  "vec4 QuatMul(vec4 q1, vec4 q2) {"
        N  "    vec4 r;"
        N  "    r.x = q1.x * q2.x - dot(q1.yzw, q2.yzw);"
        N  "    r.yzw = q1.x * q2.yzw + q2.x * q1.yzw + cross(q1.yzw, q2.yzw);"
        N  "    return r;"
        N  "}"
        N  "vec4 QuatSq(vec4 q) {"
        N  "    vec4 r;"
        N  "    r.x = q.x * q.x - dot(q.yzw, q.yzw);"
        N  "    r.yzw = 2 * q.x * q.yzw;"
        N  "    return r;"
        N  "}"
        N  "void IterateIntersect(inout vec4 q, inout vec4 qp, vec4 c, int maxIterations) {"
        N  "    for (int i = 0; i < maxIterations; i++) {"
        N  "        qp = 2.0 * QuatMul(q, qp);"
        N  "        q = QuatSq(q) + c;"
        N  "        if (dot(q, q) > ESCAPE_THRESHOLD) break;"
        N  "    }"
        N  "}"
        N  "vec3 NormEstimate(vec3 p, vec4 c, int maxIterations, float slice) {"
        N  "    vec3 N;"
        N  "    float gradX, gradY, gradZ;"
        N  "    vec4 gx1 = vec4(p - vec3(DEL, 0, 0), slice);"
        N  "    vec4 gx2 = vec4(p + vec3(DEL, 0, 0), slice);"
        N  "    vec4 gy1 = vec4(p - vec3(0, DEL, 0), slice);"
        N  "    vec4 gy2 = vec4(p + vec3(0, DEL, 0), slice);"
        N  "    vec4 gz1 = vec4(p - vec3(0, 0, DEL), slice);"
        N  "    vec4 gz2 = vec4(p + vec3(0, 0, DEL), slice);"
        N  "    for (int i = 0; i < maxIterations; i++) {"
        N  "        gx1 = QuatSq(gx1) + c;"
        N  "        gx2 = QuatSq(gx2) + c;"
        N  "        gy1 = QuatSq(gy1) + c;"
        N  "        gy2 = QuatSq(gy2) + c;"
        N  "        gz1 = QuatSq(gz1) + c;"
        N  "        gz2 = QuatSq(gz2) + c;"
        N  "    }"
        N  "    gradX = length(gx2) - length(gx1);"
        N  "    gradY = length(gy2) - length(gy1);"
        N  "    gradZ = length(gz2) - length(gz1);"
        N  "    N = normalize(vec3(gradX, gradY, gradZ));"
        N  "    return N;"
        N  "}"
        N  "float IntersectQJulia(inout vec3 rO, inout vec3 rD, vec4 c, int maxIterations, float epsilon, float slice) {"
        N  "    float dist;"
        N  "    while (true) {"
        N  "        vec4 z = vec4(rO, slice);"
        N  "        vec4 zp = vec4(1, 0, 0, 0);"
        N  "        IterateIntersect(z, zp, c, maxIterations);"
        N  "        float normZ = length(z);"
        N  "        dist = 0.5 * normZ * log(normZ) / length(zp);"
        N  "        rO += rD * dist;"
        N  "        if (dist < epsilon || dot(rO, rO) > BOUNDING_RADIUS_2) break;"
        N  "    }"
        N  "    return dist;"
        N  "}"
        N  "uniform vec3 Eye = vec3(0, 0, 2.2);"
        N  "uniform mat3 Orientation = mat3(1);"
        N  "uniform vec3 Light = vec3(3, 3, 3);"
        N  "uniform vec3 LightColor = vec3(0.95, 0.7, 0.1);"
        N  "uniform vec4 Quat = vec4(0.25, 0.5, 0.0, 0.25);"
        N  "uniform float Epsilon = 0.003;"
        N  "uniform float Slice;"
        N  "uniform int MaxIterations = 10;"
        N  "out vec4 Color;"
        N  "vec3 Phong(vec3 light, vec3 eye, vec3 pt, vec3 N) {"
        N  "    vec3 diffuse = LightColor;"
        N  "    float specularExponent = 16;"
        N  "    float specularity = 0.5;"
        N  "    vec3 L = normalize(light - pt);"
        N  "    vec3 E = normalize(eye - pt);"
        N  "    float NdotL = dot(N, L);"
        N  "    vec3 R = L - 2 * NdotL * N;"
        N  "    diffuse += abs(N) * 0.3;"
        N  "    return vec3(0.1) + diffuse * max(NdotL, 0.0) + specularity * pow(max(dot(E, R), 0.0), specularExponent);"
        N  "}"
        N  "void main() {"
        N  "    vec3 color = vec3(0);"
        N  "    vec2 sampleCoord[] = vec2[]("
        N  "        vec2(-0.25, -0.25), vec2(0.25, -0.25),"
        N  "        vec2(0.25, 0.25), vec2(-0.25, 0.25));"
        N  "    for (int s = 0; s < sampleCoord.length(); ++s) {"
        N  "        vec2 coord = vec2(gl_FragCoord.x + sampleCoord[s].x, gl_FragCoord.y + sampleCoord[s].y);"
        N  "        vec3 ray = vec3(((coord.x - 400) / 400) * 1.333, ((coord.y - 300) / 300), -1);"
        N  "        vec3 dir = normalize(Orientation * ray);"
        N  "        vec3 origin = Orientation * Eye;"
        N  "        float dist = IntersectQJulia(origin, dir, Quat, MaxIterations, Epsilon, Slice);"
        N  "        if (dist < Epsilon) {"
        N  "            vec3 N = NormEstimate(origin, Quat, MaxIterations, Slice);"
        N  "            color += Phong(Orientation * Light, Orientation * Eye, origin, N);"
        N  "        }"
        N  "    }"
        N  "    Color = vec4(color * 0.25, 1);"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// QJuliaSets
//-----------------------------------------------------------------------------
class QJuliaSets {
public:
    QJuliaSets() : mWindow(NULL), mGLContext(NULL), mVAO(0), mVBO(0), mProgram(0) {}
    ~QJuliaSets();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    GLuint mProgram;
    GLuint mVAO;
    GLuint mVBO;

    ArcBall mArcBall;
    float mZoom;
    glm::quat mQuat;
    glm::vec3 mLightColor;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
QJuliaSets::~QJuliaSets() {
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteProgram(mProgram);
    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void QJuliaSets::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void QJuliaSets::Init() {
    // window
    const int w = 800, h = 600;
    mWindow = new GLWindow("Quaternion Julia Sets", w, h);

    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    mProgram = gl::BuildProgram(Vsh(), Fsh());

    // quad
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    const float data[] = { -1, -1, 1, -1, -1, 1, 1, 1 };
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    // quat
    glGetUniformfv(mProgram, glGetUniformLocation(mProgram, "Quat"), &mQuat[0]);
    glGetUniformfv(mProgram, glGetUniformLocation(mProgram, "LightColor"), &mLightColor[0]);
    mZoom = 1.0f;
    mArcBall.SetWindowSize(w, h);

    TwInit(TW_OPENGL, NULL);
    TwWindowSize(w, h);
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='240 210'");
    TwDefine("Menu fontresizable=false resizable=false");

    TwAddVarRW(bar, "qx", TW_TYPE_FLOAT, &mQuat.x, "label='Quaternion X' step=0.01 min=-1 max=1");
    TwAddVarRW(bar, "qy", TW_TYPE_FLOAT, &mQuat.y, "label='Quaternion Y' step=0.01 min=-1 max=1");
    TwAddVarRW(bar, "qz", TW_TYPE_FLOAT, &mQuat.z, "label='Quaternion Z' step=0.01 min=-1 max=1");
    TwAddVarRW(bar, "qw", TW_TYPE_FLOAT, &mQuat.w, "label='Quaternion W' step=0.01 min=-1 max=1");

    TwAddSeparator(bar, NULL, NULL);
    TwAddVarRW(bar, "light_color", TW_TYPE_COLOR3F, &mLightColor, "label='Light Color'");

    TwAddSeparator(bar, NULL, NULL);
    TwAddButton(bar, "usage", NULL, NULL, "label='Usage:'");
    TwAddButton(bar, "help0", NULL, NULL, "label='  - mouse with LB down to rotate'");
    TwAddButton(bar, "help1", NULL, NULL, "label='  - [ Z ] to zoom'");
    TwAddButton(bar, "help2", NULL, NULL, "label='  - [ SHIFT+Z ] to unzoom'");

    mLastTime = SDL_GetTicks();
}
//-----------------------------------------------------------------------------
bool QJuliaSets::ProcessEvents() {
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
            mZoom = glm::clamp(mZoom, 0.7f, 1.5f);
            break;
        }
    }

    return true;
}
//-----------------------------------------------------------------------------
void QJuliaSets::Update() {
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

    mZoom = glm::clamp(mZoom, 0.7f, 1.5f);
    const glm::mat3 world = mArcBall.Rotation() * glm::mat3(glm::scale(mZoom, mZoom, mZoom));

    glUseProgram(mProgram);
    glUniformMatrix3fv(glGetUniformLocation(mProgram, "Orientation"), 1, GL_FALSE, glm::value_ptr(glm::inverse(world)));
    glUniform4fv(glGetUniformLocation(mProgram, "Quat"), 1, &mQuat[0]);
    glUniform3fv(glGetUniformLocation(mProgram, "LightColor"), 1, &mLightColor[0]);

    glBindVertexArray(mVAO);
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
        QJuliaSets qjuliaSets;
        qjuliaSets.Run();
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