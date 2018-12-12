// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

#include "Common.hpp"
#include <stdexcept>
#include <vector>
#include <cstdio>
#include "libGLTracer.h"
using namespace std;

//-----------------------------------------------------------------------------
#define N "\n"
namespace {
const char* Vsh() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform mat4 ProjViewWorldMatrix;"
        N  "uniform mat4 WorldMatrix;"
        N  "uniform mat4 ShadowMatrix;"
        N  "in vec4 Position;"
        N  "in vec3 Normal;"
        N  "out vec3 WorldNormal;"
        N  "out vec4 ShadowCoord;"
        N  "void main() {"
        N  "    gl_Position = ProjViewWorldMatrix * Position;"
        N  "    WorldNormal = mat3x3(WorldMatrix) * Normal;"
        N  "    ShadowCoord = ShadowMatrix * WorldMatrix * Position;"
        N  "}";
}
const char* Fsh() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform sampler2DShadow ShadowMap;"
        N  "uniform vec3 LightDir = vec3(1, 1, 1);"
        N  "uniform vec3 LightIntensity = vec3(2, 2, 2);"
        N  "uniform vec3 SurfaceDiffuse;"
        N  "in vec3 WorldNormal;"
        N  "in vec4 ShadowCoord;"
        N  "out vec4 Color;"
        N  "void main() {"
        N  "    vec3 normalVec = normalize(WorldNormal);"
        N  "    vec3 lightVec = normalize(LightDir);"
        N  "    float cosTi = max(0, dot(normalVec, lightVec));"
        N  "    float shadeFactor = textureProj(ShadowMap, ShadowCoord);"
        N  "    shadeFactor = 0.7 * shadeFactor + 0.3;"
        N  "    Color = vec4(SurfaceDiffuse * LightIntensity * cosTi * shadeFactor, 1);"
        N  "}";
}
const char* VshShadow() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform mat4 ProjViewWorldMatrix;"
        N  "in vec4 Position;"
        N  "void main() {"
        N  "    gl_Position = ProjViewWorldMatrix * Position;"
        N  "}";
}
const char* FshShadow() {
    return OGL_SHADER_BEGIN(130)
        N  "void main() {"
        N  "    gl_FragDepth = gl_FragCoord.z;"
        N  "}";
}
} // namespace
#undef N
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
// Mesh
//-----------------------------------------------------------------------------
class Mesh {
public:
    Mesh(const char* filename);
    ~Mesh();

    void Bind() const;
    void Draw() const;

private:
    GLuint mVAO;
    GLuint mVBO, mEBO;
    int mIndexCount;
};
//-----------------------------------------------------------------------------
Mesh::Mesh(const char* filename) {
    MeshLoader meshLoader(filename);

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, meshLoader.VertexSize() * meshLoader.VertexCount(), meshLoader.VertexData(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, meshLoader.VertexSize(), 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, meshLoader.VertexSize(), reinterpret_cast<void*>(sizeof(glm::vec3)));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &mEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshLoader.IndexCount() * sizeof(glm::uint), meshLoader.IndexData(), GL_STATIC_DRAW);

    mIndexCount = meshLoader.IndexCount();
}
//-----------------------------------------------------------------------------
Mesh::~Mesh() {
    glDeleteBuffers(1, &mEBO);
    glDeleteBuffers(1, &mVBO);
    glDeleteVertexArrays(1, &mVAO);
}
//-----------------------------------------------------------------------------
void Mesh::Bind() const {
    glBindVertexArray(mVAO);
}
//-----------------------------------------------------------------------------
void Mesh::Draw() const {
    glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, NULL);
}
//-----------------------------------------------------------------------------
// Object
//-----------------------------------------------------------------------------
struct Object {
    Mesh* mesh;
    glm::vec3 diffuseColor;
    glm::mat4 worldMatrix;
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
glm::vec3 ComputeDirection(float rotX, float rotY) {
    const glm::vec3 rotDir = glm::mat3(glm::rotate(glm::degrees(rotY), 0.0f, 1.0f, 0.0f)) * glm::vec3(0.0f, 0.0f, -1.0f);
    const glm::vec3 rotXAxis = -glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), rotDir);
    return glm::mat3(glm::rotate(glm::degrees(rotX), rotXAxis)) * rotDir;
}
//-----------------------------------------------------------------------------
// ShadowMapping
//-----------------------------------------------------------------------------
class ShadowMapping {
public:
    ShadowMapping() : mWindow(NULL), mGLContext(NULL), mProgram(0), mShadowProgram(0),
        mMonkeyMesh(NULL), mGroundMesh(NULL), mShadowMap(0), mShadowFBO(0) {}
    ~ShadowMapping();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    void PutLight();
    static void TW_CALL PutLightCB(void* demoPtr);

