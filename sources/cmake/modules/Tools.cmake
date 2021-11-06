# Additionaly paths.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/tools")
# String utilities.
include(StringUtils)
# Debugging utilities.
include(DebuggingUtils)
# Generate resource file with binary information like company name, file version, etc. for executables and libraries.
include(GenerateResourceFiles)