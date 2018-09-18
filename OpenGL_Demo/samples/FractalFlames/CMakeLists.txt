set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(FractalFlames FractalFlames.cpp)
target_link_libraries(FractalFlames "${SDL_LIBRARY}" common)