# ===============================================================================
# Configure wxWidgets the way it should be used in the project.
# ===============================================================================
# Set the version.
# -------------------------------------------------------------------------------
if(MINGW)
   # Commit 9cc0c9a08 is known to work for MinGW.
   # The wxWidgets developers standardized the folder structure and naming
   # conventions when building via CMake after v3.1.5.
   set(wxwidgets_GIT_TAG "9cc0c9a08")
else()
   # Use version 3.1.5 by default.
   set(wxwidgets_GIT_TAG "v3.1.5")
endif()

# -------------------------------------------------------------------------------
# Load default settings, if not set and automatically detect further settings.
# -------------------------------------------------------------------------------
# Add the settings directory to load additional modules from.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/settings/")
# Set default settings.
include(wxWidgetsSettingsDefaults)

# ===============================================================================
# Download settings.
# ===============================================================================
set( wxwidgets_URL "https://github.com/wxWidgets/wxWidgets" )

