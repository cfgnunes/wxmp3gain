/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <wx/string.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

const wxString APP_NAME = _T("wxMP3gain");
const wxString APP_VERSION = _T("3.6");
const wxString APP_NAME_WITH_VERSION = APP_NAME + _T(" v") + APP_VERSION;

const wxString APP_AUTHOR = _T("Cristiano Nunes <cfgnunes@gmail.com>");
const wxString APP_COPYRIGHT = _T("(C) 2011-2015 Cristiano Nunes <cfgnunes@gmail.com>");
const wxString APP_WEBSITE = _T("http://sourceforge.net/projects/wxmp3gain/");

const wxString APP_TOOL_EXECUTABLE = _T("mp3gain");
const wxString APP_WILDCARD_EXT = _T("MP3 files (*.mp3)|*.mp3;*.MP3");
const wxString APP_OPEN_EXT = _T("mp3");

// Config Group Strings
const wxString CONFIG_GROUP_SYSTEM = _T("/System/");
const wxString CONFIG_GROUP_GENERAL = _T("/General/");
const wxString CONFIG_GROUP_TAGS = _T("/Tags/");
const wxString CONFIG_GROUP_CTGAIN = _T("/ConstantGain/");

// Config Strings
const wxString CONFIG_STR_AppVersion = _T("AppVersion");
const wxString CONFIG_STR_LastOpenDir = _T("LastOpenDir");

const wxString CONFIG_STR_NormalVolumeDb = _T("NormalVolumeDb");
const wxString CONFIG_STR_AutoLowerEnabled = _T("AutoLowerEnabled");
const wxString CONFIG_STR_WorkOnTemporaryFile = _T("WorkOnTemporaryFile");
const wxString CONFIG_STR_PreserveTimeEnabled = _T("PreserveTimeEnabled");
const wxString CONFIG_STR_ForceInputEnabled = _T("ForceInputEnabled");

const wxString CONFIG_STR_TagOptions = _T("TagOptions");
const wxString CONFIG_STR_TagForceEnabled = _T("TagForceEnabled");

const wxString CONFIG_STR_ConstantGainEnabled = _T("ConstantGainEnabled");
const wxString CONFIG_STR_ConstantGainValue = _T("ConstantGainValue");
const wxString CONFIG_STR_ChannelGainMode = _T("ChannelGainMode");

// Default Values
const wxString DEFAULT_VALUE_LastOpenDir = wxFileName::GetHomeDir();

const int DEFAULT_VALUE_NormalVolumeDb = 890;
const bool DEFAULT_VALUE_AutoLowerEnabled = false;
const bool DEFAULT_VALUE_WorkOnTemporaryFile = false;
const bool DEFAULT_VALUE_PreserveTimeEnabled = false;
const bool DEFAULT_VALUE_ForceInputEnabled = false;

const int DEFAULT_VALUE_TagOptions = 0;
const bool DEFAULT_VALUE_TagForceEnabled = false;

const bool DEFAULT_VALUE_ConstantGainEnabled = false;
const int DEFAULT_VALUE_ConstantGainValue = 0;
const int DEFAULT_VALUE_ChannelGainMode = 0;

// ID for title in wxListCtrl
int const ID_LIST_FILE = 0;
int const ID_LIST_FOLDER = 1;
int const ID_LIST_VOLUME = 2;
int const ID_LIST_GAIN_DB = 3;
int const ID_LIST_GAIN_MP3 = 4;
int const ID_LIST_CLIPPING = 5;
int const ID_LIST_TAG_INFO = 6;

// ID for work type
int const TOOL_ANALYSIS = 0;
int const TOOL_GAIN = 1;
int const TOOL_UNDO = 2;
int const TOOL_DELETE_TAG = 3;

inline wxString GetResourceDir() {
#ifdef __LINUX__
    wxString resourceDir = _T("/usr/share/wxmp3gain/resource/");
#else
    wxString executablePath = wxStandardPaths::Get().GetExecutablePath();
    wxFileName executableFilename(executablePath);
    wxString resourceDir = executableFilename.GetPath() + _T("/resource/");
#endif
    return resourceDir;
}

#endif // CONSTANTS_H
