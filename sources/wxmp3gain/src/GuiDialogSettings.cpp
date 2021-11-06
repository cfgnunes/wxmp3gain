/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiDialogSettings.h"
#include "Constants.h"

GuiDialogSettings::GuiDialogSettings(wxWindow *parent, ConfigBase *configBase)
        : DialogSettings(parent), mp_configBase(configBase) {
    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

GuiDialogSettings::~GuiDialogSettings() {
}

void GuiDialogSettings::updateDisabledControlsEvent(wxCommandEvent &event) {
    updateDisabledControls();
    event.Skip(false);
}

void GuiDialogSettings::OnsldConstantGainCmdSliderUpdated(wxScrollEvent &event) {
    int intGain = g_sldConstantGain->GetValue();
    g_lblConstantGain->SetLabel(
            wxString::Format(_T("%+i"), intGain) + _T(" (") + wxString::Format(_T("%+.1f"), intGain * VALUE_5LOG2) +
            _T(" dB)"));
    event.Skip(false);
}

void GuiDialogSettings::OnbtnDefaultClick(wxCommandEvent &event) {
    defaultValueControls();
    updateDisabledControls();
    event.Skip(false);
}

void GuiDialogSettings::OnbtnOKClick(wxCommandEvent &event) {
    saveValuesConfig();
    Close();
    event.Skip(false);
}

void GuiDialogSettings::OnbtnCancelClick(wxCommandEvent &event) {
    Close();
    event.Skip(false);
}

void GuiDialogSettings::updateValueControls() {
    wxScrollEvent evt;

    // General controls
    g_chkAutoLower->SetValue(mp_configBase->getAutoLowerEnabled());
    g_chkForceInput->SetValue(mp_configBase->getForceInputEnabled());

    // Tags options
    g_optTagAPE->SetValue(mp_configBase->getTagOptions() == TAG_APE);
    g_optTagID3->SetValue(mp_configBase->getTagOptions() == TAG_ID3);
    g_optTagSKIP->SetValue(mp_configBase->getTagOptions() == TAG_SKIP);
    g_chkTagFORCE->SetValue(mp_configBase->getTagForceEnabled());

    // Constant gain
    g_chkConstantGain->SetValue(mp_configBase->getConstantGainEnabled());
    g_sldConstantGain->SetValue(mp_configBase->getConstantGainValue());
    OnsldConstantGainCmdSliderUpdated(evt);
    g_optBothChannel->SetValue(mp_configBase->getChannelGainMode() == CHANNEL_BOTH);
    g_optLeftChannel->SetValue(mp_configBase->getChannelGainMode() == CHANNEL_LEFT);
    g_optRightChannel->SetValue(mp_configBase->getChannelGainMode() == CHANNEL_RIGHT);
}

void GuiDialogSettings::updateDisabledControls() {
    // Tag options
    g_chkTagFORCE->Enable(!g_optTagSKIP->GetValue());

    // Constant gain
    g_sldConstantGain->Enable(g_chkConstantGain->GetValue());
    g_optBothChannel->Enable(g_chkConstantGain->GetValue());
    g_optLeftChannel->Enable(g_chkConstantGain->GetValue());
    g_optRightChannel->Enable(g_chkConstantGain->GetValue());
}

void GuiDialogSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setAutoLowerEnabled(g_chkAutoLower->GetValue());
    mp_configBase->setForceInputEnabled(g_chkForceInput->GetValue());

    // Tags options
    if (g_optTagAPE->GetValue())
        mp_configBase->setTagOptions(TAG_APE);
    else if (g_optTagID3->GetValue())
        mp_configBase->setTagOptions(TAG_ID3);
    else if (g_optTagSKIP->GetValue())
        mp_configBase->setTagOptions(TAG_SKIP);

    mp_configBase->setTagForceEnabled(g_chkTagFORCE->GetValue());

    // Constant gain
    mp_configBase->setConstantGainEnabled(g_chkConstantGain->GetValue());
    mp_configBase->setConstantGainValue(g_sldConstantGain->GetValue());
    if (g_optBothChannel->GetValue())
        mp_configBase->setChannelGainMode(CHANNEL_BOTH);
    else if (g_optLeftChannel->GetValue())
        mp_configBase->setChannelGainMode(CHANNEL_LEFT);
    else if (g_optRightChannel->GetValue())
        mp_configBase->setChannelGainMode(CHANNEL_RIGHT);

    mp_configBase->setConfigFlush();
}

void GuiDialogSettings::defaultValueControls() {
    wxScrollEvent evt;

    // System controls
    mp_configBase->setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);

    // General controls
    g_chkAutoLower->SetValue(DEFAULT_VALUE_AutoLowerEnabled);
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
