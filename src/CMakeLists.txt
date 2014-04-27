cmake_minimum_required(VERSION 2.8)

include_directories( ${KDE4_INCLUDES} )

set( gameoflife_SRCS cell.cpp gamearea.cpp gameinterface.cpp gamescreensaver.cpp gamesettings.cpp gamesetup.cpp main.cpp)

kde4_add_ui_files( gameoflife_SRCS gamesetup.ui gamearea.ui)

kde4_add_executable( gameoflife.kss ${gameoflife_SRCS} )

target_link_libraries( gameoflife.kss ${KDE4_KIO_LIBS} ${KSCREENSAVER_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${OPENGL_LIBRARIES} )

install( TARGETS gameoflife.kss ${INSTALL_TARGETS_DEFAULT_ARGS} )

install( FILES gameoflife.desktop DESTINATION ${SERVICES_INSTALL_DIR}/ScreenSavers )
install( FILES gameoflife.kss.1 DESTINATION ${MAN_INSTALL_DIR}/man1 )
