/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIGBASE_H
#define CONFIGBASE_H

#include <wx/string.h>
#include <wx/config.h>

// Config Group Strings
const wxString	CONFIG_SYSTEM_GROUP				= wxT("/System/");
const wxString	CONFIG_GENERAL_GROUP			= wxT("/General/");
const wxString	CONFIG_TAGS_GROUP		    	= wxT("/Tags/");
const wxString	CONFIG_CTGAIN_GROUP		    	= wxT("/ConstantGain/");
const wxString	CONFIG_FOPTIONS_GROUP	    	= wxT("/FileOptions/");

// Config Strings
const wxString	CONFIG_STR_LastOpenDir			= wxT("LastOpenDir");
const wxString	CONFIG_STR_NormalVolumeDb	    = wxT("NormalVolumeDb");

const wxString	CONFIG_STR_ToolExecutable	    = wxT("ToolExecutable");
const wxString	CONFIG_STR_AutoLowerEnabled		= wxT("AutoLowerEnabled");

const wxString	CONFIG_STR_TagOptions	        = wxT("TagOptions");
const wxString	CONFIG_STR_TagForceEnabled      = wxT("TagForceEnabled");

const wxString	CONFIG_STR_ConstantGainEnabled  = wxT("ConstantGainEnabled");
const wxString	CONFIG_STR_ConstantGainValue    = wxT("ConstantGainValue");
const wxString	CONFIG_STR_ChannelGainMode      = wxT("ChannelGainMode");

const wxString	CONFIG_STR_FileWriting			= wxT("FileWriting");
const wxString	CONFIG_STR_PreserveTimeEnabled	= wxT("PreserveTimeEnabled");
const wxString	CONFIG_STR_ForceInputEnabled	= wxT("ForceInputEnabled");

// Default Values
const wxString	DEFAULT_VALUE_LastOpenDir		    = wxEmptyString;
const int   	DEFAULT_VALUE_NormalVolumeDb        = 890;

const wxString	DEFAULT_VALUE_ToolExecutable        = wxT("mp3gain");
const bool  	DEFAULT_VALUE_AutoLowerEnabled  	= false;

const int   	DEFAULT_VALUE_TagOptions            = 0;
const bool	    DEFAULT_VALUE_TagForceEnabled       = false;

const bool	    DEFAULT_VALUE_ConstantGainEnabled   = false;
const int   	DEFAULT_VALUE_ConstantGainValue     = 0;
const int   	DEFAULT_VALUE_ChannelGainMode       = 0;

const int       DEFAULT_VALUE_FileWriting           = 0;
const bool      DEFAULT_VALUE_PreserveTimeEnabled   = false;
const bool	    DEFAULT_VALUE_ForceInputEnabled     = false;

class ConfigBase
{
public:
    ConfigBase(const wxString & appName = wxEmptyString);
    ~ConfigBase();

    void setDefaultConfig();
    void setConfigFlush();
    wxString getStringToolOptions();
    wxString getStringToolOptionsTag();
    wxString getStringToolOptionsGain();

    //gets...
    wxString getLastOpenDir();
    int getNormalVolumeDb();
    wxString getToolExecutable();
    bool getAutoLowerEnabled();
    int getTagOptions();
    bool getTagForceEnabled();
    bool getConstantGainEnabled();
    int getConstantGainValue();
    int getChannelGainMode();
    int getFileWriting();
    bool getPreserveTimeEnabled();
    bool getForceInputEnabled();

    //sets...
    void setLastOpenDir(wxString value);
    void setNormalVolumeDb(int value);
    void setToolExecutable(wxString value);
    void setAutoLowerEnabled(bool value);
    void setTagOptions(int value);
    void setTagForceEnabled(bool value);
    void setConstantGainEnabled(bool value);
    void setConstantGainValue(int value);
    void setChannelGainMode(int value);
    void setFileWriting(int value);
    void setPreserveTimeEnabled(bool value);
    void setForceInputEnabled(bool value);

private:
    wxConfig *config;
};

#endif
