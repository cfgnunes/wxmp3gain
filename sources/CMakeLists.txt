# ==============================================================================
# Initialization                                                                
# ==============================================================================
cmake_minimum_required(VERSION 3.16.3)

# Configure the project.
project(wxMP3gain   VERSION 4.2.0.0
                    DESCRIPTION "wxMP3gain is a free front-end for the MP3gain."
                    HOMEPAGE_URL "https://github.com/cfgnunes/wxmp3gain")

# Include a initialization routine.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/")
include(Initialization)

# Specify the C++ standard for the project.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ==============================================================================
# Project dependencies.                                                         
# ==============================================================================
# wxWidgets
# -------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_MODULE_ROOT_FOLDER}/dependencies/wxWidgets")
include(wxWidgetsSettings)
include(wxWidgetsFunctions)

# Search for wxWidgets or install if not found.
wxwidgets_find_or_install_dependencies()

# ------------------------------------------------------------------------------
# Gettext                                                                       
# ------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_MODULE_ROOT_FOLDER}/dependencies/gettext")
include(GettextSettings)
include(GettextFunctions)

# Search for gettext or install if not found.
gettext_find_or_install_dependencies()

# Set compiler parameters
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s -O3 -Wall -Wextra -Wpedantic")
endif()

# ==============================================================================
# Building the binaries.                                                        
# ==============================================================================
# Templates
# ------------------------------------------------------------------------------
add_subdirectory(templates)

# ------------------------------------------------------------------------------
# Applications                                                                  
# ------------------------------------------------------------------------------
# Add the main application.
add_subdirectory(wxmp3gain)
