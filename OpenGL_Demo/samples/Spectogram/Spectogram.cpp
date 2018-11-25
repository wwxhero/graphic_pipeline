// This source file is part of OpenGL Code Samples
// For the latest info, see http://es.g0dsoft.com/
// Copyright (c) 2010 Michal Ziulek
// This source is under MIT License

#include "Common.hpp"
#include "vorbis/vorbisfile.h"
#include <stdexcept>
#include <vector>
using namespace std;

//-----------------------------------------------------------------------------
#define N "\n"
namespace {
const char* Vsh() {
    return OGL_SHADER_BEGIN(130)
        N  "uniform mat4 ModelViewProj;"
        N  "in vec2 Position;"
        N  "in float Sample;"
        N  "void main() {"
        N  "    gl_Position = ModelViewProj * vec4(Position.x, Sample, Position.y, 1);"
        N  "}";
}
const char* Fsh() {
    return OGL_SHADER_BEGIN(130)
        N  "out vec4 Color;"
        N  "void main() {"
        N  "    Color = vec4(1);"
        N  "}";
}
} // namespace
#undef N
//-----------------------------------------------------------------------------
// Spectogram
//-----------------------------------------------------------------------------
class Spectogram {
public:
    Spectogram() :
        mWindow(NULL), mGLContext(NULL), mAudioDevice(0),
        mVAO(0), mSamplesVBO(0), mGridVBO(0), mProgram(0),
        mVorbisFileOpened(false) {}
    ~Spectogram();

    void Run();

private:
    void Init();
    bool ProcessEvents();
    void Update();

    void AudioCallback(Uint8* stream, int len);
    static void SDLCALL AudioCallback_Entry(void* userdata, Uint8* stream, int len);

    GLWindow* mWindow;
    SDL_GLContext mGLContext;
    SDL_AudioDeviceID mAudioDevice;

    GLuint mVAO, mSamplesVBO, mGridVBO, mProgram;

    OggVorbis_File mVorbisFile;
    bool mVorbisFileOpened;

