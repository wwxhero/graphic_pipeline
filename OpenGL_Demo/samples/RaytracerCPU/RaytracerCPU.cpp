// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License
#define TW_STATIC
#include "Common.hpp"
#include <stdexcept>
#include <limits>
#include <vector>
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
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N  "uniform sampler2D Tex;"
        N  "out vec4 Color;"
        N  "void main() {"
        N  "    Color = texture(Tex, gl_FragCoord.xy / Resolution.xy);"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
class Ray {
public:
    Ray(const glm::vec3& o, const glm::vec3& d) : o(o), d(d) {}
    glm::vec3 o, d;
};

class Primitive {
public:
    Primitive() : mDiffuse(0.2f), mColor(0.2f), mReflection(0) {}
    virtual ~Primitive() {}

    virtual bool Intersect(const Ray& ray, float& distance) const = 0;
    virtual glm::vec3 GetNormal(const glm::vec3& p) const = 0;

    float GetDiffuse() const { return mDiffuse; }
    void SetDiffuse(float d) { mDiffuse = d; }
    float GetReflection() const { return mReflection; }
    void SetReflection(float r) { mReflection = r; }
    glm::vec3 GetColor() const { return mColor; }
    void SetColor(const glm::vec3& c) { mColor = c; }

protected:
    float mDiffuse, mReflection;
    glm::vec3 mColor;
};

class Sphere : public Primitive {
public:
    Sphere(const glm::vec3& c, float r) : mCentre(c), mSqRadius(r * r), mRadius(r), mRRadius(1.0f / r) {}
    virtual bool Intersect(const Ray& ray, float& distance) const;
    virtual glm::vec3 GetNormal(const glm::vec3& p) const { return (p - mCentre) * mRRadius; }

private:
    glm::vec3 mCentre;
    float mSqRadius, mRadius, mRRadius;
};

class Plane : public Primitive {
public:
    Plane(const glm::vec3& n, float d) : mNormal(n), mDistance(d) {}
    virtual bool Intersect(const Ray& ray, float& distance) const;
    virtual glm::vec3 GetNormal(const glm::vec3& p) const { return mNormal; }

private:
    glm::vec3 mNormal;
    float mDistance;
};

class Light {
public:
    Light(const glm::vec3& p, const glm::vec3& c) : mPosition(p), mColor(c) {}

    glm::vec3 GetPosition() const { return mPosition; }
    glm::vec3 GetColor() const { return mColor; }

private:
    glm::vec3 mPosition;
    glm::vec3 mColor;
};
//-----------------------------------------------------------------------------
// Sphere
//-----------------------------------------------------------------------------
bool Sphere::Intersect(const Ray& ray, float& distance) const {
    const glm::vec3 l = mCentre - ray.o;
    const float s = glm::dot(l, ray.d);
    const float l2 = glm::dot(l, l);

    if (s < 0 && l2 > mSqRadius) {
        return false;
    }

    const float m2 = l2 - s * s;
    if (m2 > mSqRadius) {
        return false;
    }

    const float q = sqrt(mSqRadius - m2);
    distance = (l2 > mSqRadius) ? (s - q) : (s + q);

    return true;
}
//-----------------------------------------------------------------------------
// Plane
//-----------------------------------------------------------------------------
bool Plane::Intersect(const Ray& ray, float& distance) const {
	float d = glm::dot(mNormal, ray.d);
	if (d != 0) {
		distance = -(glm::dot(mNormal, ray.o) + mDistance) / d;

		if (distance > 0) {
			return true;
        }
	}

	return false;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
glm::vec3 ComputeDirection(float rotX, float rotY) {
    const glm::vec3 rotDir = glm::mat3(glm::rotate(glm::degrees(rotY), 0.0f, 1.0f, 0.0f)) * glm::vec3(0.0f, 0.0f, -1.0f);
    const glm::vec3 rotXAxis = -glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), rotDir);
    return glm::mat3(glm::rotate(glm::degrees(rotX), rotXAxis)) * rotDir;
}
//-----------------------------------------------------------------------------
// RaytracerCPU
//-----------------------------------------------------------------------------
class RaytracerCPU {
public:
    RaytracerCPU() :
        mWindow(NULL), mGLContext(NULL),
        mProgram(0), mVAO(0), mVBO(0), mScreenTexture(0), mScreenBuffer(0) {}
    ~RaytracerCPU();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    void Raytrace(const glm::mat4& view);
    glm::vec3 Trace(const Ray& ray);
    glm::vec3 Shade(const Ray& ray, const Primitive& prim, const glm::vec3& p, const glm::vec3& n);
    Primitive* IntersectAll(const Ray& ray, float& distance);

