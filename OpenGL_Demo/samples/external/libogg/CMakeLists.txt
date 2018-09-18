include_directories(include)
add_library(ogg src/bitwise.c src/framing.c include/ogg/ogg.h include/ogg/os_types.h)