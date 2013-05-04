APP_NAME		= wxmp3gain
SRC_DIR			= ./src
PREFIX			= /usr
#DESTDIR			= /tmp/test

INSTALL_BIN_DIR 	= $(DESTDIR)$(PREFIX)/bin
INSTALL_SHARE_DIR	= $(DESTDIR)$(PREFIX)/share

APP_SHARE_DIR = $(INSTALL_SHARE_DIR)/$(APP_NAME)
DOC_SHARE_DIR = $(INSTALL_SHARE_DIR)/doc/$(APP_NAME)

COMMON_COMPILE_FLAGS = -Wall -pthread -O2
COMMON_LINK_FLAGS    = -pthread -s

CPPFLAGS  = $(COMMON_COMPILE_FLAGS) `wx-config --cxxflags --debug=no --unicode=yes`
LINKFLAGS = $(COMMON_LINK_FLAGS) `wx-config --libs std,aui --debug=no --unicode=yes`

all:
	@g++ $(CPPFLAGS) -c $(SRC_DIR)/*.cpp
	@g++ -o $(APP_NAME) *.o $(LINKFLAGS)

	@mkdir -p ./resource/msg/pt_BR/
	@mkdir -p ./resource/msg/es/
	@mkdir -p ./resource/msg/ru/
	@msgfmt ./msg/pt_BR.po -o ./resource/msg/pt_BR/$(APP_NAME).mo
	@msgfmt ./msg/es.po -o ./resource/msg/es/$(APP_NAME).mo
	@msgfmt ./msg/ru.po -o ./resource/msg/ru/$(APP_NAME).mo

clean:
	@rm -f *.o *.depend *.layout
	@rm -rf ./bin/
	@rm -rf ./obj/
	@rm -rf ./resource/msg/
	@rm -f $(APP_NAME)

install:
	@mkdir -p $(INSTALL_BIN_DIR)
	@cp $(APP_NAME) $(INSTALL_BIN_DIR)

	@mkdir -p $(APP_SHARE_DIR)
	@cp -r ./resource $(APP_SHARE_DIR)

	@mkdir -p $(DOC_SHARE_DIR)
	@cp -r ./docs/* $(DOC_SHARE_DIR)

	@mkdir -p $(INSTALL_SHARE_DIR)/icons/hicolor/32x32/apps
	@mkdir -p $(INSTALL_SHARE_DIR)/icons/hicolor/48x48/apps
	@mkdir -p $(INSTALL_SHARE_DIR)/icons/hicolor/64x64/apps
	@mkdir -p $(INSTALL_SHARE_DIR)/icons/hicolor/128x128/apps
	@mkdir -p $(INSTALL_SHARE_DIR)/menu
	@mkdir -p $(INSTALL_SHARE_DIR)/pixmaps
	@mkdir -p $(INSTALL_SHARE_DIR)/applications
	@cp ./debian/menu/icon32x32.png		$(INSTALL_SHARE_DIR)/icons/hicolor/32x32/apps/$(APP_NAME).png
	@cp ./debian/menu/icon48x48.png		$(INSTALL_SHARE_DIR)/icons/hicolor/48x48/apps/$(APP_NAME).png
	@cp ./debian/menu/icon64x64.png		$(INSTALL_SHARE_DIR)/icons/hicolor/64x64/apps/$(APP_NAME).png
	@cp ./debian/menu/icon128x128.png	$(INSTALL_SHARE_DIR)/icons/hicolor/128x128/apps/$(APP_NAME).png
	@cp ./debian/menu/icon.xpm		$(INSTALL_SHARE_DIR)/pixmaps/$(APP_NAME).xpm
	@cp ./debian/menu/$(APP_NAME)		$(INSTALL_SHARE_DIR)/menu/$(APP_NAME)
	@cp ./debian/menu/$(APP_NAME).desktop	$(INSTALL_SHARE_DIR)/applications/$(APP_NAME).desktop

uninstall:
	@rm -f $(INSTALL_BIN_DIR)/$(APP_NAME)
	@rm -rf $(APP_SHARE_DIR)
	@rm -rf $(DOC_SHARE_DIR)

	@rm -f $(INSTALL_SHARE_DIR)/icons/hicolor/32x32/apps/$(APP_NAME).png
	@rm -f $(INSTALL_SHARE_DIR)/icons/hicolor/48x48/apps/$(APP_NAME).png
	@rm -f $(INSTALL_SHARE_DIR)/icons/hicolor/64x64/apps/$(APP_NAME).png
	@rm -f $(INSTALL_SHARE_DIR)/icons/hicolor/128x128/apps/$(APP_NAME).png
	@rm -f $(INSTALL_SHARE_DIR)/pixmaps/$(APP_NAME).xpm
	@rm -f $(INSTALL_SHARE_DIR)/menu/$(APP_NAME)
	@rm -f $(INSTALL_SHARE_DIR)/applications/$(APP_NAME).desktop
