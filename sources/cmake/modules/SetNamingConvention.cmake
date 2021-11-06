# ===============================================================================
# Naming convention for the assemblies.
# ===============================================================================

# -------------------------------------------------------------------------------
# Generate the identifiers.
# -------------------------------------------------------------------------------
# Postfix for debug assemblies.
set(DEBUG_POSTFIX "-d")

# Compiler ID.
string(TOLOWER ${CMAKE_CXX_COMPILER_ID} OUTPUT_NAME_COMPILER_ID)

# -------------------------------------------------------------------------------
# Get the compiler version.
# -------------------------------------------------------------------------------
if(MSVC)
    # Use the MSVC_TOOLSET_VERSION instead for MSVC.
    string(APPEND OUTPUT_NAME_COMPILER_INFORMATION ${OUTPUT_NAME_COMPILER_ID} ${MSVC_TOOLSET_VERSION})

else()
    string(REGEX MATCHALL "[0-9]+" OUTPUT_NAME_COMPILER_VERSION ${CMAKE_CXX_COMPILER_VERSION})
    # Get only the mayor version.
    list(GET OUTPUT_NAME_COMPILER_VERSION 0 OUTPUT_NAME_COMPILER_VERSION_MAYOR)

    string(APPEND OUTPUT_NAME_COMPILER_INFORMATION ${OUTPUT_NAME_COMPILER_ID} ${OUTPUT_NAME_COMPILER_VERSION_MAYOR})
endif()

# -------------------------------------------------------------------------------
# Method to change the properties of a target.
# -------------------------------------------------------------------------------
function(set_naming_convention TARGET_NAME)
	message(TRACE "Target name is: ${TARGET_NAME}")
	set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME "${TARGET_NAME}-${OUTPUT_NAME_COMPILER_INFORMATION}-${TARGET_ARCHITECTURE}-${CMAKE_PROJECT_VERSION_MAJOR}_${CMAKE_PROJECT_VERSION_MINOR}_${CMAKE_PROJECT_VERSION_PATCH}")
	set_debug_postfix(${TARGET_NAME})
endfunction()

# Function to set the debug postfix.
function(set_debug_postfix TARGET_NAME)
	message(TRACE "Setting debug postfix to '-d' for target: ${TARGET_NAME}")
	set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "-d")
endfunction()