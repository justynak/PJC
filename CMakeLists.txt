cmake_minimum_required(VERSION 2.8)

project( gameoflife.kss )

find_package( KDE4 REQUIRED )
find_package( OpenGL REQUIRED )

set( CMAKE_INCLUDE_CURRENT_DIR TRUE )

add_definitions( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS} )

set ( kscreensaver_FIND_REQUIRED TRUE )

find_path( KSCREENSAVER_INCLUDE_DIR kscreensaver.h ${KDE4_INCLUDE_DIR} )
find_library( KSCREENSAVER_LIBRARY NAMES kscreensaver PATHS ${KDE4_LIB_DIR} )

include( FindPackageHandleStandardArgs )

find_package_handle_standard_args( kscreensaver DEFAULT_MSG KSCREENSAVER_LIBRARY KSCREENSAVER_INCLUDE_DIR )


add_subdirectory( src )
