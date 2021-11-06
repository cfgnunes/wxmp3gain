# ===============================================================================
# Set some default settings, which can be overridden by the user.
# ===============================================================================
# Set the version.
# -------------------------------------------------------------------------------
if(NOT DEFINED gettext_VERSION_MAJOR)
    set(gettext_VERSION_MAJOR 0)
    set(gettext_VERSION_MINOR 21)
    set(iconv_VERSION_MAJOR 1)
    set(iconv_VERSION_MINOR 16)
    set(gettext_SHA1 "c7741f20308d374afbe9adcdd4ac48bf47fa2240")
	message(WARNING "gettext version is not set! Forcing to use v${gettext_VERSION_MAJOR}.${gettext_VERSION_MINOR}")
endif()

# Set one version string.
set(gettext_VERSION "${gettext_VERSION_MAJOR}.${gettext_VERSION_MINOR}")

# -------------------------------------------------------------------------------
# Set the name for the external projects.
# -------------------------------------------------------------------------------
set(gettext_EP_NAME "gettext")
# Set the paths to the helper projects.
set(gettext_HELPER_PROJECT_DIR "${CMAKE_MODULE_ROOT_FOLDER}/dependencies/gettext")

# ------------------------------------------------------------------------------
# Configuration                                                                 
# ------------------------------------------------------------------------------
# Check, if the user defined the linkage type to download.
if(DEFINED gettext_LINK_STYLE)
    # Make sure it is lowercase
    string(TOLOWER ${gettext_LINK_STYLE} gettext_LINK_STYLE)
else()
    # Set "static" as default
    set(gettext_LINK_STYLE "shared")
endif()

# Check, if the user defined the architecture type to download.
if(NOT DEFINED gettext_ARCHITECTURE_TYPE)
    # Autodetect
    if("${TARGET_ARCHITECTURE}" STREQUAL "amd64")
        set(gettext_ARCHITECTURE_TYPE "64")
    else()
        set(gettext_ARCHITECTURE_TYPE "32")
    endif()
endif()

# -------------------------------------------------------------------------------
# Build, CMake, install, etc. directory specification.
# See ExternalProject_Add for details about placeholders in angle brackets, e.g.
# <BINARY_DIR>, etc.
# -------------------------------------------------------------------------------
set( gettext_SOURCE_DIR "${CMAKE_EP_BASE_PATH}/Source/${gettext_EP_NAME}/v${gettext_VERSION}")
set( gettext_STAMP_DIR "${CMAKE_EP_BASE_PATH}/Stamp/${gettext_EP_NAME}/v${gettext_VERSION}")
set( gettext_LOG_DIR "${gettext_STAMP_DIR}/logs")
set( gettext_INSTALL_DIR "${CMAKE_EP_BASE_PATH}/Install/${gettext_EP_NAME}/v${gettext_VERSION}")