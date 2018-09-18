set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(ShadowMapping ShadowMapping.cpp)
target_link_libraries(ShadowMapping "${SDL_LIBRARY}" common)