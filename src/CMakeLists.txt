cmake_minimum_required(VERSION 2.4.6)

project(lex4 C)

set (
    SOURCES
    raw_screen.c
    media.c
    window.c
    game.c
    lex4.c
)

find_package ( SDL REQUIRED )
find_package ( SDL_image REQUIRED )
find_package ( SDL_ttf REQUIRED)

link_libraries (
   ${SDL_LIBRARY}
   ${SDLIMAGE_LIBRARY}
   ${SDLTTF_LIBRARY}
   SDLmain
)
# Workaround for the non-working REQUIRED flag
if ( NOT SDL_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

if ( NOT SDLIMAGE_FOUND )
   message ( FATAL_ERROR "SDL_image not found!" )
endif ( NOT SDLIMAGE_FOUND )

if ( NOT SDLTTF_FOUND )
   message ( FATAL_ERROR "SDL_ttf not found!" )
endif ( NOT SDLTTF_FOUND )

add_executable (
   lex4
   WIN32 # Only if you don't want the DOS prompt to appear in the background in Windows
   MACOSX_BUNDLE
   ${SOURCES} # We could've listed the source files here directly instead of using a variable to store them
)
