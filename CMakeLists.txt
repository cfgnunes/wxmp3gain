cmake_minimum_required(VERSION 2.8)
project(wxmp3gain)

# Dependencies
find_package(Gettext)
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

# Set compiler parameters
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s")

# Sources
file(GLOB SRC_FILES src/*.cpp src/*.h)
file(GLOB MSG_FILES msg/*.po)

# Translation files
if(GETTEXT_FOUND)
    foreach(MSG_FILE ${MSG_FILES})
        # Remove path and extension of 'MSG_FILE'
        get_filename_component(MSG_NAME ${MSG_FILE} NAME_WE)
        # Compile each '.po' file to '.gmo' file
        GETTEXT_PROCESS_PO_FILES(${MSG_NAME} ALL PO_FILES "msg/${MSG_NAME}.po")
        # Define the files location during install process
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${MSG_NAME}.gmo" DESTINATION "share/${PROJECT_NAME}/resource/msg/${MSG_NAME}/" RENAME "${PROJECT_NAME}.mo")
    endforeach()
else()
    message(WARNING "gettext tools not found. Translations will not be built.")
endif()

# Compile the main executable
add_executable(wxmp3gain ${SRC_FILES})
target_link_libraries(wxmp3gain ${wxWidgets_LIBRARIES})

# Define the files location during install process
if(UNIX)
    install(TARGETS "wxmp3gain" DESTINATION "bin")
    install(DIRECTORY "resource/" DESTINATION "share/${PROJECT_NAME}/resource/")
    install(DIRECTORY "docs/" DESTINATION "share/doc/${PROJECT_NAME}/")
    install(FILES "debian/menu/icon32x32.png" DESTINATION "share/icons/hicolor/32x32/apps/" RENAME "${PROJECT_NAME}.png")
    install(FILES "debian/menu/icon48x48.png" DESTINATION "share/icons/hicolor/48x48/apps/" RENAME "${PROJECT_NAME}.png")
    install(FILES "debian/menu/icon64x64.png" DESTINATION "share/icons/hicolor/64x64/apps/" RENAME "${PROJECT_NAME}.png")
    install(FILES "debian/menu/icon128x128.png" DESTINATION "share/icons/hicolor/128x128/apps/" RENAME "${PROJECT_NAME}.png")
    install(FILES "debian/menu/${PROJECT_NAME}.desktop" DESTINATION "share/applications/")
endif()
