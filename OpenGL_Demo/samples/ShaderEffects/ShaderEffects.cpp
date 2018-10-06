// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

// Original shader code was written by iq and others (http://www.iquilezles.org/apps/shadertoy/)

#include "Common.hpp"
#include <stdexcept>
#include <vector>
#include <string>
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
const char* RadialBlur() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N  "uniform float Time;"
        N  "uniform sampler2D Tex0;"
        N
        N  "out vec4 Color;"
        N
        N  "vec3 deform(in vec2 p) {"
        N  "    vec2 q = vec2(sin(1.1 * Time + p.x), sin(1.2 * Time + p.y));"
        N  "    float r = length(q);"
        N
        N  "    vec2 uv;"
        N  "    float f = sqrt(r * r + 1.0);"
        N  "    uv.x = sin(0.0 + 1.0 * Time) + p.x * f;"
        N  "    uv.y = sin(0.6 + 1.1 * Time) + p.y * f;"
        N
        N  "    return texture(Tex0, uv * 0.5).xyz;"
        N  "}"
        N
        N  "void main() {"
        N  "    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / Resolution.xy;"
        N  "    vec2 s = p;"
        N
        N  "    vec3 total = vec3(0);"
        N  "    vec2 d = -p / 40.0;"
        N  "    float w = 1.0;"
        N  "    for (int i = 0; i < 40; ++i) {"
        N  "        vec3 res = deform(s);"
        N  "        res = smoothstep(0.1, 1.0, res * res);"
        N  "        total += w * res;"
        N  "        w *= 0.99;"
        N  "        s += d;"
        N  "    }"
        N
        N  "    total /= 40;"
        N  "    float r = 1.5 / (1.0 + dot(p, p));"
        N  "    Color = vec4(total * r, 1.0);"
        N  "}";
}
const char* MotionBlur() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N  "uniform float Time;"
        N  "uniform sampler2D Tex0;"
        N
        N  "out vec4 Color;"
        N
        N  "vec3 deform(in vec2 p, float scale) {"
        N  "    float mtime = scale + Time;"
        N  "    float a = atan(p.y, p.x);"
        N  "    float r = length(p);"
        N  "    float s = r * (1.0 + 0.5 * cos(mtime * 1.7));"
        N
        N  "    vec2 uv;"
        N  "    uv.x = 0.1 * mtime + 0.05 * p.y + 0.05 * cos(-mtime + a * 3.0) / s;"
        N  "    uv.y = 0.1 * mtime + 0.05 * p.x + 0.05 * sin(-mtime + a * 3.0) / s;"
        N
        N  "    float w = 0.8 - 0.2 * cos(mtime + 3.0 * a);"
        N
        N  "    vec3 res = texture(Tex0, uv).xyz * w;"
        N  "    return res * res;"
        N  "}"
        N
        N  "void main() {"
        N  "    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / Resolution.xy;"
        N  "    vec3 total = vec3(0);"
        N  "    float w = 0;"
        N
        N  "    for (int i = 0; i < 20; ++i) {"
        N  "        vec3 res = deform(p, w);"
        N  "        total += res;"
        N  "        w += 0.02;"
        N  "    }"
        N
        N  "    total /= 20;"
        N  "    Color = vec4(3 * total, 1);"
        N  "}";
}
const char* PostProcessing() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N  "uniform float Time;"
        N  "uniform sampler2D Tex0;"
        N
        N  "out vec4 Color;"
        N
        N  "void main() {"
        N  "    vec2 q = gl_FragCoord.xy / Resolution.xy;"
        N  "    vec2 uv = 0.5 + (q - 0.5) * (0.9 + 0.1 * sin(0.2 * Time));"
        N
        N  "    vec3 oricol = texture(Tex0, vec2(q.x, 1.0 - q.y)).xyz;"
        N  "    vec3 col;"
        N
        N  "    col.r = texture(Tex0, vec2(uv.x + 0.003, -uv.y)).x;"
        N  "    col.g = texture(Tex0, vec2(uv.x + 0.000, -uv.y)).y;"
        N  "    col.b = texture(Tex0, vec2(uv.x - 0.003, -uv.y)).z;"
        N
        N  "    col = clamp(col * 0.5 + 0.5 * col * col * 1.2, 0.0, 1.0);"
        N  "    col *= 0.5 + 0.5 * 16.0 * uv.x * uv.y * (1.0 - uv.x) * (1.0 - uv.y);"
        N  "    col *= vec3(0.8, 1.0, 0.7);"
        N  "    col *= 0.9 + 0.1 * sin(10.0 * Time + uv.y * 1000.0);"
        N  "    col *= 0.97 + 0.03 * sin(110.0 * Time);"
        N
        N  "    float comp = smoothstep(0.2, 0.7, sin(Time));"
        N  "    col = mix(col, oricol, clamp(-2.0 + 2.0 * q.x + 3.0 * comp, 0.0, 1.0));"
        N
        N  "    Color = vec4(col, 1);"
        N  "}";
}
const char* Julia() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N  "uniform float Time;"
        N
        N  "out vec4 Color;"
        N
        N  "void main() {"
        N  "    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / Resolution.xy;"
        N  "    vec2 cc = vec2(cos(0.25 * Time), sin(0.25 * Time * 1.423));"
        N
        N  "    float dmin = 1000.0;"
        N  "    vec2 z = p * vec2(1.33, 1.0);"
        N  "    for (int i = 0; i < 64; ++i) {"
        N  "        z = cc + vec2(z.x * z.x - z.y * z.y, 2.0 * z.x * z.y);"
        N  "        float m2 = dot(z, z);"
        N  "        if (m2 > 100.0) break;"
        N  "        dmin = min(dmin, m2);"
        N  "    }"
        N
        N  "    float color = sqrt(sqrt(dmin)) * 0.7;"
        N  "    Color = vec4(color, color, color, 1);"
        N  "}";
}
const char* Mandel() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N  "uniform float Time;"
        N
        N  "out vec4 Color;"
        N
        N  "void main() {"
        N  "    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / Resolution.xy;"
        N  "    p.x *= Resolution.x / Resolution.y;"
        N
        N  "    float zoo = 0.62 + 0.38 * sin(0.1 * Time);"
        N  "    float coa = cos(0.1 * (1.0 - zoo) * Time);"
        N  "    float sia = sin(0.1 * (1.0 - zoo) * Time);"
        N  "    zoo = pow(zoo, 8.0);"
        N  "    vec2 xy = vec2(p.x * coa - p.y * sia, p.x * sia + p.y * coa);"
        N  "    vec2 cc = vec2(-0.745, 0.186) + xy * zoo;"
        N
        N  "    vec2 z  = vec2(0);"
        N  "    vec2 z2 = z * z;"
        N  "    float m2;"
        N  "    float co = 0;"
        N  "    for (int i = 0; i<256; ++i) {"
        N  "        z = cc + vec2(z.x * z.x - z.y * z.y, 2.0 * z.x * z.y);"
        N  "        m2 = dot(z, z);"
        N  "        if (m2 > 1024.0) break;"
        N  "        co += 1.0;"
        N  "    }"
        N
        N  "    co = co + 1.0 - log2(0.5 * log2(m2));"
        N
        N  "    co = sqrt(co / 256.0);"
        N  "    Color = vec4(0.5 + 0.5 * cos(6.2831 * co + 0.0), 0.5 + 0.5 * cos(6.2831 * co + 0.4), 0.5 + 0.5 * cos(6.2831 * co + 0.7), 1);"
        N  "}";
}
const char* MultiTexture() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N  "uniform float Time;"
        N  "uniform sampler2D Tex0;"
        N  "uniform sampler2D Tex1;"
        N
        N  "out vec4 Color;"
        N
        N  "void main() {"
        N  "    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / Resolution.xy;"
        N
        N  "    vec2 cst = vec2(cos(0.5 * Time), sin(0.5 * Time));"
        N  "    mat2 rot = 0.5 * cst.x * mat2(cst.x, -cst.y, cst.y, cst.x);"
        N
        N  "    vec3 col1 = texture(Tex0, rot * p).xyz;"
        N  "    vec3 col2 = texture(Tex1, 0.5 * p + sin(0.1 * Time)).xyz;"
        N
        N  "    vec3 col = col2 * col1;"
        N
        N  "    Color = vec4(col, 1);"
        N  "}";
}
const char* Flower() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform float Time;"
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N
        N  "out vec4 Color;"
        N
        N  "//float U(float x) { return 0.5 + 0.5 * sign(x); }"
        N  "float U(float x) { return (x > 0.0) ? 1.0 : 0.0; }"
        N  "//float U(float x) { return abs(x) / x; }"
        N
        N  "void main() {"
        N  "    vec2 p = (2.0 * gl_FragCoord.xy - Resolution.xy) / Resolution.y;"
        N
        N  "    float a = atan(p.x, p.y);"
        N  "    float r = length(p) * 0.75;"
        N
        N  "    float w = cos(3.1415927 * Time - r * 2.0);"
        N  "    float h = 0.5 + 0.5 * cos(12.0 * a - w * 7.0 + r * 8.0);"
        N  "    float d = 0.25 + 0.75 * pow(h, 1.0 * r) * (0.7 + 0.3 * w);"
        N
        N  "    float col = U(d - r) * sqrt(1.0 - r / d) * r * 2.5;"
        N  "    col *= 1.25 + 0.25 * cos((12.0 * a - w * 7.0+ r * 8.0) / 2.0);"
        N  "    col *= 1.0 - 0.35 * (0.5 + 0.5 * sin(r * 30.0)) * (0.5 + 0.5 * cos(12.0 * a - w * 7.0 + r * 8.0));"
        N  "    Color = vec4("
        N  "        col,"
        N  "        col - h * 0.5 + r * 0.2 + 0.35 * h * (1.0 - r),"
        N  "        col - h * r + 0.1 * h * (1.0 - r),"
        N  "        1.0);"
        N  "}";
}
const char* Heart() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform float Time;"
        N  "uniform vec2 Resolution = vec2(800, 600);"
        N
        N  "out vec4 Color;"
        N
        N  "void main() {"
        N  "    vec2 p = (2.0 * gl_FragCoord.xy - Resolution.xy) / Resolution.y;"
        N
        N  "    float tt = mod(Time, 2.0) / 2.0;"
        N  "    float ss = pow(tt, 0.2) * 0.5 + 0.5;"
        N  "    ss -= ss * 0.2 * sin(tt * 6.2831 * 5.0) * exp(-tt * 6.0);"
        N  "    p *= vec2(0.5, 1.5) + ss * vec2(0.5, -0.5);"
        N
        N  "    float a = atan(p.x, p.y) / 3.141593;"
        N  "    float r = length(p);"
        N
        N  "    float h = abs(a);"
        N  "    float d = (13.0 * h - 22.0 * h * h + 10.0 * h * h * h) / (6.0 - 5.0 * h);"
        N
        N  "    float f = step(r, d) * pow(1.0 - r / d, 0.25);"
        N
        N  "    Color = vec4(f, 0, 0, 1);"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// ShaderEffects
