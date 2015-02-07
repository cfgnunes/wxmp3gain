/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmMain.h"
#include "frmSettings.h"
#include "Progress.h"
#include "Conversion.h"
#include "Global.h"
#include "DndFile.h"

//(*InternalHeaders(frmMain)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include <wx/aboutdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>

//(*IdInit(frmMain)
const long frmMain::ID_STATICTEXT1 = wxNewId();
const long frmMain::ID_TEXTCTRL1 = wxNewId();
const long frmMain::ID_STATICTEXT2 = wxNewId();
const long frmMain::ID_STATICTEXT3 = wxNewId();
const long frmMain::ID_STATICTEXT4 = wxNewId();
const long frmMain::ID_LISTCTRL2 = wxNewId();
const long frmMain::ID_PANEL1 = wxNewId();
const long frmMain::ID_MENUITEM17 = wxNewId();
const long frmMain::ID_MENUITEM2 = wxNewId();
const long frmMain::ID_MENUITEM1 = wxNewId();
const long frmMain::ID_MENUITEM3 = wxNewId();
const long frmMain::ID_MENUITEM4 = wxNewId();
const long frmMain::ID_MENUITEM6 = wxNewId();
const long frmMain::ID_MENUITEM14 = wxNewId();
const long frmMain::ID_MENUITEM15 = wxNewId();
const long frmMain::ID_MENUITEM16 = wxNewId();
const long frmMain::ID_MENUITEM7 = wxNewId();
const long frmMain::ID_MENUITEM8 = wxNewId();
const long frmMain::ID_MENUITEM10 = wxNewId();
const long frmMain::ID_MENUITEM11 = wxNewId();
const long frmMain::ID_MENUITEM9 = wxNewId();
const long frmMain::ID_STATUSBAR1 = wxNewId();
const long frmMain::ID_TOOLBARITEM8 = wxNewId();
const long frmMain::ID_TOOLBARITEM1 = wxNewId();
const long frmMain::ID_TOOLBARITEM2 = wxNewId();
const long frmMain::ID_TOOLBARITEM3 = wxNewId();
const long frmMain::ID_TOOLBARITEM4 = wxNewId();
const long frmMain::ID_TOOLBARITEM5 = wxNewId();
const long frmMain::ID_TOOLBARITEM6 = wxNewId();
const long frmMain::ID_TOOLBARITEM7 = wxNewId();
const long frmMain::ID_TOOLBAR1 = wxNewId();
const long frmMain::ID_MENUITEM18 = wxNewId();
const long frmMain::ID_MENUITEM5 = wxNewId();
const long frmMain::ID_MENUITEM12 = wxNewId();
const long frmMain::ID_MENUITEM13 = wxNewId();
const long frmMain::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frmMain, wxFrame)
//(*EventTable(frmMain)
//*)
END_EVENT_TABLE()

