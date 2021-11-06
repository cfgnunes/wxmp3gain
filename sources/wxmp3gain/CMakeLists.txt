# ===============================================================================
# The wxMP3Gain GUI.
# ===============================================================================
# Set the name of the target.
set(TARGET_NAME ${CMAKE_PROJECT_NAME})
# Convert the target name to camel case.
delimited_string_to_upper_camel_case(${TARGET_NAME} TARGET_NAME_CAMEL_CASE "-")
# Convert the target name to lower case.
string(TOLOWER ${TARGET_NAME} TARGET_NAME_LOWERED)

if(WIN32)
    # Add the executable with a WinMain entry point on Windows.
    # See https://cmake.org/cmake/help/latest/prop_tgt/WIN32_EXECUTABLE.html
    add_executable(${TARGET_NAME} WIN32)
else()
    # Add the executable.
    add_executable(${TARGET_NAME})
endif()
# Set linker language
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Potentially add compiler and version information to the output.
# Check if the user passed the WXMP3_GAIN_VERSIONED_OUTPUT variable.
if(DEFINED WXMP3GAIN_VERSIONED_OUTPUT)
    # The variable is passed, check if it is set to 'true'.
    if(WXMP3GAIN_VERSIONED_OUTPUT)
        # Set the naming convention.
        set_naming_convention(${TARGET_NAME})
    endif()
else()
    # At least set the debug postfix to "-d"
    set_debug_postfix(${TARGET_NAME})
endif()

# Make sure wxWidget is included.
include(${wxWidgets_USE_FILE})

# ===============================================================================
# Resources
# ===============================================================================
# Copy resources to target directory during development.
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
					   ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_RESOURCES_FOLDER} $<TARGET_FILE_DIR:${TARGET_NAME}>/${CMAKE_RESOURCES_FOLDER}
	)

# ===============================================================================
# Copy .desktop file and replace variables.
# ===============================================================================
if(UNIX)
    # Copy to binary directory.
    configure_file(debian/menu/${TARGET_NAME}.desktop ${TARGET_NAME}.desktop)
endif()

# ===============================================================================
# Sources
# ===============================================================================
# List the sources, private to the application.
set(${TARGET_NAME}_PRIVATE_SRCS	# wxmp3gain
								src/Main.h
								src/Main.cpp
								src/GuiFrameMain.h
								src/GuiFrameMain.cpp
								src/GuiDialogSettings.h
								src/GuiDialogSettings.cpp
								src/Gui.h
								src/Gui.cpp
								src/Gui.fbp

                                src/FileListManager.h
                                src/FileListManager.cpp
                                src/FileInfo.h
                                src/FileInfo.cpp
                                src/DndFile.h
                                src/DndFile.cpp
                                src/Conversion.h
                                src/Conversion.cpp
                                src/ConfigBase.h
                                src/ConfigBase.cpp
							)

# -------------------------------------------------------------------------------
# Group all sources (only relevant for some IDEs).
# -------------------------------------------------------------------------------
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src PREFIX "Sources" FILES ${${TARGET_NAME}_PRIVATE_SRCS})

# ===============================================================================
# Generate Sources
# ===============================================================================
# Generate resource file defining the binary information.
# -------------------------------------------------------------------------------
generate_resource_files( ${TARGET_NAME}
						"wxMP3gain GUI"
                        ${CMAKE_SOURCES_ROOT_FOLDER}/templates/resource/resource_icon.h.in
                        ${CMAKE_SOURCES_ROOT_FOLDER}/templates/resource/resource_icon.rc.in
						${CMAKE_GENERATED_SOURCES_FOLDER}
						"GENERATED_RESOURCE_FILES"
						ICON "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon-app.ico"
					)

# Append the generated resource files to the list.
list(APPEND ${TARGET_NAME}_GENERATED_SOURCES  ${GENERATED_RESOURCE_FILES})

# -------------------------------------------------------------------------------
# Add the sources.
# -------------------------------------------------------------------------------
target_sources(${TARGET_NAME}	PRIVATE
									${${TARGET_NAME}_PRIVATE_SRCS}
									${${TARGET_NAME}_GENERATED_SOURCES}
								)

# ===============================================================================
# Add additional include directories.
# ===============================================================================
target_include_directories(${TARGET_NAME}
	PRIVATE		${CMAKE_CURRENT_SOURCE_DIR}/src
				${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_GENERATED_SOURCES_FOLDER}
				${PROJECT_TEMPLATE_OUTPUT_DIR}/${CMAKE_GENERATED_SOURCES_FOLDER}/
	)

# ===============================================================================
# Add Dependencies
# ===============================================================================
# Link dependencies.
target_link_libraries(${TARGET_NAME} ${wxWidgets_LIBRARIES})

# ==============================================================================
# Install docs, icons, etc.                                                     
# ==============================================================================
set(MSG_FILES   cs.po
                de.po
                es.po
                hr_HR.po
                ja.po
                pt_BR.po
                ru.po
                tr.po
    )

