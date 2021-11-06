# ===============================================================================
# gettext Get Build Command
# -------------------------------------------------------------------------------
# Define the command to build gettext, depending on the compiler.
# ===============================================================================
function(gettext_get_build_command)
	
	# Loop over each configuration to build.
	foreach(gettext_CONFIGURATION_TO_BUILD ${gettext_CONFIGURATIONS_TO_BUILD})
		# Check if there is already a build command.
		if(DEFINED gettext_BUILD_COMMAND)
			# Prepare the next build command.
			list(APPEND gettext_BUILD_COMMAND "COMMAND" )
		endif()
		# Append the folder for the currently iterated configuration.
	    list(APPEND gettext_BUILD_COMMAND ${CMAKE_COMMAND} --build ${gettext_BUILD_DIR}/${gettext_CONFIGURATION_TO_BUILD})
    endforeach()

    # -------------------------------------------------------------------------------
	# Set variables in the parent scope.
	# -------------------------------------------------------------------------------
	set(gettext_BUILD_COMMAND ${gettext_BUILD_COMMAND} PARENT_SCOPE)
	message(DEBUG "The command to build ${gettext_EP_NAME}: '${gettext_BUILD_COMMAND}'")
endfunction()
