# ===============================================================================
# wxWidgets Get Build Command
# -------------------------------------------------------------------------------
# Define the command to build wxWidgets, depending on the compiler.
# ===============================================================================
function(wxwidgets_get_build_command)
	
	# Loop over each configuration to build.
	foreach(wxwidgets_CONFIGURATION_TO_BUILD ${wxwidgets_CONFIGURATIONS_TO_BUILD})
		# Check if there is already a build command.
		if(DEFINED wxwidgets_BUILD_COMMAND)
			# Prepare the next build command.
			list(APPEND wxwidgets_BUILD_COMMAND "COMMAND" )
		endif()
		# Append the folder for the currently iterated configuration.
	    list(APPEND wxwidgets_BUILD_COMMAND ${CMAKE_COMMAND} --build ${wxwidgets_BUILD_DIR}/${wxwidgets_CONFIGURATION_TO_BUILD})
    endforeach()

    # -------------------------------------------------------------------------------
	# Set variables in the parent scope.
	# -------------------------------------------------------------------------------
	set(wxwidgets_BUILD_COMMAND ${wxwidgets_BUILD_COMMAND} PARENT_SCOPE)
	message(DEBUG "The command to build ${wxwidgets_EP_NAME}: '${wxwidgets_BUILD_COMMAND}'")
endfunction()
