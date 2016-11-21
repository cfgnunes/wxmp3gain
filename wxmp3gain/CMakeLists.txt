cmake_minimum_required(VERSION 3.5)
project(wxmp3gain)
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Application.cpp
    src/Application.h
    src/ConfigBase.cpp
    src/ConfigBase.h
    src/Constants.h
    src/Conversion.cpp
    src/Conversion.h
    src/DndFile.cpp
    src/DndFile.h
    src/FileInfo.cpp
    src/FileInfo.h
    src/FileListManager.cpp
    src/FileListManager.h
    src/Gui.cpp
    src/Gui.h
    src/GuiMain.cpp
    src/GuiMain.h
    src/GuiSettings.cpp
    src/GuiSettings.h)

add_executable(wxmp3gain ${SOURCE_FILES})
target_link_libraries(wxmp3gain ${wxWidgets_LIBRARIES})