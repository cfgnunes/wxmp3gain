# ===============================================================================
# wxWidgets Find or Install Dependencies
# -------------------------------------------------------------------------------
# Find wxWidgets. If wxWidgets is not found, then they are automatically built.
# Aborts on error.
# ===============================================================================
macro(wxwidgets_find_or_install_dependencies)

    # Check if the user specified the paths to the wxWidgets sources and binaries.
    if(DEFINED wxWidgets_ROOT_DIR AND DEFINED wxWidgets_LIB_DIR)
        # Call the workaround to fix a problem in the CMake FindwxWidgets script.
        try_finding_wxwidgets()
    endif()

    # Try to use whichever version found.
    find_package(wxWidgets)
	
	# --------------------------------------------------------------------
	# Check if the wxWidgets have been built in a previous iteration of 
	# this macro.
	# --------------------------------------------------------------------
    if(NOT ${wxWidgets_FOUND})
        # wxWidgets was not found. Assume it has been automatically downloaded
        # and built in a previous iteration of this macro.

        # Set as a configurable CACHE variable.
        set(wxWidgets_ROOT_DIR ${wxwidgets_INSTALL_DIR} CACHE PATH "Base wxWidgets directory (e.g., C:/wxWidgets-2.6.3)." FORCE)
        # Set as a "normal" variable.
        set(wxWidgets_ROOT_DIR ${wxwidgets_INSTALL_DIR})

        # Add the wxWidgets root directory to the search path.
        set(CMAKE_PREFIX_PATH ${wxWidgets_ROOT_DIR})

        # For MinGW the LIB_DIR needs to be set.
       if(MINGW)
           # Set the path depending on the target architecture.
           if("${TARGET_ARCHITECTURE}" STREQUAL "amd64")
               # Set as a configurable CACHE variable.
               set(wxWidgets_LIB_DIR "${wxwidgets_INSTALL_DIR}/lib/gcc_x64_lib" CACHE PATH "Path to wxWidgets libraries (e.g., C:/wxWidgets-2.6.3/lib/vc_lib)." FORCE)
               # Set as a "normal" variable.
               set(wxWidgets_LIB_DIR "${wxwidgets_INSTALL_DIR}/lib/gcc_x64_lib")
           else()
               # Set as a configurable CACHE variable.
               set(wxWidgets_LIB_DIR "${wxwidgets_INSTALL_DIR}/lib/gcc_x32_lib" CACHE PATH "Path to wxWidgets libraries (e.g., C:/wxWidgets-2.6.3/lib/vc_lib)." FORCE)
               # Set as a "normal" variable.
               set(wxWidgets_LIB_DIR "${wxwidgets_INSTALL_DIR}/lib/gcc_x32_lib")
           endif()
       endif()

        # Call the workaround to fix a problem in the CMake FindwxWidgets script.
        try_finding_wxwidgets()

        # Now try to "really" find wxWidgets.
		find_package(wxWidgets)
    endif()

    # Check again if wxWidgets was found.
    if(${wxWidgets_FOUND})
        message(DEBUG "wxWidgets found. No need to get it.")

    else()
        # wxWidgets was not found!
        # Invoke the wxwidgets-dependency-helper project to get wxWidgets.
        wxwidgets_invoke_dependency_helper()

        # Call the workaround to fix a problem in the CMake FindwxWidgets script.
        try_finding_wxwidgets()
		
        # Check again, it should exist now.
        # This time it must be found (REQUIRED)
        message(DEBUG "Searching again for wxWidgets...")
        find_package(wxWidgets REQUIRED)

    endif()
endmacro()

# ===============================================================================
# Try finding wxWidgets
# -------------------------------------------------------------------------------
# When manually specifying the wxWidgets_LIB_DIR, find_package(wxWidgets) does
# not find the library during the configuration phase.
#
# A workaround is calling this function (must not be a macro!) once. Afterwards
# find_package(wxWidgets) will work without having to run the configuration phase
# twice.
# ===============================================================================
function(try_finding_wxwidgets)
    find_package(wxWidgets)
endfunction()