//-----------------------------------------------------------------------------
class ShaderEffects {
public:
    ShaderEffects() : mWindow(NULL), mGLContext(NULL), mVAO(0), mVBO(0), mProgram(0) {
        SDL_zero(mTex);
    }
    ~ShaderEffects();

    void Run();
    
private:
    void Init();
    bool ProcessEvents();
    void Update();

    void LoadEffect();
    static void TW_CALL LoadEffect_Entry(void* demoPtr);

    GLWindow* mWindow;
    SDL_GLContext mGLContext;

    GLuint mVAO, mVBO, mProgram;
    GLuint mTex[2];

    int mEffectID;
};
//-----------------------------------------------------------------------------
ShaderEffects::~ShaderEffects() {
    glDeleteTextures(SDL_arraysize(mTex), mTex);
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteProgram(mProgram);
    glUseProgram(0);

    TwTerminate();
    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void ShaderEffects::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void ShaderEffects::Init() {
    // window
    mWindow = new GLWindow("Shader Effects", 800, 600);
    
    // OpenGL context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    // VBO
    const float data[] = { -1, 1,  -1, -1,  1, 1,  1, -1  };
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    // VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    // textures
    glGenTextures(SDL_arraysize(mTex), mTex);

    // GUI
    TwInit(TW_OPENGL, NULL);
    TwWindowSize(mWindow->Width(), mWindow->Height());
    TwDeleteAllBars();

    TwBar* bar = TwNewBar("Menu");
    TwDefine("Menu color='0 0 0' alpha=128 position='10 10' size='240 70'");
    TwDefine("Menu fontresizable=false resizable=false valueswidth=100");

    const TwEnumVal v[] = {
        { 0, "Radial Blur" },
        { 1, "Motion Blur" },
        { 2, "Post Processing" },
        { 3, "Julia" },
        { 4, "Mandel" },
        { 5, "Multi Texture" },
        { 6, "Flower" },
        { 7, "Heart" },
    };

    const TwType type = TwDefineEnum("EffectsEnum", v, SDL_arraysize(v));
    TwAddVarRW(bar, "Effect", type, &mEffectID, "");
    TwAddButton(bar, "LoadEffect", LoadEffect_Entry, this, "label='Load Effect'");

    mEffectID = 0;
    LoadEffect();
}
//-----------------------------------------------------------------------------
bool ShaderEffects::ProcessEvents() {
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            return false;
        }

        if (ProcessAntTweakBarEvent(evt)) {
            continue;
        }
        ProcessCommonEvent(evt);
    }

    return true;
}
//-----------------------------------------------------------------------------
void ShaderEffects::Update() {
    const float currentTime = SDL_GetTicks() * 0.001f;

    glUseProgram(mProgram);
    glUniform1f(glGetUniformLocation(mProgram, "Time"), currentTime);

    for (size_t i = 0; i < SDL_arraysize(mTex); ++i) {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, mTex[i]);
    }

    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glUseProgram(0);
    glBindVertexArray(0);
    TwDraw();

    mWindow->Swap();
}
//-----------------------------------------------------------------------------
void ShaderEffects::LoadEffect() {
    string fsh, tex[2];

    if (mEffectID == 0) {
        fsh = RadialBlur();
        tex[0] = "../../media/tex0.jpg";
    }
    else if (mEffectID == 1) {
        fsh = MotionBlur();
        tex[0] = "../../media/tex1.jpg";
    }
    else if (mEffectID == 2) {
        fsh = PostProcessing();
        tex[0] = "../../media/tex2.jpg";
    }
    else if (mEffectID == 3) {
        fsh = Julia();
    }
    else if (mEffectID == 4) {
        fsh = Mandel();
    }
    else if (mEffectID == 5) {
        fsh = MultiTexture();
        tex[0] = "../../media/tex0.jpg";
        tex[1] = "../../media/tex3.jpg";
    }
    else if (mEffectID == 6) {
        fsh = Flower();
    }
    else if (mEffectID == 7) {
        fsh = Heart();
    }

    if (!fsh.empty()) {
        glDeleteProgram(mProgram);
        mProgram = gl::BuildProgram(Vsh(), fsh.c_str());

        glUseProgram(mProgram);
        glUniform1i(glGetUniformLocation(mProgram, "Tex0"), 0);
        glUniform1i(glGetUniformLocation(mProgram, "Tex1"), 1);

        for (size_t i = 0; i < SDL_arraysize(tex); ++i) {
            if (!tex[i].empty()) {
                int w, h, n;
                stbi_uc* pixels = stbi_load(tex[i].c_str(), &w, &h, &n, 0);
                if (!pixels) {
                    throw runtime_error("failed to load " + tex[i]);
                }

                glActiveTexture(GL_TEXTURE0 + i);
                glBindTexture(GL_TEXTURE_2D, mTex[i]);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, n == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, pixels);
                stbi_image_free(pixels);
            }
        }
    }
}
//-----------------------------------------------------------------------------
void ShaderEffects::LoadEffect_Entry(void* ptr) {
    static_cast<ShaderEffects*>(ptr)->LoadEffect();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
        DisplayErrorMessage("main", "SDL_Init failed");
        return 0;
    }

    try {
        ShaderEffects shaderEffects;
        shaderEffects.Run();
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