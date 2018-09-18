set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
include_directories(../external/libogg/include ../external/libvorbis/include)
add_executable(Spectogram Spectogram.cpp)
target_link_libraries(Spectogram "${SDL_LIBRARY}" common ogg vorbis vorbisfile)