# ===============================================================================
# gettext Find or Install Dependencies
# -------------------------------------------------------------------------------
# Find gettext. If gettext is not found, then they are automatically built.
# Aborts on error.
# ===============================================================================
macro(gettext_find_or_install_dependencies)
    message(DEBUG "Searching for gettext.")

    # Search for dependencies differently on Windows and Linux.
    if(WIN32)

        # First, try to find it directly, in the PATH variable.
        # Maybe it is already installed via e.g. MSYS2?
        find_package(Gettext)

        # Check if it was found.
        if(NOT "${GETTEXT_FOUND}")
            # If it was not found, check if it was already downloaded
            # and installed.
            message(DEBUG "Searching for gettext on Windows in '${gettext_INSTALL_DIR}/bin'")
            list(APPEND CMAKE_PREFIX_PATH "${gettext_INSTALL_DIR}/bin")
            # Try to use whichever version found.
            find_package(Gettext)
        endif()

    else()
        # On Linux, check if the user installed the dependencies via e.g. the package
        # manager.
        find_package(Gettext)

    endif()
	
	# --------------------------------------------------------------------
	# Check if gettext has been build in a previous iteration of 
	# this macro.
	# --------------------------------------------------------------------
    # Check if gettext is found.
    if(${GETTEXT_FOUND})
        message(DEBUG "gettext found. No need to get it.")

    else()
        message(DEBUG "gettext NOT found. Getting it.")

        # gettext was not found!
        # Invoke the gettext-dependency-helper project to get gettext.
        gettext_invoke_dependency_helper()
		
        # Check again, it should exist now.
        # This time it must be found (REQUIRED)
        message(DEBUG "Searching again for gettext...")
        
        find_package(Gettext REQUIRED)

    endif()
endmacro()