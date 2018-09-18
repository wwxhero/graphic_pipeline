add_library(common Common.hpp Common.cpp OpenGL.hpp OpenGL.cpp OpenGLTools.hpp OpenGLTools.cpp OpenGLMath.hpp)
target_link_libraries(common AntTweakBarStatic stbi)