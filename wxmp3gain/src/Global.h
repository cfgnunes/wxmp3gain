/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <wx/string.h>

const wxString	APP_NAME = wxT("wxMP3gain");
const wxString	APP_VERSION = wxT("2.3");
const wxString	APP_NAME_WITH_VERSION = APP_NAME + wxT(" v") + APP_VERSION;

const wxString	APP_AUTHOR = wxT("Cristiano Nunes");
const wxString	APP_WEBSITE = wxT("http://sourceforge.net/projects/wxmp3gain/");
const wxString	APP_EMAIL = wxT("cfgnunes@gmail.com");

const wxString  APP_WILDCARD_EXT = wxT("MP3 files (*.mp3)|*.mp3;*.MP3");
const wxString  APP_OPEN_EXT = wxT("mp3");

#ifdef __LINUX__
const wxString	RESOURCE_DIR = wxT("/usr/share/wxmp3gain/resource/");
#else
const wxString	RESOURCE_DIR = wxT("resource/");
#endif

#endif // GLOBAL_H_INCLUDED
