# ===============================================================================
# Define where the external projects / libraries should be downloaded and built.
# ===============================================================================
include( ExternalProject )

# Add wxWidgets as an external project.
ExternalProject_Add(${wxwidgets_EP_NAME}

    SOURCE_DIR ${wxwidgets_SOURCE_DIR}

	STAMP_DIR ${wxwidgets_STAMP_DIR}
	LOG_DIR ${wxwidgets_LOG_DIR}

	GIT_REPOSITORY ${wxwidgets_URL}
	GIT_TAG ${wxwidgets_GIT_TAG}
	GIT_PROGRESS ON

	CONFIGURE_COMMAND ${wxwidgets_CONFIGURE_COMMAND}

	BUILD_COMMAND ${wxwidgets_BUILD_COMMAND}

	INSTALL_COMMAND ${wxwidgets_INSTALL_COMMAND}

	# Do not set this true, as it would override the <SOURCE_DIR> to be equal to <BINARY_DIR>
	BUILD_IN_SOURCE false
)
