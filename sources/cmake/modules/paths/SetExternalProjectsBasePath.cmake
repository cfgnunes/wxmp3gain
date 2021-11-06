# The external projects base path is used to store project dependencies, which may by usable by
# other projects as well. The idea is to build up a local repository on your PC, similar to
# what other build tools like maven, gradle, etc. do.

set(CMAKE_EP_BASE_PATH_DESCRIPTION "The path where to download and build external project dependencies." INTERNAL "" )

# Check if an external project base path is defined as an environmental variable.
if(DEFINED ENV{CMAKE_EP_BASE_PATH})
	# Set the local variable to the value of the environmental one, converting it to a valid CMake path.
	file(TO_CMAKE_PATH $ENV{CMAKE_EP_BASE_PATH} CMAKE_EP_BASE_PATH)
endif()

# Check if an external project base path is defined, by e.g. an argument passed to CMAKE.
if(NOT DEFINED CMAKE_EP_BASE_PATH)
	# Set a default location to install shared, external projects, if the user
	# did not set an environmental variable <CMAKE_EP_BASE_PATH> for that purpose
	# or he did not pass a <CMAKE_EP_BASE_PATH> via the command line.
	message("CMake external project base path is not set! Setting default value!")

	# Try setting a sensible <CMAKE_EP_BASE_PATH_DESCRIPTION> for both Linux and Windows operating systems.
	if(UNIX)
		# Setting base path to subfolder in user directory. A globally accessible folder should be used instead.
		set(CMAKE_EP_BASE_PATH "${USER_DIRECTORY}/.repositories/cmake/" CACHE PATH "${CMAKE_EP_BASE_PATH_DESCRIPTION}" )
		
	elseif(WIN32)
		set(CMAKE_EP_BASE_PATH "$ENV{SYSTEMDRIVE}/Repositories/CMake/" CACHE PATH "${CMAKE_EP_BASE_PATH_DESCRIPTION}" )	

	endif()

endif()

# Check if the path already exists.
if(EXISTS ${CMAKE_EP_BASE_PATH})
	# The path does exist
	message(STATUS "External project base path is '${CMAKE_EP_BASE_PATH}'")	

else()
	# The path does not exist, create it!
	message(STATUS "Creating external project base path '${CMAKE_EP_BASE_PATH}'")	
	file(MAKE_DIRECTORY ${CMAKE_EP_BASE_PATH})

endif()

# Check again, if the CMAKE_EP_BASE_PATH exists. Could not be the case if not running
# on Unix or Windows, but any other OS.
if(DEFINED CMAKE_EP_BASE_PATH)
	# Set the external project base path.
	set_directory_properties(PROPERTIES EP_BASE "${CMAKE_EP_BASE_PATH}")
else()	
	message(WARNING "Base path to store external projects is not set! Using project folder.")
endif()
