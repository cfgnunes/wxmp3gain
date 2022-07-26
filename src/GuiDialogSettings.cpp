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
    int intGain = gui_sldConstantGain->GetValue();
    gui_lblConstantGain->SetLabel(
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
    gui_chkAutoLower->SetValue(mp_configBase->getAutoLowerEnabled());
    gui_chkForceInput->SetValue(mp_configBase->getForceInputEnabled());

    // Tags options
    gui_optTagAPE->SetValue(mp_configBase->getTagOptions() == TAG_APE);
    gui_optTagID3->SetValue(mp_configBase->getTagOptions() == TAG_ID3);
    gui_optTagSKIP->SetValue(mp_configBase->getTagOptions() == TAG_SKIP);
    gui_chkTagFORCE->SetValue(mp_configBase->getTagForceEnabled());

    // Constant gain
    gui_chkConstantGain->SetValue(mp_configBase->getConstantGainEnabled());
    gui_sldConstantGain->SetValue(mp_configBase->getConstantGainValue());
    OnsldConstantGainCmdSliderUpdated(evt);
    gui_optBothChannel->SetValue(mp_configBase->getChannelGainMode() == CHANNEL_BOTH);
    gui_optLeftChannel->SetValue(mp_configBase->getChannelGainMode() == CHANNEL_LEFT);
    gui_optRightChannel->SetValue(mp_configBase->getChannelGainMode() == CHANNEL_RIGHT);
}

void GuiDialogSettings::updateDisabledControls() {
    // Tag options
    gui_chkTagFORCE->Enable(!gui_optTagSKIP->GetValue());

    // Constant gain
    gui_sldConstantGain->Enable(gui_chkConstantGain->GetValue());
    gui_optBothChannel->Enable(gui_chkConstantGain->GetValue());
    gui_optLeftChannel->Enable(gui_chkConstantGain->GetValue());
    gui_optRightChannel->Enable(gui_chkConstantGain->GetValue());
}

void GuiDialogSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setAutoLowerEnabled(gui_chkAutoLower->GetValue());
    mp_configBase->setForceInputEnabled(gui_chkForceInput->GetValue());

    // Tags options
    if (gui_optTagAPE->GetValue())
        mp_configBase->setTagOptions(TAG_APE);
    else if (gui_optTagID3->GetValue())
        mp_configBase->setTagOptions(TAG_ID3);
    else if (gui_optTagSKIP->GetValue())
        mp_configBase->setTagOptions(TAG_SKIP);

    mp_configBase->setTagForceEnabled(gui_chkTagFORCE->GetValue());

    // Constant gain
    mp_configBase->setConstantGainEnabled(gui_chkConstantGain->GetValue());
    mp_configBase->setConstantGainValue(gui_sldConstantGain->GetValue());
    if (gui_optBothChannel->GetValue())
        mp_configBase->setChannelGainMode(CHANNEL_BOTH);
    else if (gui_optLeftChannel->GetValue())
        mp_configBase->setChannelGainMode(CHANNEL_LEFT);
    else if (gui_optRightChannel->GetValue())
        mp_configBase->setChannelGainMode(CHANNEL_RIGHT);

    mp_configBase->setConfigFlush();
}

void GuiDialogSettings::defaultValueControls() {
    wxScrollEvent evt;

    // System controls
    mp_configBase->setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);

    // General controls
    gui_chkAutoLower->SetValue(DEFAULT_VALUE_AutoLowerEnabled);
    gui_chkForceInput->SetValue(DEFAULT_VALUE_ForceInputEnabled);

    // Tags options
    gui_optTagAPE->SetValue(true);
    gui_optTagID3->SetValue(false);
    gui_optTagSKIP->SetValue(false);
    gui_chkTagFORCE->SetValue(DEFAULT_VALUE_TagForceEnabled);

    // Constant gain
    gui_chkConstantGain->SetValue(DEFAULT_VALUE_ConstantGainEnabled);
    gui_sldConstantGain->SetValue(DEFAULT_VALUE_ConstantGainValue);
    OnsldConstantGainCmdSliderUpdated(evt);
    gui_optBothChannel->SetValue(true);
    gui_optLeftChannel->SetValue(false);
    gui_optRightChannel->SetValue(false);
}
