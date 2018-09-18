include_directories(include)
include_directories(../libogg/include)

add_library(vorbis
	lib/analysis.c
	lib/barkmel.c
	lib/bitrate.c
	lib/block.c
	lib/codebook.c
	lib/envelope.c
	lib/floor0.c
	lib/floor1.c
	lib/info.c
	lib/lookup.c
	lib/lpc.c
	lib/lsp.c
	lib/mapping0.c
	lib/mdct.c
	lib/psy.c
	lib/registry.c
	lib/res0.c
	lib/sharedbook.c
	lib/smallft.c
	lib/synthesis.c
	lib/vorbisenc.c
	lib/window.c
	include/vorbis/codec.h
	include/vorbis/vorbisenc.h)
	
add_library(vorbisfile lib/vorbisfile.c include/vorbis/vorbisfile.h)