    void UpdateCamera(float dt);

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    vector<glm::vec3> mFramebuffer;

    GLuint mProgram;
    GLuint mVAO, mVBO;
    GLuint mScreenTexture;
    GLuint mScreenBuffer;

    int mFrameCounter;
    int mCurrentLine;

    vector<Primitive*> mPrimitive;
    vector<Light*> mLight;

    glm::vec3 mCameraPos;
    float mCameraRotX, mCameraRotY;

    Uint32 mLastTime;
};
//-----------------------------------------------------------------------------
RaytracerCPU::~RaytracerCPU() {
    for (size_t i = 0; i < mPrimitive.size(); ++i) {
        delete mPrimitive[i];
    }
    for (size_t i = 0; i < mLight.size(); ++i) {
        delete mLight[i];
    }

    glDeleteBuffers(1, &mScreenBuffer);
    glDeleteTextures(1, &mScreenTexture);
    glDeleteBuffers(1, &mVBO);
    glDeleteVertexArrays(1, &mVAO);
    glDeleteProgram(mProgram);
    glUseProgram(0);

    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void RaytracerCPU::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void RaytracerCPU::Init() {
    // window
    mWindow = new GLWindow("Simple CPU Raytracer", 800, 600);

    // context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    mFramebuffer.resize(mWindow->Width() * mWindow->Height());
    mCurrentLine = 0;
    mFrameCounter = 0;

    // texture
    glGenTextures(1, &mScreenTexture);
    glBindTexture(GL_TEXTURE_2D, mScreenTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, mWindow->Width(), mWindow->Height(), 0, GL_RGB, GL_FLOAT, NULL);

    glGenBuffers(1, &mScreenBuffer);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, mScreenBuffer);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, mWindow->Width() * mWindow->Height() * sizeof(glm::vec3), NULL, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    // program
    mProgram = gl::BuildProgram(Vsh(), Fsh());

    // vbo
    const float data[] = { -1, 1, -1, -1, 1, 1, 1, -1 };
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // vao
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    Primitive* p = new Sphere(glm::vec3(1, -0.8f, -3), 2.5f);
    p->SetColor(glm::vec3(0.7f, 0.7f, 0.0f));
    p->SetReflection(0.6f);
    p->SetDiffuse(0.75f);
	mPrimitive.push_back(p);

    p = new Plane(glm::vec3(0, 1, 0), 4.4f);
    p->SetColor(glm::vec3(0.4f, 0.3f, 0.3f));
    p->SetDiffuse(1);
	mPrimitive.push_back(p);

    p = new Sphere(glm::vec3(-5.5f, -0.5, -7), 2);
    p->SetColor(glm::vec3(0.7f, 0.0f, 0.1f));
    p->SetDiffuse(0.7f);
    p->SetReflection(1);
	mPrimitive.push_back(p);


    mLight.push_back(new Light(glm::vec3(0, 5, -5), glm::vec3(0.6f)));
    mLight.push_back(new Light(glm::vec3(2, 5, -1), glm::vec3(0.7f, 0.7f, 0.9f)));
    mLight.push_back(new Light(glm::vec3(0, 15, 0), glm::vec3(0.8)));

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
bool RaytracerCPU::ProcessEvents() {
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
void RaytracerCPU::Update() {
    const Uint32 now = SDL_GetTicks();
    const float dt = (now - mLastTime) * 0.001f;
    mLastTime = now;

    UpdateCamera(dt);

    const glm::mat4 view = glm::lookAt(mCameraPos, mCameraPos + ComputeDirection(mCameraRotX, mCameraRotY),
        glm::vec3(0.0f, 1.0f, 0.0f));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mScreenTexture);

    // update buffer content
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, mScreenBuffer);
    void* ptr = glMapBufferRange(GL_PIXEL_UNPACK_BUFFER, 0, mWindow->Width() * mWindow->Height() * sizeof(glm::vec3),
        GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
    memcpy(ptr, &mFramebuffer[0], mWindow->Width() * mWindow->Height() * sizeof(glm::vec3));
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);

    // update texture content
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, mScreenBuffer);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, mWindow->Width(), mWindow->Height(),
        GL_RGB, GL_FLOAT, 0);

    Raytrace(glm::inverse(view));

    glUseProgram(mProgram);
    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    // draw GUI
    glUseProgram(0);
    glBindVertexArray(0);
    TwDraw();

    mWindow->Swap();
}
//-----------------------------------------------------------------------------
void RaytracerCPU::Raytrace(const glm::mat4& view) {
    const float invWidth = 1.0f / mWindow->Width();
    const float invHeight = 1.0f / mWindow->Height();

    const glm::vec3 orig = glm::vec3(view * glm::vec4(0, 0, 5, 1));

    for (int y = 0; y < mWindow->Height(); ++y) {
        for (int x = 0; x < mWindow->Width(); ++x) {

            const float kcx = ((x + 0.5f) * invWidth - 0.5f) * 8;
            const float kcy = ((y + 0.5f) * invHeight - 0.5f) * 6;

            const glm::vec3 rO = glm::vec3(view * glm::vec4(kcx, kcy, 0, 1));
            const Ray ray(rO, glm::normalize(rO - orig));

            mFramebuffer[y * mWindow->Width() + x] = Trace(ray);
        }
    }
}
//-----------------------------------------------------------------------------
glm::vec3 RaytracerCPU::Trace(const Ray& ray) {
    float distance;
    Primitive* prim = IntersectAll(ray, distance);

    if (!prim) {
        return glm::vec3(0.0f);
    }

    const glm::vec3 p = ray.o + distance * ray.d;
    return Shade(ray, *prim, p, prim->GetNormal(p));
}
//-----------------------------------------------------------------------------
glm::vec3 RaytracerCPU::Shade(const Ray& ray, const Primitive& prim, const glm::vec3& p, const glm::vec3& n) {
    glm::vec3 color(0.0f);

    for (size_t i = 0; i < mLight.size(); ++i) {
        const glm::vec3 lightVec = mLight[i]->GetPosition() - p;
        const glm::vec3 l = glm::normalize(lightVec);

        float dist;
        const Ray shadowRay(p + l * 0.001f, l);
        IntersectAll(shadowRay, dist);

        if (glm::length(lightVec) < dist) {
            const float d = prim.GetDiffuse() * glm::max(glm::dot(n, l), 0.0f);
            color += d * prim.GetColor() * mLight[i]->GetColor();
        }
    }

    return color;
}
//-----------------------------------------------------------------------------
Primitive* RaytracerCPU::IntersectAll(const Ray& ray, float& distance) {
    float currDistance, minDistance = 1000000.0f;
    Primitive* minPrim = NULL;

    for (size_t i = 0; i < mPrimitive.size(); ++i) {
        if (mPrimitive[i]->Intersect(ray, currDistance) && currDistance < minDistance) {
            minDistance = currDistance;
            minPrim = mPrimitive[i];
        }
    }

    distance = minDistance;
    return minPrim;
}
//-----------------------------------------------------------------------------
void RaytracerCPU::UpdateCamera(float dt) {
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
        RaytracerCPU raytracer;
        raytracer.Run();
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