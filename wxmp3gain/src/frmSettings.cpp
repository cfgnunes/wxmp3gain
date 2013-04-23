/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmSettings.h"
#include "Global.h"

//(*InternalHeaders(frmSettings)
#include <wx/intl.h>
#include <wx/string.h>
//*)

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
: configBase(configBase)
{
    //(*Initialize(frmSettings)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxBoxSizer* BoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer5;

    Create(parent, wxID_ANY, _("Settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Gain options"));
    chkAutoLower = new wxCheckBox(Panel6, ID_CHECKBOX3, _("Automatically lower track gain to not clip audio"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    chkAutoLower->SetValue(false);
    StaticBoxSizer4->Add(chkAutoLower, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer3->Add(StaticBoxSizer4, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("MP3gain executable"));
    txtToolExecutable = new wxTextCtrl(Panel6, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer2->Add(txtToolExecutable, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    btnToolExecutable = new wxButton(Panel6, ID_BUTTON5, _("..."), wxDefaultPosition, wxSize(22, 22), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer2->Add(btnToolExecutable, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer2, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel6);
    BoxSizer3->SetSizeHints(Panel6);
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Tags options"));
    optTagAPE = new wxRadioButton(Panel1, ID_RADIOBUTTON4, _("Use APEv2 tag for gain information (default)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    StaticBoxSizer3->Add(optTagAPE, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    optTagID3 = new wxRadioButton(Panel1, ID_RADIOBUTTON5, _("Use ID3v2 tag for gain information"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
    StaticBoxSizer3->Add(optTagID3, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    optTagSKIP = new wxRadioButton(Panel1, ID_RADIOBUTTON6, _("Skip stored tag info (do not read or write tags)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
    StaticBoxSizer3->Add(optTagSKIP, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer2->Add(StaticBoxSizer3, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Tags reading"));
    chkTagFORCE = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Force re-calculation (do not read tag info)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    chkTagFORCE->SetValue(false);
    StaticBoxSizer7->Add(chkTagFORCE, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer2->Add(StaticBoxSizer7, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Constant gain"));
    chkConstantGain = new wxCheckBox(Panel3, ID_CHECKBOX1, _("Use constant gain without doing any analysis"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    chkConstantGain->SetValue(false);
    StaticBoxSizer6->Add(chkConstantGain, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT2, _("Constant gain:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer6->Add(StaticText2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    sldConstantGain = new wxSlider(Panel3, ID_SLIDER1, 0, -8, 8, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS | wxSL_SELRANGE, wxDefaultValidator, _T("ID_SLIDER1"));
    BoxSizer6->Add(sldConstantGain, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    lblConstantGain = new wxStaticText(Panel3, ID_STATICTEXT1, _("+0 (+00.0 dB)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer6->Add(lblConstantGain, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6->Add(BoxSizer6, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer6, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Channel"));
    optBothChannel = new wxRadioButton(Panel3, ID_RADIOBUTTON2, _("Gain on both channels"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer1->Add(optBothChannel, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    optLeftChannel = new wxRadioButton(Panel3, ID_RADIOBUTTON3, _("Gain on left channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    StaticBoxSizer1->Add(optLeftChannel, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    optRightChannel = new wxRadioButton(Panel3, ID_RADIOBUTTON1, _("Gain on right channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    StaticBoxSizer1->Add(optRightChannel, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
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
    chcFileWriting = new wxChoice(Panel2, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    chcFileWriting->Append(_("work on temp file"));
    chcFileWriting->Append(_("work on original file"));
    BoxSizer5->Add(chcFileWriting, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(BoxSizer5, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    chkPreserveTime = new wxCheckBox(Panel2, ID_CHECKBOX5, _("Preserve original file timestamp"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    chkPreserveTime->SetValue(false);
    StaticBoxSizer5->Add(chkPreserveTime, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    chkForceInput = new wxCheckBox(Panel2, ID_CHECKBOX6, _("Force to assume input file is an MPEG 2 Layer III file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    chkForceInput->SetValue(false);
    StaticBoxSizer5->Add(chkForceInput, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
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
    btnDefault = new wxButton(this, ID_BUTTON1, _("Restore Defaults"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer10->Add(btnDefault, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    btnOK = new wxButton(this, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer10->Add(btnOK, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    btnCancel = new wxButton(this, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer10->Add(btnCancel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer10, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, _("mp3gain"), wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE | wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
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

    // Updates the volores controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

frmSettings::~frmSettings()
{
    //(*Destroy(frmSettings)
    //*)
}

void frmSettings::OnbtnOKClick(wxCommandEvent& event)
{
    saveValuesConfig();
    Close();
}

void frmSettings::OnbtnCancelClick(wxCommandEvent& event)
{
    Close();
}

void frmSettings::OnbtnDefaultClick(wxCommandEvent& event)
{
    defaultValueControls();
    updateDisabledControls();
}

void frmSettings::OnbtnToolExecutableClick(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_OK)
    {
        txtToolExecutable->Clear();
        txtToolExecutable->WriteText(FileDialog1->GetPath());
    }
}

void frmSettings::updateValueControls()
{
    wxScrollEvent evt;

    // General controls
    txtToolExecutable->Clear();
    txtToolExecutable->WriteText(configBase->getToolExecutable());
    chkAutoLower->SetValue(configBase->getAutoLowerEnabled());

    // Tags options
    optTagAPE->SetValue(configBase->getTagOptions() == 0);
    optTagID3->SetValue(configBase->getTagOptions() == 1);
    optTagSKIP->SetValue(configBase->getTagOptions() == 2);
    chkTagFORCE->SetValue(configBase->getTagForceEnabled());

    // Constant gain
    chkConstantGain->SetValue(configBase->getConstantGainEnabled());
    sldConstantGain->SetValue(configBase->getConstantGainValue());
    OnsldConstantGainCmdSliderUpdated(evt);
    optBothChannel->SetValue(configBase->getChannelGainMode() == 0);
    optLeftChannel->SetValue(configBase->getChannelGainMode() == 1);
    optRightChannel->SetValue(configBase->getChannelGainMode() == 2);

    // File options
    chcFileWriting->SetSelection(configBase->getFileWriting());
    chkPreserveTime->SetValue(configBase->getPreserveTimeEnabled());
    chkForceInput->SetValue(configBase->getForceInputEnabled());
}

void frmSettings::saveValuesConfig()
{
    // General controls
    configBase->setToolExecutable(txtToolExecutable->GetLineText(0));
    configBase->setAutoLowerEnabled(chkAutoLower->GetValue());

    // Tags options
    if (optTagAPE->GetValue())
        configBase->setTagOptions(0);
    else if (optTagID3->GetValue())
        configBase->setTagOptions(1);
    else if (optTagSKIP->GetValue())
        configBase->setTagOptions(2);

    configBase->setTagForceEnabled(chkTagFORCE->GetValue());

    // Constant gain
    configBase->setConstantGainEnabled(chkConstantGain->GetValue());
    configBase->setConstantGainValue(sldConstantGain->GetValue());
    if (optBothChannel->GetValue())
        configBase->setChannelGainMode(0);
    else if (optLeftChannel->GetValue())
        configBase->setChannelGainMode(1);
    else if (optRightChannel->GetValue())
        configBase->setChannelGainMode(2);

    // File options
    configBase->setFileWriting(chcFileWriting->GetSelection());
    configBase->setPreserveTimeEnabled(chkPreserveTime->GetValue());
    configBase->setForceInputEnabled(chkForceInput->GetValue());

    configBase->setConfigFlush();
}

void frmSettings::defaultValueControls()
{
    wxScrollEvent evt;

    // System controls
    configBase->setNormalVolumeDb(DEFAULT_VALUE_NormalVolumeDb);

    // General controls
    txtToolExecutable->Clear();
    txtToolExecutable->WriteText(DEFAULT_VALUE_ToolExecutable);
    chkAutoLower->SetValue(DEFAULT_VALUE_AutoLowerEnabled);

    // Tags options
    optTagAPE->SetValue(true);
    optTagID3->SetValue(false);
    optTagSKIP->SetValue(false);
    chkTagFORCE->SetValue(DEFAULT_VALUE_TagForceEnabled);

    // Constant gain
    chkConstantGain->SetValue(DEFAULT_VALUE_ConstantGainEnabled);
    sldConstantGain->SetValue(DEFAULT_VALUE_ConstantGainValue);
    OnsldConstantGainCmdSliderUpdated(evt);
    optBothChannel->SetValue(true);
    optLeftChannel->SetValue(false);
    optRightChannel->SetValue(false);

    // File options
    chcFileWriting->SetSelection(DEFAULT_VALUE_FileWriting);
    chkPreserveTime->SetValue(DEFAULT_VALUE_PreserveTimeEnabled);
    chkForceInput->SetValue(DEFAULT_VALUE_ForceInputEnabled);
}

void frmSettings::updateDisabledControlsEvent(wxCommandEvent& event)
{
    updateDisabledControls();
}

void frmSettings::updateDisabledControls()
{
    // Tag options
    chkTagFORCE->Enable(!optTagSKIP->GetValue());

    // Constant gain
    sldConstantGain->Enable(chkConstantGain->GetValue());
    optBothChannel->Enable(chkConstantGain->GetValue());
    optLeftChannel->Enable(chkConstantGain->GetValue());
    optRightChannel->Enable(chkConstantGain->GetValue());
}

void frmSettings::OnsldConstantGainCmdSliderUpdated(wxScrollEvent& event)
{
    int intGain = sldConstantGain->GetValue();
    lblConstantGain->SetLabel(wxString::Format(wxT("%+i"), intGain) + wxT(" (") + wxString::Format(wxT("%+.1f"), intGain * (5.0 * log10(2.0))) + wxT(" dB)"));
}
