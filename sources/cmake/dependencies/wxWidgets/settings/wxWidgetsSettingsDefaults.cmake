# ===============================================================================
# Set some default settings, which can be overridden by the user.
# ===============================================================================
# Set the version.
# -------------------------------------------------------------------------------
if(NOT DEFINED wxwidgets_GIT_TAG)
	if(MINGW)
	   # Commit 9cc0c9a08 is known to work for MinGW.
	   # The wxWidgets developers standardized the folder structure and naming
	   # conventions when building via CMake after v3.1.5.
	   set(wxwidgets_GIT_TAG "9cc0c9a08")
	else()
	   # Use version 3.1.5 by default.
	   set(wxwidgets_GIT_TAG "v3.1.5")
	endif()
	message(WARNING "wxWidgets GIT tag is not set! Forcing to use ${wxwidgets_GIT_TAG}")
endif()

# -------------------------------------------------------------------------------
# Set the name for the external projects.
# -------------------------------------------------------------------------------
set(wxwidgets_EP_NAME "wxwidgets")
# Set the paths to the helper projects.
set(wxwidgets_HELPER_PROJECT_DIR "${CMAKE_MODULE_ROOT_FOLDER}/dependencies/wxWidgets")

# For MSVC build both Release and Debug configurations, else only Release.
if(MSVC)
	set(wxwidgets_CONFIGURATIONS_TO_BUILD Debug Release)
else()
	set(wxwidgets_CONFIGURATIONS_TO_BUILD Release)
endif()

# Check, if the user wants to build shared libraries.
if(DEFINED BUILD_SHARED_LIBS)
    # wxWidgets uses its own flag. Map the CMake flag.
    set(wxBUILD_SHARED ${BUILD_SHARED_LIBS})
else()
    # By default, shared libraries are build. 
    # Override to build static libraries. Else we would have to take care
    # about copying the shared libraries into the build and install folder.
    set(wxBUILD_SHARED FALSE)
endif()

# Build shared and static libraries into different folders.
If(${wxBUILD_SHARED})
    set(wxwidgets_LINK_STYLE "shared")
else()
    set(wxwidgets_LINK_STYLE "static")
endif()

# Other variables which could be set but are not really interesting:
# See https://docs.wxwidgets.org/3.1.5/overview_cmake.html
# Leaving them to their default values.

# -------------------------------------------------------------------------------
# Build, CMake, install, etc. directory specification.
# See ExternalProject_Add for details about placeholders in angle brackets, e.g.
# <BINARY_DIR>, etc.
# -------------------------------------------------------------------------------
set( wxwidgets_SOURCE_DIR "${CMAKE_EP_BASE_PATH}/Source/${wxwidgets_EP_NAME}")
set( wxwidgets_BUILD_DIR "${CMAKE_EP_BASE_PATH}/Build/${wxwidgets_EP_NAME}/${wxwidgets_GIT_TAG}/${COMPILER_NAME}/${TARGET_ARCHITECTURE}")
set( wxwidgets_STAMP_DIR "${CMAKE_EP_BASE_PATH}/Stamp/${wxwidgets_EP_NAME}/${COMPILER_NAME}/${TARGET_ARCHITECTURE}")
set( wxwidgets_LOG_DIR "${wxwidgets_STAMP_DIR}/logs")
set( wxwidgets_INSTALL_DIR "${CMAKE_EP_BASE_PATH}/Install/${wxwidgets_EP_NAME}/${wxwidgets_GIT_TAG}/${COMPILER_NAME}/${TARGET_ARCHITECTURE}/${wxwidgets_LINK_STYLE}")
