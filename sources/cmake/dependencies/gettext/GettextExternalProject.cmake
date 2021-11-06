# ===============================================================================
# Define where the external projects / libraries should be downloaded and built.
# ===============================================================================
include( ExternalProject )

# Add gettext as an external project.
ExternalProject_Add(${gettext_EP_NAME}

    SOURCE_DIR ${gettext_SOURCE_DIR}

	STAMP_DIR ${gettext_STAMP_DIR}
	LOG_DIR ${gettext_LOG_DIR}

    URL ${gettext_URL}
    URL_HASH SHA1=${gettext_SHA1}

    CONFIGURE_COMMAND COMMAND ${CMAKE_COMMAND} -E true

    BUILD_COMMAND COMMAND ${CMAKE_COMMAND} -E true

	INSTALL_COMMAND ${gettext_INSTALL_COMMAND}
)
