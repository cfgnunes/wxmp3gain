/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiSettings.h"
#include "Global.h"

#include <wx/filedlg.h>
#include <wx/dirdlg.h>

GuiSettings::GuiSettings(wxWindow* parent, ConfigBase* configBase)
: Settings(parent), mp_configBase(configBase) {
    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

GuiSettings::~GuiSettings() {
}

void GuiSettings::updateDisabledControlsEvent(wxCommandEvent& event) {
    updateDisabledControls();
}

void GuiSettings::OnsldConstantGainCmdSliderUpdated(wxScrollEvent& event) {
    int intGain = g_sldConstantGain->GetValue();
    g_lblConstantGain->SetLabel(wxString::Format(_T("%+i"), intGain) + _T(" (") + wxString::Format(_T("%+.1f"), intGain * (5.0 * log10(2.0))) + _T(" dB)"));
}

void GuiSettings::OnbtnDefaultClick(wxCommandEvent& event) {
    defaultValueControls();
    updateDisabledControls();
}

void GuiSettings::OnbtnOKClick(wxCommandEvent& event) {
    saveValuesConfig();
    Close();
}

void GuiSettings::OnbtnCancelClick(wxCommandEvent& event) {
    Close();
}

void GuiSettings::updateValueControls() {
    wxScrollEvent evt;

    // General controls
    g_chkAutoLower->SetValue(mp_configBase->getAutoLowerEnabled());
    g_chkWorkOnTemporaryFile->SetValue(mp_configBase->getWorkOnTemporaryFile());
    g_chkPreserveTime->SetValue(mp_configBase->getPreserveTimeEnabled());
    g_chkForceInput->SetValue(mp_configBase->getForceInputEnabled());

    // Tags options
    g_optTagAPE->SetValue(mp_configBase->getTagOptions() == 0);
    g_optTagID3->SetValue(mp_configBase->getTagOptions() == 1);
    g_optTagSKIP->SetValue(mp_configBase->getTagOptions() == 2);
    g_chkTagFORCE->SetValue(mp_configBase->getTagForceEnabled());

    // Constant gain
    g_chkConstantGain->SetValue(mp_configBase->getConstantGainEnabled());
    g_sldConstantGain->SetValue(mp_configBase->getConstantGainValue());
    OnsldConstantGainCmdSliderUpdated(evt);
    g_optBothChannel->SetValue(mp_configBase->getChannelGainMode() == 0);
    g_optLeftChannel->SetValue(mp_configBase->getChannelGainMode() == 1);
    g_optRightChannel->SetValue(mp_configBase->getChannelGainMode() == 2);
}

void GuiSettings::updateDisabledControls() {
    // Tag options
    g_chkTagFORCE->Enable(!g_optTagSKIP->GetValue());

    // Constant gain
    g_sldConstantGain->Enable(g_chkConstantGain->GetValue());
    g_optBothChannel->Enable(g_chkConstantGain->GetValue());
    g_optLeftChannel->Enable(g_chkConstantGain->GetValue());
    g_optRightChannel->Enable(g_chkConstantGain->GetValue());
}

void GuiSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setAutoLowerEnabled(g_chkAutoLower->GetValue());
    mp_configBase->setWorkOnTemporaryFile(g_chkWorkOnTemporaryFile->GetValue());
    mp_configBase->setPreserveTimeEnabled(g_chkPreserveTime->GetValue());
    mp_configBase->setForceInputEnabled(g_chkForceInput->GetValue());

    // Tags options
    if (g_optTagAPE->GetValue())
        mp_configBase->setTagOptions(0);
    else if (g_optTagID3->GetValue())
        mp_configBase->setTagOptions(1);
    else if (g_optTagSKIP->GetValue())
        mp_configBase->setTagOptions(2);

    mp_configBase->setTagForceEnabled(g_chkTagFORCE->GetValue());

    // Constant gain
    mp_configBase->setConstantGainEnabled(g_chkConstantGain->GetValue());
    mp_configBase->setConstantGainValue(g_sldConstantGain->GetValue());
    if (g_optBothChannel->GetValue())
        mp_configBase->setChannelGainMode(0);
    else if (g_optLeftChannel->GetValue())
        mp_configBase->setChannelGainMode(1);
    else if (g_optRightChannel->GetValue())
        mp_configBase->setChannelGainMode(2);

    mp_configBase->setConfigFlush();
}

void GuiSettings::defaultValueControls() {
    wxScrollEvent evt;

    // System controls
    mp_configBase->setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);

    // General controls
    g_chkAutoLower->SetValue(DEFAULT_VALUE_AutoLowerEnabled);
    g_chkWorkOnTemporaryFile->SetValue(DEFAULT_VALUE_WorkOnTemporaryFile);
    g_chkPreserveTime->SetValue(DEFAULT_VALUE_PreserveTimeEnabled);
    g_chkForceInput->SetValue(DEFAULT_VALUE_ForceInputEnabled);

    // Tags options
    g_optTagAPE->SetValue(true);
    g_optTagID3->SetValue(false);
    g_optTagSKIP->SetValue(false);
    g_chkTagFORCE->SetValue(DEFAULT_VALUE_TagForceEnabled);

    // Constant gain
    g_chkConstantGain->SetValue(DEFAULT_VALUE_ConstantGainEnabled);
    g_sldConstantGain->SetValue(DEFAULT_VALUE_ConstantGainValue);
    OnsldConstantGainCmdSliderUpdated(evt);
    g_optBothChannel->SetValue(true);
    g_optLeftChannel->SetValue(false);
    g_optRightChannel->SetValue(false);
}

void GuiSettings::setLabelsControls() {
}
