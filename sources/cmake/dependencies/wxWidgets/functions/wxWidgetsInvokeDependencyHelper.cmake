# ===============================================================================
# wxWidgets Invoke Dependency Helper
# -------------------------------------------------------------------------------
# Invoke the wxwidgets-dependency-helper project to download, extract, build and
# install wxWidgets.
# ===============================================================================
function(wxwidgets_invoke_dependency_helper)

	# Inform the user about missing components.
	message("Preparing to download, build and install the missing wxWidgets libraries.")

	# Set the build directory.
	set( wxwidgets-dependency-helper_BUILD_DIR "${CMAKE_BINARY_DIR}/dependencies/wxwidgets-dependency-helper")

	# -------------------------------------------------------------------------------
	# Build up the arguments.
	# -------------------------------------------------------------------------------
	# Build folder.
	list(APPEND wxwidgets-dependency-helper_ARGUMENT_LIST "-B${wxwidgets-dependency-helper_BUILD_DIR}")
	# CMake Generator
	if(DEFINED CMAKE_GENERATOR AND NOT ${CMAKE_GENERATOR} STREQUAL "")
		list(APPEND wxwidgets-dependency-helper_ARGUMENT_LIST "-G${CMAKE_GENERATOR}")
	endif()
	# CMake Platform.
	if(DEFINED CMAKE_GENERATOR_PLATFORM AND NOT ${CMAKE_GENERATOR_PLATFORM} STREQUAL "")
		list(APPEND wxwidgets-dependency-helper_ARGUMENT_LIST "-A${CMAKE_GENERATOR_PLATFORM}")
	endif()

	# Debug level.
	list(APPEND wxwidgets-dependency-helper_ARGUMENT_LIST "--loglevel=DEBUG")
	# Forward arguments passed with the '-D' flag.
	list(APPEND wxwidgets-dependency-helper_ARGUMENTS CMAKE_BUILD_TYPE)
	list(APPEND wxwidgets-dependency-helper_ARGUMENTS CMAKE_MODULE_ROOT_FOLDER)
    	list(APPEND wxwidgets-dependency-helper_ARGUMENTS CMAKE_EP_BASE_PATH)
	list(APPEND wxwidgets-dependency-helper_ARGUMENTS CMAKE_TOOLCHAIN_FILE)
	list(APPEND wxwidgets-dependency-helper_ARGUMENTS BUILD_SHARED_LIBS)
	# Append to list of arguments to pass.
	foreach(wxwidgets-dependency-helper_ARGUMENT ${wxwidgets-dependency-helper_ARGUMENTS})
		if(DEFINED ${wxwidgets-dependency-helper_ARGUMENT} AND NOT ${${wxwidgets-dependency-helper_ARGUMENT}} STREQUAL "")
			list(APPEND wxwidgets-dependency-helper_ARGUMENT_LIST "-D${wxwidgets-dependency-helper_ARGUMENT}=${${wxwidgets-dependency-helper_ARGUMENT}}")
		endif()
	endforeach()

	# Inform the user, that the 'wxwidgets-dependency-helper' project gets configured.
	message("Configuring 'wxwidgets-dependency-helper' project to get missing wxWidgets.")

	execute_process(
		COMMAND ${CMAKE_COMMAND} ${wxwidgets-dependency-helper_ARGUMENT_LIST}
		WORKING_DIRECTORY ${wxwidgets_HELPER_PROJECT_DIR}
	)

	# Inform the user, that the missing components will now be built.
	message("Actually download, extract, build and install wxWidgets into the CMAKE_EP_BASE_PATH.")
	execute_process(
		COMMAND ${CMAKE_COMMAND} --build .
		WORKING_DIRECTORY ${wxwidgets-dependency-helper_BUILD_DIR}
	)
endfunction()
