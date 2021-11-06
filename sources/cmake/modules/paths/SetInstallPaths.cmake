# ===============================================================================
# Set the folders to install the project.
# ===============================================================================
# Set platform dependent folder paths.
if(UNIX)
	# Use the typical UNIX style paths.
	include(GNUInstallDirs)

    # ==============================================================================
    # Desktop Launchers                                                             
    # ==============================================================================
    # Assume the project is built for a freedesktop.org compliant OS.
    # See https://en.wikipedia.org/wiki/Freedesktop.org
    # ------------------------------------------------------------------------------
    # Set the folders for launcher files (*.desktop).
    # See https://www.freedesktop.org/wiki/Specifications/desktop-entry-spec/
    set(CMAKE_UNIX_LAUNCHER_USER "${USER_DIRECTORY}/.local/${CMAKE_INSTALL_DATADIR}/applications")
    # Make sure .desktop files are not put into `/usr/local/share/applications`, where
    # they are not found.
    set(CMAKE_UNIX_LAUNCHER_GLOBAL "/usr/${CMAKE_INSTALL_DATADIR}/applications")

    # The path where the resources are installed to.
    set(CMAKE_INSTALL_RESOURCESDIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}/${CMAKE_PROJECT_NAME}/${CMAKE_RESOURCES_FOLDER}")
else()
    set(CMAKE_INSTALL_BINDIR "${CMAKE_INSTALL_PREFIX}")
    set(CMAKE_INSTALL_DOCDIR "docs")

    # The path where the resources are installed to.
    set(CMAKE_INSTALL_RESOURCESDIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_RESOURCES_FOLDER}")
endif()

# Set some additional paths.
set(EXPORT_INSTALL_DIR "cmake" CACHE PATH "Folder into which the export files are installed.")	
set(CONFIG_INSTALL_DIR "config" CACHE PATH "Folder into which the configuration files are installed.")
set(LICENSE_INSTALL_DIR "licenses" CACHE PATH "Folder into which the license files are installed.")