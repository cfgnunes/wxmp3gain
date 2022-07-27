/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUI_FRAME_MAIN_HPP
#define GUI_FRAME_MAIN_HPP

#include "ConfigBase.hpp"
#include "DndFile.hpp"
#include "FileListManager.hpp"
#include "Gui.h"

class GuiFrameMain : public FrameMain {
  public:
    GuiFrameMain(wxWindow *parent);
    virtual ~GuiFrameMain();

    void setFilesCmdLine(const wxArrayString &filenames);

  protected:
    void OntxtNormalVolumeTextKillFocus(wxFocusEvent &event);
    void OnlstFilesDeleteItem(wxListEvent &event);
    void OnlstFilesInsertItem(wxListEvent &event);
    void OnlstFilesItemSelect(wxListEvent &event);
    void OnlstFilesItemRClick(wxListEvent &event);
    void OnlstFilesKeyDown(wxListEvent &event);
    void btnProcessStop(wxCommandEvent &event);
    void mnuAddDirectory(wxCommandEvent &event);
    void mnuAddFiles(wxCommandEvent &event);
    void mnuExit(wxCommandEvent &event);
    void mnuRemoveFiles(wxCommandEvent &event);
    void mnuClearList(wxCommandEvent &event);
    void mnuSettings(wxCommandEvent &event);
    void mnuClearAnalysis(wxCommandEvent &event);
    void mnuGain(wxCommandEvent &event);
    void mnuUndoGain(wxCommandEvent &event);
    void mnuDeleteTag(wxCommandEvent &event);
    void mnuToolWebsite(wxCommandEvent &event);
    void mnuWebsite(wxCommandEvent &event);
    void mnuAbout(wxCommandEvent &event);
    void mnuAnalyze(wxCommandEvent &event);
    void OnTimer1Trigger(wxTimerEvent &event);

  private:
    void updateTxtNormalVolumeDb();
    void updateControls();
    void loadResources();
    void processExecute();
    void processFile(unsigned long int fileIterator);
    void processOutputString(unsigned long int fileIterator);

    ConfigBase *mp_configBase;
    FileListManager *mp_fileListManager;
    DndFile *mp_dndFile;
    double m_dblNormalVolume;
    wxString m_exeTool;
    wxArrayString m_exeInputString;
    wxArrayString m_exeInputErrorString;
    int m_processType;
    bool m_processRunning;
};

#endif // GUI_FRAME_MAIN_HPP
