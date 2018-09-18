set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(Mandelbrot Mandelbrot.cpp)
target_link_libraries(Mandelbrot "${SDL_LIBRARY}" common)