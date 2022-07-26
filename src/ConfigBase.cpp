/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ConfigBase.h"
#include "Constants.h"

ConfigBase::ConfigBase(const wxString &appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (getAppVersion().Cmp(APP_VERSION) != 0)
        setDefaultConfig();
}

ConfigBase::~ConfigBase() {
    delete mp_config;
}

void ConfigBase::setDefaultConfig() {
    setAppVersion(APP_VERSION);
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);

    setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);
    setAutoLowerEnabled(DEFAULT_VALUE_AutoLowerEnabled);
    setForceInputEnabled(DEFAULT_VALUE_ForceInputEnabled);

    setTagForceEnabled(DEFAULT_VALUE_TagForceEnabled);
    setTagOptions(DEFAULT_VALUE_TagOptions);

    setConstantGainEnabled(DEFAULT_VALUE_ConstantGainEnabled);
    setConstantGainValue(DEFAULT_VALUE_ConstantGainValue);
    setChannelGainMode(DEFAULT_VALUE_ChannelGainMode);
}

void ConfigBase::setConfigFlush() {
    mp_config->Flush();
}

wxString ConfigBase::getStringToolOptions() const {
    wxString toolOptions;

    // ForceInput
    if (getForceInputEnabled())
        toolOptions.append(_T("-f "));

    toolOptions.Trim();
    return toolOptions;
}

wxString ConfigBase::getStringToolOptionsTag() const {
    wxString toolOptions;

    // TagsOptions
    switch (getTagOptions()) {
        case TAG_APE:
            toolOptions.append(_T("-s a "));
            break;
        case TAG_ID3:
            toolOptions.append(_T("-s i "));
            break;
        default:
        case TAG_SKIP:
            toolOptions.append(_T("-s s "));
            break;
    }

    toolOptions.Trim();
    return toolOptions;
}

wxString ConfigBase::getStringToolOptionsGain() const {
    wxString toolOptions;

    // Ignore clipping warning when applying gain
    toolOptions.append(_T("-c "));

    // Constant Gain
    if (getConstantGainEnabled()) {
        switch (getChannelGainMode()) {
            default:
            case CHANNEL_BOTH:
                toolOptions.append(_T("-g ") + wxString::Format(_T("%i "), getConstantGainValue()));
                break;
            case CHANNEL_LEFT:
                toolOptions.append(_T("-l 0 ") + wxString::Format(_T("%i "), getConstantGainValue()));
                break;
            case CHANNEL_RIGHT:
                toolOptions.append(_T("-l 1 ") + wxString::Format(_T("%i "), getConstantGainValue()));
                break;
        }
    }

    toolOptions.Trim();
    return toolOptions;
}

// Gets

wxString ConfigBase::getAppVersion() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, &value);
    return value;
}

wxString ConfigBase::getLastOpenDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, &value);
    return value;
}

int ConfigBase::getNormalVolumeDb() const {
    int value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_NormalVolumeDb, &value);
    return value;
}

bool ConfigBase::getAutoLowerEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_AutoLowerEnabled, &value);
    return value;
}

bool ConfigBase::getForceInputEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_ForceInputEnabled, &value);
    return value;
}

int ConfigBase::getTagOptions() const {
    int value;
    mp_config->Read(CONFIG_GROUP_TAGS + CONFIG_STR_TagOptions, &value);
    return value;
}

bool ConfigBase::getTagForceEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_TAGS + CONFIG_STR_TagForceEnabled, &value);
    return value;
}

bool ConfigBase::getConstantGainEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_CTGAIN + CONFIG_STR_ConstantGainEnabled, &value);
    return value;
}

int ConfigBase::getConstantGainValue() const {
    int value;
    mp_config->Read(CONFIG_GROUP_CTGAIN + CONFIG_STR_ConstantGainValue, &value);
    return value;
}

int ConfigBase::getChannelGainMode() const {
    int value;
    mp_config->Read(CONFIG_GROUP_CTGAIN + CONFIG_STR_ChannelGainMode, &value);
    return value;
}

// Sets

void ConfigBase::setAppVersion(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, value);
}

void ConfigBase::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, value);
}

void ConfigBase::setNormalVolumeDb(int value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_NormalVolumeDb, value);
}

void ConfigBase::setAutoLowerEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_AutoLowerEnabled, value);
}

void ConfigBase::setForceInputEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_ForceInputEnabled, value);
}

void ConfigBase::setTagOptions(int value) {
    mp_config->Write(CONFIG_GROUP_TAGS + CONFIG_STR_TagOptions, value);
}

void ConfigBase::setTagForceEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_TAGS + CONFIG_STR_TagForceEnabled, value);
}

void ConfigBase::setConstantGainEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_CTGAIN + CONFIG_STR_ConstantGainEnabled, value);
}

void ConfigBase::setConstantGainValue(int value) {
    mp_config->Write(CONFIG_GROUP_CTGAIN + CONFIG_STR_ConstantGainValue, value);
}

void ConfigBase::setChannelGainMode(int value) {
    mp_config->Write(CONFIG_GROUP_CTGAIN + CONFIG_STR_ChannelGainMode, value);
}
