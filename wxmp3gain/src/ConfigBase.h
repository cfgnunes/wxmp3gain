/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIGBASE_H
#define CONFIGBASE_H

#include <wx/string.h>
#include <wx/config.h>

// Config Group Strings
const wxString CONFIG_SYSTEM_GROUP = _T("/System/");
const wxString CONFIG_GENERAL_GROUP = _T("/General/");
const wxString CONFIG_TAGS_GROUP = _T("/Tags/");
const wxString CONFIG_CTGAIN_GROUP = _T("/ConstantGain/");

// Config Strings
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
const wxString DEFAULT_VALUE_LastOpenDir = wxEmptyString;

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

class ConfigBase {
public:
    ConfigBase(const wxString& appName = wxEmptyString);
    ~ConfigBase();

    void setDefaultConfig();
    void setConfigFlush();
    wxString getStringToolOptions() const;
    wxString getStringToolOptionsTag() const;
    wxString getStringToolOptionsGain() const;

    // Gets...
    wxString getLastOpenDir() const;
    int getNormalVolumeDb() const;
    bool getAutoLowerEnabled() const;
    bool getWorkOnTemporaryFile() const;
    bool getPreserveTimeEnabled() const;
    bool getForceInputEnabled() const;
    int getTagOptions() const;
    bool getTagForceEnabled() const;
    bool getConstantGainEnabled() const;
    int getConstantGainValue() const;
    int getChannelGainMode() const;

    // Sets...
    void setLastOpenDir(wxString value);
    void setNormalVolumeDb(int value);
    void setAutoLowerEnabled(bool value);
    void setWorkOnTemporaryFile(bool value);
    void setPreserveTimeEnabled(bool value);
    void setForceInputEnabled(bool value);
    void setTagOptions(int value);
    void setTagForceEnabled(bool value);
    void setConstantGainEnabled(bool value);
    void setConstantGainValue(int value);
    void setChannelGainMode(int value);

private:
    wxConfig *mp_config;
};

#endif // CONFIGBASE_H
