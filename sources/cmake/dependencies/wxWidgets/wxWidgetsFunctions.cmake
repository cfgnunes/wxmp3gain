# ===============================================================================
# Functions to help add the wxWidgets library as a dependency
# of the project.
# ===============================================================================

# -------------------------------------------------------------------------------
# wxWidgets
# -------------------------------------------------------------------------------
# Add the settings directory to load additional modules from.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/functions")
# Load all files defining functions.
include(wxWidgetsConfigureCommand)
include(wxWidgetsBuildCommand)
include(wxWidgetsInstallCommand)
include(wxWidgetsInvokeDependencyHelper)
include(wxWidgetsFindOrInstallDependencies)
