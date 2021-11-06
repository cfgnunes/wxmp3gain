# ===============================================================================
# gettext Get Configure Command
# -------------------------------------------------------------------------------
# Define the command to configure gettext, depending on the compiler.
# ===============================================================================
function(gettext_get_configure_command)

	# Loop over each configuration to build.
	foreach(gettext_CONFIGURATION_TO_BUILD ${gettext_CONFIGURATIONS_TO_BUILD})

		# Check if there is already a configure command.
		if(DEFINED gettext_CONFIGURE_COMMAND)
			# Prepare the next configuration command.
			list(APPEND gettext_CONFIGURE_COMMAND "COMMAND" )
		endif()
		
		# Start with calling cmake.exe
	    list(APPEND gettext_CONFIGURE_COMMAND ${CMAKE_COMMAND})
	
	    # -------------------------------------------------------------------------------
	    # Build up the arguments.
	    # -------------------------------------------------------------------------------
	    # Source folder.
	    list(APPEND gettext_CONFIGURE_COMMAND "-S${gettext_SOURCE_DIR}")	    

		# Build folder.
		list(APPEND gettext_CONFIGURE_COMMAND "-B${gettext_BUILD_DIR}/${gettext_CONFIGURATION_TO_BUILD}")
	
	    # Define the generator, depending on the compiler.
		if(MSVC)
	        # Use NMake makefiles in order to build from command line, instead of the
	        # MS Visual Studio IDE.
	        list(APPEND gettext_CONFIGURE_COMMAND "-GNMake Makefiles")
		elseif(MINGW)
	        # Use MinGW makefiles in order to build from command line, instead of the
	        # Eclipse CDT or Code::Blocks IDE.
	        list(APPEND gettext_CONFIGURE_COMMAND "-GMinGW Makefiles")
	    else()
	        # Use the same generator as the main project.
	        list(APPEND gettext_CONFIGURE_COMMAND "-G${CMAKE_GENERATOR}")
		endif()
	
	    # Debug level.
	    list(APPEND gettext_CONFIGURE_COMMAND "--loglevel=DEBUG")
	
	    # Set the currently iterated build configuration.
	    set(CMAKE_BUILD_TYPE ${gettext_CONFIGURATION_TO_BUILD})
	
	    # Forward arguments passed with the '-D' flag.
	    list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS CMAKE_BUILD_TYPE)
	    
	    # Do NOT forward the toolchain file!
	    # Else the CMAKE_*_FLAGS cannot be overriden and additionally the settings CMAKE_CXX_VISIBILITY_PRESET 
	    # and CMAKE_VISIBILITY_INLINES_HIDDEN throw errors.
	    list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS CMAKE_C_FLAGS)
	    list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS CMAKE_CXX_FLAGS)
	    list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS CMAKE_C_COMPILER)
	    list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS CMAKE_CXX_COMPILER)
	    if(MINGW)
	    	list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS CMAKE_RC_COMPILER)
	    endif()
	
	    list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS BUILD_SHARED_LIBS)
	    list(APPEND gettext_CONFIGURE_COMMAND_ARGUMENTS wxBUILD_SHARED)
	    
	    # Append to list of arguments to pass.
	    foreach(gettext_CONFIGURE_COMMAND_ARGUMENT ${gettext_CONFIGURE_COMMAND_ARGUMENTS})
	        if(DEFINED gettext_CONFIGURE_COMMAND_ARGUMENT AND NOT "${${gettext_CONFIGURE_COMMAND_ARGUMENT}}" STREQUAL "")
	            list(APPEND gettext_CONFIGURE_COMMAND "-D${gettext_CONFIGURE_COMMAND_ARGUMENT}=${${gettext_CONFIGURE_COMMAND_ARGUMENT}}")        	
	        endif()
	    endforeach()
	
	    # Set the install folder.
	    list(APPEND gettext_CONFIGURE_COMMAND "-DCMAKE_INSTALL_PREFIX=${gettext_INSTALL_DIR}")
    endforeach()

	# -------------------------------------------------------------------------------
	# Set variables in the parent scope.
	# -------------------------------------------------------------------------------
	set(gettext_CONFIGURE_COMMAND ${gettext_CONFIGURE_COMMAND} PARENT_SCOPE)
	message(DEBUG "The command to configure ${gettext_EP_NAME}: '${gettext_CONFIGURE_COMMAND}'")
endfunction()
