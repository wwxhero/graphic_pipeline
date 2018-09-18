set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(ShaderEffects ShaderEffects.cpp)
target_link_libraries(ShaderEffects "${SDL_LIBRARY}" common)