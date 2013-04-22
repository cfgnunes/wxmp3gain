/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ConfigBase.h"

#include "Global.h"

ConfigBase::ConfigBase(const wxString & appName)
{
    config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if(!config->Exists(CONFIG_GENERAL_GROUP))
        setDefaultConfig();
}

ConfigBase::~ConfigBase()
{
    delete config;
}

void ConfigBase::setDefaultConfig()
{
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

void ConfigBase::setConfigFlush()
{
    config->Flush();
}

wxString ConfigBase::getStringToolOptions()
{
    wxString toolOptions;

    // FileWriting
    switch (getFileWriting())
    {
    case 0:
        toolOptions.append(wxT("-t "));
        break;
    case 1:
        toolOptions.append(wxT("-T "));
        break;
    }

    // PreserveTimestamp
    if(getPreserveTimeEnabled())
        toolOptions.append(wxT("-p "));

    // ForceInput
    if(getForceInputEnabled())
        toolOptions.append(wxT("-f "));

    toolOptions.Trim();
    return toolOptions;
}

wxString ConfigBase::getStringToolOptionsTag()
{
    wxString toolOptions;

    // TagsOptions
    switch (getTagOptions())
    {
    case 0:
        toolOptions.append(wxT("-s a "));
        break;
    case 1:
        toolOptions.append(wxT("-s i "));
        break;
    case 2:
        toolOptions.append(wxT("-s s "));
        break;
    }

    toolOptions.Trim();
    return toolOptions;
}

wxString ConfigBase::getStringToolOptionsGain()
{
    wxString toolOptions;

    // Ignore clipping warning when applying gain
    toolOptions.append(wxT("-c "));

    // Constant Gain
    if(getConstantGainEnabled())
    {
        switch (getChannelGainMode())
        {
        case 0:
            toolOptions.append(wxT("-g ") + wxString::Format(wxT("%i "), getConstantGainValue()));
            break;
        case 1:
            toolOptions.append(wxT("-l 0 ") + wxString::Format(wxT("%i "), getConstantGainValue()));
            break;
        case 2:
            toolOptions.append(wxT("-l 1 ") + wxString::Format(wxT("%i "), getConstantGainValue()));
            break;
        }
    }

    toolOptions.Trim();
    return toolOptions;
}

//gets...
wxString ConfigBase::getLastOpenDir()
{
    wxString value = wxEmptyString;
    config->Read(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, &value);
    return value;
}

int ConfigBase::getNormalVolumeDb()
{
    int value;
    config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_NormalVolumeDb, &value);
    return value;
}

wxString ConfigBase::getToolExecutable()
{
    wxString value = wxEmptyString;
    config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, &value);
    return value;
}

bool ConfigBase::getAutoLowerEnabled()
{
    bool value;
    config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_AutoLowerEnabled, &value);
    return value;
}

int ConfigBase::getTagOptions()
{
    int value;
    config->Read(CONFIG_TAGS_GROUP + CONFIG_STR_TagOptions, &value);
    return value;
}

bool ConfigBase::getTagForceEnabled()
{
    bool value;
    config->Read(CONFIG_TAGS_GROUP + CONFIG_STR_TagForceEnabled, &value);
    return value;
}

bool ConfigBase::getConstantGainEnabled()
{
    bool value;
    config->Read(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainEnabled, &value);
    return value;
}

int ConfigBase::getConstantGainValue()
{
    int value;
    config->Read(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainValue, &value);
    return value;
}

int ConfigBase::getChannelGainMode()
{
    int value;
    config->Read(CONFIG_CTGAIN_GROUP + CONFIG_STR_ChannelGainMode, &value);
    return value;
}

int ConfigBase::getFileWriting()
{
    int value;
    config->Read(CONFIG_FOPTIONS_GROUP + CONFIG_STR_FileWriting, &value);
    return value;
}

bool ConfigBase::getPreserveTimeEnabled()
{
    bool value;
    config->Read(CONFIG_FOPTIONS_GROUP + CONFIG_STR_PreserveTimeEnabled, &value);
    return value;
}

bool ConfigBase::getForceInputEnabled()
{
    bool value;
    config->Read(CONFIG_FOPTIONS_GROUP + CONFIG_STR_ForceInputEnabled, &value);
    return value;
}

//sets...
void ConfigBase::setLastOpenDir(wxString value)
{
    config->Write(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, value);
}

void ConfigBase::setNormalVolumeDb(int value)
{
    config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_NormalVolumeDb, value);
}

void ConfigBase::setToolExecutable(wxString value)
{
    config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, value);
}

void ConfigBase::setAutoLowerEnabled(bool value)
{
    config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_AutoLowerEnabled, value);
}

void ConfigBase::setTagOptions(int value)
{
    config->Write(CONFIG_TAGS_GROUP + CONFIG_STR_TagOptions, value);
}

void ConfigBase::setTagForceEnabled(bool value)
{
    config->Write(CONFIG_TAGS_GROUP + CONFIG_STR_TagForceEnabled, value);
}

void ConfigBase::setConstantGainEnabled(bool value)
{
    config->Write(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainEnabled, value);
}

void ConfigBase::setConstantGainValue(int value)
{
    config->Write(CONFIG_CTGAIN_GROUP + CONFIG_STR_ConstantGainValue, value);
}

void ConfigBase::setChannelGainMode(int value)
{
    config->Write(CONFIG_CTGAIN_GROUP + CONFIG_STR_ChannelGainMode, value);
}

void ConfigBase::setFileWriting(int value)
{
    config->Write(CONFIG_FOPTIONS_GROUP + CONFIG_STR_FileWriting, value);
}

void ConfigBase::setPreserveTimeEnabled(bool value)
{
    config->Write(CONFIG_FOPTIONS_GROUP + CONFIG_STR_PreserveTimeEnabled, value);
}

void ConfigBase::setForceInputEnabled(bool value)
{
    config->Write(CONFIG_FOPTIONS_GROUP + CONFIG_STR_ForceInputEnabled, value);
}
