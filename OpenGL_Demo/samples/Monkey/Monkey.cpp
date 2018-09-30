// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

#include "Common.hpp"
#include <stdexcept>
#include <vector>
using namespace std;

//-----------------------------------------------------------------------------
// MeshLoader
//-----------------------------------------------------------------------------
class MeshLoader {
public:
    MeshLoader(const char* filename) {
        Load(filename);
    }
    void Load(const char* filename) {
        FILE* fp = fopen(filename, "r");
        try {
            if (!fp) {
                throw runtime_error(string("failed to load ") + filename);
            }

            char command[256];
            int vertexCount = -1, faceCount = -1;

            while (true) {
                fscanf(fp, "%s", &command[0]);

                if (feof(fp) || strcmp(command, "end_header") == 0) {
                    break;
                }
                else if (strcmp(command, "element") == 0) {
                    fscanf(fp, "%s", &command[0]);
                    if (strcmp(command, "vertex") == 0) {
                        fscanf(fp, "%d", &vertexCount);
                    }
                    else if (strcmp(command, "face") == 0) {
                        fscanf(fp, "%d", &faceCount);
                    }
                }

                fgets(&command[0], sizeof(command), fp);
            }

            if (vertexCount < 0 || faceCount < 0) {
                throw runtime_error(string("failed to load ") + filename);
            }

            mVertexData.resize(vertexCount * 2);
            for (int i = 0; i < vertexCount; ++i) {
                glm::vec3 v;
                fscanf(fp, "%f %f %f", &v.x, &v.z, &v.y);
                v.z = -v.z;
                mVertexData[i * 2] = v;

                fscanf(fp, "%f %f %f", &v.x, &v.z, &v.y);
                v.z = -v.z;
                mVertexData[i * 2 + 1] = v;
            }

            int c;
            mIndexData.resize(faceCount * 3);

            for (int i = 0; i < faceCount; ++i) {
                const int idx = i * 3;
                fscanf(fp, "%d %d %d %d", &c, &mIndexData[idx], &mIndexData[idx + 1], &mIndexData[idx + 2]);
            }
        }
        catch (...) {
            if (fp) {
                fclose(fp);
            }
            throw;
        }

        fclose(fp);
    }

    GLsizei VertexSize() const { return static_cast<GLsizei>(sizeof(glm::vec3) * 2); }
    GLsizei VertexCount() const { return static_cast<GLsizei>(mVertexData.size() / 2); }
    GLsizei IndexCount() const { return static_cast<GLsizei>(mIndexData.size()); }

    const glm::vec3* VertexData() const { return &mVertexData[0]; }
    const glm::uint* IndexData() const { return &mIndexData[0]; }

private:
    vector<glm::vec3> mVertexData;
    vector<glm::uint> mIndexData;
};
//-----------------------------------------------------------------------------
#define N "\n"
namespace {
const char* VshPhong() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform mat4 MVPMatrix;"
        N  "uniform mat4 WorldMatrix;"
        N  "in vec4 Position;"
        N  "in vec3 Normal;"
        N  "out vec3 WorldPos;"
        N  "out vec3 WorldNormal;"
        N  "void main() {"
        N  "    gl_Position = MVPMatrix * Position;"
        N  "    WorldPos = vec3(WorldMatrix * Position);"
        N  "    WorldNormal = mat3(WorldMatrix) * Normal;"
        N  "}";
}
const char* FshPhong() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec3 EyePos = vec3(2, 2, 2);"
        N  "uniform vec3 SurfaceDiffuse;"
        N  "uniform vec3 SurfaceSpecular;"
        N  "uniform float SurfaceSmooth;"
        N  "uniform vec3 LightPos[2] = vec3[2](vec3(10, 10, 12), vec3(-4, 5, 7));"
        N  "uniform vec3 LightIntensity[2] = vec3[2](vec3(2, 2, 2), vec3(1.6f, 1.6f, 0.6f));"
        N  "in vec3 WorldPos;"
        N  "in vec3 WorldNormal;"
        N  "out vec4 Color;"
        N  "vec3 Shade(vec3 p, vec3 n) {"
        N  "    vec3 eyeVec = normalize(EyePos - p);"
        N  "    vec3 lightVec = normalize(LightPos[0] - p);"
        N  "    vec3 halfVec = 0.5 * (eyeVec + lightVec);"
        N  "    float cosTh = clamp(dot(n, halfVec), 0, 1);"
        N  "    float cosTi = clamp(dot(n, lightVec), 0, 1);"
        N  "    vec3 Lo = (SurfaceDiffuse + SurfaceSpecular * pow(cosTh, SurfaceSmooth)) * LightIntensity[0] * cosTi;"
        N  "    lightVec = normalize(LightPos[1] - p);"
        N  "    halfVec = 0.5 * (eyeVec + lightVec);"
        N  "    cosTh = clamp(dot(n, halfVec), 0, 1);"
        N  "    cosTi = clamp(dot(n, lightVec), 0, 1);"
        N  "    Lo += (SurfaceDiffuse + SurfaceSpecular * pow(cosTh, SurfaceSmooth)) * LightIntensity[1] * cosTi;"
        N  "    return Lo;"
        N  "}"
        N  "void main() {"
        N  "    vec3 nw = normalize(WorldNormal);"
        N  "    Color.rgb = Shade(WorldPos, nw);"
        N  "    Color.a = 1;"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// Monkey
