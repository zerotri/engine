cmake_minimum_required(VERSION 2.6)
include(FindPkgConfig)

include_directories(BEFORE ${CMAKE_BINARY_DIR}/include)
find_package(SDL2 REQUIRED sdl2)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${SDL2_INCLUDE_DIR}
)

set( GAME_INCLUDES
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${SDL2_INCLUDE_DIRS}
)
set( GAME_INCLUDES
	${GAME_INCLUDES}
PARENT_SCOPE )

set( GAME_LIBS
	${SDL2_LIBRARIES}
	game
)
set( GAME_LIBS
	${GAME_LIBS}
PARENT_SCOPE )

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/src )
