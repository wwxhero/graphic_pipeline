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
        N  "uniform mat4 Rotation;"
        N  "in vec4 Position;"
        N  "in vec3 ColorIn;"
        N  "out vec3 Color;"
        N  "void main() {"
        N  "    gl_Position = Rotation * Position;"
        N  "    Color = mat3(Rotation) * ColorIn;"
        N  "}";
}
const char* Fsh() {
    return OGL_SHADER_BEGIN(130)
        N  "in vec3 Color;"
        N  "out vec4 ColorOut;"
        N  "void main() {"
        N  "    ColorOut = vec4(Color, 1);"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// MultiWindow
//-----------------------------------------------------------------------------
class MultiWindow {
public:
    MultiWindow() : mWindow0(NULL), mWindow1(NULL), mGLContext0(NULL), mGLContext1(NULL) {}
    ~MultiWindow();

    void Run();
    
private:
    void Init();
    bool ProcessEvents();

    static int RenderingThreadA_Entry(void* data);
    static int RenderingThreadB_Entry(void* data);

    void RenderingThreadA();
    void RenderingThreadB();

    bool mRun;

    Window* mWindow0;
    Window* mWindow1;

    SDL_GLContext mGLContext0;
    SDL_GLContext mGLContext1;
};
//-----------------------------------------------------------------------------
MultiWindow::~MultiWindow() {
    SDL_GL_DeleteContext(mGLContext0);
    SDL_GL_DeleteContext(mGLContext1);

    delete mWindow0;
    delete mWindow1;
}
//-----------------------------------------------------------------------------
void MultiWindow::Run() {
    Init();
    while (mRun) {
        ProcessEvents();
    }
}
//-----------------------------------------------------------------------------
void MultiWindow::Init() {
    // create windows
    mWindow0 = new Window("MultiWindow 0", 600, 600);
    mWindow1 = new Window("MultiWindow 1", 600, 600);
    
    SDL_GLContext tempContext = SDL_GL_CreateContext(mWindow0->Get());
    if (!tempContext) {
        throw runtime_error("failed to create tempContext");
    }

    gl::LoadCommandPointers(30);

    SDL_GL_DeleteContext(tempContext);

    mRun = true;

    SDL_CreateThread(RenderingThreadA_Entry, this);
    SDL_CreateThread(RenderingThreadB_Entry, this);
}
//-----------------------------------------------------------------------------
bool MultiWindow::ProcessEvents() {
    SDL_Event evt;
    while (SDL_WaitEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            return mRun = false;
        }

        ProcessCommonEvent(evt);
    }

    return true;
}
//-----------------------------------------------------------------------------
void MultiWindow::RenderingThreadA() {
    // create OpenGL context
    if (!(mGLContext0 = SDL_GL_CreateContext(mWindow0->Get()))) {
        throw runtime_error("failed to create mGLContext0");
    }
    SDL_GL_SetSwapInterval(0);

    // create Vertex Buffer Object (VBO)
    const float data[] = { -1, -1, 1, 0, 0,  1, -1, 0, 1, 0,  0, 1, 0, 0, 1 };
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // create Vertex Array Object (VAO)
    const GLsizei stride = sizeof(glm::vec2) + sizeof(glm::vec3);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void*>(sizeof(glm::vec2)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // create GLSL Program
    GLuint program = gl::BuildProgram(Vsh(), Fsh(), false);
    glBindAttribLocation(program, 0, "Position");
    glBindAttribLocation(program, 1, "ColorIn");
    gl::LinkProgram(program);

    while (mRun) {
        static float rot;
        rot = SDL_GetTicks() * 0.001f;

        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glUniformMatrix4fv(glGetUniformLocation(program, "Rotation"), 1, GL_FALSE,
            glm::value_ptr(glm::rotate(glm::degrees(rot), 0.0f, 0.0f, 1.0f)));
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        mWindow0->Swap();
    }
}
//-----------------------------------------------------------------------------
void MultiWindow::RenderingThreadB() {
    // create OpenGL context
    if (!(mGLContext1 = SDL_GL_CreateContext(mWindow1->Get()))) {
        throw runtime_error("failed to create mGLContext1");
    }
    SDL_GL_SetSwapInterval(0);

    // create Vertex Buffer Object (VBO)
    const float data[] = { -1, -1, 1, 0, 0,  1, -1, 0, 1, 0,  0, 1, 0, 0, 1 };
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // create Vertex Array Object (VAO)
    const GLsizei stride = sizeof(glm::vec2) + sizeof(glm::vec3);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void*>(sizeof(glm::vec2)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // create GLSL Program
    GLuint program = gl::BuildProgram(Vsh(), Fsh(), false);
    glBindAttribLocation(program, 0, "Position");
    glBindAttribLocation(program, 1, "ColorIn");
    gl::LinkProgram(program);

    while (mRun) {
        static float rot;
        rot = SDL_GetTicks() * 0.001f;

        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glUniformMatrix4fv(glGetUniformLocation(program, "Rotation"), 1, GL_FALSE,
            glm::value_ptr(glm::rotate(glm::degrees(-rot), 0.0f, 0.0f, 1.0f)));
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        mWindow1->Swap();
    }
}
//-----------------------------------------------------------------------------
int MultiWindow::RenderingThreadA_Entry(void* data) {
    try {
        static_cast<MultiWindow*>(data)->RenderingThreadA();
    }
    catch (const exception& ex) {
        DisplayErrorMessage("RenderingThreadA_Entry", ex.what());
    }
    catch (...) {
        DisplayErrorMessage("RenderingThreadA_Entry", "undefined exception");
    }

    return 0;
}
//-----------------------------------------------------------------------------
int MultiWindow::RenderingThreadB_Entry(void* data) {
    try {
        static_cast<MultiWindow*>(data)->RenderingThreadB();
    }
    catch (const exception& ex) {
        DisplayErrorMessage("RenderingThreadB_Entry", ex.what());
    }
    catch (...) {
        DisplayErrorMessage("RenderingThreadB_Entry", "undefined exception");
    }

    return 0;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
        DisplayErrorMessage("main", "SDL_Init failed");
        return 0;
    }

    try {
        MultiWindow multiWindow;
        multiWindow.Run();
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