    void DrawObjects(const glm::mat4& projView, bool shadowPass);
    void UpdateCamera(float dt);

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    vector<Object> mObjectList;

    GLuint mProgram;
    GLuint mShadowProgram;

    Mesh* mMonkeyMesh;
    Mesh* mGroundMesh;

    // shadow render target
    GLuint mShadowMap;
    GLuint mShadowFBO;

    glm::vec3 mLightDir;
    glm::vec3 mCameraPos;
    float mCameraRotX, mCameraRotY;

    Uint32 mLastTime;
    int mWinWidth, mWinHeight;
};
//-----------------------------------------------------------------------------
ShadowMapping::~ShadowMapping() {
    delete mMonkeyMesh;
    delete mGroundMesh;
    glDeleteTextures(1, &mShadowMap);
    glDeleteFramebuffers(1, &mShadowFBO);
    glDeleteProgram(mProgram);
    glDeleteProgram(mShadowProgram);
    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void ShadowMapping::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void ShadowMapping::Init() {
    // window
    mWinWidth = 800, mWinHeight = 800;
    mWindow = new GLWindow("Shadow Mapping", mWinWidth, mWinHeight);

    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.3 functions
    gl::LoadCommandPointers(33);

    TwInit(TW_OPENGL, NULL);
    TwWindowSize(mWinWidth, mWinHeight);
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='240 120'");
    TwDefine("Menu fontresizable=false resizable=false movable=false");
    TwAddButton(bar, "PutLight", PutLightCB, this, "label='Align Light To Camera'");
    TwAddSeparator(bar, NULL, NULL);
    TwAddButton(bar, "usage", NULL, NULL, "label='Usage:'");
    TwAddButton(bar, "help0", NULL, NULL, "label='  - [ W ][ A ][ S ][ D ] to move'");
    TwAddButton(bar, "help1", NULL, NULL, "label='  - mouse with LB down to rotate'");

    // create program
    mProgram = gl::BuildProgram(Vsh(), Fsh(), false);
    glBindAttribLocation(mProgram, 0, "Position");
    glBindAttribLocation(mProgram, 1, "Normal");
    gl::LinkProgram(mProgram);

    // create shadow program
    mShadowProgram = gl::BuildProgram(VshShadow(), FshShadow());

    // create scene
    mMonkeyMesh = new Mesh("../../media/monkey.ply");
    mGroundMesh = new Mesh("../../media/ground.ply");

    Object obj;
    obj.mesh = mMonkeyMesh;
    obj.diffuseColor = glm::vec3(0.9f, 0.5f, 1);
    obj.worldMatrix = glm::translate(-1.5f, 1.5f, 0.1f);
    mObjectList.push_back(obj);

    obj.mesh = mMonkeyMesh;
    obj.diffuseColor = glm::vec3(0.2f, 0.9f, 0.1f);
    obj.worldMatrix = glm::translate(1.5f, 1.0f, 0.0f);
    mObjectList.push_back(obj);

    obj.mesh = mGroundMesh;
    obj.diffuseColor = glm::vec3(0.2f, 0.3f, 0.9f);
    obj.worldMatrix = glm::mat4();
    mObjectList.push_back(obj);

    // set GL state
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glPolygonOffset(1.1f, 4.0f);

    mCameraPos = glm::vec3(0.0f, 1.0f, 7.0f);
    mCameraRotX = mCameraRotY = 0;

    GLint ptrLightDir = glGetUniformLocation(mProgram, "LightDir");
    glGetUniformfv(mProgram, ptrLightDir, glm::value_ptr(mLightDir));

    // create shadow map
    glGenTextures(1, &mShadowMap);
    glBindTexture(GL_TEXTURE_2D, mShadowMap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);

    // create shadow fbo
    glGenFramebuffers(1, &mShadowFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, mShadowFBO);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, mShadowMap, 0);
}
//-----------------------------------------------------------------------------
bool ShadowMapping::ProcessEvents() {
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
void ShadowMapping::Update() {
    const Uint32 now = SDL_GetTicks();
    const float dt = (now - mLastTime) * 0.001f;
    mLastTime = now;

    UpdateCamera(dt);

    mObjectList[0].worldMatrix *= glm::rotate(glm::degrees(dt), 1.0f, 0.0f, 0.0f);
    mObjectList[1].worldMatrix *= glm::rotate(glm::degrees(dt * 1.3f), 0.0f, 1.0f, 0.0f);

    // shadow pass (draw scene from light point of view)
    glm::mat4 lightProjView =
        glm::perspective(70.0f, 1.0f, 5.0f, 100.0f) *
        glm::lookAt(10.0f * glm::normalize(mLightDir), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    glEnable(GL_POLYGON_OFFSET_FILL);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, mShadowFBO);
    glViewport(0, 0, 1024, 1024);
    glClear(GL_DEPTH_BUFFER_BIT);
    DrawObjects(lightProjView, true);

    // update uniforms
    glUseProgram(mProgram);
    glm::mat4 shadowMatrix =
        glm::translate(0.5f, 0.5f, 0.5f) * glm::scale(glm::vec3(0.5f)) * lightProjView;
    GLint ptrShadowMatrix = glGetUniformLocation(mProgram, "ShadowMatrix");
    if (-1 != ptrShadowMatrix)
        glUniformMatrix4fv(ptrShadowMatrix, 1, GL_FALSE, &shadowMatrix[0][0]);

    // normal pass (draw scene from camera point of view)
    const glm::mat4 projView =
        glm::perspective(45.0f, 1.0f, 1.0f, 100.0f) *
        glm::lookAt(mCameraPos, mCameraPos + ComputeDirection(mCameraRotX, mCameraRotY), glm::vec3(0.0f, 1.0f, 0.0f));

    glDisable(GL_POLYGON_OFFSET_FILL);
    glBindTexture(GL_TEXTURE_2D, mShadowMap);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, mWinWidth, mWinHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawObjects(projView, false);

    // draw GUI
    glUseProgram(0);
    glBindVertexArray(0);
    TwDraw();

    mWindow->Swap();
}
//-----------------------------------------------------------------------------
void ShadowMapping::DrawObjects(const glm::mat4& projView, bool shadowPass) {
    for (vector<Object>::const_iterator i = mObjectList.begin(); i != mObjectList.end(); ++i) {
        const Object& obj = *i;

        if (shadowPass) {
            glUseProgram(mShadowProgram);
            const glm::mat4 pvw = projView * obj.worldMatrix;
            GLint ptrProjViewworldMatrix = glGetUniformLocation(mShadowProgram, "ProjViewWorldMatrix");
            glUniformMatrix4fv(ptrProjViewworldMatrix, 1, GL_FALSE, &pvw[0][0]);
        }
        else {
            glUseProgram(mProgram);
            const glm::mat4 pvw = projView * obj.worldMatrix;
            GLint ptrProjViewworldMatrix = glGetUniformLocation(mProgram, "ProjViewWorldMatrix");
			GLint ptrWorldMatrix = glGetUniformLocation(mProgram, "WorldMatrix");
			GLint ptrSurfaceDiffuse = glGetUniformLocation(mProgram, "SurfaceDiffuse");
            glUniformMatrix4fv(ptrProjViewworldMatrix, 1, GL_FALSE, &pvw[0][0]);
            glUniformMatrix4fv(ptrWorldMatrix, 1, GL_FALSE, &obj.worldMatrix[0][0]);
            glUniform3fv(ptrSurfaceDiffuse, 1, glm::value_ptr(obj.diffuseColor * 1.0f / 3.1415926f));
        }

        obj.mesh->Bind();
        obj.mesh->Draw();
    }
}
//-----------------------------------------------------------------------------
void ShadowMapping::UpdateCamera(float dt) {
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
void ShadowMapping::PutLight() {
    glUseProgram(mProgram);
    mLightDir = mCameraPos;
	GLint ptrLightDir = glGetUniformLocation(mProgram, "LightDir");
    glUniform3fv(ptrLightDir, 1, glm::value_ptr(mLightDir));
}
//-----------------------------------------------------------------------------
void ShadowMapping::PutLightCB(void* demoPtr) {
    static_cast<ShadowMapping*>(demoPtr)->PutLight();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
        DisplayErrorMessage("main", "SDL_Init failed");
        return 0;
    }

    try {
        ShadowMapping shadowMapping;
        shadowMapping.Run();
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