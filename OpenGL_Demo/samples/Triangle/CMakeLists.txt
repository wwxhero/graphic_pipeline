set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(Triangle Triangle.cpp)
target_link_libraries(Triangle "${SDL_LIBRARY}" common)