/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmAbout.h"

#include "Global.h"

//(*InternalHeaders(frmAbout)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/image.h>

//(*IdInit(frmAbout)
const long frmAbout::ID_STATICBITMAP1 = wxNewId();
const long frmAbout::ID_STATICTEXT2 = wxNewId();
const long frmAbout::ID_STATICTEXT1 = wxNewId();
const long frmAbout::ID_STATICLINE1 = wxNewId();
const long frmAbout::ID_STATICTEXT4 = wxNewId();
const long frmAbout::ID_STATICTEXT6 = wxNewId();
const long frmAbout::ID_HYPERLINKCTRL2 = wxNewId();
const long frmAbout::ID_STATICTEXT5 = wxNewId();
const long frmAbout::ID_HYPERLINKCTRL1 = wxNewId();
const long frmAbout::ID_STATICLINE3 = wxNewId();
const long frmAbout::ID_STATICTEXT3 = wxNewId();
const long frmAbout::ID_HYPERLINKCTRL3 = wxNewId();
const long frmAbout::ID_STATICBITMAP2 = wxNewId();
const long frmAbout::ID_STATICLINE2 = wxNewId();
const long frmAbout::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frmAbout,wxDialog)
    //(*EventTable(frmAbout)
    //*)
END_EVENT_TABLE()

frmAbout::frmAbout(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(frmAbout)
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("About..."), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
    BoxSizer2->Add(StaticBitmap1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    lblAppName = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxSize(304,13), 0, _T("ID_STATICTEXT2"));
    wxFont lblAppNameFont = wxSystemSettings::GetFont(wxSYS_SYSTEM_FONT);
    if ( !lblAppNameFont.Ok() ) lblAppNameFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    lblAppNameFont.SetWeight(wxBOLD);
    lblAppName->SetFont(lblAppNameFont);
    BoxSizer3->Add(lblAppName, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    lblVersion = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(lblVersion, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer3->Add(StaticLine1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lblAuthor = new wxStaticText(this, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer3->Add(lblAuthor, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    lblEmail = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer6->Add(lblEmail, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    linkEmail = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL2, _("link"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL2"));
    BoxSizer6->Add(linkEmail, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    lblWebsite = new wxStaticText(this, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer5->Add(lblWebsite, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    linkWebsite = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL1, _("link"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
    BoxSizer5->Add(linkWebsite, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    BoxSizer3->Add(StaticLine3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT3, _("This program is licensed under the terms\nof the GNU General Public License version 3:\n\nAvailable online under:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer3->Add(StaticText1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    HyperlinkCtrl1 = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL3, _("http://www.gnu.org/licenses/gpl-3.0.html"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL3"));
    BoxSizer3->Add(HyperlinkCtrl1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxNullBitmap, wxDefaultPosition, wxSize(127,51), 0, _T("ID_STATICBITMAP2"));
    BoxSizer3->Add(StaticBitmap2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer1->Add(StaticLine2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmAbout::OnbtnOKClick);
    //*)

    // Set labels
    lblAppName->SetLabel(APP_NAME);
    lblVersion->SetLabel(wxT("Version ") + APP_VERSION);
    lblAuthor->SetLabel(wxT("Author: ") + APP_AUTHOR);
    lblWebsite->SetLabel(wxT("Website: "));
    linkWebsite->SetLabel(APP_WEBSITE);
    linkWebsite->SetURL(APP_WEBSITE);
    lblEmail->SetLabel(wxT("E-mail: "));
    linkEmail->SetLabel(APP_EMAIL);
    linkEmail->SetURL(wxT("mailto:") + APP_EMAIL);

    // Load resource
    loadResources();
}

frmAbout::~frmAbout()
{
    //(*Destroy(frmAbout)
    //*)
}

void frmAbout::OnbtnOKClick(wxCommandEvent& event)
{
    Close();
}

void frmAbout::loadResources()
{
    // Images
    StaticBitmap1->SetBitmap(wxBitmap(wxImage(RESOURCE_DIR + _T("logos/logo.png"))));
    StaticBitmap2->SetBitmap(wxBitmap(wxImage(RESOURCE_DIR + _T("logos/gplv3-127x51.png"))));
}
