/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmSettings.h"
#include "Global.h"

//(*InternalHeaders(frmSettings)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <wx/filedlg.h>
#include <wx/dirdlg.h>

//(*IdInit(frmSettings)
const long frmSettings::ID_CHECKBOX3 = wxNewId();
const long frmSettings::ID_TEXTCTRL2 = wxNewId();
const long frmSettings::ID_BUTTON5 = wxNewId();
const long frmSettings::ID_PANEL6 = wxNewId();
const long frmSettings::ID_RADIOBUTTON4 = wxNewId();
const long frmSettings::ID_RADIOBUTTON5 = wxNewId();
const long frmSettings::ID_RADIOBUTTON6 = wxNewId();
const long frmSettings::ID_CHECKBOX2 = wxNewId();
const long frmSettings::ID_PANEL1 = wxNewId();
const long frmSettings::ID_CHECKBOX1 = wxNewId();
const long frmSettings::ID_STATICTEXT2 = wxNewId();
const long frmSettings::ID_SLIDER1 = wxNewId();
const long frmSettings::ID_STATICTEXT1 = wxNewId();
const long frmSettings::ID_RADIOBUTTON2 = wxNewId();
const long frmSettings::ID_RADIOBUTTON3 = wxNewId();
const long frmSettings::ID_RADIOBUTTON1 = wxNewId();
const long frmSettings::ID_PANEL3 = wxNewId();
const long frmSettings::ID_STATICTEXT4 = wxNewId();
const long frmSettings::ID_CHOICE4 = wxNewId();
const long frmSettings::ID_CHECKBOX5 = wxNewId();
const long frmSettings::ID_CHECKBOX6 = wxNewId();
const long frmSettings::ID_PANEL2 = wxNewId();
const long frmSettings::ID_NOTEBOOK1 = wxNewId();
const long frmSettings::ID_BUTTON1 = wxNewId();
const long frmSettings::ID_BUTTON2 = wxNewId();
const long frmSettings::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frmSettings, wxDialog)
//(*EventTable(frmSettings)
//*)
END_EVENT_TABLE()

