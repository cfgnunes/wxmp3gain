# ===============================================================================
# Configure gettext the way it should be used in the project.
# ===============================================================================
# Set the version.
# -------------------------------------------------------------------------------
set(gettext_VERSION_MAJOR 0)
set(gettext_VERSION_MINOR 21)
set(iconv_VERSION_MAJOR 1)
set(iconv_VERSION_MINOR 16)
set(gettext_SHA1 "c7741f20308d374afbe9adcdd4ac48bf47fa2240" )

# -------------------------------------------------------------------------------
# Load default settings, if not set and automatically detect further settings.
# -------------------------------------------------------------------------------
# Add the settings directory to load additional modules from.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/settings/")
# Set default settings.
include(GettextSettingsDefaults)

# ===============================================================================
# Download settings.
# ===============================================================================
set( gettext_URL "https://github.com/mlocati/gettext-iconv-windows/releases/download/v${gettext_VERSION_MAJOR}.${gettext_VERSION_MINOR}-v${iconv_VERSION_MAJOR}.${iconv_VERSION_MINOR}/gettext${gettext_VERSION_MAJOR}.${gettext_VERSION_MINOR}-iconv${iconv_VERSION_MAJOR}.${iconv_VERSION_MINOR}-${gettext_LINK_STYLE}-${gettext_ARCHITECTURE_TYPE}.zip" )

