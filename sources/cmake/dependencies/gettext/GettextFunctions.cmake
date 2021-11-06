# ===============================================================================
# Functions to help add the gettext library as a dependency
# of the project.
# ===============================================================================

# -------------------------------------------------------------------------------
# gettext
# -------------------------------------------------------------------------------
# Add the settings directory to load additional modules from.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/functions")
# Load all files defining functions.
include(GettextConfigureCommand)
include(GettextBuildCommand)
include(GettextInstallCommand)
include(GettextInvokeDependencyHelper)
include(GettextFindOrInstallDependencies)
