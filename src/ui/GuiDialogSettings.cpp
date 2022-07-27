/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiDialogSettings.hpp"
#include "../Constants.hpp"

GuiDialogSettings::GuiDialogSettings(wxWindow *parent, AppSettings *appSettings) : DialogSettings(parent), mp_appSettings(appSettings) {
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

void GuiDialogSettings::OnsldConstantGainSliderUpdated(wxScrollEvent &event) {
    int intGain = gui_sldConstantGain->GetValue();

    wxString strGain;
    strGain += wxString::Format(_T("%+i"), intGain);
    strGain += _T(" (");
    strGain += wxString::Format(_T("%+.1f"), intGain * VALUE_5LOG2);
    strGain += _T(" dB)");

    gui_lblConstantGain->SetLabel(strGain);
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
    gui_chkAutoLower->SetValue(mp_appSettings->getAutoLowerEnabled());
    gui_chkForceInput->SetValue(mp_appSettings->getForceInputEnabled());

    // Tags options
    gui_optTagAPE->SetValue(mp_appSettings->getTagOptions() == TAG_APE);
    gui_optTagID3->SetValue(mp_appSettings->getTagOptions() == TAG_ID3);
    gui_optTagSKIP->SetValue(mp_appSettings->getTagOptions() == TAG_SKIP);
    gui_chkTagFORCE->SetValue(mp_appSettings->getTagForceEnabled());

    // Constant gain
    gui_chkConstantGain->SetValue(mp_appSettings->getConstantGainEnabled());
    gui_sldConstantGain->SetValue(mp_appSettings->getCtGainValue());
    OnsldConstantGainSliderUpdated(evt);
    gui_optBothChannel->SetValue(mp_appSettings->getChannelGainMode() == CHANNEL_BOTH);
    gui_optLeftChannel->SetValue(mp_appSettings->getChannelGainMode() == CHANNEL_LEFT);
    gui_optRightChannel->SetValue(mp_appSettings->getChannelGainMode() == CHANNEL_RIGHT);
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
    mp_appSettings->setAutoLowerEnabled(gui_chkAutoLower->GetValue());
    mp_appSettings->setForceInputEnabled(gui_chkForceInput->GetValue());

    // Tags options
    if (gui_optTagAPE->GetValue())
        mp_appSettings->setTagOptions(TAG_APE);
    else if (gui_optTagID3->GetValue())
        mp_appSettings->setTagOptions(TAG_ID3);
    else if (gui_optTagSKIP->GetValue())
        mp_appSettings->setTagOptions(TAG_SKIP);

    mp_appSettings->setTagForceEnabled(gui_chkTagFORCE->GetValue());

    // Constant gain
    mp_appSettings->setConstantGainEnabled(gui_chkConstantGain->GetValue());
    mp_appSettings->setCtGainValue(gui_sldConstantGain->GetValue());
    if (gui_optBothChannel->GetValue())
        mp_appSettings->setChannelGainMode(CHANNEL_BOTH);
    else if (gui_optLeftChannel->GetValue())
        mp_appSettings->setChannelGainMode(CHANNEL_LEFT);
    else if (gui_optRightChannel->GetValue())
        mp_appSettings->setChannelGainMode(CHANNEL_RIGHT);

    mp_appSettings->flush();
}

void GuiDialogSettings::defaultValueControls() {
    wxScrollEvent evt;

    // System controls
    mp_appSettings->setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);

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
    gui_sldConstantGain->SetValue(DEFAULT_VALUE_CtGainValue);
    OnsldConstantGainSliderUpdated(evt);
    gui_optBothChannel->SetValue(true);
    gui_optLeftChannel->SetValue(false);
    gui_optRightChannel->SetValue(false);
}
