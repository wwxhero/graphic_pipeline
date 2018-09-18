set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(VolumetricRayCasting VolumetricRayCasting.cpp)
target_link_libraries(VolumetricRayCasting "${SDL_LIBRARY}" common)