frmSettings::frmSettings(wxWindow* parent, ConfigBase* configBase, wxWindowID id)
: mp_configBase(configBase) {
    //(*Initialize(frmSettings)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("Settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Gain options"));
    g_chkAutoLower = new wxCheckBox(Panel6, ID_CHECKBOX3, _("Automatically lower gain to not clip audio"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    g_chkAutoLower->SetValue(false);
    StaticBoxSizer4->Add(g_chkAutoLower, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer3->Add(StaticBoxSizer4, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("MP3gain executable"));
    g_txtToolExecutable = new wxTextCtrl(Panel6, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer2->Add(g_txtToolExecutable, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    g_btnToolExecutable = new wxButton(Panel6, ID_BUTTON5, wxEmptyString, wxDefaultPosition, wxSize(22, 22), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer2->Add(g_btnToolExecutable, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer2, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel6);
    BoxSizer3->SetSizeHints(Panel6);
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Tags options"));
    g_optTagAPE = new wxRadioButton(Panel1, ID_RADIOBUTTON4, _("Use APEv2 tag for gain information (default)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    StaticBoxSizer3->Add(g_optTagAPE, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_optTagID3 = new wxRadioButton(Panel1, ID_RADIOBUTTON5, _("Use ID3v2 tag for gain information"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
    StaticBoxSizer3->Add(g_optTagID3, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_optTagSKIP = new wxRadioButton(Panel1, ID_RADIOBUTTON6, _("Skip stored tag info (do not read or write tags)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
    StaticBoxSizer3->Add(g_optTagSKIP, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer2->Add(StaticBoxSizer3, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Tags reading"));
    g_chkTagFORCE = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Force re-calculation (do not read tag info)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    g_chkTagFORCE->SetValue(false);
    StaticBoxSizer7->Add(g_chkTagFORCE, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer2->Add(StaticBoxSizer7, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Constant gain"));
    g_chkConstantGain = new wxCheckBox(Panel3, ID_CHECKBOX1, _("Use constant gain without doing any analysis"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    g_chkConstantGain->SetValue(false);
    StaticBoxSizer6->Add(g_chkConstantGain, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT2, _("Constant gain:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer6->Add(StaticText2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_sldConstantGain = new wxSlider(Panel3, ID_SLIDER1, 0, -8, 8, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS | wxSL_SELRANGE, wxDefaultValidator, _T("ID_SLIDER1"));
    BoxSizer6->Add(g_sldConstantGain, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_lblConstantGain = new wxStaticText(Panel3, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer6->Add(g_lblConstantGain, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6->Add(BoxSizer6, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer6, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Channel"));
    g_optBothChannel = new wxRadioButton(Panel3, ID_RADIOBUTTON2, _("Gain on both channels"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer1->Add(g_optBothChannel, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_optLeftChannel = new wxRadioButton(Panel3, ID_RADIOBUTTON3, _("Gain on left channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    StaticBoxSizer1->Add(g_optLeftChannel, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_optRightChannel = new wxRadioButton(Panel3, ID_RADIOBUTTON1, _("Gain on right channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    StaticBoxSizer1->Add(g_optRightChannel, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer7->Add(StaticBoxSizer1, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(BoxSizer7);
    BoxSizer7->Fit(Panel3);
    BoxSizer7->SetSizeHints(Panel3);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("File options"));
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("File writing:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer5->Add(StaticText4, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_chcFileWriting = new wxChoice(Panel2, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    g_chcFileWriting->Append(_("work on temp file"));
    g_chcFileWriting->Append(_("work on original file"));
    BoxSizer5->Add(g_chcFileWriting, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(BoxSizer5, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_chkPreserveTime = new wxCheckBox(Panel2, ID_CHECKBOX5, _("Keep file timestamps"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    g_chkPreserveTime->SetValue(false);
    StaticBoxSizer5->Add(g_chkPreserveTime, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_chkForceInput = new wxCheckBox(Panel2, ID_CHECKBOX6, _("Force to assume input is an MPEG 2 Layer III file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    g_chkForceInput->SetValue(false);
    StaticBoxSizer5->Add(g_chkForceInput, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer4->Add(StaticBoxSizer5, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer4);
    BoxSizer4->Fit(Panel2);
    BoxSizer4->SetSizeHints(Panel2);
    Notebook1->AddPage(Panel6, _("General"), false);
    Notebook1->AddPage(Panel1, _("Tags"), false);
    Notebook1->AddPage(Panel3, _("Constant gain"), false);
    Notebook1->AddPage(Panel2, _("File options"), false);
    BoxSizer1->Add(Notebook1, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    g_btnDefault = new wxButton(this, ID_BUTTON1, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer10->Add(g_btnDefault, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_btnOK = new wxButton(this, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer10->Add(g_btnOK, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_btnCancel = new wxButton(this, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer10->Add(g_btnCancel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer10, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnToolExecutableClick);
    Connect(ID_RADIOBUTTON4, wxEVT_COMMAND_RADIOBUTTON_SELECTED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_RADIOBUTTON5, wxEVT_COMMAND_RADIOBUTTON_SELECTED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_RADIOBUTTON6, wxEVT_COMMAND_RADIOBUTTON_SELECTED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX1, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_SLIDER1, wxEVT_COMMAND_SLIDER_UPDATED, (wxObjectEventFunction) & frmSettings::OnsldConstantGainCmdSliderUpdated);
    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnDefaultClick);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnOKClick);
    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnCancelClick);
    //*)

    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

frmSettings::~frmSettings() {
    //(*Destroy(frmSettings)
    //*)
}

void frmSettings::OnbtnOKClick(wxCommandEvent& event) {
    saveValuesConfig();
    Close();
}

void frmSettings::OnbtnCancelClick(wxCommandEvent& event) {
    Close();
}

void frmSettings::OnbtnDefaultClick(wxCommandEvent& event) {
    defaultValueControls();
    updateDisabledControls();
}

void frmSettings::OnbtnToolExecutableClick(wxCommandEvent& event) {
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN);
    if (fileDialog.ShowModal() == wxID_OK) {
        g_txtToolExecutable->Clear();
        g_txtToolExecutable->WriteText(fileDialog.GetPath());
    }
}

void frmSettings::updateValueControls() {
    wxScrollEvent evt;

    // General controls
    g_txtToolExecutable->Clear();
    g_txtToolExecutable->WriteText(mp_configBase->getToolExecutable());
    g_chkAutoLower->SetValue(mp_configBase->getAutoLowerEnabled());

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

    // File options
    g_chcFileWriting->SetSelection(mp_configBase->getFileWriting());
    g_chkPreserveTime->SetValue(mp_configBase->getPreserveTimeEnabled());
    g_chkForceInput->SetValue(mp_configBase->getForceInputEnabled());
}

void frmSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setToolExecutable(g_txtToolExecutable->GetLineText(0));
    mp_configBase->setAutoLowerEnabled(g_chkAutoLower->GetValue());

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

    // File options
    mp_configBase->setFileWriting(g_chcFileWriting->GetSelection());
    mp_configBase->setPreserveTimeEnabled(g_chkPreserveTime->GetValue());
    mp_configBase->setForceInputEnabled(g_chkForceInput->GetValue());

    mp_configBase->setConfigFlush();
}

void frmSettings::defaultValueControls() {
    wxScrollEvent evt;

    // System controls
    mp_configBase->setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);

    // General controls
    g_txtToolExecutable->Clear();
    g_txtToolExecutable->WriteText(DEFAULT_VALUE_ToolExecutable);
    g_chkAutoLower->SetValue(DEFAULT_VALUE_AutoLowerEnabled);

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

    // File options
    g_chcFileWriting->SetSelection(DEFAULT_VALUE_FileWriting);
    g_chkPreserveTime->SetValue(DEFAULT_VALUE_PreserveTimeEnabled);
    g_chkForceInput->SetValue(DEFAULT_VALUE_ForceInputEnabled);
}

void frmSettings::updateDisabledControlsEvent(wxCommandEvent& event) {
    updateDisabledControls();
}

void frmSettings::updateDisabledControls() {
    // Tag options
    g_chkTagFORCE->Enable(!g_optTagSKIP->GetValue());

    // Constant gain
    g_sldConstantGain->Enable(g_chkConstantGain->GetValue());
    g_optBothChannel->Enable(g_chkConstantGain->GetValue());
    g_optLeftChannel->Enable(g_chkConstantGain->GetValue());
    g_optRightChannel->Enable(g_chkConstantGain->GetValue());
}

void frmSettings::OnsldConstantGainCmdSliderUpdated(wxScrollEvent& event) {
    int intGain = g_sldConstantGain->GetValue();
    g_lblConstantGain->SetLabel(wxString::Format(_T("%+i"), intGain) + _T(" (") + wxString::Format(_T("%+.1f"), intGain * (5.0 * log10(2.0))) + _T(" dB)"));
}

void frmSettings::setLabelsControls() {
    g_btnToolExecutable->SetLabel(_T("..."));
}