# Translation files
if(GETTEXT_FOUND)
    # Add the creation of the translation files as a target for wxMP3gain.
    add_dependencies(${TARGET_NAME} "pofiles")

    foreach (MSG_FILE ${MSG_FILES})
        # Remove path and extension of 'MSG_FILE'
        get_filename_component(MSG_NAME ${MSG_FILE} NAME_WE)
        # Compile each '.po' file to '.gmo' file
        GETTEXT_PROCESS_PO_FILES(${MSG_NAME} ALL PO_FILES "msg/${MSG_NAME}.po")

        # Build up a command copying translation files to the target directory during development.
        list(APPEND WXMP3GAIN_COPY_TRANSLATIONS_COMMANDS COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${CMAKE_CURRENT_BINARY_DIR}/${MSG_NAME}.gmo" "$<TARGET_FILE_DIR:${TARGET_NAME}>/${CMAKE_RESOURCES_FOLDER}/msg/${MSG_NAME}/${TARGET_NAME_LOWERED}.mo")
        
        # Define the files location during install process
        if(WIN32)
            install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${MSG_NAME}.gmo" DESTINATION "${CMAKE_RESOURCES_FOLDER}/msg/${MSG_NAME}/" RENAME "${TARGET_NAME_LOWERED}.mo")
        else()
            install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${MSG_NAME}.gmo" DESTINATION "${CMAKE_INSTALL_DATADIR}/${TARGET_NAME}/${CMAKE_RESOURCES_FOLDER}/msg/${MSG_NAME}/" RENAME "${TARGET_NAME_LOWERED}.mo")
        endif()
    endforeach()
else()
    message(WARNING "gettext tools not found. Translations will not be built.")
endif()

# Copy translations to this target's (the binaries) directory during development.
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                    ${WXMP3GAIN_COPY_TRANSLATIONS_COMMANDS}
                    COMMENT "Copying translation files."
	)


# Define the binary location during install process
install(TARGETS ${TARGET_NAME} DESTINATION "${CMAKE_INSTALL_BINDIR}")

# Define the files location during install process
if(WIN32)
    install(DIRECTORY "${CMAKE_RESOURCES_FOLDER}" DESTINATION "${CMAKE_INSTALL_PREFIX}")
    install(FILES "${CMAKE_DOC_FOLDER}/AUTHORS" DESTINATION "${CMAKE_INSTALL_PREFIX}" RENAME "Authors.txt")
    install(FILES "${CMAKE_DOC_FOLDER}/CHANGELOG" DESTINATION "${CMAKE_INSTALL_PREFIX}" RENAME "Changelog.txt")
    install(FILES "${CMAKE_DOC_FOLDER}/COPYING" DESTINATION "${CMAKE_INSTALL_PREFIX}" RENAME "License.txt")
    install(FILES "${CMAKE_DOC_FOLDER}/README" DESTINATION "${CMAKE_INSTALL_PREFIX}" RENAME "Readme.txt")
else()
    install(DIRECTORY "${CMAKE_RESOURCES_FOLDER}" DESTINATION "${CMAKE_INSTALL_DATADIR}/${TARGET_NAME}")
    install(FILES "${CMAKE_DOC_FOLDER}/AUTHORS" DESTINATION "${CMAKE_INSTALL_DOCDIR}")
    install(FILES "${CMAKE_DOC_FOLDER}/CHANGELOG" DESTINATION "${CMAKE_INSTALL_DOCDIR}")
    install(FILES "${CMAKE_DOC_FOLDER}/COPYING" DESTINATION "${CMAKE_INSTALL_DOCDIR}")
    install(FILES "${CMAKE_DOC_FOLDER}/README" DESTINATION "${CMAKE_INSTALL_DOCDIR}")
    install(FILES "debian/menu/icon32x32.png" DESTINATION "${CMAKE_INSTALL_DATADIR}/icons/hicolor/32x32/apps/" RENAME "${TARGET_NAME}.png")
    install(FILES "debian/menu/icon48x48.png" DESTINATION "${CMAKE_INSTALL_DATADIR}/icons/hicolor/48x48/apps/" RENAME "${TARGET_NAME}.png")
    install(FILES "debian/menu/icon64x64.png" DESTINATION "${CMAKE_INSTALL_DATADIR}/icons/hicolor/64x64/apps/" RENAME "${TARGET_NAME}.png")
    install(FILES "debian/menu/icon128x128.png" DESTINATION "${CMAKE_INSTALL_DATADIR}/icons/hicolor/128x128/apps/" RENAME "${TARGET_NAME}.png")
    
    # Check if the launcher should be installed for the user only, or globally.
    # The latter is assumed.
    if("${WXMP3GAIN_USER_LAUNCHER_ONLY}")
        # Install the .desktop file into the user's folder.
        install(    FILES "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.desktop" 
                    DESTINATION "${CMAKE_UNIX_LAUNCHER_USER}"
                    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ)
        # Run chown, to change user and group.
        install( CODE "execute_process(COMMAND sudo chown ${CMAKE_CURRENT_USERNAME}:${CMAKE_CURRENT_USERNAME} ${CMAKE_UNIX_LAUNCHER_USER}/${TARGET_NAME}.desktop)")
    else()
        # Install the .desktop file into the global launcher folder.
        install(    FILES "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.desktop" 
                    DESTINATION "${CMAKE_UNIX_LAUNCHER_GLOBAL}"
                    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)
    endif()    
endif()
