# ===============================================================================
# Inform the user about the CMake project settings.
# ===============================================================================
# CMake settings
# -------------------------------------------------------------------------------
if(DEFINED CMAKE_TOOLCHAIN_FILE)
	# Prevent annoying message that CMAKE_TOOLCHAIN_FILE is not used when
	# building, but only on configuration.
	message(DEBUG "Using toolchain file: '${CMAKE_TOOLCHAIN_FILE}'")

	# Set it as a cache variable.
	set(CMAKE_TOOLCHAIN_FILE ${CMAKE_TOOLCHAIN_FILE} CACHE FILEPATH "The path to the toolchain file.")
endif()

# Check if CMAKE_GENERATOR_PLATFORM exists and is not an empty string.
if((DEFINED CMAKE_GENERATOR_PLATFORM) AND (NOT ${CMAKE_GENERATOR_PLATFORM} STREQUAL ""))
	message(STATUS "Platform is: '${CMAKE_GENERATOR_PLATFORM}'")
endif()

# -------------------------------------------------------------------------------
# Target architecture and used compiler.
# -------------------------------------------------------------------------------
message(VERBOSE "Detected compiler is ${COMPILER_BITNESS}bit.")
message(VERBOSE "Target architecture is '${TARGET_ARCHITECTURE}'.")

# -------------------------------------------------------------------------------
# Paths
# -------------------------------------------------------------------------------
message(VERBOSE "The project root folder is ${CMAKE_PROJECT_ROOT}")
message(DEBUG "All executables are put into ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}.")
message(DEBUG "All dynamic libraries are put into ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}.")
message(DEBUG "All static and import libraries are put into ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}.")
message(VERBOSE "Found user directory '${USER_DIRECTORY}'")