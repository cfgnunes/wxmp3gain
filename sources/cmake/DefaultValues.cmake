# ==============================================================================
# Default Values
# ==============================================================================
# Set some default values for variables, if not specified in the command line.
# ------------------------------------------------------------------------------
if(NOT DEFINED BUILD_SHARED_LIBS)
    # Use static build by default, else the project must be extended to copy the libraries (DLLs)
    # to the 'targe' and installation directory, when building for Windows.
    option(BUILD_SHARED_LIBS "Build shared libraries as default instead of static ones." OFF)
endif()