//-----------------------------------------------------------------------------
class Monkey {
public:
    Monkey() : mWindow(NULL), mGLContext(NULL), mVAO(0), mVBO(0), mEBO(0), mProgram(0) {}
    ~Monkey();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    GLuint mVAO;
    GLuint mVBO, mEBO;
    GLsizei mIndexCount;
    GLuint mProgram;

    glm::vec3 mDiffuseColor, mSpecularColor;
    float mSmoothness;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
Monkey::~Monkey() {
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteBuffers(1, &mEBO);
    glDeleteProgram(mProgram);
    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void Monkey::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void Monkey::Init() {
    // window
    const int w = 800, h = 600;
    mWindow = new GLWindow("Monkey", w, h);

    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    mProgram = gl::BuildProgram(VshPhong(), FshPhong(), false);
    glBindAttribLocation(mProgram, 0, "Position");
    glBindAttribLocation(mProgram, 1, "Normal");
    gl::LinkProgram(mProgram);

	mDiffuseColor = glm::vec3(0.9f, 0.5f, 1);
    mSpecularColor = glm::vec3(0.3f, 0.3f, 0.3f);
    mSmoothness = 256.0f;

    // create mesh
    MeshLoader mloader("../../media/monkey.ply");

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mloader.VertexSize() * mloader.VertexCount(), mloader.VertexData(), GL_STATIC_DRAW);

    const int stride = sizeof(glm::vec3) * 2;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void*>(sizeof(glm::vec3)));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &mEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mloader.IndexCount() * sizeof(glm::uint), mloader.IndexData(), GL_STATIC_DRAW);
    mIndexCount = mloader.IndexCount();

    glEnable(GL_DEPTH_TEST);

    int bInitialized = TwInit(TW_OPENGL, NULL);
    TwWindowSize(w, h);
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='200 150'");
    TwDefine("Menu fontresizable=false resizable=false");

    TwAddVarRW(bar, "diffuse_color", TW_TYPE_COLOR3F, &mDiffuseColor, "label='Diffuse Color' open");
    TwAddVarRW(bar, "specular_color", TW_TYPE_COLOR3F, &mSpecularColor, "label='Specular Color'");
    TwAddVarRW(bar, "smoothness", TW_TYPE_FLOAT, &mSmoothness, "label='Smoothness' step=1 min=8 max=256");

    mLastTime = SDL_GetTicks();
}
//-----------------------------------------------------------------------------
bool Monkey::ProcessEvents() {
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
void Monkey::Update() {
    const Uint32 now = SDL_GetTicks();
    const float dt = (now - mLastTime) * 0.001f;
    mLastTime = now;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const glm::mat4 projView = glm::perspective(60.0f, 1.333f, 0.1f, 20.0f) *
        glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    static float rotY;
    const glm::mat4 world = glm::rotate(glm::degrees(rotY += dt), 0.0f, 1.0f, 0.0f);
    const glm::mat4 projViewWorld = projView * world;

    glUseProgram(mProgram);
    glUniformMatrix4fv(glGetUniformLocation(mProgram,"MVPMatrix"), 1, GL_FALSE, glm::value_ptr(projViewWorld));
    glUniformMatrix4fv(glGetUniformLocation(mProgram, "WorldMatrix"), 1, GL_FALSE, glm::value_ptr(world));

    const float PI = 3.1415926f;
    const float PI_INV = 1.0f / PI;
    glUniform3fv(glGetUniformLocation(mProgram, "SurfaceDiffuse"), 1, glm::value_ptr(mDiffuseColor * PI_INV));
    glUniform3fv(glGetUniformLocation(mProgram, "SurfaceSpecular"), 1, glm::value_ptr(((mSmoothness + 8) / (8 * PI)) * mSpecularColor));
    glUniform1f(glGetUniformLocation(mProgram, "SurfaceSmooth"), mSmoothness);

    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, 0);

    // draw GUI
    glUseProgram(0);
    glBindVertexArray(0);
#ifdef WIN32
    TwDraw();
#endif

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
        Monkey monkey;
        monkey.Run();
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
