message( "Includes: ${GAME_INCLUDES}" )
include_directories( ${GAME_INCLUDES} )
add_library(
	game
	STATIC
	window.c
)
