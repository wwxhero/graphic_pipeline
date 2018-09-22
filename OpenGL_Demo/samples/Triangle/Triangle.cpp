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
        N  "in vec3 ColorIn;"
        N  "out vec3 Color;"
        N  "void main() {"
        N  "    gl_Position = Position;"
        N  "    Color = ColorIn;"
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
// Triangle
//-----------------------------------------------------------------------------
class Triangle {
public:
    Triangle() : mWindow(NULL), mGLContext(NULL), mVAO(0), mVBO(0), mProgram(0) {}
    ~Triangle();

    void Run();
    
private:
    void Init();
    bool ProcessEvents();
    void Update();

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    GLuint mVAO, mVBO, mProgram;
};
//-----------------------------------------------------------------------------
Triangle::~Triangle() {
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteProgram(mProgram);
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void Triangle::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void Triangle::Init() {
    // create window
    mWindow = new GLWindow("Triangle", 800, 600);
    
    // create OpenGL context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    // create Vertex Buffer Object (VBO)
    const float data[] = { -1, -1, 1, 0, 0,  1, -1, 0, 1, 0,  0, 1, 0, 0, 1 };
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // create Vertex Array Object (VAO)
    const GLsizei stride = sizeof(glm::vec2) + sizeof(glm::vec3);
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void*>(sizeof(glm::vec2)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // create GLSL Program
    mProgram = gl::BuildProgram(Vsh(), Fsh(), false);
    glBindAttribLocation(mProgram, 0, "Position");
    glBindAttribLocation(mProgram, 1, "ColorIn");
    gl::LinkProgram(mProgram);
}
//-----------------------------------------------------------------------------
bool Triangle::ProcessEvents() {
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            return false;
        }

        ProcessCommonEvent(evt);
    }

    return true;
}
//-----------------------------------------------------------------------------
void Triangle::Update() {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(mProgram);
    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

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
        Triangle triangle;
        triangle.Run();
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