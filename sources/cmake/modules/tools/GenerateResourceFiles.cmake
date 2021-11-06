# ===============================================================================
# Generate Resource Files (Windows Only)
# -------------------------------------------------------------------------------
# Generates resource files containing binary information for executable (.exe) 
# and shared library (.dll) files.
# ===============================================================================
# TARGET_NAME: Name of an executable (.exe) or shared library (.dll) target.
# TARGET_FULL_NAME: The name of the target shown in the file properties
# INPUT_TEMPLATE_HEADER_FILE: Path to header template file.
# INPUT_TEMPLATE_RESOURCE_FILE: Path to resource template file.
# OUTPUT_DIRECTORY: Path where the files should be generated to.
# TARGET_GENERATED_RESOURCE_FILES:	The variable filled with the names of the
#									generated resource files.
# DESCRIPTION: 	Optional description of the target shown in the file properties.
#				The description can only be used for shared libraries.
# ICON <FILENAME>: 	Optional path to an icon, which can only be	used with
#                   executables.
# -------------------------------------------------------------------------------
function(generate_resource_files	TARGET_NAME 
									TARGET_FULL_NAME
                                    INPUT_TEMPLATE_HEADER_FILE
                                    INPUT_TEMPLATE_RESOURCE_FILE
									OUTPUT_DIRECTORY
									TARGET_GENERATED_RESOURCE_FILES
								)

    # All of this only works for Windows.
	if(WIN32)
	
        # Parse optional ICON and DESCRIPTION arguments.
        cmake_parse_arguments(generate_resource_files "" "ICON;DESCRIPTION" "" ${ARGN} )
        
        # When using MinGW, make sure no spaces are in the path, else it won't work.
        if(MINGW)
            # Search for the first space in the CMAKE_CURRENT_BINARY_DIR.
            string(FIND ${CMAKE_CURRENT_BINARY_DIR} " " POSITION_OF_WHITESPACE)
            
            # Check if there was a space in the CMAKE_CURRENT_BINARY_DIR.
            if(NOT POSITION_OF_WHITESPACE EQUAL -1)
                message(WARNING "Cannot compile resource files, since there are spaces in the CMAKE_CURRENT_BINARY_DIR!")
                return()
            endif()
        endif()
	
		# Check if the target is an executable or library.
		get_target_property(TARGET_TYPE ${TARGET_NAME} TYPE)
		
		# This only works for executables or shared libraries.
		if ( "${TARGET_TYPE}" STREQUAL "EXECUTABLE" OR
			 "${TARGET_TYPE}" STREQUAL "SHARED_LIBRARY")		
	
			# Set the information.
			set(BINARY_FULL_NAME ${TARGET_FULL_NAME})
			# Check if a description was provided.
			if (NOT "${generate_resource_files_DESCRIPTION}" STREQUAL "")
				# Set the provided description.
				set(BINARY_DESCRIPTION ${generate_resource_files_DESCRIPTION})
			else()
				# Set the TARGET_FULL_NAME instead.
				set(BINARY_DESCRIPTION ${TARGET_FULL_NAME})
			endif()
			set(BINARY_ICON_INPUT_FILE ${generate_resource_files_ICON})
			
			# Get the current year for the copyright information.
			string(TIMESTAMP CURRENT_YEAR "%Y")
			# Get the output name of the target.
			get_target_property(OUTPUT_NAME ${TARGET_NAME} OUTPUT_NAME)
            # Check if an OUTPUT_NAME target property is set.
            string(FIND ${OUTPUT_NAME} "-NOTFOUND" OUTPUT_NAME_NOT_FOUND_POSITION REVERSE)
            if(NOT ${OUTPUT_NAME_NOT_FOUND_POSITION} EQUAL -1)
                # The OUTPUT_NAME target property, was NOT FOUND, i.e. it is not set.
                # Use the target name instead.
                set(OUTPUT_NAME ${TARGET_NAME})
            endif()
			# Get the debug postfix.
			get_target_property(DEBUG_POSTFIX ${TARGET_NAME} DEBUG_POSTFIX)

            # Check if target is an EXECUTABLE or a SHARED_LIBRARY
            if ( "${TARGET_TYPE}" STREQUAL "EXECUTABLE")
                # Set the filename suffix of an executable.
                set(BINARY_FILENAME_SUFFIX ${CMAKE_EXECUTABLE_SUFFIX})
            else()
                # Filename suffix of a shared library.
                set(BINARY_FILENAME_SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX})
            endif()
			
			# Check if a icon filename was provided.
			if (NOT "${BINARY_ICON_INPUT_FILE}" STREQUAL "")
                # Get the icon filename and extension.
                get_filename_component(BINARY_ICON_FILENAME "${BINARY_ICON_INPUT_FILE}" NAME_WE)
                get_filename_component(BINARY_ICON_EXTENSION "${BINARY_ICON_INPUT_FILE}" EXT)

				# Define where to copy the icon file.
                set(BINARY_ICON_OUTPUT_FILE ${OUTPUT_DIRECTORY}/icons/${BINARY_ICON_FILENAME}${BINARY_ICON_EXTENSION})

                # Copy the icon and add it to the sources.
                configure_file(${BINARY_ICON_INPUT_FILE} ${BINARY_ICON_OUTPUT_FILE} COPYONLY)
			endif ()

            # Differentiate output name between multi-config and single-config generator.
            if(GENERATOR_IS_MULTI_CONFIG)
                  set(BINARY_FILENAME ${OUTPUT_NAME}${BINARY_FILENAME_SUFFIX})
            else()
                # Check if Debug is the current configuration.
                if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
                    set(BINARY_FILENAME ${OUTPUT_NAME}${DEBUG_POSTFIX}${BINARY_FILENAME_SUFFIX})
                else()
                    set(BINARY_FILENAME ${OUTPUT_NAME}${BINARY_FILENAME_SUFFIX})
                endif()
            endif()
              
              # Fill out the templates.
            configure_file(${INPUT_TEMPLATE_HEADER_FILE} ${OUTPUT_DIRECTORY}/resource.h)
            configure_file(${INPUT_TEMPLATE_RESOURCE_FILE} ${OUTPUT_DIRECTORY}/resource.rc)
            
            # Set the GENERATED_RESOURCE_FILES in the parent scope.
            set(${TARGET_GENERATED_RESOURCE_FILES} 	${OUTPUT_DIRECTORY}/resource.h
                                                    ${OUTPUT_DIRECTORY}/resource.rc 
                                                    ${BINARY_ICON_OUTPUT_FILE}	
                                                    PARENT_SCOPE													
                                                )
		else()
			message(DEBUG "Cannot add binary information to target of type '${TARGET_TYPE}'")
		endif()
	endif()
								
endfunction()
