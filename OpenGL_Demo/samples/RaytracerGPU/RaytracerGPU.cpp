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
const char* Vsh_visvbo() {
    return OGL_SHADER_BEGIN(130)
        N  "in vec4 Position;"
        N  "out vec4 color_v;"
        N  "void main() {"
        N  "    gl_Position = Position;"
        N  "    color_v = vec4((gl_Position.xy+1)*0.5, 1, 1);"
        N  "}";
}
const char* Fsh_trvial() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform mat4 View;"
        N  "uniform float Time;"
        N  "in vec4 color_v;"
        N  "out vec4 color_f;"
        N  "void main() {"
        N  "    color_f = color_v;"
        N  "}";
}
const char* Fsh() {
	return OGL_SHADER_BEGIN(130)
        N  "//#define _DEBUG"
        N  "uniform mat4 View;"
        N  "uniform float Time;"
        N  "out vec4 Color;"
        N  ""
        N  "struct Object {"
        N  "    int type;"
        N  "    vec4 params;"
        N  "    vec3 color;"
        N  "    float diffuse;"
        N  "};"
        N  ""
        N  "struct Light {"
        N  "    vec3 position;"
        N  "    vec3 color;"
        N  "};"
        N  ""
        N  "Object Objects[] = Object[]("
        N  "    Object(0, vec4(1, -0.8, -3, 2.5), vec3(0.7, 0.7, 0.0), 0.75),"
        N  "    Object(0, vec4(-5.5, -0.5, -7, 2), vec3(0.7, 0.0, 0.1), 0.7),"
        N  "    Object(1, vec4(0, 1, 0, 4.4), vec3(0.4, 0.3, 0.3), 1.0)"
        N  ");"
        N  ""
        N  "Light Lights[] = Light[]("
        N  "    Light(vec3(0, 5, -5), vec3(0.6)),"
        N  "    Light(vec3(2, 5, -1), vec3(0.7, 0.7, 0.9)),"
        N  "    Light(vec3(0, 15, 0), vec3(0.8))"
        N  ");"
        N  ""
        N  "vec3 GetNormal(int object, vec3 p) {"
        N  "    if (Objects[object].type == 0) {"
        N  "        return (p - Objects[object].params.xyz) / Objects[object].params.w;"
        N  "    }"
        N  "    else {"
        N  "        return Objects[object].params.xyz;"
        N  "    }"
        N  "}"
        N  ""
        N  "float IntersectSphere(vec3 rO, vec3 rD, vec3 sC, float sR) {"
        N  "    vec3 s = rO-sC;"
        N  "    float b = 2*dot(s, rD);"
        N  "    float c = dot(s, s)-sR*sR;"
        N  "    float d = b*b-4*c;"
        N  "    float t = -1;"
        N  "    if (!(d < 0))"
        N  "    {"
        N  "        float min = 0.5 * (-b-sqrt(d));"
        N  "        float max = 0.5 * (-b+sqrt(d));"
        N  "        if (min > 0)"
        N  "           t = min;"
        N  "        else if (max > 0)"
        N  "            t = max;"
        N  "    }"
        N  "    return t;"
        N  "}"
        N  ""
        N  "float IntersectPlane(vec3 rO, vec3 rD, vec3 pN, float pD) {"
        N  "    float dp = dot(pN, rD);"
        N  "    float d = -(dot(pN, rO) + pD) / dp;"
        N  ""
        N  "    return d;"
        N  "}"
        N  ""
        N  "int IntersectObject(vec3 rO, vec3 rD, out float d) {"
        N  "    float currDistance, minDistance = 100000.0;"
        N  "    int minObject = -1;"
        N  ""
        N  "    for (int i = 0; i < Objects.length(); ++i) {"
        N  "        if (Objects[i].type == 0) {"
        N  "            if ((currDistance = IntersectSphere(rO, rD, Objects[i].params.xyz, Objects[i].params.w)) >= 0"
        N  "            && currDistance < minDistance)"
        N  "            {"
        N  "                minDistance = currDistance;"
        N  "                minObject = i;"
        N  "            }"
        N  "        }"
        N  "        else {"
        N  "            if ((currDistance = IntersectPlane(rO, rD, Objects[i].params.xyz, Objects[i].params.w)) >= 0"
        N  "            && currDistance < minDistance)"
        N  "            {"
        N  "                minDistance = currDistance;"
        N  "                minObject = i;"
        N  "            }"
        N  "        }"
        N  "    }"
        N  ""
        N  "    d = minDistance;"
        N  "    return minObject;"
        N  "}"
        N  ""
        N  "vec3 Shade(int object, vec3 p, vec3 n) {"
        N  "    vec3 color = vec3(0);"
        N  ""
        N  "    for (int i = 0; i < Lights.length(); ++i) {"
        N  "        vec3 lightVec = Lights[i].position - p;"
        N  "        vec3 l = normalize(lightVec);"
        N  ""
        N  "        float sD;"
        N  "        int j = IntersectObject(p + l * 0.001, l, sD);"
        N  ""
        N  "        if (length(lightVec) < sD) {"
        N  "            float d = Objects[object].diffuse * max(dot(n, l), 0);"
        N  "            color += d * Objects[object].color * Lights[i].color;"
        N  "        }"
        N  "    }"
        N  ""
        N  "    return color;"
        N  "}"
        N  ""
        N  "vec3 Trace(vec3 rO, vec3 rD) {"
        N  "    float d;"
        N  "    int object = IntersectObject(rO, rD, d);"
        N  ""
        N  "    if (object == -1) {"
        N  "        return vec3(0);"
        N  "    }"
        N  ""
        N  "    vec3 p = rO + d * rD;"
        N  "    vec3 n = GetNormal(object, p);"
        N  "    return Shade(object, p, n);"
        N  "}"
        N  ""
        N  "void main() {"
        N  "    vec4 orig = View * vec4(0, 0, 5, 1);"
        N  "    float invWidth = 1.0 / 800.0;"
        N  "    float invHeight = 1.0 / 600.0;"
        N  "    float kcx = (gl_FragCoord.x * invWidth - 0.5) * 8;"
        N  "    float kcy = (gl_FragCoord.y * invHeight - 0.5) * 6;"
        N  "    vec4 rayO = View * vec4(kcx, kcy, 0, 1);"
        N  "    vec3 rayD = normalize(rayO.xyz - orig.xyz);"
        N  ""
        N  "    //Objects[0].params.xz -= sin(Time) * cos(Time);"
        N  "    //Objects[1].params.xz += sin(Time) * cos(Time);"
        N  "#ifndef _DEBUG"
        N  "    Color = vec4(Trace(rayO.xyz, rayD), 1);"
        N  "#else"
        N  "    Color = vec4(1, 1, 1, 1);"
        N  "    for (int i = 0; i < Objects.length(); ++i) {"
        N  "        if (Objects[i].type == 0) {"
        N  "            float t = IntersectSphere(rayO.xyz, rayD, Objects[i].params.xyz, Objects[i].params.w);"
        N  "            if (t > 0)"
        N  "            {"
        N  "                highp int t_i = int(t*1000);"
        N  "                int wb = 255 * 255;"
        N  "                int b = t_i/wb;"
        N  "                int rb = t_i - b*wb;"
        N  "                int wg = 255;"
        N  "                int g = rb/wg;"
        N  "                int rg = rb - g*wg;"
        N  "                int r = rg;"
        N  "                Color = vec4(float(r)/float(255), float(g)/float(255), float(b)/float(255), 1);"
        N  "                break;"
        N  "            }"
        N  "        }"
        N  "    }"
        N  "#endif"
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
    RaytracerGPU() : m_Window(NULL), m_GLContext(NULL), m_VAO(0), m_VBO(0), m_Program(0) {}
    ~RaytracerGPU();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    void UpdateCamera(float dt);

    GLWindow* m_Window;
    SDL_GLContext m_GLContext;

    GLuint m_Program;
    GLuint m_VAO, m_VBO;

    glm::vec3 m_CameraPos;
    float mCameraRotX, mCameraRotY;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
RaytracerGPU::~RaytracerGPU() {
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteProgram(m_Program);
    TwTerminate();
    SDL_GL_DeleteContext(m_GLContext);
    delete m_Window;
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
    m_Window = new GLWindow("Simple GPU Raytracer", 800, 600);

    // context
    if (!(m_GLContext = SDL_GL_CreateContext(m_Window->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }
    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(33);

    // program
    m_Program = gl::BuildProgram(Vsh(), Fsh());
    //m_Program = gl::BuildProgram(Vsh_visvbo(), Fsh_trvial());

    // vbo
    const float data[] = { -1, -1, 1, -1, -1, 1, 1, 1 };
    //const float data[] = { -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, 0.5 };
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // vao
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    m_CameraPos = glm::vec3(0.0f, 1.0f, 7.0f);
    mCameraRotX = mCameraRotY = 0;

    TwInit(TW_OPENGL, NULL);
    TwWindowSize(m_Window->Width(), m_Window->Height());
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

    glm::vec3 cameraCenter = m_CameraPos + ComputeDirection(mCameraRotX, mCameraRotY);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    const glm::mat4 view = glm::lookAt(m_CameraPos, cameraCenter, cameraUp);
    printf("\nlookAt:"
            "\n\teye=[%5.2f, %5.2f, %5.2f]"
            "\n\tcenter=[%5.2f, %5.2f, %5.2f]"
            "\n\tup=[%5.2f, %5.2f, %5.2f]"
        , m_CameraPos.x, m_CameraPos.y, m_CameraPos.z
        , cameraCenter.x, cameraCenter.y, cameraCenter.z
        , cameraUp.x, cameraUp.y, cameraUp.z);

    glUseProgram(m_Program);
    glUniformMatrix4fv(glGetUniformLocation(m_Program, "View"), 1, GL_FALSE, glm::value_ptr(glm::inverse(view)));
    glUniform1f(glGetUniformLocation(m_Program, "Time"), currentTime);

    glBindVertexArray(m_VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    // draw GUI
    //glUseProgram(0);
    //glBindVertexArray(0);
    //TwDraw();

    m_Window->Swap();
}
//-----------------------------------------------------------------------------
void RaytracerGPU::UpdateCamera(float dt) {
    const float moveScale = 10 * dt;
    const float rotScale = 2 * dt;
    const glm::vec3 forward = ComputeDirection(mCameraRotX, mCameraRotY);
    const glm::vec3 right = -glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), ComputeDirection(mCameraRotX, mCameraRotY));

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_W]) {
        m_CameraPos += forward * moveScale;
    }
    if (keyState[SDL_SCANCODE_S]) {
        m_CameraPos -= forward * moveScale;
    }
    if (keyState[SDL_SCANCODE_D]) {
        m_CameraPos += right * moveScale;
    }
    if (keyState[SDL_SCANCODE_A]) {
        m_CameraPos -= right * moveScale;
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