set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(RaytracerCPU RaytracerCPU.cpp)
target_link_libraries(RaytracerCPU "${SDL_LIBRARY}" common)