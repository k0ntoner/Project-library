cmake_minimum_required(VERSION 3.5)

project(library VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(library
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        sigh_up.h sigh_up.cpp sigh_up.ui
        log_in.h log_in.cpp log_in.ui
        catalog.h catalog.cpp catalog.ui
        Accaunts.txt
        resors.qrc
        harry_potter__stone.h harry_potter__stone.cpp harry_potter__stone.ui
        crime_and_punishment.h crime_and_punishment.cpp crime_and_punishment.ui
        liked.h liked.cpp liked.ui
        galaxy.h galaxy.cpp galaxy.ui
        war_and_peace.h war_and_peace.cpp war_and_peace.ui
        a_game_of_thrones.h a_game_of_thrones.cpp a_game_of_thrones.ui
        narnia.h narnia.cpp narnia.ui
        margarita.h margarita.cpp margarita.ui
        Accaunts_saves.txt
        list_books.h list_books.cpp list_books.ui
        Books.txt
        open.h open.cpp open.ui



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET library APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(library SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(library
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.library)
endif()
set_target_properties(library PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS library
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(library)
endif()
