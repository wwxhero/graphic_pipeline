set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(JuliaSets JuliaSets.cpp)
target_link_libraries(JuliaSets "${SDL_LIBRARY}" common)