/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmMain.h"

#include "frmSettings.h"
#include "frmAbout.h"
#include "Progress.h"
#include "Conversion.h"
#include "Global.h"
#include "DndFile.h"

//(*InternalHeaders(frmMain)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

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
//*)

BEGIN_EVENT_TABLE(frmMain, wxFrame)
//(*EventTable(frmMain)
//*)
END_EVENT_TABLE()

frmMain::frmMain(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //(*Initialize(frmMain)
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem2;
    wxBoxSizer* BoxNormalVolume;
    wxMenu* Menu3;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem4;
    wxMenuItem* MenuItem11;
    wxMenuItem* MenuItem10;
    wxBoxSizer* BoxMain;
    wxMenuItem* MenuItem3;
    wxBoxSizer* BoxConstantGain;
    wxMenuItem* MenuItem6;
    wxMenu* Menu2;
    wxMenuItem* MenuItem9;
    wxMenu* Menu5;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(763, 450));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8, 16), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxMain = new wxBoxSizer(wxVERTICAL);
    BoxNormalVolume = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Target \"Normal\" volume:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxNormalVolume->Add(StaticText1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    txtNormalVolume = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    txtNormalVolume->SetMaxLength(5);
    BoxNormalVolume->Add(txtNormalVolume, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("dB. (Default 89.0 dB)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxNormalVolume->Add(StaticText2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxMain->Add(BoxNormalVolume, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxConstantGain = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Using constant gain: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxConstantGain->Add(StaticText3, 0, wxTOP | wxBOTTOM | wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    lblConstantGain = new wxStaticText(Panel1, ID_STATICTEXT4, _("+0 (+00.0 dB)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxConstantGain->Add(lblConstantGain, 1, wxTOP | wxBOTTOM | wxRIGHT | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxMain->Add(BoxConstantGain, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    lstFiles = new wxListCtrl(Panel1, ID_LISTCTRL2, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    BoxMain->Add(lstFiles, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxMain);
    BoxMain->Fit(Panel1);
    BoxMain->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu2 = new wxMenu();
    MenuItem17 = new wxMenuItem(Menu2, ID_MENUITEM17, _("Add F&older"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem17);
    MenuItem2 = new wxMenuItem(Menu2, ID_MENUITEM2, _("&Add Files"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    Menu2->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu2, ID_MENUITEM1, _("E&xit"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem1);
    MenuBar1->Append(Menu2, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM3, _("&Remove Files"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM4, _("&Clear List"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    Menu3->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM6, _("&Settings"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuBar1->Append(Menu3, _("&Edit"));
    Menu6 = new wxMenu();
    MenuItem14 = new wxMenuItem(Menu6, ID_MENUITEM14, _("&Track Analysis\tCtrl+T"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem14);
    Menu6->AppendSeparator();
    MenuItem15 = new wxMenuItem(Menu6, ID_MENUITEM15, _("Clea&r Analysis"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem15);
    MenuBar1->Append(Menu6, _("&Analysis"));
    Menu7 = new wxMenu();
    MenuItem16 = new wxMenuItem(Menu7, ID_MENUITEM16, _("Track &Gain\tCtrl+G"), wxEmptyString, wxITEM_NORMAL);
    Menu7->Append(MenuItem16);
    Menu7->AppendSeparator();
    MenuItem7 = new wxMenuItem(Menu7, ID_MENUITEM7, _("&Undo gain changes (based on stored tag info)\tCtrl+Z"), wxEmptyString, wxITEM_NORMAL);
    Menu7->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu7, ID_MENUITEM8, _("&Delete stored tag info"), wxEmptyString, wxITEM_NORMAL);
    Menu7->Append(MenuItem8);
    MenuBar1->Append(Menu7, _("&Gain"));
    Menu5 = new wxMenu();
    MenuItem12 = new wxMenuItem(Menu5, ID_MENUITEM10, _("&MP3gain Website"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem12);
    MenuItem13 = new wxMenuItem(Menu5, ID_MENUITEM11, _("&wxMP3gain Website"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem13);
    Menu5->AppendSeparator();
    MenuItem9 = new wxMenuItem(Menu5, ID_MENUITEM9, _("&About"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem9);
    MenuBar1->Append(Menu5, _("&Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, wxST_SIZEGRIP, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = {-10, -10};
    int __wxStatusBarStyles_1[2] = {wxSB_NORMAL, wxSB_NORMAL};
    StatusBar1->SetFieldsCount(2, __wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2, __wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_FLAT | wxTB_HORIZONTAL | wxTB_TEXT | wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARITEM8, _("Add folder"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(ID_TOOLBARITEM1, _("Add files"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem3 = ToolBar1->AddTool(ID_TOOLBARITEM2, _("Remove files"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem4 = ToolBar1->AddTool(ID_TOOLBARITEM3, _("Clear files"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem5 = ToolBar1->AddTool(ID_TOOLBARITEM4, _("Analysis"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem6 = ToolBar1->AddTool(ID_TOOLBARITEM5, _("Gain"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem7 = ToolBar1->AddTool(ID_TOOLBARITEM6, _("Settings"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem8 = ToolBar1->AddTool(ID_TOOLBARITEM7, _("About"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    MenuItem18 = new wxMenuItem((&Menu1), ID_MENUITEM18, _("Add F&older"), wxEmptyString, wxITEM_NORMAL);
    Menu1.Append(MenuItem18);
    MenuItem5 = new wxMenuItem((&Menu1), ID_MENUITEM5, _("&Add Files"), wxEmptyString, wxITEM_NORMAL);
    Menu1.Append(MenuItem5);
    MenuItem10 = new wxMenuItem((&Menu1), ID_MENUITEM12, _("&Remove files"), wxEmptyString, wxITEM_NORMAL);
    Menu1.Append(MenuItem10);
    MenuItem11 = new wxMenuItem((&Menu1), ID_MENUITEM13, _("&Clear list"), wxEmptyString, wxITEM_NORMAL);
    Menu1.Append(MenuItem11);
    Center();

    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_DELETE_ITEM, (wxObjectEventFunction) & frmMain::OnlstFilesDeleteItem);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_ITEM_SELECTED, (wxObjectEventFunction) & frmMain::OnlstFilesClick);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_ITEM_DESELECTED, (wxObjectEventFunction) & frmMain::OnlstFilesClick);
    Connect(ID_LISTCTRL2, wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, (wxObjectEventFunction) & frmMain::OnlstFilesItemRClick);
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
    //*)

    // If lost focus of txtNormalVolume
    txtNormalVolume->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(frmMain::OntxtNormalVolumeTextKillFocus), NULL, this);
    txtNormalVolume->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(frmMain::OntxtNormalVolumeText), NULL, this);

    // Aux list for wxListctrl
    lstFilesData = new ArrayOfFiles();

    // Support Drag & Drop
    lstFiles->SetDropTarget(new DndFile(lstFiles, lstFilesData));

    // Configuration file
    configBase = new ConfigBase(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Title List
    lstFiles->InsertColumn(0, _("File"), wxLIST_FORMAT_LEFT, 400);
    lstFiles->InsertColumn(1, _("Volume"), wxLIST_FORMAT_LEFT, 70);
    lstFiles->InsertColumn(2, _("Clipping"), wxLIST_FORMAT_LEFT, 70);
    lstFiles->InsertColumn(3, _("Gain (dB)"), wxLIST_FORMAT_LEFT, 70);
    lstFiles->InsertColumn(4, _("Gain (mp3)"), wxLIST_FORMAT_LEFT, 70);
    lstFiles->InsertColumn(5, _("Tag info"), wxLIST_FORMAT_LEFT, 70);

    // Updates the status bar
    updateStatusBar();

    // Updates the controls that should be disabled
    updateDisabledControls();

    // Update txtNormalVolume
    updateTxtNormalVolumeDb();

    boxMain = BoxMain;
    boxNormalVolume = BoxNormalVolume;
    boxConstantGain = BoxConstantGain;

    // Box visible: Normal Volume OR Constant gain
    if (configBase->getConstantGainEnabled())
        boxNormalVolume->Show(false);
    else
        boxConstantGain->Show(false);

    boxMain->Layout();
}

frmMain::~frmMain()
{
    //(*Destroy(frmMain)
    //*)

    // Deletes the object configuration file and updates the file / record
    delete configBase;
}

void frmMain::mnuAddFiles(wxCommandEvent& event)
{
    wxArrayString files;
    wxFileDialog FileDialog1(this, _("Select files"), wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    FileDialog1.SetDirectory(configBase->getLastOpenDir());

    if (FileDialog1.ShowModal() == wxID_OK)
    {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        FileDialog1.GetPaths(files);
        DndFile dndFile(lstFiles, lstFilesData);
        dndFile.InsertFileList(files);

        // Remembers the last used directory
        configBase->setLastOpenDir(FileDialog1.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
}

void frmMain::mnuAddDirectory(wxCommandEvent& event)
{
    wxDirDialog DirDialog1(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    DirDialog1.SetPath(configBase->getLastOpenDir());
    if (DirDialog1.ShowModal() == wxID_OK)
    {
        SetCursor(wxCURSOR_WAIT);
        DndFile dndFile(lstFiles, lstFilesData);
        dndFile.InsertFileListDir(DirDialog1.GetPath());

        // Remembers the last used directory
        configBase->setLastOpenDir(DirDialog1.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
}

void frmMain::mnuExit(wxCommandEvent& event)
{
    // Terminates the program
    Close();
}

void frmMain::mnuClearList(wxCommandEvent& event)
{
    // Deletes all items from the list
    lstFiles->DeleteAllItems();
    lstFilesData->Clear();

    updateDisabledControls();
}

void frmMain::mnuRemoveFiles(wxCommandEvent& event)
{
    int itemCount = lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++)
    {
        lstFiles->DeleteItem(lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED));
    }

    SetCursor(wxCURSOR_ARROW);

    updateDisabledControls();
}

void frmMain::mnuScan(wxCommandEvent& event)
{
    // Displays the "Progress" window
    Progress Dlg(0, configBase, lstFiles, lstFilesData, dblNormalVolume, TOOL_ANALYSIS);
    Dlg.Execute();
}

void frmMain::mnuFix(wxCommandEvent& event)
{
    // Displays the "Progress" window
    Progress Dlg(0, configBase, lstFiles, lstFilesData, dblNormalVolume, TOOL_GAIN);
    Dlg.Execute();
}

void frmMain::mnuUndoGain(wxCommandEvent& event)
{
    wxCommandEvent evt;

    // Displays the "Progress" window
    Progress Dlg(0, configBase, lstFiles, lstFilesData, dblNormalVolume, TOOL_UNDO);
    Dlg.Execute();

    mnuClearAnalysis(evt);
}

void frmMain::mnuRemoveTags(wxCommandEvent& event)
{
    wxCommandEvent evt;

    // Displays the "Progress" window
    Progress Dlg(0, configBase, lstFiles, lstFilesData, dblNormalVolume, TOOL_DELETE_TAG);
    Dlg.Execute();

    mnuClearAnalysis(evt);
}

void frmMain::OnlstFilesItemRClick(wxListEvent& event)
{
    updateDisabledControls();

    // Displays the popup menu when you click a list item
    lstFiles->PopupMenu(&Menu1);
}

void frmMain::OnlstFilesClick(wxListEvent& event)
{
    updateDisabledControls();
}

void frmMain::updateDisabledControls()
{
    // Disables the menu item "Remove files" if no item is selected
    Menu1.Enable(ID_MENUITEM12, lstFiles->GetSelectedItemCount() > 0);
    MenuBar1->Enable(ID_MENUITEM3, lstFiles->GetSelectedItemCount() > 0);
    ToolBar1->EnableTool(ID_TOOLBARITEM2, lstFiles->GetSelectedItemCount() > 0);

    // Disables the menu item "Clear list" if there is no item in the list
    Menu1.Enable(ID_MENUITEM13, lstFiles->GetItemCount() > 0);
    MenuBar1->Enable(ID_MENUITEM4, lstFiles->GetItemCount() > 0);
    ToolBar1->EnableTool(ID_TOOLBARITEM3, lstFiles->GetItemCount() > 0);

    // Disables menus Scan and Fix case there is no item in the list
    MenuBar1->Enable(ID_MENUITEM14, lstFiles->GetItemCount() > 0);
    MenuBar1->Enable(ID_MENUITEM15, lstFiles->GetItemCount() > 0);
    MenuBar1->Enable(ID_MENUITEM16, lstFiles->GetItemCount() > 0);
    MenuBar1->Enable(ID_MENUITEM7, lstFiles->GetItemCount() > 0 && configBase->getTagOptions() != 2);
    MenuBar1->Enable(ID_MENUITEM8, lstFiles->GetItemCount() > 0 && configBase->getTagOptions() != 2);
    ToolBar1->EnableTool(ID_TOOLBARITEM4, lstFiles->GetItemCount() > 0);
    ToolBar1->EnableTool(ID_TOOLBARITEM5, lstFiles->GetItemCount() > 0);
}

void frmMain::mnuSettings(wxCommandEvent& event)
{
    wxCommandEvent evt;
    int oldTagOptions = configBase->getTagOptions();
    bool oldTagForceEnabled = configBase->getTagForceEnabled();

    // Displays the "Settings" window
    frmSettings Dlg(this, configBase);
    Dlg.ShowModal();

    // Updates the box bar after closing the window "Settings"
    if (configBase->getConstantGainEnabled())
    {
        boxNormalVolume->Show(false);
        boxConstantGain->Show(true);
    }

    else
    {
        boxConstantGain->Show(false);
        boxNormalVolume->Show(true);
    }
    boxMain->Layout();

    if (oldTagOptions != configBase->getTagOptions() || oldTagForceEnabled != configBase->getTagForceEnabled())
        mnuClearAnalysis(evt);

    // Updates after closing the window "Settings"
    updateGainLabels(lstFiles, configBase, lstFilesData, dblNormalVolume);
    updateDisabledControls();
    updateStatusBar();
    updateTxtNormalVolumeDb();
}

void frmMain::updateStatusBar()
{
    wxArrayString inputString;
    wxArrayString inputErrorString;

    // Execute external application
    wxExecute(configBase->getToolExecutable() + wxT(" -v"), inputString, inputErrorString, wxEXEC_NODISABLE);

    // Show the version of tool
    if (!inputErrorString.IsEmpty())
        StatusBar1->SetStatusText(wxT("Using MP3gain version: ") + inputErrorString.Item(0).AfterLast(' '), 1);
    else
        StatusBar1->SetStatusText(wxT("MP3gain not found!"), 1);

    //Constant gain box
    lblConstantGain->SetLabel(wxString::Format(wxT("%+i"), configBase->getConstantGainValue()) + wxT(" (") + wxString::Format(wxT("%+.1f"), configBase->getConstantGainValue() * (5.0 * log10(2.0))) + wxT(" dB)"));
}

void frmMain::mnuAbout(wxCommandEvent& event)
{
    frmAbout Dlg(this);
    Dlg.ShowModal();
}

void frmMain::mnuWebsite(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(wxT("http://sourceforge.net/projects/wxmp3gain/"));
}

void frmMain::mnuToolWebsite(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(wxT("http://mp3gain.sourceforge.net/"));
}

void frmMain::loadResources()
{
    // Window icon
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(RESOURCE_DIR + _T("icon2.ico"))));
    SetIcon(FrameIcon);

    // Toolbar bitmaps
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM1, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/add.png"))));
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM2, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/remove.png"))));
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM3, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/clear.png"))));
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM4, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/analysis.png"))));
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM5, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/gain.png"))));
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM6, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/settings.png"))));
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM7, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/about.png"))));
    ToolBar1->SetToolNormalBitmap(ID_TOOLBARITEM8, wxBitmap(wxImage(RESOURCE_DIR + _T("toolbar/folder.png"))));
}

void frmMain::OntxtNormalVolumeText(wxCommandEvent& event)
{
    wxString strNormalVolume = txtNormalVolume->GetLineText(0);
    Conversion::convertDotComma(strNormalVolume);
    strNormalVolume.ToDouble(&dblNormalVolume);

    if (dblNormalVolume < 75)
        dblNormalVolume = 75.0;
    else if (dblNormalVolume > 105)
        dblNormalVolume = 105.0;

    updateGainLabels(lstFiles, configBase, lstFilesData, dblNormalVolume);
}

void frmMain::OntxtNormalVolumeTextKillFocus(wxFocusEvent& event)
{
    // Save the NormalVolumeDb
    configBase->setNormalVolumeDb((int) (float) (dblNormalVolume * 10.0));
    updateTxtNormalVolumeDb();
}

void frmMain::updateTxtNormalVolumeDb()
{
    dblNormalVolume = (double) (configBase->getNormalVolumeDb() / 10.0);
    txtNormalVolume->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(frmMain::OntxtNormalVolumeText), NULL, this);
    txtNormalVolume->Clear();
    txtNormalVolume->WriteText(wxString::Format(wxT("%.1f"), dblNormalVolume));
    txtNormalVolume->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(frmMain::OntxtNormalVolumeText), NULL, this);
}

void frmMain::OnlstFilesInsertItem(wxListEvent& event)
{
    updateDisabledControls();
}

void frmMain::OnlstFilesDeleteItem(wxListEvent& event)
{
    lstFilesData->Detach(event.GetIndex());
    updateDisabledControls();
}

void frmMain::updateGainLabels(wxListCtrl* listFilesUpdate, ConfigBase* configBaseUpdate, ArrayOfFiles* lstFilesDataUpdate, const double& dblNormalVolumeUpdate)
{
    for (int i = 0; i < listFilesUpdate->GetItemCount(); i++)
    {
        FileInfo& fileInfo = lstFilesDataUpdate->Item(i);

        // Update GainChange
        if (configBaseUpdate->getConstantGainEnabled())
        {
            fileInfo.setGainChange(configBaseUpdate->getConstantGainValue());
        }
        else
        {
            double dblGainChange = (dblNormalVolumeUpdate - fileInfo.getVolume()) / (5.0 * log10(2.0));
            int intGainChange = Conversion::convertDoubleToIntGain(dblGainChange);
            fileInfo.setGainChange(intGainChange);
        }

        // Correct gain if has clipping
        if (configBaseUpdate->getAutoLowerEnabled())
        {
            int maxNoclipMp3Gain = Conversion::getMaxNoclipMp3Gain(fileInfo.getMaxPcmSample());
            if (fileInfo.getGainChange() > maxNoclipMp3Gain)
                fileInfo.setGainChange(maxNoclipMp3Gain);
        }

        // Update the list itens
        if (fileInfo.isVolumeSet())
        {
            listFilesUpdate->SetItem(i, 4, wxString::Format(wxT("%i"), fileInfo.getGainChange()));
            listFilesUpdate->SetItem(i, 3, wxString::Format(wxT("%.1f"), fileInfo.getGainChange() * (5.0 * log10(2.0))));
        }
        else
        {
            listFilesUpdate->SetItem(i, 4, wxT(""));
            listFilesUpdate->SetItem(i, 3, wxT(""));
        }
    }
}

void frmMain::mnuClearAnalysis(wxCommandEvent& event)
{
    for (int i = 0; i < lstFiles->GetItemCount(); i++)
    {
        FileInfo& fileInfo = lstFilesData->Item(i);
        fileInfo.volumeReset();
        lstFiles->SetItem(i, 1, wxT(""));
        lstFiles->SetItem(i, 2, wxT(""));
        lstFiles->SetItem(i, 3, wxT(""));
        lstFiles->SetItem(i, 4, wxT(""));
        lstFiles->SetItem(i, 5, wxT(""));
        lstFiles->SetItemTextColour(i, *wxBLACK);
    }
}

