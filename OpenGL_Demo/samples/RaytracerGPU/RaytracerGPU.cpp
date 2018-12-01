// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

#include "Common.hpp"
#include <stdexcept>
#include "libGLTracer.h"
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
        N  "uniform mat4 View;"
        N  "uniform float Time;"
        N  "out vec4 Color;"
        N
        N  "struct Object {"
        N  "    int type;"
        N  "    vec4 params;"
        N  "    vec3 color;"
        N  "    float diffuse;"
        N  "};"
        N
        N  "struct Light {"
        N  "    vec3 position;"
        N  "    vec3 color;"
        N  "};"
        N
        N  "Object Objects[] = Object[]("
        N  "    Object(0, vec4(1, -0.8, -3, 2.5), vec3(0.7, 0.7, 0.0), 0.75),"
        N  "    Object(0, vec4(-5.5, -0.5, -7, 2), vec3(0.7, 0.0, 0.1), 0.7),"
        N  "    Object(1, vec4(0, 1, 0, 4.4), vec3(0.4, 0.3, 0.3), 1.0)"
        N  ");"
        N
        N  "Light Lights[] = Light[]("
        N  "    Light(vec3(0, 5, -5), vec3(0.6)),"
        N  "    Light(vec3(2, 5, -1), vec3(0.7, 0.7, 0.9)),"
        N  "    Light(vec3(0, 15, 0), vec3(0.8))"
        N  ");"
        N
        N  "vec3 GetNormal(int object, vec3 p) {"
        N  "    if (Objects[object].type == 0) {"
        N  "        return (p - Objects[object].params.xyz) / Objects[object].params.w;"
        N  "    }"
        N  "    else {"
        N  "        return Objects[object].params.xyz;"
        N  "    }"
        N  "}"
        N
        N  "bool IntersectSphere(vec3 rO, vec3 rD, vec3 sC, float sR, out float d) {"
        N  "    vec3 l = sC - rO;"
        N  "    float s = dot(l, rD);"
        N  "    float l2 = dot(l, l);"
        N  "    float sqR = sR * sR;"
        N  "    float m2 = l2 - s * s;"
        N  "    float q = sqrt(sqR - m2);"
        N  "    d = (l2 > sqR) ? (s - q) : (s + q);"
        N
        N  "    if (d > 0) {"
        N  "        return true;"
        N  "    }"
        N
        N  "    return false;"
        N  "}"
        N
        N  "bool IntersectPlane(vec3 rO, vec3 rD, vec3 pN, float pD, out float d) {"
	    N  "    float dp = dot(pN, rD);"
		N  "    d = -(dot(pN, rO) + pD) / dp;"
        N
		N  "    if (d > 0) {"
		N  "        return true;"
        N  "    }"
        N
	    N  "    return false;"
        N  "}"
        N
        N  "int IntersectObject(vec3 rO, vec3 rD, out float d) {"
        N  "    float currDistance, minDistance = 100000.0;"
        N  "    int minObject = -1;"
        N
        N  "    for (int i = 0; i < Objects.length(); ++i) {"
        N  "        if (Objects[i].type == 0) {"
        N  "            if (IntersectSphere(rO, rD, Objects[i].params.xyz, Objects[i].params.w, currDistance) && currDistance < minDistance) {"
        N  "                minDistance = currDistance;"
        N  "                minObject = i;"
        N  "            }"
        N  "        }"
        N  "        else {"
        N  "            if (IntersectPlane(rO, rD, Objects[i].params.xyz, Objects[i].params.w, currDistance) && currDistance < minDistance) {"
        N  "                minDistance = currDistance;"
        N  "                minObject = i;"
        N  "            }"
        N  "        }"
        N  "    }"
        N
        N  "    d = minDistance;"
        N  "    return minObject;"
        N  "}"
        N
        N  "vec3 Shade(vec3 rO, vec3 rD, int object, vec3 p, vec3 n) {"
        N  "    vec3 color = vec3(0);"
        N
        N  "    for (int i = 0; i < Lights.length(); ++i) {"
        N  "        vec3 lightVec = Lights[i].position - p;"
        N  "        vec3 l = normalize(lightVec);"
        N
        N  "        float sD;"
        N  "        IntersectObject(p + l * 0.001, l, sD);"
        N
        N  "        if (length(lightVec) < sD) {"
        N  "            float d = Objects[object].diffuse * max(dot(n, l), 0);"
        N  "            color += d * Objects[object].color * Lights[i].color;"
        N  "        }"
        N  "    }"
        N
        N  "    return color;"
        N  "}"
        N
        N  "vec3 Trace(vec3 rO, vec3 rD) {"
        N  "    float d;"
        N  "    int object = IntersectObject(rO, rD, d);"
        N
        N  "    if (object == -1) {"
        N  "        return vec3(0);"
        N  "    }"
        N
        N  "    vec3 p = rO + d * rD;"
        N  "    vec3 n = GetNormal(object, p);"
        N  "    return Shade(rO, rD, object, p, n);"
        N  "}"
        N
        N  "void main() {"
        N  "    vec4 orig = View * vec4(0, 0, 5, 1);"
        N  "    float invWidth = 1.0 / 800.0;"
        N  "    float invHeight = 1.0 / 600.0;"
        N  "    float kcx = (gl_FragCoord.x * invWidth - 0.5) * 8;"
        N  "    float kcy = (gl_FragCoord.y * invHeight - 0.5) * 6;"
        N  "    vec4 rayO = View * vec4(kcx, kcy, 0, 1);"
        N  "    vec3 rayD = normalize(rayO.xyz - orig.xyz);"
        N
        N  "    Objects[0].params.xz -= sin(Time) * cos(Time);"
        N  "    Objects[1].params.xz += sin(Time) * cos(Time);"
        N
        N  "    Color = vec4(Trace(rayO.xyz, rayD), 1);"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
