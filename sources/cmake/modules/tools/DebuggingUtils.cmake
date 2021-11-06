# ===============================================================================
# Debugging Utilities
# ===============================================================================

# -------------------------------------------------------------------------------
# Get all targets and store them in 'var'.
# -------------------------------------------------------------------------------
function(get_all_targets var)
    set(targets)
    get_all_targets_recursive(targets ${CMAKE_CURRENT_SOURCE_DIR})
    set(${var} ${targets} PARENT_SCOPE)
endfunction()

macro(get_all_targets_recursive targets dir)
    get_property(subdirectories DIRECTORY ${dir} PROPERTY SUBDIRECTORIES)
    foreach(subdir ${subdirectories})
        get_all_targets_recursive(${targets} ${subdir})
    endforeach()

    get_property(current_targets DIRECTORY ${dir} PROPERTY BUILDSYSTEM_TARGETS)
    list(APPEND ${targets} ${current_targets})
endmacro()

# -------------------------------------------------------------------------------
# Dump all the CMAKE variables.
# -------------------------------------------------------------------------------
function(dump_cmake_variables)
    get_cmake_property(VARIABLE_NAMES VARIABLES)
    list (SORT VARIABLE_NAMES)
    foreach (VARIABLE_NAME ${VARIABLE_NAMES})
        if (ARGV0)
            unset(MATCHED)
            string(REGEX MATCH ${ARGV0} MATCHED ${VARIABLE_NAME})
            if (NOT MATCHED)
                continue()
            endif()
        endif()
        message(STATUS "${VARIABLE_NAME}=${${VARIABLE_NAME}}")
    endforeach()
endfunction()

# -------------------------------------------------------------------------------
# Dump all the CMAKE variables, containing a certain string.
# -------------------------------------------------------------------------------
# CONTAINED_STRING: Any string to search for.
# KEY_VALUE_OR_BOTH: If "KEY", only the variable name is considered, if
#                    "VALUE" the value of the variable is as well considered.
#                    If "BOTH", the variable is printed if the CONTAINED_STRING
#                    is occurring in either the KEY or the VALUE.
function(dump_cmake_variables_containing CONTAINED_STRING KEY_VALUE_OR_BOTH)
    # Get all variable names.
    get_cmake_property(VARIABLE_NAMES VARIABLES)
    # Sort alphabetically.
    list (SORT VARIABLE_NAMES)
    # Iterate each variable.
    foreach (VARIABLE_NAME ${VARIABLE_NAMES})
        # Check if KEY (Variable name) should be checked.
        if("${KEY_VALUE_OR_BOTH}" STREQUAL "KEY" OR "${KEY_VALUE_OR_BOTH}" STREQUAL "BOTH")
            # Search for the string in the variable name.
            string(FIND "${VARIABLE_NAME}" "${CONTAINED_STRING}" FOUND_AT_POSITION)
            # Check if it was found.
            if (NOT FOUND_AT_POSITION EQUAL -1)
                # The string was found, print the variable and its value.
                message(STATUS "${VARIABLE_NAME}=${${VARIABLE_NAME}}")
                # No need to print it again, if also the value contains the string.
                continue()
            endif()
        endif()
        # Check if VALUE should be checked.
        if("${KEY_VALUE_OR_BOTH}" STREQUAL "VALUE" OR "${KEY_VALUE_OR_BOTH}" STREQUAL "BOTH")
            # Search for the string in the value.
            string(FIND "${${VARIABLE_NAME}}" "${CONTAINED_STRING}" FOUND_AT_POSITION)
            # Check if it was found.
            if (NOT FOUND_AT_POSITION EQUAL -1)
                # The string was found, print the variable and its value.
                message(STATUS "${VARIABLE_NAME}=${${VARIABLE_NAME}}")
            endif()
        endif()
    endforeach()
endfunction()

# -------------------------------------------------------------------------------
# Generate a list of all CMake properties.
# -------------------------------------------------------------------------------
function(generate_cmake_property_list)
	# Generate a list with all CMake properties, if it does not yet exist.
	if(NOT DEFINED CMAKE_PROPERTY_LIST)
		# Get all properties that cmake supports
		execute_process(COMMAND ${CMAKE_COMMAND} --help-property-list OUTPUT_VARIABLE CMAKE_PROPERTY_LIST)

		# Convert command output into a CMake list
		STRING(REGEX REPLACE ";" "\\\\;" CMAKE_PROPERTY_LIST "${CMAKE_PROPERTY_LIST}")
		STRING(REGEX REPLACE "\n" ";" CMAKE_PROPERTY_LIST "${CMAKE_PROPERTY_LIST}")

		# Set the variable globally.
		set(CMAKE_PROPERTY_LIST ${CMAKE_PROPERTY_LIST} PARENT_SCOPE)
	endif()
endfunction()

# -------------------------------------------------------------------------------
# Print all properties of a target.
# -------------------------------------------------------------------------------
function(print_target_properties TARGET_NAME)
	# Make sure CMAKE_PROPERTY_LIST exists.
	generate_cmake_property_list()

	# Make sure the target exists.
    if(NOT TARGET ${TARGET_NAME})
      message("There is no target named '${TARGET_NAME}'")
      return()
    endif()

	# Iterate through the properties.
    foreach (ITERATED_PROPERTY ${CMAKE_PROPERTY_LIST})
    	# Replace all occurrances of <CONFIG> with the actual current CMAKE_BUILD_TYPE
    	# NOTE: This should not work on MSVS, which is why this is commented.
        # string(REPLACE "<CONFIG>" "${CMAKE_BUILD_TYPE}" ITERATED_PROPERTY ${ITERATED_PROPERTY})

        # Check if target is imported.
	    get_target_property(IS_IMPORTED ${TARGET_NAME} "IMPORTED")

	    # Skip checking for all "LOCATION" properties, if the target is imported.
	    # See https://stackoverflow.com/questions/32197663/how-can-i-remove-the-the-location-property-may-not-be-read-from-target-error-i
	    if((ITERATED_PROPERTY STREQUAL "LOCATION" OR ITERATED_PROPERTY MATCHES "^LOCATION_" OR ITERATED_PROPERTY MATCHES "_LOCATION$") AND NOT ${IS_IMPORTED} )
	        continue()
	    endif()

		# Get the value.
        get_target_property(ITERATED_PROPERTY_VALUE ${TARGET_NAME} ${ITERATED_PROPERTY})
        # Check if the value is set.
        if (ITERATED_PROPERTY_VALUE)
            # Print the target name, iterated property and it's value.
            message ("${TARGET_NAME} ${ITERATED_PROPERTY} = ${ITERATED_PROPERTY_VALUE}")
        endif()
    endforeach()
endfunction()
