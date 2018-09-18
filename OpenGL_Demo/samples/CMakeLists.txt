cmake_minimum_required(VERSION 2.8)

project("OpenGLSDKSamples")
set(OpenGLSDKSamples_VERSION_MAJOR 1)
set(OpenGLSDKSamples_VERSION_MINOR 0)

find_package(SDL)

if (SDL_FOUND)

    include_directories("${SDL_INCLUDE_DIR}" external common external/AntTweakBar/include external/stbi external/glm)
    
    add_subdirectory(external)
    add_subdirectory(common)
    
    add_subdirectory(Triangle)
    add_subdirectory(ShadowMapping)
    add_subdirectory(RaytracerCPU)
    add_subdirectory(QJuliaSets)
    add_subdirectory(Monkey)
    add_subdirectory(Mandelbrot)
    add_subdirectory(GshShell)
    add_subdirectory(FractalFlames)
    add_subdirectory(MultiWindow)
    add_subdirectory(RaytracerGPU)
    add_subdirectory(Spectogram)
    add_subdirectory(JuliaSets)
	add_subdirectory(VolumetricRayCasting)
	add_subdirectory(ShaderEffects)
    
else (SDL_FOUND)

    message("SDL not found")
    
endif (SDL_FOUND)