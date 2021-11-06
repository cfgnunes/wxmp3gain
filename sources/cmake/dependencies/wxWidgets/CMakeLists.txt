# ===============================================================================
# Initialization
# ===============================================================================
cmake_minimum_required(VERSION 3.16.3)

# Set the project name and version.
project(wxwidgets-dependency-helper VERSION 1.0.0.0
			DESCRIPTION "Helper project to get wxWidgets during CMake configuration phase."
    )

# Include the standardized initialization routine valid for all projects.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_MODULE_ROOT_FOLDER}")
include(Initialization)
# Save the directory.
set(wxwidgets_CMAKE_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Specify the C++ standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ===============================================================================
# Project dependencies.
# ===============================================================================
# Load wxWidgets modules.
# -------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${wxwidgets_CMAKE_SOURCE_DIR}")
include(wxWidgetsSettings)
include(wxWidgetsFunctions)

# -------------------------------------------------------------------------------
# Create commands to configure, build and install wxWidgets.
# -------------------------------------------------------------------------------
wxwidgets_get_configure_command()
wxwidgets_get_build_command()
wxwidgets_get_install_command()

# -------------------------------------------------------------------------------
# Include wxWidgets as an external project, to be downloaded by this project.
# -------------------------------------------------------------------------------
include(wxWidgetsExternalProject)
