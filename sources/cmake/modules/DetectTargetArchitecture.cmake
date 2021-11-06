# ===============================================================================
# Detect the target architecture, if it is not defined in the toolchain.
# ===============================================================================

# Check if the target architecture is defined in the toolchain.
if(NOT DEFINED TARGET_ARCHITECTURE)
	# The CMAKE_GENERATOR_PLATFORM is used together with Microsoft Visual Studio, check if it is defined and not empty.
	if (DEFINED CMAKE_GENERATOR_PLATFORM AND NOT "${CMAKE_GENERATOR_PLATFORM}" STREQUAL "")
		
		# If it is defined, check which is the value and rename accordingly.
		if(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")
			# Set target architecture to Intel x86.
			set(TARGET_ARCHITECTURE "x86")
		elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")
			# Set target architecture to AMD 64.
			set(TARGET_ARCHITECTURE "amd64")
		else()
			# Set target architecture to the value of CMAKE_GENERATOR_PLATFORM.
			# Possible other values are 'ARM' or 'ARM64'.
			string(TOLOWER ${CMAKE_GENERATOR_PLATFORM} _GENERATOR_PLATFORM)
			set (TARGET_ARCHITECTURE ${_GENERATOR_PLATFORM})
		endif()	
	else()
		# Fallback to CMAKE_SYSTEM_PROCESSOR.
		string(TOLOWER ${CMAKE_SYSTEM_PROCESSOR} _SYSTEM_PROCESSOR)
		set (TARGET_ARCHITECTURE ${_SYSTEM_PROCESSOR})

        # Replace x86_64 with amd64
        if(${TARGET_ARCHITECTURE} STREQUAL "x86_64")
            set(TARGET_ARCHITECTURE "amd64")
        endif()
        message(DEBUG "Inferred target architecture '${TARGET_ARCHITECTURE}' from system processor!")
	endif ()
endif ()
