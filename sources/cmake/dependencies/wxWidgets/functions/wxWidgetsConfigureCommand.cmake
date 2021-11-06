# ===============================================================================
# wxWidgets Get Configure Command
# -------------------------------------------------------------------------------
# Define the command to configure wxWidgets, depending on the compiler.
# ===============================================================================
function(wxwidgets_get_configure_command)

	# Loop over each configuration to build.
	foreach(wxwidgets_CONFIGURATION_TO_BUILD ${wxwidgets_CONFIGURATIONS_TO_BUILD})

		# Check if there is already a configure command.
		if(DEFINED wxwidgets_CONFIGURE_COMMAND)
			# Prepare the next configuration command.
			list(APPEND wxwidgets_CONFIGURE_COMMAND "COMMAND" )
		endif()
		
		# Start with calling cmake.exe
	    list(APPEND wxwidgets_CONFIGURE_COMMAND ${CMAKE_COMMAND})
	
	    # -------------------------------------------------------------------------------
	    # Build up the arguments.
	    # -------------------------------------------------------------------------------
	    # Source folder.
	    list(APPEND wxwidgets_CONFIGURE_COMMAND "-S${wxwidgets_SOURCE_DIR}")	    

		# Build folder.
		list(APPEND wxwidgets_CONFIGURE_COMMAND "-B${wxwidgets_BUILD_DIR}/${wxwidgets_CONFIGURATION_TO_BUILD}")
	
	    # Define the generator, depending on the compiler.
		if(MSVC)
	        # Use NMake makefiles in order to build from command line, instead of the
	        # MS Visual Studio IDE.
	        list(APPEND wxwidgets_CONFIGURE_COMMAND "-GNMake Makefiles")
		elseif(MINGW)
	        # Use MinGW makefiles in order to build from command line, instead of the
	        # Eclipse CDT or Code::Blocks IDE.
	        list(APPEND wxwidgets_CONFIGURE_COMMAND "-GMinGW Makefiles")
	    else()
	        # Use the same generator as the main project.
	        list(APPEND wxwidgets_CONFIGURE_COMMAND "-G${CMAKE_GENERATOR}")
		endif()
	
	    # Debug level.
	    list(APPEND wxwidgets_CONFIGURE_COMMAND "--loglevel=DEBUG")
	
	    # Set the currently iterated build configuration.
	    set(CMAKE_BUILD_TYPE ${wxwidgets_CONFIGURATION_TO_BUILD})
	    
	    # Forward arguments passed with the '-D' flag.
	    list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS CMAKE_BUILD_TYPE)
	    
	    # Do NOT forward the toolchain file!
	    # Else the CMAKE_*_FLAGS cannot be overriden and additionally the settings CMAKE_CXX_VISIBILITY_PRESET 
	    # and CMAKE_VISIBILITY_INLINES_HIDDEN throw errors.
	    list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS CMAKE_C_FLAGS)
	    list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS CMAKE_CXX_FLAGS)
	    list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS CMAKE_C_COMPILER)
	    list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS CMAKE_CXX_COMPILER)
	    if(MINGW)
	    	list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS CMAKE_RC_COMPILER)
	    endif()
	
	    list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS BUILD_SHARED_LIBS)
	    list(APPEND wxwidgets_CONFIGURE_COMMAND_ARGUMENTS wxBUILD_SHARED)
	    
	    # Append to list of arguments to pass.
	    foreach(wxwidgets_CONFIGURE_COMMAND_ARGUMENT ${wxwidgets_CONFIGURE_COMMAND_ARGUMENTS})
	        if(DEFINED wxwidgets_CONFIGURE_COMMAND_ARGUMENT AND NOT "${${wxwidgets_CONFIGURE_COMMAND_ARGUMENT}}" STREQUAL "")
	            list(APPEND wxwidgets_CONFIGURE_COMMAND "-D${wxwidgets_CONFIGURE_COMMAND_ARGUMENT}=${${wxwidgets_CONFIGURE_COMMAND_ARGUMENT}}")        	
	        endif()
	    endforeach()
	
	    # Set the install folder.
	    list(APPEND wxwidgets_CONFIGURE_COMMAND "-DCMAKE_INSTALL_PREFIX=${wxwidgets_INSTALL_DIR}")
    endforeach()

	# -------------------------------------------------------------------------------
	# Set variables in the parent scope.
	# -------------------------------------------------------------------------------
	set(wxwidgets_CONFIGURE_COMMAND ${wxwidgets_CONFIGURE_COMMAND} PARENT_SCOPE)
	message(DEBUG "The command to configure ${wxwidgets_EP_NAME}: '${wxwidgets_CONFIGURE_COMMAND}'")
endfunction()
