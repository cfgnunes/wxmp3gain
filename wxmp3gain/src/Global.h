/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <wx/string.h>

const wxString APP_NAME = _T("wxMP3gain");
const wxString APP_VERSION = _T("3.0");
const wxString APP_NAME_WITH_VERSION = APP_NAME + _T(" v") + APP_VERSION;

const wxString APP_AUTHOR = _T("Cristiano Nunes <cfgnunes@gmail.com>");
const wxString APP_COPYRIGHT = _T("(C) 2011-2015 Cristiano Nunes <cfgnunes@gmail.com>");
const wxString APP_WEBSITE = _T("http://sourceforge.net/projects/wxmp3gain/");

const wxString APP_WILDCARD_EXT = _T("MP3 files (*.mp3)|*.mp3;*.MP3");
const wxString APP_OPEN_EXT = _T("mp3");

#ifdef __LINUX__
const wxString RESOURCE_DIR = _T("/usr/share/wxmp3gain/resource/");
#else
const wxString RESOURCE_DIR = _T("resource/");
#endif

#endif // GLOBAL_H_INCLUDED
