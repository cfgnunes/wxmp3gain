/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUIMAIN_H
#define GUIMAIN_H

#include "Gui.h"
#include "ConfigBase.h"
#include "FileInfo.h"
#include "DndFile.h"

class GuiMain : public Main {
public:
    GuiMain(wxWindow* parent);
    virtual ~GuiMain();
    void setFilesCmdLine(const wxArrayString& filenames);
    static void updateGainLabels(wxListCtrl* listFilesUpdate, ConfigBase* configBaseUpdate, ArrayOfFiles* lstFilesDataUpdate, const double& dblNormalVolumeUpdate);

protected:
    void OntxtNormalVolumeTextKillFocus(wxFocusEvent& event);
    void OnlstFilesDeleteItem(wxListEvent& event);
    void OnlstFilesInsertItem(wxListEvent& event);
    void OnlstFilesItemSelect(wxListEvent& event);
    void OnlstFilesItemRClick(wxListEvent& event);
    void OnlstFilesKeyDown(wxListEvent& event);
    void mnuAddDirectory(wxCommandEvent& event);
    void mnuAddFiles(wxCommandEvent& event);
    void mnuExit(wxCommandEvent& event);
    void mnuRemoveFiles(wxCommandEvent& event);
    void mnuClearList(wxCommandEvent& event);
    void mnuSettings(wxCommandEvent& event);
    void mnuClearAnalysis(wxCommandEvent& event);
    void mnuGain(wxCommandEvent& event);
    void mnuUndoGain(wxCommandEvent& event);
    void mnuDeleteTag(wxCommandEvent& event);
    void mnuToolWebsite(wxCommandEvent& event);
    void mnuWebsite(wxCommandEvent& event);
    void mnuAbout(wxCommandEvent& event);
    void mnuAnalyze(wxCommandEvent& event);
    void OnTimer1Trigger(wxTimerEvent& event);

private:
    void updateTxtNormalVolumeDb();
    void updateControls();
    void updateControlsDelayed();
    void loadResources();

    ConfigBase *mp_configBase;
    ArrayOfFiles *mp_lstFilesData;
    DndFile *mp_dndFile;
    double m_dblNormalVolume;
    wxString m_exeTool;
    wxArrayString m_exeInputString;
    wxArrayString m_exeInputErrorString;
};

#endif // GUIMAIN_H
