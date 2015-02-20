/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiMain.h"
#include "GuiSettings.h"
#include "Progress.h"
#include "Conversion.h"
#include "Constants.h"

#include <wx/aboutdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>

GuiMain::GuiMain(wxWindow* parent)
: Main(parent) {
    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // File list manager
    mp_fileListManager = new FileListManager(g_lstFiles);

    // List Drag & Drop
    mp_dndFile = new DndFile(mp_fileListManager);
    g_lstFiles->SetDropTarget(mp_dndFile);

    // Title List
    g_lstFiles->InsertColumn(ID_LIST_FILE, _("File"), wxLIST_FORMAT_LEFT, 200);
    g_lstFiles->InsertColumn(ID_LIST_FOLDER, _("Folder"), wxLIST_FORMAT_LEFT, 200);
    g_lstFiles->InsertColumn(ID_LIST_VOLUME, _("Volume"), wxLIST_FORMAT_LEFT, 60);
    g_lstFiles->InsertColumn(ID_LIST_CLIPPING, _("Clipping"), wxLIST_FORMAT_LEFT, 70);
    g_lstFiles->InsertColumn(ID_LIST_GAIN_DB, _("Gain (dB)"), wxLIST_FORMAT_LEFT, 80);
    g_lstFiles->InsertColumn(ID_LIST_GAIN_MP3, _("Gain (mp3)"), wxLIST_FORMAT_LEFT, 80);
    g_lstFiles->InsertColumn(ID_LIST_TAG_INFO, _("Tag info"), wxLIST_FORMAT_LEFT, 70);

    // Set statusbar widths
    const int wxStatusBarWidths [3] = {-10, -5, -10};
    g_mainStatusBar->SetStatusWidths(3, wxStatusBarWidths);

    // Configuration file
    mp_configBase = new ConfigBase(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Updates the controls
    updateControls();

    // Update txtNormalVolume
    updateTxtNormalVolumeDb();

    // Box visible: Normal Volume OR Constant gain
    if (mp_configBase->getConstantGainEnabled())
        g_boxNormalVolume->Show(false);
    else
        g_boxConstantGain->Show(false);

    g_boxMain->Layout();
}

void GuiMain::OntxtNormalVolumeTextKillFocus(wxFocusEvent& event) {
    wxString strNormalVolume = g_txtNormalVolume->GetLineText(0);
    Conversion::convertDotComma(strNormalVolume);
    strNormalVolume.ToDouble(&m_dblNormalVolume);

    if (m_dblNormalVolume < 75)
        m_dblNormalVolume = 75.0;
    else if (m_dblNormalVolume > 105)
        m_dblNormalVolume = 105.0;

    mp_fileListManager->updateGainLabels(m_dblNormalVolume, mp_configBase);

    // Save the NormalVolumeDb
    mp_configBase->setNormalVolumeDb((int) (float) (m_dblNormalVolume * 10.0));
    updateTxtNormalVolumeDb();

    event.Skip();
}

GuiMain::~GuiMain() {
    delete mp_fileListManager;
    delete mp_configBase;
}

void GuiMain::OnlstFilesDeleteItem(wxListEvent& event) {
    mp_fileListManager->deleteItem(event.GetIndex());

    updateControls();
    event.Skip();
}

void GuiMain::OnlstFilesInsertItem(wxListEvent& event) {
    updateControls();
    event.Skip();
}

void GuiMain::OnlstFilesItemSelect(wxListEvent& event) {
    updateControls();
    event.Skip();
}

void GuiMain::OnlstFilesItemRClick(wxListEvent& event) {
    updateControls();

    // Displays the popup menu when you click a list item
    g_lstFiles->PopupMenu(g_mainMenu);
    event.Skip();
}

void GuiMain::OnlstFilesKeyDown(wxListEvent& event) {
    // Remove files with Delete key
    int keyCode = event.GetKeyCode();
    if (keyCode == WXK_DELETE)
        mnuRemoveFiles(event);

    event.Skip();
}

void GuiMain::mnuAddDirectory(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_configBase->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        mp_fileListManager->insertDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
}

void GuiMain::mnuAddFiles(wxCommandEvent& event) {
    wxArrayString files;
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_configBase->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        mp_fileListManager->insertFiles(files);

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
}

void GuiMain::mnuExit(wxCommandEvent& event) {
    // Terminates the program
    Close();
}

void GuiMain::mnuRemoveFiles(wxCommandEvent& event) {
    int itemCount = g_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++)
        g_lstFiles->DeleteItem(g_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED));
    SetCursor(wxCURSOR_ARROW);

    updateControls();
}

void GuiMain::mnuClearList(wxCommandEvent& event) {
    // Deletes all items from the list
    mp_fileListManager->clear();

    updateControls();
}

void GuiMain::mnuSettings(wxCommandEvent & event) {
    wxCommandEvent evt;
    int oldTagOptions = mp_configBase->getTagOptions();
    bool oldTagForceEnabled = mp_configBase->getTagForceEnabled();

    // Displays the "Settings" window
    GuiSettings guiSettings(this, mp_configBase);
    guiSettings.ShowModal();

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
    mp_fileListManager->updateGainLabels(m_dblNormalVolume, mp_configBase);
}

