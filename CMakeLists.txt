cmake_minimum_required(VERSION 3.22)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(tic_tac_toe main.cpp mainwindow.cpp mainwindow.h instruction.cpp instruction.h)
target_link_libraries(tic_tac_toe
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

