# ===============================================================================
# gettext Get Install Command
# -------------------------------------------------------------------------------
# Define the command to install gettext, depending on the compiler.
# ===============================================================================
function(gettext_get_install_command)

    # Append the folder for the currently iterated configuration.
    list(APPEND gettext_INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory "${gettext_SOURCE_DIR}" "${gettext_INSTALL_DIR}")

	# -------------------------------------------------------------------------------
	# Set variables in the parent scope.
	# -------------------------------------------------------------------------------
	set(gettext_INSTALL_COMMAND ${gettext_INSTALL_COMMAND} PARENT_SCOPE)
	message(DEBUG "The command to install ${gettext_EP_NAME}: '${gettext_INSTALL_COMMAND}'")
endfunction()
