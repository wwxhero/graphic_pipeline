include_directories(include)

set(hpp_files include/AntTweakBar.h)

set(cpp_files
    src/LoadOGL.cpp src/TwBar.cpp src/TwColors.cpp src/TwFonts.cpp src/TwMgr.cpp src/TwOpenGL.cpp src/TwPrecomp.cpp src/AntTweakBar.rc)

add_library(AntTweakBarStatic ${hpp_files} ${cpp_files})