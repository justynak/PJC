cmake_minimum_required(VERSION 2.8)

include_directories( ${KDE4_INCLUDES} )

set( gameoflife_SRCS area.cpp cell.cpp main.cpp mainwindow.cpp )

kde4_add_ui_files( gameoflife_SRCS area.ui mainwindow.ui)

kde4_add_executable( gameoflife.kss ${gameoflife_SRCS} )

target_link_libraries( gameoflife.kss ${KDE4_KIO_LIBS} ${KSCREENSAVER_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${OPENGL_LIBRARIES} )

install( TARGETS gameoflife.kss ${INSTALL_TARGETS_DEFAULT_ARGS} )

install( FILES gameoflife.desktop DESTINATION ${SERVICES_INSTALL_DIR}/ScreenSavers )
install( FILES gameoflife.kss.1 DESTINATION ${MAN_INSTALL_DIR}/man1 )
 