void GuiMain::mnuClearAnalysis(wxCommandEvent& event) {
    for (unsigned long int i = 0; i < mp_fileListManager->size(); i++) {
        FileInfo& fileInfo = mp_fileListManager->getItem(i);
        fileInfo.volumeReset();
        g_lstFiles->SetItem(i, 2, _T(""));
        g_lstFiles->SetItem(i, 3, _T(""));
        g_lstFiles->SetItem(i, 4, _T(""));
        g_lstFiles->SetItem(i, 5, _T(""));
        g_lstFiles->SetItem(i, 6, _T(""));
        g_lstFiles->SetItemTextColour(i, *wxBLACK);
    }
}

void GuiMain::mnuAnalyze(wxCommandEvent& event) {
    // Displays the "Progress" window
    Progress progressDialog(this, mp_configBase, mp_fileListManager, m_dblNormalVolume, TOOL_ANALYSIS);
    progressDialog.execute();
}

void GuiMain::mnuGain(wxCommandEvent& event) {
    // Displays the "Progress" window
    Progress progressDialog(this, mp_configBase, mp_fileListManager, m_dblNormalVolume, TOOL_GAIN);
    progressDialog.execute();
}

void GuiMain::mnuUndoGain(wxCommandEvent& event) {
    wxCommandEvent evt;

    // Displays the "Progress" window
    Progress progressDialog(this, mp_configBase, mp_fileListManager, m_dblNormalVolume, TOOL_UNDO);
    progressDialog.execute();

    mnuClearAnalysis(evt);
}

void GuiMain::mnuDeleteTag(wxCommandEvent& event) {
    wxCommandEvent evt;

    // Displays the "Progress" window
    Progress progressDialog(this, mp_configBase, mp_fileListManager, m_dblNormalVolume, TOOL_DELETE_TAG);
    progressDialog.execute();

    mnuClearAnalysis(evt);
}

void GuiMain::mnuToolWebsite(wxCommandEvent & event) {
    wxLaunchDefaultBrowser(_T("http://mp3gain.sourceforge.net/"));
}

void GuiMain::mnuWebsite(wxCommandEvent & event) {
    wxLaunchDefaultBrowser(APP_WEBSITE);
}

void GuiMain::mnuAbout(wxCommandEvent& event) {
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

void GuiMain::OnTimer1Trigger(wxTimerEvent& event) {
    wxString newExeTool = APP_TOOL_EXECUTABLE;
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
    g_mainMenu->Enable(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainMenuBar->Enable(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainToolBar->EnableTool(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0);

    // Disables the menu item "Clear list" if there is no item in the list
    g_mainMenu->Enable(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0);

    // Disables menus when there is no item in the list
    g_mainMenuBar->Enable(ID_ANALYZE, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_CLEAR_ANALYSIS, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_GAIN, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_UNDO_GAIN, g_lstFiles->GetItemCount() > 0 && mp_configBase->getTagOptions() != 2);
    g_mainMenuBar->Enable(ID_DELETE_TAG, g_lstFiles->GetItemCount() > 0 && mp_configBase->getTagOptions() != 2);
    g_mainToolBar->EnableTool(ID_ANALYZE, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_GAIN, g_lstFiles->GetItemCount() > 0);
}

void GuiMain::loadResources() {
    wxString resourceDir = GetResourceDir();

    // Window icon
    wxIcon frameIcon;
    frameIcon.CopyFromBitmap(wxBitmap(wxImage(resourceDir + _T("icon-frame.ico"))));
    SetIcon(frameIcon);

    // Toolbar bitmaps
    g_mainToolBar->SetToolNormalBitmap(ID_ADD_FILES, wxBitmap(wxImage(resourceDir + _T("toolbar/add-file.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ADD_FOLDER, wxBitmap(wxImage(resourceDir + _T("toolbar/add-folder.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_REMOVE_FILES, wxBitmap(wxImage(resourceDir + _T("toolbar/remove.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_CLEAR_LIST, wxBitmap(wxImage(resourceDir + _T("toolbar/clear.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ANALYZE, wxBitmap(wxImage(resourceDir + _T("toolbar/analysis.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_GAIN, wxBitmap(wxImage(resourceDir + _T("toolbar/gain.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_SETTINGS, wxBitmap(wxImage(resourceDir + _T("toolbar/settings.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ABOUT, wxBitmap(wxImage(resourceDir + _T("toolbar/about.png"))));
}

void GuiMain::updateTxtNormalVolumeDb() {
    m_dblNormalVolume = (double) (mp_configBase->getNormalVolumeDb() / 10.0);
    g_txtNormalVolume->Clear();
    g_txtNormalVolume->WriteText(wxString::Format(_T("%.1f"), m_dblNormalVolume));
}

void GuiMain::updateControls() {
    /*
     * :KLUDGE:
     * EVT_LIST_INSERT_ITEM is triggered before or after item is added:
     *   on wxGTK -> triggered before item is added;
     *   on wxMSW -> triggered after item is added.
     */
    m_timer1.Start(20, true);
}

void GuiMain::setFilesCmdLine(const wxArrayString& filenames) {
    mp_fileListManager->insertFilesAndDir(filenames);
}
