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
        N  "uniform mat4 view2world;"
        N  "uniform float Time;"
        N  "in vec4 color_v;"
        N  "out vec4 color_f;"
        N  "void main() {"
        N  "    color_f = color_v;"
        N  "}";
}
const char* LoadGLSL(const char* fileName)
{
	char* code = NULL;
#ifdef _WIN32
    int pp = 0;
#ifdef _DEBUG
	const char* srcPath = __FILE__;
#else
    char* srcPath = new char[MAX_PATH];
    GetModuleFileNameA(NULL, srcPath, MAX_PATH);
#endif
	for (int p = 0
		; srcPath[p] != '\0'
		; p++)
	{
		if (srcPath[p] == '\\')
			pp = p;
	}
	std::string fullPath(srcPath, srcPath + pp + 1);
	fullPath += fileName;

	//TODO: extract parent path from __FILE__
    HANDLE hFile = ::CreateFileA(fullPath.c_str()
                                , GENERIC_READ
                                , 0
                                , NULL
                                , OPEN_EXISTING
                                , FILE_ATTRIBUTE_NORMAL
                                , NULL);
    assert(INVALID_HANDLE_VALUE != hFile);
    DWORD dwSize = ::GetFileSize(hFile, NULL);
    code = new char[dwSize+1];
    DWORD dwRead = 0;
    ::ReadFile(hFile
            , code
            , dwSize
            , &dwRead
            , NULL);
    code[dwRead] = '\0';
    ::CloseHandle(hFile);
#ifndef _DEBUG
    delete [] srcPath;
#endif
#endif
    return code;
}

#define UnLoadGLSL(ptrCode)\
	delete [] ptrCode
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
    const char* v_glsl = LoadGLSL("Vsh.glsl");
    const char* f_glsl = LoadGLSL("Fsh.glsl");
    m_Program = gl::BuildProgram(v_glsl, f_glsl);
    UnLoadGLSL(v_glsl);
    UnLoadGLSL(f_glsl);
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
    const glm::mat4 world2view = glm::lookAt(m_CameraPos, cameraCenter, cameraUp);
    printf("\nlookAt:"
            "\n\teye=[%5.2f, %5.2f, %5.2f]"
            "\n\tcenter=[%5.2f, %5.2f, %5.2f]"
            "\n\tup=[%5.2f, %5.2f, %5.2f]"
        , m_CameraPos.x, m_CameraPos.y, m_CameraPos.z
        , cameraCenter.x, cameraCenter.y, cameraCenter.z
        , cameraUp.x, cameraUp.y, cameraUp.z);
    for (int i_row = 0; i_row < 4; i_row ++)
    {
		printf("\n\t|%5.2f %5.2f %5.2f %5.2f|", world2view[0][i_row], world2view[1][i_row], world2view[2][i_row], world2view[3][i_row]);
    }

    glUseProgram(m_Program);
    glUniformMatrix4fv(glGetUniformLocation(m_Program, "view2world"), 1, GL_FALSE, glm::value_ptr(glm::inverse(world2view)));
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