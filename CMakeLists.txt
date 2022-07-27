cmake_minimum_required(VERSION 2.9)
project(wxmp3gain CXX)

if(WIN32)
    set(wxWidgets_ROOT_DIR "C:/wxWidgets-3.1.1")
    set(wxWidgets_LIB_DIR "C:/wxWidgets-3.1.1/lib/gcc810_dll")
    set(wxWidgets_CONFIGURATION mwsu)
endif()

# Dependencies
find_package(Gettext)
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

# Set compiler parameters
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi -s -Wall -Wextra -Wpedantic")

# Sources
file(GLOB SRC_FILES src/*.cpp src/*.h)
file(GLOB MSG_FILES msg/*.po)

# Translation files
if(GETTEXT_FOUND)
    foreach (MSG_FILE ${MSG_FILES})
        # Remove path and extension of 'MSG_FILE'
        get_filename_component(MSG_NAME ${MSG_FILE} NAME_WE)
        # Compile each '.po' file to '.gmo' file
        GETTEXT_PROCESS_PO_FILES(${MSG_NAME} ALL PO_FILES "msg/${MSG_NAME}.po")
        # Define the files location during install process
        if(WIN32)
            install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${MSG_NAME}.gmo" DESTINATION "data/msg/${MSG_NAME}/" RENAME "${CMAKE_PROJECT_NAME}.mo")
        else()
            install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${MSG_NAME}.gmo" DESTINATION "share/${CMAKE_PROJECT_NAME}/data/msg/${MSG_NAME}/" RENAME "${CMAKE_PROJECT_NAME}.mo")
        endif()
    endforeach()
else()
    message(WARNING "gettext tools not found. Translations will not be built.")
endif()

# Compile the main executable
if(WIN32)
    set(SRC_FILES ${SRC_FILES} windows-dist/resource.rc)
    add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SRC_FILES})
else()
    add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})
endif()
target_link_libraries(${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Define the files location during install process
if(WIN32)
    install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "/")
    install(DIRECTORY "resource" DESTINATION "resource")
    install(FILES "doc/CHANGELOG" DESTINATION "/" RENAME "Changelog.txt")
    install(FILES "doc/COPYING" DESTINATION "/" RENAME "License.txt")
    install(FILES "doc/README" DESTINATION "/" RENAME "Readme.txt")
    install(FILES "C:/wxWidgets-3.1.1/lib/gcc810_dll/wxmsw313u_core_gcc810.dll" DESTINATION "/")
    install(FILES "C:/wxWidgets-3.1.1/lib/gcc810_dll/wxbase313u_gcc810.dll" DESTINATION "/")
else()
    install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "bin")
    install(DIRECTORY "data/" DESTINATION "share/${CMAKE_PROJECT_NAME}/data")
    install(DIRECTORY "doc/" DESTINATION "share/doc/${CMAKE_PROJECT_NAME}")
    install(FILES "debian/menu/icon32x32.png" DESTINATION "share/icons/hicolor/32x32/apps/" RENAME "${CMAKE_PROJECT_NAME}.png")
    install(FILES "debian/menu/icon48x48.png" DESTINATION "share/icons/hicolor/48x48/apps/" RENAME "${CMAKE_PROJECT_NAME}.png")
    install(FILES "debian/menu/icon64x64.png" DESTINATION "share/icons/hicolor/64x64/apps/" RENAME "${CMAKE_PROJECT_NAME}.png")
    install(FILES "debian/menu/icon128x128.png" DESTINATION "share/icons/hicolor/128x128/apps/" RENAME "${CMAKE_PROJECT_NAME}.png")
    install(FILES "debian/menu/${CMAKE_PROJECT_NAME}.desktop" DESTINATION "share/applications/")
endif()

# Define the 'run' target
add_custom_target(run
    COMMAND ${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
    WORKING_DIRECTORY ../${CMAKE_PROJECT_DIR}
)
