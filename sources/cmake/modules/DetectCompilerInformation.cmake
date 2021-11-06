# See https://cmake.org/cmake/help/latest/variable/CMAKE_SIZEOF_VOID_P.html
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(COMPILER_BITNESS 64)
else()
	set(COMPILER_BITNESS 32)
endif()

# Set the compiler name.
string(TOLOWER ${CMAKE_CXX_COMPILER_ID} COMPILER_NAME)