    vector<short> mSamples;
    bool mSamplesDirty;
};
//-----------------------------------------------------------------------------
Spectogram::~Spectogram() {
    if (mVorbisFileOpened) {
        ov_clear(&mVorbisFile);
    }

    if (mAudioDevice) {
        SDL_CloseAudioDevice(mAudioDevice);
    }

    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mSamplesVBO);
    glDeleteBuffers(1, &mGridVBO);
    glDeleteProgram(mProgram);
    glUseProgram(0);

    SDL_GL_DeleteContext(mGLContext);
    delete mWindow;
}
//-----------------------------------------------------------------------------
void Spectogram::Run() {
    Init();
    while (ProcessEvents()) {
        Update();
    }
}
//-----------------------------------------------------------------------------
void Spectogram::Init() {
    // create window
    mWindow = new GLWindow("Spectogram", 800, 600);

    // create OpenGL context
    if (!(mGLContext = SDL_GL_CreateContext(mWindow->Get()))) {
        throw runtime_error("SDL_GL_CreateContext failed");
    }

    SDL_GL_SetSwapInterval(0);

    // load OpenGL 3.0 functions
    gl::LoadCommandPointers(30);

    // audio device
    SDL_AudioSpec audioSpec;
    audioSpec.callback = AudioCallback_Entry;
    audioSpec.channels = 2;
    audioSpec.format = AUDIO_S16;
    audioSpec.samples = 1024;
    audioSpec.freq = 22050;
    audioSpec.userdata = this;

    if (!(mAudioDevice = SDL_OpenAudioDevice(NULL, 0, &audioSpec, NULL, 0))) {
        throw runtime_error("SDL_OpenAudioDevice failed");
    }

    mSamples.resize(audioSpec.channels * audioSpec.samples);
    mSamplesDirty = false;


    /* create grid vbo */ {
        vector<glm::vec2> grid(1024);
        const float length = 10.0f;
        for (size_t i = 0; i < grid.size(); ++i) {
            grid[i].x = i * length / grid.size() - length / 2;
            grid[i].y = 0.0f;
        }

        glGenBuffers(1, &mGridVBO);
        glBindBuffer(GL_ARRAY_BUFFER, mGridVBO);
        glBufferData(GL_ARRAY_BUFFER, grid.size() * sizeof(glm::vec2), &grid[0], GL_STATIC_DRAW);
    }

    // create samples vbo
    glGenBuffers(1, &mSamplesVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mSamplesVBO);
    glBufferData(GL_ARRAY_BUFFER, mSamples.size() * sizeof(short), &mSamples[0], GL_STREAM_DRAW);

    // create vao
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glBindBuffer(GL_ARRAY_BUFFER, mGridVBO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, mSamplesVBO);
    glVertexAttribPointer(1, 1, GL_SHORT, GL_TRUE, 2 * sizeof(short), 0);
    glEnableVertexAttribArray(1);

    // create program
    mProgram = gl::BuildProgram(Vsh(), Fsh(), false);
    glBindAttribLocation(mProgram, 0, "Position");
    glBindAttribLocation(mProgram, 1, "Sample");
    gl::LinkProgram(mProgram);

    // open vorbis file
    FILE* fp = fopen("../../media/stereo.ogg", "rb");
    if (!fp) {
        throw runtime_error("failed to open stereo.ogg file");
    }

    if (ov_open_callbacks(fp, &mVorbisFile, NULL, 0, OV_CALLBACKS_DEFAULT)) {
        throw runtime_error("failed to open stereo.ogg file");
    }

    mVorbisFileOpened = true;

    // play the music
    SDL_PauseAudioDevice(mAudioDevice, 0);
}
//-----------------------------------------------------------------------------
bool Spectogram::ProcessEvents() {
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            SDL_PauseAudioDevice(mAudioDevice, 1);
            return false;
        }

        ProcessCommonEvent(evt);
    }

    return true;
}
//-----------------------------------------------------------------------------
void Spectogram::Update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (mSamplesDirty) {
        SDL_LockAudioDevice(mAudioDevice);

        glBindBuffer(GL_ARRAY_BUFFER, mSamplesVBO);
        void* ptr = glMapBufferRange(GL_ARRAY_BUFFER, 0, mSamples.size() * sizeof(short), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
        memcpy(ptr, &mSamples[0], mSamples.size() * sizeof(short));
        glUnmapBuffer(GL_ARRAY_BUFFER);

        mSamplesDirty = false;

        SDL_UnlockAudioDevice(mAudioDevice);
    }

    const glm::mat4 modelViewProj =
        glm::perspective(45.0f, 1.0f, 1.0f, 1000.0f) *
        glm::lookAt(glm::vec3(0.0f, 0.0f, 4.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    glUseProgram(mProgram);
    glUniformMatrix4fv(glGetUniformLocation(mProgram, "ModelViewProj"), 1, GL_FALSE, &modelViewProj[0][0]);

    glBindVertexArray(mVAO);
    glDrawArrays(GL_LINE_STRIP, 0, 1024);

    mWindow->Swap();
}
//-----------------------------------------------------------------------------
void Spectogram::AudioCallback(Uint8* stream, int len) {
    int bitstream;
    long bytesRead = 0;

    while (true) {
        long r = ov_read(&mVorbisFile, reinterpret_cast<char*>(&mSamples[0]) + bytesRead,
            len - bytesRead, 0, 2, 1, &bitstream);

        if (r <= 0) { // eof or error
            ov_time_seek(&mVorbisFile, 0);
            return;
        }

        bytesRead += r;
        if (bytesRead >= len) {
            break;
        }
    }

    // send samples to the audio device
    memcpy(stream, &mSamples[0], bytesRead);

    mSamplesDirty = true;
}
//-----------------------------------------------------------------------------
void Spectogram::AudioCallback_Entry(void* userdata, Uint8* stream, int len) {
    static_cast<Spectogram*>(userdata)->AudioCallback(stream, len);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        DisplayErrorMessage("main", "SDL_Init failed");
        return 0;
    }

    try {
        Spectogram spectogram;
        spectogram.Run();
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