set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(Monkey Monkey.cpp)
target_link_libraries(Monkey "${SDL_LIBRARY}" common)