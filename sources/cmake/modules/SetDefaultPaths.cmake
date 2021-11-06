# ===============================================================================
# Set some default paths.
# ===============================================================================
# Set the following paths only if not already specified.
# -------------------------------------------------------------------------------
# Set the location of the project root.
if(NOT DEFINED CMAKE_PROJECT_ROOT)
	get_filename_component(CMAKE_PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
endif()

# Set the root folder, where all sources are located in.
if(NOT DEFINED CMAKE_SOURCES_ROOT_FOLDER)
	set(CMAKE_SOURCES_ROOT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# Set the root folder, where all custom CMake modules are located in.
if(NOT DEFINED CMAKE_MODULE_ROOT_FOLDER)
	set(CMAKE_MODULE_ROOT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
endif()

# Set a folder generated sourced should be put into.
if(NOT DEFINED CMAKE_GENERATED_SOURCES_FOLDER)
	set(CMAKE_GENERATED_SOURCES_FOLDER generated)
endif()

# Set a folder for the resources.
if(NOT DEFINED CMAKE_RESOURCES_FOLDER)
	set(CMAKE_RESOURCES_FOLDER resources)
endif()

# Set a folder for the dcoumentation.
if(NOT DEFINED CMAKE_DOC_FOLDER)
	set(CMAKE_DOC_FOLDER doc)
endif()

# Additionaly paths.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/paths")
# Set the user's directory in a variable.
include(SetUserDirectory)
# Set where the external projects / libraries should be downloaded and built.
include(SetExternalProjectsBasePath)
# Set where the output is compiled into.
include(SetCompilePaths)
# Set where the final executables, libraries, config and include files should be copied to.
include(SetInstallPaths)
