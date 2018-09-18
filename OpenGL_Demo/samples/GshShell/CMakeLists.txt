set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(GshShell GshShell.cpp)
target_link_libraries(GshShell "${SDL_LIBRARY}" common)