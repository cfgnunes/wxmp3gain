/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiFrameMain.hpp"
#include "../Constants.hpp"
#include "../Conversion.hpp"
#include "GuiDialogSettings.hpp"

#include <wx/aboutdlg.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>

GuiFrameMain::GuiFrameMain(wxWindow *parent) : FrameMain(parent), m_processRunning(false) {
    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // File list manager
    mp_listManager = new ListManager(gui_lstFiles);

    // List Drag & Drop
    mp_fileDrop = new FileDrop(mp_listManager);
    gui_lstFiles->SetDropTarget(mp_fileDrop);

    // Title List
    gui_lstFiles->InsertColumn(ID_LIST_FILE, _("File"), wxLIST_FORMAT_LEFT, 200);
    gui_lstFiles->InsertColumn(ID_LIST_FOLDER, _("Folder"), wxLIST_FORMAT_LEFT, 200);
    gui_lstFiles->InsertColumn(ID_LIST_VOLUME, _("Volume"), wxLIST_FORMAT_LEFT, 60);
    gui_lstFiles->InsertColumn(ID_LIST_CLIPPING, _("Clipping"), wxLIST_FORMAT_LEFT, 70);
    gui_lstFiles->InsertColumn(ID_LIST_GAIN_DB, _("Gain (dB)"), wxLIST_FORMAT_LEFT, 80);
    gui_lstFiles->InsertColumn(ID_LIST_GAIN_MP3, _("Gain (mp3)"), wxLIST_FORMAT_LEFT, 80);
    gui_lstFiles->InsertColumn(ID_LIST_TAG_INFO, _("Tag info"), wxLIST_FORMAT_LEFT, 70);

    // Set statusbar widths
    const int wxStatusBarWidths[3] = {-10, -10, -5};
    gui_mainStatusBar->SetStatusWidths(3, wxStatusBarWidths);

    // Configuration file
    mp_appSettings = new AppSettings(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Updates the controls
    updateControls();

    // Update txtNormalVolume
    updateTxtNormalVolumeDb();

    // Box visible: Normal Volume OR Constant gain
    if (mp_appSettings->getConstantGainEnabled())
        gui_boxNormalVolume->Show(false);
    else
        gui_boxConstantGain->Show(false);

    gui_boxMain->Layout();
}

void GuiFrameMain::OntxtNormalVolumeTextKillFocus(wxFocusEvent &event) {
    wxString strNormalVolume = gui_txtNormalVolume->GetLineText(0);
    Conversion::convertDotComma(strNormalVolume);
    strNormalVolume.ToDouble(&m_dblNormalVolume);

    if (m_dblNormalVolume < 75)
        m_dblNormalVolume = 75.0;
    else if (m_dblNormalVolume > 105)
        m_dblNormalVolume = 105.0;

    mp_listManager->updateGainLabels(m_dblNormalVolume, mp_appSettings);

    // Save the NormalVolumeDb
    mp_appSettings->setNormalVolumeDb((int)(float)(m_dblNormalVolume * 10.0));
    updateTxtNormalVolumeDb();

    event.Skip();
}

GuiFrameMain::~GuiFrameMain() {
    delete mp_listManager;
    delete mp_appSettings;
}

void GuiFrameMain::OnlstFilesDeleteItem(wxListEvent &event) {
    if (!m_processRunning) {
        mp_listManager->deleteItem((unsigned long)event.GetIndex());
        updateControls();
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesInsertItem(wxListEvent &event) {
    if (!m_processRunning) {
        updateControls();
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesItemSelect(wxListEvent &event) {
    if (!m_processRunning) {
        updateControls();
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesItemRClick(wxListEvent &event) {
    if (!m_processRunning) {
        updateControls();
        // Displays the popup menu when you click a list item
        gui_lstFiles->PopupMenu(gui_mainMenu);
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesKeyDown(wxListEvent &event) {
    if (!m_processRunning) {
        // Remove files with Delete key
        int keyCode = event.GetKeyCode();
        if (keyCode == WXK_DELETE)
            mnuRemoveFiles(event);
    }
    event.Skip();
}

void GuiFrameMain::btnProcessStop(wxCommandEvent &event) {
    m_processRunning = false;
    gui_btnStop->Enable(false);
    event.Skip(false);
}

void GuiFrameMain::mnuAddDirectory(wxCommandEvent &event) {
    wxString msg = _("Select directory");
    wxDirDialog dirDialog(this, msg, wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_appSettings->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        mp_listManager->insertDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_appSettings->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
    event.Skip(false);
}

void GuiFrameMain::mnuAddFiles(wxCommandEvent &event) {
    wxArrayString files;
    wxString msg = _("Select file");
    wxFileDialog fileDialog(this, msg, wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_appSettings->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        mp_listManager->insertFiles(files);

        // Remembers the last used directory
        mp_appSettings->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
    event.Skip(false);
}

void GuiFrameMain::mnuExit(wxCommandEvent &event) {
    // Terminates the program
    Close();
    event.Skip(false);
}

void GuiFrameMain::mnuRemoveFiles(wxCommandEvent &event) {
    int itemCount = gui_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++) {
        long item = gui_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        gui_lstFiles->DeleteItem(item);
    }
    SetCursor(wxCURSOR_ARROW);

    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuClearList(wxCommandEvent &event) {
    // Deletes all items from the list
    mp_listManager->clear();

    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuSettings(wxCommandEvent &event) {
    int oldTagOptions = mp_appSettings->getTagOptions();
    bool oldTagForceEnabled = mp_appSettings->getTagForceEnabled();

    // Displays the "Settings" window
    GuiDialogSettings guiSettings(this, mp_appSettings);
    guiSettings.ShowModal();

    // Updates the box bar after closing the window "Settings"
    if (mp_appSettings->getConstantGainEnabled()) {
        gui_boxNormalVolume->Show(false);
        gui_boxConstantGain->Show(true);
    } else {
        gui_boxConstantGain->Show(false);
        gui_boxNormalVolume->Show(true);
    }
    gui_boxMain->Layout();

    if (oldTagOptions != mp_appSettings->getTagOptions() || oldTagForceEnabled != mp_appSettings->getTagForceEnabled())
        mnuClearAnalysis(event);

    // Updates after closing the window "Settings"
    updateControls();
    updateTxtNormalVolumeDb();
    mp_listManager->updateGainLabels(m_dblNormalVolume, mp_appSettings);
    event.Skip(false);
}

void GuiFrameMain::mnuClearAnalysis(wxCommandEvent &event) {
    for (unsigned long int i = 0; i < mp_listManager->size(); i++) {
        FileData &fileData = mp_listManager->getFileData(i);
        fileData.volumeReset();
        gui_lstFiles->SetItem(i, 2, _T(""));
        gui_lstFiles->SetItem(i, 3, _T(""));
        gui_lstFiles->SetItem(i, 4, _T(""));
        gui_lstFiles->SetItem(i, 5, _T(""));
        gui_lstFiles->SetItem(i, 6, _T(""));
        gui_lstFiles->SetItemTextColour(i, *wxBLACK);
    }
    event.Skip(false);
}

void GuiFrameMain::mnuAnalyze(wxCommandEvent &event) {
    m_processType = TOOL_ANALYSIS;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuGain(wxCommandEvent &event) {
    m_processType = TOOL_GAIN;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuUndoGain(wxCommandEvent &event) {
    m_processType = TOOL_UNDO;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();

    mnuClearAnalysis(event);
    event.Skip(false);
}

void GuiFrameMain::mnuDeleteTag(wxCommandEvent &event) {
    m_processType = TOOL_DELETE_TAG;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();

    mnuClearAnalysis(event);
    event.Skip(false);
}

void GuiFrameMain::mnuToolWebsite(wxCommandEvent &event) {
    wxLaunchDefaultBrowser(_T("http://mp3gain.sourceforge.net/"));
    event.Skip(false);
}

void GuiFrameMain::mnuWebsite(wxCommandEvent &event) {
    wxLaunchDefaultBrowser(APP_WEBSITE);
    event.Skip(false);
}

void GuiFrameMain::mnuAbout(wxCommandEvent &event) {
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(APP_NAME);
    aboutInfo.SetVersion(APP_VERSION);
    aboutInfo.SetDescription(_("Free front-end for the MP3gain"));
    aboutInfo.SetCopyright(APP_COPYRIGHT);
    aboutInfo.SetWebSite(APP_WEBSITE);
    wxString dataDir = getDataDir();
    aboutInfo.SetIcon(wxIcon(dataDir + _T("icons/app.ico"), wxBITMAP_TYPE_ICO));
    wxAboutBox(aboutInfo);
    event.Skip(false);
}

void GuiFrameMain::OnTimer1Trigger(wxTimerEvent &event) {
    wxString newExeTool = APP_TOOL_EXECUTABLE;
    if (!m_exeTool.IsSameAs(newExeTool, false)) {
        m_exeInputString.Clear();
        m_exeInputErrorString.Clear();
        m_exeTool = newExeTool;
        // Execute external application
        wxExecute(m_exeTool + _T(" -v"), m_exeInputString, m_exeInputErrorString, wxEXEC_NODISABLE);

        // Show the version of tool
        wxString version;
        if (!m_exeInputErrorString.IsEmpty()) {
            version = _("Using MP3gain version: ");
            version += m_exeInputErrorString.Item(0).AfterLast(' ');

        } else {
            version = _("MP3gain not found!");
        }
        gui_mainStatusBar->SetStatusText(version, 0);
    }

    // Show the number of files in list on status bar
    wxString strNFiles;
    strNFiles += wxString::Format(_T("%i "), gui_lstFiles->GetItemCount());
    strNFiles += _("files");
    gui_mainStatusBar->SetStatusText(strNFiles, 1);

    // Constant gain box
    wxString strGain;
    strGain += wxString::Format(_T("%+i"), mp_appSettings->getCtGainValue());
    strGain += _T(" (");
    strGain += wxString::Format(_T("%+.1f"), mp_appSettings->getCtGainValue() * VALUE_5LOG2);
    strGain += _T(" dB)");
    gui_lblConstantGain->SetLabel(strGain);

    for (size_t i = 0; i < gui_mainMenuBar->GetMenuCount(); i++)
        gui_mainMenuBar->EnableTop(i, !m_processRunning);

    gui_mainToolBar->Enable(!m_processRunning);
    gui_txtNormalVolume->Enable(!m_processRunning);

    gui_mainMenu->Enable(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);
    gui_mainMenuBar->Enable(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);
    gui_mainToolBar->EnableTool(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);

    gui_mainMenu->Enable(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_mainMenuBar->Enable(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_mainToolBar->EnableTool(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);

    gui_mainMenuBar->Enable(ID_ANALYZE, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_mainToolBar->EnableTool(ID_ANALYZE, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);

    gui_mainMenuBar->Enable(ID_GAIN, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_mainToolBar->EnableTool(ID_GAIN, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);

    gui_mainMenuBar->Enable(ID_CLEAR_ANALYSIS, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_mainMenuBar->Enable(ID_UNDO_GAIN, gui_lstFiles->GetItemCount() > 0 && mp_appSettings->getTagOptions() != 2 && !m_processRunning);
    gui_mainMenuBar->Enable(ID_DELETE_TAG, gui_lstFiles->GetItemCount() > 0 && mp_appSettings->getTagOptions() != 2 && !m_processRunning);

    gui_btnStop->Enable(m_processRunning);
    event.Skip(false);
}

void GuiFrameMain::loadResources() {
    wxString dataDir = getDataDir();

    // Window icon
    SetIcon(wxIcon(dataDir + _T("icons/app.ico"), wxBITMAP_TYPE_ICO));

    // Toolbar bitmaps
    gui_mainToolBar->SetToolNormalBitmap(ID_ADD_FILES, wxBitmap(wxImage(dataDir + _T("toolbar/add-file.png"))));
    gui_mainToolBar->SetToolNormalBitmap(ID_ADD_FOLDER, wxBitmap(wxImage(dataDir + _T("toolbar/add-folder.png"))));
    gui_mainToolBar->SetToolNormalBitmap(ID_REMOVE_FILES, wxBitmap(wxImage(dataDir + _T("toolbar/remove.png"))));
    gui_mainToolBar->SetToolNormalBitmap(ID_CLEAR_LIST, wxBitmap(wxImage(dataDir + _T("toolbar/clear.png"))));
    gui_mainToolBar->SetToolNormalBitmap(ID_ANALYZE, wxBitmap(wxImage(dataDir + _T("toolbar/analysis.png"))));
    gui_mainToolBar->SetToolNormalBitmap(ID_GAIN, wxBitmap(wxImage(dataDir + _T("toolbar/gain.png"))));
    gui_mainToolBar->SetToolNormalBitmap(ID_SETTINGS, wxBitmap(wxImage(dataDir + _T("toolbar/settings.png"))));
    gui_mainToolBar->SetToolNormalBitmap(ID_ABOUT, wxBitmap(wxImage(dataDir + _T("toolbar/about.png"))));
}

void GuiFrameMain::updateTxtNormalVolumeDb() {
    m_dblNormalVolume = mp_appSettings->getNormalVolumeDb() / 10.0;
    gui_txtNormalVolume->Clear();
    gui_txtNormalVolume->WriteText(wxString::Format(_T("%.1f"), m_dblNormalVolume));
}

void GuiFrameMain::updateControls() {
    /*
     * :KLUDGE:
     * EVT_LIST_INSERT_ITEM is triggered before or after item is added:
     *   on wxGTK -> triggered before item is added;
     *   on wxMSW -> triggered after item is added.
     */
    m_timer1.Start(20, true);
}

void GuiFrameMain::setFilesCmdLine(const wxArrayString &filenames) {
    mp_listManager->insertFilesAndDir(filenames);
}

void GuiFrameMain::processExecute() {
    unsigned long int maxValue = mp_listManager->size();
    unsigned long int i;
    wxString msg;

    gui_gugProgress->SetRange((int)maxValue);
    for (i = 0; i < maxValue; i++) {
        processFile(i);
        gui_gugProgress->SetValue((int)i + 1);

        if (!m_processRunning) {
            msg = _("Do you want to stop process now?");
            if (wxMessageBox(msg, APP_NAME, wxYES_NO | wxICON_QUESTION) == wxYES) {
                i++;
                break;
            }
            m_processRunning = true;
            gui_btnStop->Enable(true);
        }
    }

    msg = wxString::Format(_("Processed %lu files of %lu."), i, maxValue);
    wxMessageBox(msg, APP_NAME, wxOK | wxICON_INFORMATION);

    gui_gugProgress->SetValue(0);
}

void GuiFrameMain::processFile(unsigned long int fileIdx) {
    wxString fullCommand;
    fullCommand += APP_TOOL_EXECUTABLE + _T(" ");
    fullCommand += mp_appSettings->getStringToolOptions() + _T(" ");
    fullCommand += mp_appSettings->getStringToolOptionsTag();

    wxString runCommand;
    FileData &fileData = mp_listManager->getFileData(fileIdx);
    wxFileName filenameInput = fileData.getFileName();

    // Works on a temp file
    wxString filenameTemp = wxFileName::CreateTempFileName(_T("temp-")) + _T(".mp3");
    wxCopyFile(filenameInput.GetFullPath(), filenameTemp, true);

    if (m_processType == TOOL_GAIN || m_processType == TOOL_ANALYSIS) {
        // Get old volume values (try read tag info first [if enabled tag read] )
        if (!fileData.isVolumeSet() && mp_appSettings->getTagOptions() != 2 && !mp_appSettings->getTagForceEnabled()) {
            runCommand = fullCommand + _T(" -s c \"") + filenameTemp + _T("\"");
            wxExecute(runCommand, m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            processOutputString(fileIdx);
            if (fileData.isVolumeSet())
                mp_listManager->getListCtrl().SetItem(fileIdx, ID_LIST_TAG_INFO, _("yes"));
        }
        if (!fileData.isVolumeSet()) {
            runCommand = APP_TOOL_EXECUTABLE + _T(" -s s \"") + filenameTemp + _T("\"");
            wxExecute(runCommand, m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            processOutputString(fileIdx);
            mp_listManager->getListCtrl().SetItem(fileIdx, ID_LIST_TAG_INFO, _T(""));
        }
    }

    // Set gain volume
    if (m_processType == TOOL_GAIN && fileData.getGainChange() != 0) {
        // Execute Gain
        if (mp_appSettings->getConstantGainEnabled()) {
            runCommand = fullCommand + _T(" ");
            runCommand += mp_appSettings->getStringToolOptionsGain();
            runCommand += _T(" \"") + filenameTemp + _T("\"");
        } else {
            runCommand = fullCommand + _T(" ");
            runCommand += mp_appSettings->getStringToolOptionsGain();
            runCommand += _T(" -g ");
            runCommand += wxString::Format(_T("%i "), fileData.getGainChange());
            runCommand += _T(" \"") + filenameTemp + _T("\"");
        }
        wxExecute(runCommand, m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        m_exeInputString.Clear();

        // Read file info after gain / Write tag gain
        // (bug found on mp3gain linux)
        runCommand = fullCommand + _T(" \"") + filenameTemp + _T("\"");
        wxExecute(runCommand, m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        switch (mp_appSettings->getTagOptions()) {
        default:
        case 0:
        case 1:
            mp_listManager->getListCtrl().SetItem(fileIdx, ID_LIST_TAG_INFO, _("yes"));
            break;
        case 2:
            mp_listManager->getListCtrl().SetItem(fileIdx, ID_LIST_TAG_INFO, _T(""));
            break;
        }

        // Updates the list
        processOutputString(fileIdx);
    }

    if (m_processType == TOOL_UNDO) {
        runCommand = fullCommand + _T(" -u \"") + filenameTemp + _T("\"");
        wxExecute(runCommand, m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
    }

    if (m_processType == TOOL_DELETE_TAG) {
        runCommand = fullCommand + _T(" -s d \"") + filenameTemp + _T("\"");
        wxExecute(runCommand, m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
    }

    // Delete temp file or rename to the original filename
    if (m_processType == TOOL_ANALYSIS)
        wxRemoveFile(filenameTemp);
    else
        wxRenameFile(filenameTemp, filenameInput.GetFullPath(), true);

    wxString msg;
    msg = wxString::Format(_("Processed %lu files of %lu."), fileIdx + 1, mp_listManager->size());
    gui_mainStatusBar->SetStatusText(msg, 1);
}

void GuiFrameMain::processOutputString(unsigned long int fileIdx) {
    FileData &fileData = mp_listManager->getFileData(fileIdx);
    wxString tempStr;

    if (!m_exeInputString.IsEmpty()) {
        for (unsigned int i = 0; i < m_exeInputString.GetCount(); i++) {
            tempStr = m_exeInputString.Item(i);

            if (tempStr.Lower().Contains(_T("track")) && tempStr.Lower().Contains(_T("db change"))) {
                double dbGainValue;
                double volume;

                wxString valueString = tempStr.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dbGainValue);
                volume = DEFAULT_VALUE_NormalVolumeDb / 10 - dbGainValue;

                fileData.setVolume(volume);

                mp_listManager->getListCtrl().SetItem(fileIdx, ID_LIST_VOLUME, wxString::Format(_T("%.1f"), volume));
            } // Clipping means that some value in some frame of the song is greater than +/- 32767
            else if (tempStr.Lower().Contains(_T("max pcm"))) {
                double dblMaxPcmSample;
                wxString valueString = tempStr.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dblMaxPcmSample);
                fileData.setMaxPcmSample(dblMaxPcmSample);

                if (dblMaxPcmSample > 32767) {
                    mp_listManager->getListCtrl().SetItem(fileIdx, ID_LIST_CLIPPING, _("yes"));
                    mp_listManager->getListCtrl().SetItemTextColour(fileIdx, *wxRED);
                } else {
                    mp_listManager->getListCtrl().SetItem(fileIdx, ID_LIST_CLIPPING, _T(""));
                    mp_listManager->getListCtrl().SetItemTextColour(fileIdx, *wxBLACK);
                }
                mp_listManager->updateGainLabels(m_dblNormalVolume, mp_appSettings);
            }
        }

        // Clear the output
        m_exeInputString.Clear();
    }
}
