/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ConfigBase.h"
#include "Global.h"

ConfigBase::ConfigBase(const wxString& appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (!mp_config->Exists(CONFIG_GENERAL_GROUP))
        setDefaultConfig();
}

ConfigBase::~ConfigBase() {
    delete mp_config;
}

void ConfigBase::setDefaultConfig() {
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);
    setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);

    setToolExecutable(DEFAULT_VALUE_ToolExecutable);
    setAutoLowerEnabled(DEFAULT_VALUE_AutoLowerEnabled);

    setTagOptions(DEFAULT_VALUE_TagOptions);

    setConstantGainEnabled(DEFAULT_VALUE_ConstantGainEnabled);
    setConstantGainValue(DEFAULT_VALUE_ConstantGainValue);
    setChannelGainMode(DEFAULT_VALUE_ChannelGainMode);

    setFileWriting(DEFAULT_VALUE_FileWriting);
    setPreserveTimeEnabled(DEFAULT_VALUE_PreserveTimeEnabled);
    setForceInputEnabled(DEFAULT_VALUE_ForceInputEnabled);
}

void ConfigBase::setConfigFlush() {
    mp_config->Flush();
}

wxString ConfigBase::getStringToolOptions() {
    wxString toolOptions;

    // FileWriting
    switch (getFileWriting()) {
        case 0:
            toolOptions.append(_T("-t "));
            break;
        case 1:
            toolOptions.append(_T("-T "));
            break;
    }

    // PreserveTimestamp
    if (getPreserveTimeEnabled())
        toolOptions.append(_T("-p "));

    // ForceInput
    if (getForceInputEnabled())
        toolOptions.append(_T("-f "));

    toolOptions.Trim();
    return toolOptions;
}

wxString ConfigBase::getStringToolOptionsTag() {
    wxString toolOptions;

    // TagsOptions
    switch (getTagOptions()) {
        case 0:
            toolOptions.append(_T("-s a "));
            break;
        case 1:
            toolOptions.append(_T("-s i "));
            break;
        case 2:
            toolOptions.append(_T("-s s "));
            break;
    }

    toolOptions.Trim();
    return toolOptions;
}

wxString ConfigBase::getStringToolOptionsGain() {
    wxString toolOptions;

    // Ignore clipping warning when applying gain
    toolOptions.append(_T("-c "));

    // Constant Gain
    if (getConstantGainEnabled()) {
        switch (getChannelGainMode()) {
            case 0:
                toolOptions.append(_T("-g ") + wxString::Format(_T("%i "), getConstantGainValue()));
                break;
            case 1:
                toolOptions.append(_T("-l 0 ") + wxString::Format(_T("%i "), getConstantGainValue()));
                break;
            case 2:
                toolOptions.append(_T("-l 1 ") + wxString::Format(_T("%i "), getConstantGainValue()));
                break;
        }
    }

    toolOptions.Trim();
    return toolOptions;
}

// Gets...

wxString ConfigBase::getLastOpenDir() {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, &value);
    return value;
}

int ConfigBase::getNormalVolumeDb() {
    int value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_NormalVolumeDb, &value);
    return value;
}

wxString ConfigBase::getToolExecutable() {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, &value);
    return value;
}

bool ConfigBase::getAutoLowerEnabled() {
    bool value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_AutoLowerEnabled, &value);
    return value;
}

int ConfigBase::getTagOptions() {
    int value;
    mp_config->Read(CONFIG_TAGS_GROUP + CONFIG_STR_TagOptions, &value);
    return value;
}

bool ConfigBase::getTagForceEnabled() {
    bool value;
    mp_config->Read(CONFIG_TAGS_GROUP + CONFIG_STR_TagForceEnabled, &value);
    return value;
}

bool ConfigBase::getConstantGainEnabled() {
    bool value;
    mp_config->Read(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainEnabled, &value);
    return value;
}

int ConfigBase::getConstantGainValue() {
    int value;
    mp_config->Read(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainValue, &value);
    return value;
}

int ConfigBase::getChannelGainMode() {
    int value;
    mp_config->Read(CONFIG_CTGAIN_GROUP + CONFIG_STR_ChannelGainMode, &value);
    return value;
}

int ConfigBase::getFileWriting() {
    int value;
    mp_config->Read(CONFIG_FOPTIONS_GROUP + CONFIG_STR_FileWriting, &value);
    return value;
}

bool ConfigBase::getPreserveTimeEnabled() {
    bool value;
    mp_config->Read(CONFIG_FOPTIONS_GROUP + CONFIG_STR_PreserveTimeEnabled, &value);
    return value;
}

bool ConfigBase::getForceInputEnabled() {
    bool value;
    mp_config->Read(CONFIG_FOPTIONS_GROUP + CONFIG_STR_ForceInputEnabled, &value);
    return value;
}

// Sets...

void ConfigBase::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, value);
}

void ConfigBase::setNormalVolumeDb(int value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_NormalVolumeDb, value);
}

void ConfigBase::setToolExecutable(wxString value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, value);
}

void ConfigBase::setAutoLowerEnabled(bool value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_AutoLowerEnabled, value);
}

void ConfigBase::setTagOptions(int value) {
    mp_config->Write(CONFIG_TAGS_GROUP + CONFIG_STR_TagOptions, value);
}

void ConfigBase::setTagForceEnabled(bool value) {
    mp_config->Write(CONFIG_TAGS_GROUP + CONFIG_STR_TagForceEnabled, value);
}

void ConfigBase::setConstantGainEnabled(bool value) {
    mp_config->Write(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainEnabled, value);
}

void ConfigBase::setConstantGainValue(int value) {
    mp_config->Write(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainValue, value);
}

void ConfigBase::setChannelGainMode(int value) {
    mp_config->Write(CONFIG_CTGAIN_GROUP + CONFIG_STR_ChannelGainMode, value);
}

void ConfigBase::setFileWriting(int value) {
    mp_config->Write(CONFIG_FOPTIONS_GROUP + CONFIG_STR_FileWriting, value);
}

void ConfigBase::setPreserveTimeEnabled(bool value) {
    mp_config->Write(CONFIG_FOPTIONS_GROUP + CONFIG_STR_PreserveTimeEnabled, value);
}

void ConfigBase::setForceInputEnabled(bool value) {
    mp_config->Write(CONFIG_FOPTIONS_GROUP + CONFIG_STR_ForceInputEnabled, value);
}
