/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "AppSettings.hpp"
#include "Constants.hpp"

AppSettings::AppSettings(const wxString &appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (getAppVersion().Cmp(APP_VERSION) != 0)
        setDefaultValues();
}

AppSettings::~AppSettings() {
    delete mp_config;
}

void AppSettings::setDefaultValues() {
    setAppVersion(APP_VERSION);
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);

    setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);
    setAutoLowerEnabled(DEFAULT_VALUE_AutoLowerEnabled);
    setForceInputEnabled(DEFAULT_VALUE_ForceInputEnabled);

    setTagForceEnabled(DEFAULT_VALUE_TagForceEnabled);
    setTagOptions(DEFAULT_VALUE_TagOptions);

    setConstantGainEnabled(DEFAULT_VALUE_ConstantGainEnabled);
    setCtGainValue(DEFAULT_VALUE_CtGainValue);
    setChannelGainMode(DEFAULT_VALUE_ChannelGainMode);
}

void AppSettings::flush() {
    mp_config->Flush();
}

wxString AppSettings::getStringToolOptions() const {
    wxString toolOptions;

    // ForceInput
    if (getForceInputEnabled())
        toolOptions.append(_T("-f "));

    toolOptions.Trim();
    return toolOptions;
}

wxString AppSettings::getStringToolOptionsTag() const {
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

wxString AppSettings::getStringToolOptionsGain() const {
    wxString toolOptions;

    // Ignore clipping warning when applying gain
    toolOptions.append(_T("-c "));

    // Constant Gain
    if (getConstantGainEnabled()) {
        switch (getChannelGainMode()) {
        default:
        case CHANNEL_BOTH:
            toolOptions.append(_T("-g ") + wxString::Format(_T("%i "), getCtGainValue()));
            break;
        case CHANNEL_LEFT:
            toolOptions.append(_T("-l 0 ") + wxString::Format(_T("%i "), getCtGainValue()));
            break;
        case CHANNEL_RIGHT:
            toolOptions.append(_T("-l 1 ") + wxString::Format(_T("%i "), getCtGainValue()));
            break;
        }
    }

    toolOptions.Trim();
    return toolOptions;
}

// Gets

wxString AppSettings::getAppVersion() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, &value);
    return value;
}

wxString AppSettings::getLastOpenDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, &value);
    return value;
}

int AppSettings::getNormalVolumeDb() const {
    int value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_NormalVolumeDb, &value);
    return value;
}

bool AppSettings::getAutoLowerEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_AutoLowerEnabled, &value);
    return value;
}

bool AppSettings::getForceInputEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_ForceInputEnabled, &value);
    return value;
}

int AppSettings::getTagOptions() const {
    int value;
    mp_config->Read(CONFIG_GROUP_TAGS + CONFIG_STR_TagOptions, &value);
    return value;
}

bool AppSettings::getTagForceEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_TAGS + CONFIG_STR_TagForceEnabled, &value);
    return value;
}

bool AppSettings::getConstantGainEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_CTGAIN + CONFIG_STR_ConstantGainEnabled, &value);
    return value;
}

int AppSettings::getCtGainValue() const {
    int value;
    mp_config->Read(CONFIG_GROUP_CTGAIN + CONFIG_STR_CtGainValue, &value);
    return value;
}

int AppSettings::getChannelGainMode() const {
    int value;
    mp_config->Read(CONFIG_GROUP_CTGAIN + CONFIG_STR_ChannelGainMode, &value);
    return value;
}

// Sets

void AppSettings::setAppVersion(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, value);
}

void AppSettings::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, value);
}

void AppSettings::setNormalVolumeDb(int value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_NormalVolumeDb, value);
}

void AppSettings::setAutoLowerEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_AutoLowerEnabled, value);
}

void AppSettings::setForceInputEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_ForceInputEnabled, value);
}

void AppSettings::setTagOptions(int value) {
    mp_config->Write(CONFIG_GROUP_TAGS + CONFIG_STR_TagOptions, value);
}

void AppSettings::setTagForceEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_TAGS + CONFIG_STR_TagForceEnabled, value);
}

void AppSettings::setConstantGainEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_CTGAIN + CONFIG_STR_ConstantGainEnabled, value);
}

void AppSettings::setCtGainValue(int value) {
    mp_config->Write(CONFIG_GROUP_CTGAIN + CONFIG_STR_CtGainValue, value);
}

void AppSettings::setChannelGainMode(int value) {
    mp_config->Write(CONFIG_GROUP_CTGAIN + CONFIG_STR_ChannelGainMode, value);
}
