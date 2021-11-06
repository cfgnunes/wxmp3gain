# ===============================================================================
# Enable Properties Of Global Scope
# ===============================================================================
# For some reason the properties of global scope 
# https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html#properties-of-global-scope
# are not automatically available.
# They have to be 'enabled' using the 'get_property' method.
# Some interesting ones are enabled in this file.
# -------------------------------------------------------------------------------

get_property(GENERATOR_IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)