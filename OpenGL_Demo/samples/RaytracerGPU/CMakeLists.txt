set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(RaytracerGPU RaytracerGPU.cpp)
target_link_libraries(RaytracerGPU "${SDL_LIBRARY}" common)