glm::vec3 ComputeDirection(float rotX, float rotY) {
    const glm::vec3 rotDir = glm::mat3(glm::rotate(glm::degrees(rotY), 0.0f, 1.0f, 0.0f)) * glm::vec3(0.0f, 0.0f, -1.0f);
    const glm::vec3 rotXAxis = -glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), rotDir);
    return glm::mat3(glm::rotate(glm::degrees(rotX), rotXAxis)) * rotDir;
}
//-----------------------------------------------------------------------------
// RaytracerGPU
//-----------------------------------------------------------------------------
class RaytracerGPU {
public:
    RaytracerGPU() : mWindow(NULL), mGLContext(NULL), mVAO(0), mVBO(0), mProgram(0) {}
    ~RaytracerGPU();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    void UpdateCamera(float dt);

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    GLuint mProgram;
    GLuint mVAO, mVBO;

    glm::vec3 mCameraPos;
    float mCameraRotX, mCameraRotY;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
RaytracerGPU::~RaytracerGPU() {
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteProgram(mProgram);
    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void RaytracerGPU::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void RaytracerGPU::Init() {
    // window
    mWindow = new GLWindow("Simple GPU Raytracer", 800, 600);

    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }
    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(33);

    // program
    mProgram = gl::BuildProgram(Vsh(), Fsh());

    // vbo
    const float data[] = { -1, -1, 1, -1, -1, 1, 1, 1 };
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // vao
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    mCameraPos = glm::vec3(0.0f, 1.0f, 7.0f);
    mCameraRotX = mCameraRotY = 0;

    TwInit(TW_OPENGL, NULL);
    TwWindowSize(mWindow->Width(), mWindow->Height());
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='240 85'");
    TwDefine("Menu fontresizable=false resizable=false movable=false");
    TwAddButton(bar, "usage", NULL, NULL, "label='Usage:'");
    TwAddButton(bar, "help0", NULL, NULL, "label='  - [ W ][ A ][ S ][ D ] to move'");
    TwAddButton(bar, "help1", NULL, NULL, "label='  - mouse with LB down to rotate'");
}
//-----------------------------------------------------------------------------
bool RaytracerGPU::ProcessEvents() {
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            return false;
        }

        if (ProcessAntTweakBarEvent(evt)) continue;
        ProcessCommonEvent(evt);
    }

    return true;
}
//-----------------------------------------------------------------------------
void RaytracerGPU::Update() {
    const Uint32 now = SDL_GetTicks();
    const float dt = (now - mLastTime) * 0.001f;
    mLastTime = now;
    const float currentTime = now * 0.001f;

    UpdateCamera(dt);

    const glm::mat4 view = glm::lookAt(mCameraPos, mCameraPos + ComputeDirection(mCameraRotX, mCameraRotY),
        glm::vec3(0.0f, 1.0f, 0.0f));

    glUseProgram(mProgram);
    glUniformMatrix4fv(glGetUniformLocation(mProgram, "View"), 1, GL_FALSE, glm::value_ptr(glm::inverse(view)));
    glUniform1f(glGetUniformLocation(mProgram, "Time"), currentTime);

    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    // draw GUI
    glUseProgram(0);
    glBindVertexArray(0);
    TwDraw();

    mWindow->Swap();
}
//-----------------------------------------------------------------------------
void RaytracerGPU::UpdateCamera(float dt) {
    const float moveScale = 10 * dt;
    const float rotScale = 2 * dt;
    const glm::vec3 forward = ComputeDirection(mCameraRotX, mCameraRotY);
    const glm::vec3 right = -glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), ComputeDirection(mCameraRotX, mCameraRotY));

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_W]) {
        mCameraPos += forward * moveScale;
    }
    if (keyState[SDL_SCANCODE_S]) {
        mCameraPos -= forward * moveScale;
    }
    if (keyState[SDL_SCANCODE_D]) {
        mCameraPos += right * moveScale;
    }
    if (keyState[SDL_SCANCODE_A]) {
        mCameraPos -= right * moveScale;
    }

    int rx, ry;
    Uint8 buttonState = SDL_GetRelativeMouseState(&rx, &ry);
    if (buttonState & SDL_BUTTON_LMASK) {
        mCameraRotX -= ry * 0.005f;
        mCameraRotY -= rx * 0.005f;
    }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
        DisplayErrorMessage("main", "SDL_Init failed");
        return 0;
    }

    try {
        RaytracerGPU raytracer2;
        raytracer2.Run();
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