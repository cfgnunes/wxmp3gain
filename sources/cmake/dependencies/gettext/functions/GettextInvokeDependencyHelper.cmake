# ===============================================================================
# gettext Invoke Dependency Helper
# -------------------------------------------------------------------------------
# Invoke the gettext-dependency-helper project to download, extract, build and
# install gettext.
# ===============================================================================
function(gettext_invoke_dependency_helper)

	# Inform the user about missing components.
	message("Preparing to download and install the missing gettext executables.")

	# Set the build directory.
	set( gettext-dependency-helper_BUILD_DIR "${CMAKE_BINARY_DIR}/dependencies/gettext-dependency-helper")

	# -------------------------------------------------------------------------------
	# Build up the arguments.
	# -------------------------------------------------------------------------------
	# Build folder.
	list(APPEND gettext-dependency-helper_ARGUMENT_LIST "-B${gettext-dependency-helper_BUILD_DIR}")
	# CMake Generator
	if(DEFINED CMAKE_GENERATOR AND NOT ${CMAKE_GENERATOR} STREQUAL "")
		list(APPEND gettext-dependency-helper_ARGUMENT_LIST "-G${CMAKE_GENERATOR}")
	endif()
	# CMake Platform.
	if(DEFINED CMAKE_GENERATOR_PLATFORM AND NOT ${CMAKE_GENERATOR_PLATFORM} STREQUAL "")
		list(APPEND gettext-dependency-helper_ARGUMENT_LIST "-A${CMAKE_GENERATOR_PLATFORM}")
	endif()

	# Debug level.
	list(APPEND gettext-dependency-helper_ARGUMENT_LIST "--loglevel=DEBUG")
	# Forward arguments passed with the '-D' flag.
	list(APPEND gettext-dependency-helper_ARGUMENTS CMAKE_MODULE_ROOT_FOLDER)
    	list(APPEND gettext-dependency-helper_ARGUMENTS CMAKE_EP_BASE_PATH)
	list(APPEND gettext-dependency-helper_ARGUMENTS CMAKE_TOOLCHAIN_FILE)
	# Append to list of arguments to pass.
	foreach(gettext-dependency-helper_ARGUMENT ${gettext-dependency-helper_ARGUMENTS})
		if(DEFINED ${gettext-dependency-helper_ARGUMENT} AND NOT ${${gettext-dependency-helper_ARGUMENT}} STREQUAL "")
			list(APPEND gettext-dependency-helper_ARGUMENT_LIST "-D${gettext-dependency-helper_ARGUMENT}=${${gettext-dependency-helper_ARGUMENT}}")
		endif()
	endforeach()

	# Inform the user, that the 'gettext-dependency-helper' project gets configured.
	message("Configuring 'gettext-dependency-helper' project to get missing gettext.")

	execute_process(
		COMMAND ${CMAKE_COMMAND} ${gettext-dependency-helper_ARGUMENT_LIST}
		WORKING_DIRECTORY ${gettext_HELPER_PROJECT_DIR}
	)

	# Inform the user, that the missing components will now be built.
	message("Actually download, extract, build and install gettext into the CMAKE_EP_BASE_PATH.")
	execute_process(
		COMMAND ${CMAKE_COMMAND} --build .
		WORKING_DIRECTORY ${gettext-dependency-helper_BUILD_DIR}
	)
endfunction()
