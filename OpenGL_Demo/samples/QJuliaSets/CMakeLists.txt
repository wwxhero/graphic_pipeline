set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(QJuliaSets QJuliaSets.cpp)
target_link_libraries(QJuliaSets "${SDL_LIBRARY}" common)