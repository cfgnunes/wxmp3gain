cmake_minimum_required(VERSION 3.5)
project(wxmp3gain)

# Dependencies
find_package(Gettext)
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

# Set compiler parameters
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s")

# Sources
file(GLOB SOURCE_FILES src/*.cpp src/*.h)
file(GLOB LANG_FILES msg/*.po)

# Translation files
if(GETTEXT_FOUND)
    foreach(LANG_FILE ${LANG_FILES})
        # Remove path and extension of 'LANG_FILE'
        get_filename_component(LANG_NAME ${LANG_FILE} NAME_WE)
        # Compile each '.po' file to '.gmo' file
        GETTEXT_PROCESS_PO_FILES(${LANG_NAME} ALL PO_FILES "msg/${LANG_NAME}.po")
        # Define the files location during install process
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${LANG_NAME}.gmo" DESTINATION "share/${PROJECT_NAME}/resource/msg/${LANG_NAME}/" RENAME "${PROJECT_NAME}.mo")
    endforeach()
else()
    message(WARNING "gettext tools not found. Translations will not be built.")
endif()

# Compile the main executable
add_executable(wxmp3gain ${SOURCE_FILES})
target_link_libraries(wxmp3gain ${wxWidgets_LIBRARIES})

# Define the files location during install process
install(TARGETS "wxmp3gain" DESTINATION "bin")
install(DIRECTORY "resource/" DESTINATION "share/${PROJECT_NAME}/resource/")
install(DIRECTORY "docs/" DESTINATION "share/doc/${PROJECT_NAME}/")
install(FILES "debian/menu/icon32x32.png" DESTINATION "share/icons/hicolor/32x32/apps/" RENAME "${PROJECT_NAME}.png")
install(FILES "debian/menu/icon48x48.png" DESTINATION "share/icons/hicolor/48x48/apps/" RENAME "${PROJECT_NAME}.png")
install(FILES "debian/menu/icon64x64.png" DESTINATION "share/icons/hicolor/64x64/apps/" RENAME "${PROJECT_NAME}.png")
install(FILES "debian/menu/icon128x128.png" DESTINATION "share/icons/hicolor/128x128/apps/" RENAME "${PROJECT_NAME}.png")
install(FILES "debian/menu/${PROJECT_NAME}.desktop" DESTINATION "share/applications/")
