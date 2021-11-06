# Set the variable, depending on the operating system.
if(UNIX)
	set(USER_DIRECTORY "$ENV{HOME}" CACHE INTERNAL "")
elseif(WIN32)
	set(USER_DIRECTORY "$ENV{USERPROFILE}" CACHE INTERNAL "")
else()
	message(FATAL_ERROR "Could not set user directory!")
endif()