frmMain::frmMain(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) {
    //(*Initialize(frmMain)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu5;
    wxMenu* Menu3;
    wxBoxSizer* BoxConstantGain;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem9;
    wxMenuItem* MenuItem11;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem10;
    wxMenuItem* MenuItem6;
    wxMenuItem* MenuItem4;
    wxBoxSizer* BoxMain;
    wxBoxSizer* BoxNormalVolume;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(763, 450));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8, 16), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxMain = new wxBoxSizer(wxVERTICAL);
    BoxNormalVolume = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Normal volume (dB):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxNormalVolume->Add(StaticText1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_txtNormalVolume = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    g_txtNormalVolume->SetMaxLength(5);
    BoxNormalVolume->Add(g_txtNormalVolume, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("(Default 89.0 dB)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxNormalVolume->Add(StaticText2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxMain->Add(BoxNormalVolume, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxConstantGain = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Using constant gain: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxConstantGain->Add(StaticText3, 0, wxTOP | wxBOTTOM | wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_lblConstantGain = new wxStaticText(Panel1, ID_STATICTEXT4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxConstantGain->Add(g_lblConstantGain, 1, wxTOP | wxBOTTOM | wxRIGHT | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxMain->Add(BoxConstantGain, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_lstFiles = new wxListCtrl(Panel1, ID_LISTCTRL2, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    g_lstFiles->SetFocus();
    BoxMain->Add(g_lstFiles, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxMain);
    BoxMain->Fit(Panel1);
    BoxMain->SetSizeHints(Panel1);
    g_mainMenuBar = new wxMenuBar();
    Menu2 = new wxMenu();
    MenuItem17 = new wxMenuItem(Menu2, ID_MENUITEM17, _("Add folder"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem17);
    MenuItem2 = new wxMenuItem(Menu2, ID_MENUITEM2, _("Add files"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    Menu2->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu2, ID_MENUITEM1, _("Exit"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem1);
    g_mainMenuBar->Append(Menu2, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Remove files"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Clear list"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    Menu3->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM6, _("Settings"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    g_mainMenuBar->Append(Menu3, _("&Edit"));
    Menu6 = new wxMenu();
    MenuItem14 = new wxMenuItem(Menu6, ID_MENUITEM14, _("Analyze"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem14);
    Menu6->AppendSeparator();
    MenuItem15 = new wxMenuItem(Menu6, ID_MENUITEM15, _("Clear analysis"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem15);
    g_mainMenuBar->Append(Menu6, _("&Analysis"));
    Menu7 = new wxMenu();
    MenuItem16 = new wxMenuItem(Menu7, ID_MENUITEM16, _("Gain"), wxEmptyString, wxITEM_NORMAL);
    Menu7->Append(MenuItem16);
    Menu7->AppendSeparator();
    MenuItem7 = new wxMenuItem(Menu7, ID_MENUITEM7, _("Undo gain changes (based on stored tag info)\tCtrl+Z"), wxEmptyString, wxITEM_NORMAL);
    Menu7->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu7, ID_MENUITEM8, _("Delete stored tag info"), wxEmptyString, wxITEM_NORMAL);
    Menu7->Append(MenuItem8);
    g_mainMenuBar->Append(Menu7, _("&Gain"));
    Menu5 = new wxMenu();
    MenuItem12 = new wxMenuItem(Menu5, ID_MENUITEM10, _("MP3gain Website"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem12);
    MenuItem13 = new wxMenuItem(Menu5, ID_MENUITEM11, _("wxMP3gain Website"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem13);
    Menu5->AppendSeparator();
    MenuItem9 = new wxMenuItem(Menu5, ID_MENUITEM9, _("About"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem9);
    g_mainMenuBar->Append(Menu5, _("&Help"));
    SetMenuBar(g_mainMenuBar);
    g_mainStatusBar = new wxStatusBar(this, ID_STATUSBAR1, wxST_SIZEGRIP, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[3] = {-10, -5, -10};
    int __wxStatusBarStyles_1[3] = {wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL};
    g_mainStatusBar->SetFieldsCount(3, __wxStatusBarWidths_1);
    g_mainStatusBar->SetStatusStyles(3, __wxStatusBarStyles_1);
    SetStatusBar(g_mainStatusBar);
    g_mainToolBar = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_FLAT | wxTB_HORIZONTAL | wxTB_TEXT | wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = g_mainToolBar->AddTool(ID_TOOLBARITEM8, _("Add folder"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem2 = g_mainToolBar->AddTool(ID_TOOLBARITEM1, _("Add files"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem3 = g_mainToolBar->AddTool(ID_TOOLBARITEM2, _("Remove files"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem4 = g_mainToolBar->AddTool(ID_TOOLBARITEM3, _("Clear list"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    g_mainToolBar->AddSeparator();
    ToolBarItem5 = g_mainToolBar->AddTool(ID_TOOLBARITEM4, _("Analyze"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem6 = g_mainToolBar->AddTool(ID_TOOLBARITEM5, _("Gain"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    g_mainToolBar->AddSeparator();
    ToolBarItem7 = g_mainToolBar->AddTool(ID_TOOLBARITEM6, _("Settings"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem8 = g_mainToolBar->AddTool(ID_TOOLBARITEM7, _("About"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    g_mainToolBar->Realize();
    SetToolBar(g_mainToolBar);
    MenuItem18 = new wxMenuItem((&g_mainMenu), ID_MENUITEM18, _("Add folder"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem18);
    MenuItem5 = new wxMenuItem((&g_mainMenu), ID_MENUITEM5, _("Add files"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem5);
    MenuItem10 = new wxMenuItem((&g_mainMenu), ID_MENUITEM12, _("Remove files"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem10);
    MenuItem11 = new wxMenuItem((&g_mainMenu), ID_MENUITEM13, _("Clear list"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem11);
    Timer1.SetOwner(this, ID_TIMER1);
    Center();

    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_DELETE_ITEM, (wxObjectEventFunction) & frmMain::OnlstFilesDeleteItem);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_ITEM_SELECTED, (wxObjectEventFunction) & frmMain::OnlstFilesInsertItem);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_ITEM_DESELECTED, (wxObjectEventFunction) & frmMain::OnlstFilesInsertItem);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, (wxObjectEventFunction) & frmMain::OnlstFilesItemRClick);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_KEY_DOWN, (wxObjectEventFunction) & frmMain::OnlstFilesKeyDown);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_INSERT_ITEM, (wxObjectEventFunction) & frmMain::OnlstFilesInsertItem);
    Connect(ID_MENUITEM17, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddDirectory);
    Connect(ID_MENUITEM2, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddFiles);
    Connect(ID_MENUITEM1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuExit);
    Connect(ID_MENUITEM3, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuRemoveFiles);
    Connect(ID_MENUITEM4, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuClearList);
    Connect(ID_MENUITEM6, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuSettings);
    Connect(ID_MENUITEM14, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuScan);
    Connect(ID_MENUITEM15, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuClearAnalysis);
    Connect(ID_MENUITEM16, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuFix);
    Connect(ID_MENUITEM7, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuUndoGain);
    Connect(ID_MENUITEM8, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuRemoveTags);
    Connect(ID_MENUITEM10, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuToolWebsite);
    Connect(ID_MENUITEM11, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuWebsite);
    Connect(ID_MENUITEM9, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAbout);
    Connect(ID_TOOLBARITEM8, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuAddDirectory);
    Connect(ID_TOOLBARITEM1, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuAddFiles);
    Connect(ID_TOOLBARITEM2, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuRemoveFiles);
    Connect(ID_TOOLBARITEM3, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuClearList);
    Connect(ID_TOOLBARITEM4, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuScan);
    Connect(ID_TOOLBARITEM5, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuFix);
    Connect(ID_TOOLBARITEM6, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuSettings);
    Connect(ID_TOOLBARITEM7, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuAbout);
    Connect(ID_MENUITEM18, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddDirectory);
    Connect(ID_MENUITEM5, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddFiles);
    Connect(ID_MENUITEM12, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuRemoveFiles);
    Connect(ID_MENUITEM13, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuClearList);
    Connect(ID_TIMER1, wxEVT_TIMER, (wxObjectEventFunction) & frmMain::OnTimer1Trigger);
    //*)

    // If lost focus of txtNormalVolume
    g_txtNormalVolume->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(frmMain::OntxtNormalVolumeTextKillFocus), NULL, this);

    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // Aux list for wxListctrl
    mp_lstFilesData = new ArrayOfFiles();

    // Support Drag & Drop
    g_lstFiles->SetDropTarget(new DndFile(g_lstFiles, mp_lstFilesData));

    // Configuration file
    mp_configBase = new ConfigBase(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Title List
    g_lstFiles->InsertColumn(0, _("File"), wxLIST_FORMAT_LEFT, 350);
    g_lstFiles->InsertColumn(1, _("Volume"), wxLIST_FORMAT_LEFT, 70);
    g_lstFiles->InsertColumn(2, _("Clipping"), wxLIST_FORMAT_LEFT, 80);
    g_lstFiles->InsertColumn(3, _("Gain (dB)"), wxLIST_FORMAT_LEFT, 85);
    g_lstFiles->InsertColumn(4, _("Gain (mp3)"), wxLIST_FORMAT_LEFT, 85);
    g_lstFiles->InsertColumn(5, _("Tag info"), wxLIST_FORMAT_LEFT, 80);

    // Updates the controls
    updateControls();

    // Update txtNormalVolume
    updateTxtNormalVolumeDb();

    g_boxMain = BoxMain;
    g_boxNormalVolume = BoxNormalVolume;
    g_boxConstantGain = BoxConstantGain;

    // Box visible: Normal Volume OR Constant gain
    if (mp_configBase->getConstantGainEnabled())
        g_boxNormalVolume->Show(false);
    else
        g_boxConstantGain->Show(false);

    g_boxMain->Layout();
}

frmMain::~frmMain() {
    delete mp_lstFilesData;

    // Deletes the object configuration file and updates the file / record
    delete mp_configBase;
}

void frmMain::setFilesCmdLine(const wxArrayString& filenames) {
    DndFile dndFile(g_lstFiles, mp_lstFilesData);
    dndFile.OnDropFiles(0, 0, filenames);
}

void frmMain::mnuAddFiles(wxCommandEvent& event) {
    wxArrayString files;
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_configBase->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        DndFile dndFile(g_lstFiles, mp_lstFilesData);
        dndFile.insertFileList(files);

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
}

void frmMain::mnuAddDirectory(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_configBase->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        DndFile dndFile(g_lstFiles, mp_lstFilesData);
        dndFile.insertFileListDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
}

void frmMain::mnuExit(wxCommandEvent& event) {
    // Terminates the program
    Close();
}

void frmMain::mnuClearList(wxCommandEvent& event) {
    // Deletes all items from the list
    g_lstFiles->DeleteAllItems();
    mp_lstFilesData->Clear();

    updateControls();
}

void frmMain::mnuRemoveFiles(wxCommandEvent& event) {
    int itemCount = g_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++) {
        g_lstFiles->DeleteItem(g_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED));
    }

    SetCursor(wxCURSOR_ARROW);

    updateControls();
}

void frmMain::mnuScan(wxCommandEvent& event) {
    // Displays the "Progress" window
    Progress progressDialog(0, mp_configBase, g_lstFiles, mp_lstFilesData, m_dblNormalVolume, TOOL_ANALYSIS);
    progressDialog.Execute();
}

void frmMain::mnuFix(wxCommandEvent& event) {
    // Displays the "Progress" window
    Progress progressDialog(0, mp_configBase, g_lstFiles, mp_lstFilesData, m_dblNormalVolume, TOOL_GAIN);
    progressDialog.Execute();
}

void frmMain::mnuUndoGain(wxCommandEvent& event) {
    wxCommandEvent evt;

    // Displays the "Progress" window
    Progress progressDialog(0, mp_configBase, g_lstFiles, mp_lstFilesData, m_dblNormalVolume, TOOL_UNDO);
    progressDialog.Execute();

    mnuClearAnalysis(evt);
}

void frmMain::mnuRemoveTags(wxCommandEvent& event) {
    wxCommandEvent evt;

    // Displays the "Progress" window
    Progress progressDialog(0, mp_configBase, g_lstFiles, mp_lstFilesData, m_dblNormalVolume, TOOL_DELETE_TAG);
    progressDialog.Execute();

    mnuClearAnalysis(evt);
}

void frmMain::mnuSettings(wxCommandEvent& event) {
    wxCommandEvent evt;
    int oldTagOptions = mp_configBase->getTagOptions();
    bool oldTagForceEnabled = mp_configBase->getTagForceEnabled();

    // Displays the "Settings" window
    frmSettings Dlg(this, mp_configBase);
    Dlg.ShowModal();

    // Updates the box bar after closing the window "Settings"
    if (mp_configBase->getConstantGainEnabled()) {
        g_boxNormalVolume->Show(false);
        g_boxConstantGain->Show(true);
    } else {
        g_boxConstantGain->Show(false);
        g_boxNormalVolume->Show(true);
    }
    g_boxMain->Layout();

    if (oldTagOptions != mp_configBase->getTagOptions() || oldTagForceEnabled != mp_configBase->getTagForceEnabled())
        mnuClearAnalysis(evt);

    // Updates after closing the window "Settings"
    updateControls();
    updateTxtNormalVolumeDb();
    updateGainLabels(g_lstFiles, mp_configBase, mp_lstFilesData, m_dblNormalVolume);
}

void frmMain::mnuAbout(wxCommandEvent& event) {
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(APP_NAME);
    aboutInfo.SetVersion(APP_VERSION);
    aboutInfo.SetDescription(_("Free front-end for the MP3gain"));
    aboutInfo.SetCopyright(APP_COPYRIGHT);
    aboutInfo.SetWebSite(APP_WEBSITE);
    aboutInfo.AddDeveloper(APP_AUTHOR);
    aboutInfo.AddTranslator(APP_AUTHOR);
    aboutInfo.AddTranslator(_T("Carlos Sánchez <carlos1994sanchez@gmail.com>"));
    aboutInfo.AddTranslator(_T("Jan Rimmek <jan@rimmek.de>"));
    aboutInfo.AddTranslator(_T("Sergey Basalaev <sbasalaev@gmail.com>"));
    aboutInfo.AddTranslator(_T("Pavel Fric <pavelfric@seznam.cz>"));
    wxAboutBox(aboutInfo);
}

void frmMain::mnuWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(APP_WEBSITE);
}

void frmMain::mnuToolWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(_T("http://mp3gain.sourceforge.net/"));
}

void frmMain::loadResources() {
    wxString resourceDir = GetResourceDir();

    // Window icon
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(resourceDir + _T("icon2.ico"))));
    SetIcon(FrameIcon);

    // Toolbar bitmaps
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM1, wxBitmap(wxImage(resourceDir + _T("toolbar/add.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM2, wxBitmap(wxImage(resourceDir + _T("toolbar/remove.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM3, wxBitmap(wxImage(resourceDir + _T("toolbar/clear.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM4, wxBitmap(wxImage(resourceDir + _T("toolbar/analysis.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM5, wxBitmap(wxImage(resourceDir + _T("toolbar/gain.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM6, wxBitmap(wxImage(resourceDir + _T("toolbar/settings.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM7, wxBitmap(wxImage(resourceDir + _T("toolbar/about.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM8, wxBitmap(wxImage(resourceDir + _T("toolbar/folder.png"))));
}

void frmMain::OntxtNormalVolumeTextKillFocus(wxFocusEvent& event) {
    wxString strNormalVolume = g_txtNormalVolume->GetLineText(0);
    Conversion::convertDotComma(strNormalVolume);
    strNormalVolume.ToDouble(&m_dblNormalVolume);

    if (m_dblNormalVolume < 75)
        m_dblNormalVolume = 75.0;
    else if (m_dblNormalVolume > 105)
        m_dblNormalVolume = 105.0;

    updateGainLabels(g_lstFiles, mp_configBase, mp_lstFilesData, m_dblNormalVolume);

    // Save the NormalVolumeDb
    mp_configBase->setNormalVolumeDb((int) (float) (m_dblNormalVolume * 10.0));
    updateTxtNormalVolumeDb();

    event.Skip();
}

void frmMain::updateTxtNormalVolumeDb() {
    m_dblNormalVolume = (double) (mp_configBase->getNormalVolumeDb() / 10.0);
    g_txtNormalVolume->Clear();
    g_txtNormalVolume->WriteText(wxString::Format(_T("%.1f"), m_dblNormalVolume));
}

void frmMain::updateGainLabels(wxListCtrl* listFilesUpdate, ConfigBase* configBaseUpdate, ArrayOfFiles* lstFilesDataUpdate, const double& dblNormalVolumeUpdate) {
    for (int i = 0; i < listFilesUpdate->GetItemCount(); i++) {
        FileInfo& fileInfo = lstFilesDataUpdate->Item(i);

        // Update GainChange
        if (configBaseUpdate->getConstantGainEnabled()) {
            fileInfo.setGainChange(configBaseUpdate->getConstantGainValue());
        } else {
            double dblGainChange = (dblNormalVolumeUpdate - fileInfo.getVolume()) / (5.0 * log10(2.0));
            int intGainChange = Conversion::convertDoubleToIntGain(dblGainChange);
            fileInfo.setGainChange(intGainChange);
        }

        // Correct gain if has clipping
        if (configBaseUpdate->getAutoLowerEnabled()) {
            int maxNoclipMp3Gain = Conversion::getMaxNoclipMp3Gain(fileInfo.getMaxPcmSample());
            if (fileInfo.getGainChange() > maxNoclipMp3Gain)
                fileInfo.setGainChange(maxNoclipMp3Gain);
        }

        // Update the list itens
        if (fileInfo.isVolumeSet()) {
            listFilesUpdate->SetItem(i, 4, wxString::Format(_T("%i"), fileInfo.getGainChange()));
            listFilesUpdate->SetItem(i, 3, wxString::Format(_T("%.1f"), fileInfo.getGainChange() * (5.0 * log10(2.0))));
        } else {
            listFilesUpdate->SetItem(i, 4, _T(""));
            listFilesUpdate->SetItem(i, 3, _T(""));
        }
    }
}

void frmMain::mnuClearAnalysis(wxCommandEvent& event) {
    for (int i = 0; i < g_lstFiles->GetItemCount(); i++) {
        FileInfo& fileInfo = mp_lstFilesData->Item(i);
        fileInfo.volumeReset();
        g_lstFiles->SetItem(i, 1, _T(""));
        g_lstFiles->SetItem(i, 2, _T(""));
        g_lstFiles->SetItem(i, 3, _T(""));
        g_lstFiles->SetItem(i, 4, _T(""));
        g_lstFiles->SetItem(i, 5, _T(""));
        g_lstFiles->SetItemTextColour(i, *wxBLACK);
    }
}

void frmMain::OnlstFilesItemRClick(wxListEvent& event) {
    updateControls();

    // Displays the popup menu when you click a list item
    g_lstFiles->PopupMenu(&g_mainMenu);
    event.Skip();
}

void frmMain::OnlstFilesDeleteItem(wxListEvent& event) {
    mp_lstFilesData->Detach(event.GetIndex());
    updateControls();
    event.Skip();
}

void frmMain::OnlstFilesInsertItem(wxListEvent& event) {
    updateControls();
    event.Skip();
}

void frmMain::updateControls() {
    Timer1.Start(10, true);
}

void frmMain::OnTimer1Trigger(wxTimerEvent& event) {
    wxString newExeTool = mp_configBase->getToolExecutable();
    if (!m_exeTool.IsSameAs(newExeTool, false)) {
        m_exeInputString.Clear();
        m_exeInputErrorString.Clear();
        m_exeTool = newExeTool;
        // Execute external application
        wxExecute(m_exeTool + _T(" -v"), m_exeInputString, m_exeInputErrorString, wxEXEC_NODISABLE);

        // Show the version of tool
        if (!m_exeInputErrorString.IsEmpty())
            g_mainStatusBar->SetStatusText(_("Using MP3gain version: ") + m_exeInputErrorString.Item(0).AfterLast(' '), 0);
        else
            g_mainStatusBar->SetStatusText(_("MP3gain not found!"), 0);
    }

    // Show the number of files in list on status bar
    g_mainStatusBar->SetStatusText(wxString::Format(_T("%i "), g_lstFiles->GetItemCount()) + _("files"), 1);

    // Constant gain box
    g_lblConstantGain->SetLabel(wxString::Format(_T("%+i"), mp_configBase->getConstantGainValue()) + _T(" (") + wxString::Format(_T("%+.1f"), mp_configBase->getConstantGainValue() * (5.0 * log10(2.0))) + _T(" dB)"));

    // Disables the menu item "Remove files" if no item is selected
    g_mainMenu.Enable(ID_MENUITEM12, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM3, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM2, g_lstFiles->GetSelectedItemCount() > 0);

    // Disables the menu item "Clear list" if there is no item in the list
    g_mainMenu.Enable(ID_MENUITEM13, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM4, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM3, g_lstFiles->GetItemCount() > 0);

    // Disables menus Scan and Fix case there is no item in the list
    g_mainMenuBar->Enable(ID_MENUITEM14, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM15, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM16, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM7, g_lstFiles->GetItemCount() > 0 && mp_configBase->getTagOptions() != 2);
    g_mainMenuBar->Enable(ID_MENUITEM8, g_lstFiles->GetItemCount() > 0 && mp_configBase->getTagOptions() != 2);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM4, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM5, g_lstFiles->GetItemCount() > 0);
}

void frmMain::OnlstFilesKeyDown(wxListEvent& event) {
    // Remove files with Delete key
    int keyCode = event.GetKeyCode();
    if (keyCode == WXK_DELETE)
        mnuRemoveFiles(event);

    event.Skip();
}
