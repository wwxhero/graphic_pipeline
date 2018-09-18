set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(MultiWindow MultiWindow.cpp)
target_link_libraries(MultiWindow "${SDL_LIBRARY}" common)