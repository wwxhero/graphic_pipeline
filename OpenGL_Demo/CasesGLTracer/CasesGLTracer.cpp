// CasesGLTracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

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

    GLuint mVAO;
    GLuint mVBO;
    GLuint mProgram;
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
    const int w = 800, h = 600;
    mWindow = new GLWindow("Monkey", w, h);

    // create OpenGL context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    // create GLSL Program
    const GLuint c_idxPos = 0;
    const GLuint c_idxClr = 1;
    mProgram = gl::BuildProgram(Vsh(), Fsh(), false);
    glBindAttribLocation(mProgram, c_idxPos, "Position");
    glBindAttribLocation(mProgram, c_idxClr, "ColorIn");
    gl::LinkProgram(mProgram);

    // create Vertex Buffer Object (VBO)
    //                      x,  y, r, g, b
    const float data[] = { -1, -1, 1, 0, 0
                        ,   1, -1, 0, 1, 0
                        ,   0,  1, 0, 0, 1 };

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // create Vertex Array Object (VAO)
    const GLsizei stride = 5 * sizeof(float);

    glVertexAttribPointer(c_idxPos, 2, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(c_idxPos);

    glVertexAttribPointer(c_idxClr, 3, GL_FLOAT, GL_FALSE, stride, (void*)(2*sizeof(float)));
    glEnableVertexAttribArray(c_idxClr);

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
#define TRACE_TEST
#ifndef TRACE_TEST
void Triangle::Update() {
    glClear(GL_COLOR_BUFFER_BIT);
	//case for common return
    auto isProgram = glIsProgram(mProgram);
    if (isProgram)
    	glUseProgram(mProgram);
    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
	//case for if statement
	if (glIsProgram(mProgram))
	{
		glUseProgram(mProgram);
	}
	// case for else if statement
	else if (glIsProgram(mProgram))
	{
		glUseProgram(mProgram);
	}

	GLboolean is = GL_FALSE;
	//boom: it allows extreamly complicated statement inside of the parenthesis, not able to easily recode it in c/c++ MACRO
	if (is = glIsProgram(mProgram))
	{
		glUseProgram(mProgram);
	}

	//case for while loop statement
	while (glIsProgram(mProgram))
	{
		glUseProgram(mProgram);
	}



    mWindow->Swap();
}
#else
void Triangle::Update() {
	GLTRACE_VOID_1(glClear, GL_COLOR_BUFFER_BIT);
	//case for common return
	auto isProgram = GLTRACE_RET_1(glIsProgram, mProgram);
	if (isProgram)
    	GLTRACE_VOID_1(glUseProgram, mProgram);
    GLTRACE_VOID_1(glBindVertexArray, mVAO);
    GLTRACE_VOID_3(glDrawArrays, GL_TRIANGLES, 0, 3);
    //case for if statement
	if (GLTRACE_RET_1(glIsProgram, mProgram))
	{
		glUseProgram(mProgram);
	}
	// case for else if statement
	else if (GLTRACE_RET_1(glIsProgram, mProgram))
	{
		glUseProgram(mProgram);
	}

	GLboolean is = GL_FALSE;
	//boom: it allows extreamly complicated statement inside of the parenthesis, not able to easily recode it in c/c++ MACRO
	if (is = GLTRACE_RET_1(glIsProgram, mProgram))
	{
		glUseProgram(mProgram);
	}

	//case for while loop statement
	/*while (GLTRACE_RET_1(glIsProgram, mProgram))
	{
		glUseProgram(mProgram);
	}*/

    mWindow->Swap();
}
#endif
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
