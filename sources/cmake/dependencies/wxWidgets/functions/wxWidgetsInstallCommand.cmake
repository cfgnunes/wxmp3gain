# ===============================================================================
# wxWidgets Get Install Command
# -------------------------------------------------------------------------------
# Define the command to install wxWidgets, depending on the compiler.
# ===============================================================================
function(wxwidgets_get_install_command)

	# Loop over each configuration to install.
	foreach(wxwidgets_CONFIGURATION_TO_BUILD ${wxwidgets_CONFIGURATIONS_TO_BUILD})
		# Check if there is already a install command.
		if(DEFINED wxwidgets_INSTALL_COMMAND)
			# Prepare the next install command.
			list(APPEND wxwidgets_INSTALL_COMMAND "COMMAND" )
		endif()
		# Append the folder for the currently iterated configuration.
	    list(APPEND wxwidgets_INSTALL_COMMAND ${CMAKE_COMMAND} --install ${wxwidgets_BUILD_DIR}/${wxwidgets_CONFIGURATION_TO_BUILD})
    endforeach()

	# -------------------------------------------------------------------------------
	# Set variables in the parent scope.
	# -------------------------------------------------------------------------------
	set(wxwidgets_INSTALL_COMMAND ${wxwidgets_INSTALL_COMMAND} PARENT_SCOPE)
	message(DEBUG "The command to install ${wxwidgets_EP_NAME}: '${wxwidgets_INSTALL_COMMAND}'")
endfunction()
