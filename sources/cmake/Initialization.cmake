# ===============================================================================
# Initialize the project, loading some standard CMake and custom modules, setting 
# project relevant variables.
# ===============================================================================
# Default values
include(DefaultValues)

# CMake Print Helpers for debugging purposes.
include(CMakePrintHelpers)

# Get the amount of processors available on this PC.
include(ProcessorCount)
ProcessorCount(AMOUNT_OF_PROCESSORS)
# Helpers to export the project via CmakeConfig files.
include(CMakePackageConfigHelpers)

# Set the amount of processors to use for compiling.
if(NOT DEFINED CMAKE_BUILD_PARALLEL_LEVEL)
	set(CMAKE_BUILD_PARALLEL_LEVEL ${AMOUNT_OF_PROCESSORS})
endif()

# -------------------------------------------------------------------------------
# Load custom modules setting project relevant variables.
# -------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/modules/")
# Check if the compiler is 32bit or 64bit.
include(DetectCompilerInformation)
# Detect the target architecture.
include(DetectTargetArchitecture)
# Define the naming convention for the assemblies and load a module with a function to set it.
include(SetNamingConvention)
# Set some default paths.
include(SetDefaultPaths)
# Set some OS dependent values.
include(SetOperatingSystemDependentVariables)
# Include some general tools.
include(Tools)
# Inform the user.
include(InformUserAboutCmakeSettings)
# Enable properties of global scope.
include(EnablePropertiesOfGlobalScope)