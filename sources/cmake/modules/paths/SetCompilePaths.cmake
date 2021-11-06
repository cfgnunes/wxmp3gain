# ==============================================================================
# Compile paths                                                                 
# ==============================================================================
# Set target base path everything is compiled to.
set(TARGET_BASE_PATH "target/${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION_MAJOR}_${CMAKE_PROJECT_VERSION_MINOR}_${CMAKE_PROJECT_VERSION_PATCH}")

# Set path for executables.
if(NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${TARGET_BASE_PATH}/bin)
endif()

# Set path for shared libraries.
if(NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${TARGET_BASE_PATH}/bin)
endif()

# Set path for static libraries.
if(NOT DEFINED CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${TARGET_BASE_PATH}/lib)
endif()