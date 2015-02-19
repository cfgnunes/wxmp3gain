/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "Progress.h"
#include "GuiMain.h"
#include "Conversion.h"

#include <wx/filename.h>
#include <wx/colour.h>
#include <wx/progdlg.h>
#include <wx/msgdlg.h>

Progress::Progress(wxWindow *parent, ConfigBase* configBase, FileListManager *fileListManager, double dblNormalVolume, int workType)
: mp_parent(parent), mp_configBase(configBase), mp_fileListManager(fileListManager), m_dblNormalVolume(dblNormalVolume), m_workType(workType) {
}

Progress::~Progress() {
}

void Progress::execute() {
    unsigned long int maxValue = mp_fileListManager->size();
    bool cont = true;

    wxProgressDialog dialog(_("Progress"), _("Wait..."), maxValue, mp_parent, wxPD_CAN_ABORT | wxPD_APP_MODAL | wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME);
    dialog.Update(0, wxString::Format(_("Processed %lu files of %lu."), (unsigned long int) 0, maxValue));
    for (unsigned long int i = 0; i < maxValue; i++) {
        processFile(i);
        cont = dialog.Update(i + 1, wxString::Format(_("Processed %lu files of %lu."), i + 1, maxValue));
        if (!cont) {
            if (wxMessageBox(_("Do you want to stop process now?"), APP_NAME, wxYES_NO | wxICON_QUESTION) == wxYES)
                break;
            dialog.Resume();
        }
    }
}

void Progress::processFile(unsigned long int fileIterator) {
    wxString fullCommand = APP_TOOL_EXECUTABLE + _T(" ") + mp_configBase->getStringToolOptions() + _T(" ") + mp_configBase->getStringToolOptionsTag();
    wxString runCommand;
    FileInfo& fileInfo = mp_fileListManager->getItem(fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    if (m_workType == TOOL_GAIN || m_workType == TOOL_ANALYSIS) {
        // Get old volume values (try read tag info first [if enabled tag read] )
        if (!fileInfo.isVolumeSet() && mp_configBase->getTagOptions() != 2 && !mp_configBase->getTagForceEnabled()) {
            runCommand = fullCommand + _T(" -s c \"") + filenameInput.GetFullPath() + _T("\"");
            wxExecute(runCommand, m_inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            processOutputString(fileIterator);
            if (fileInfo.isVolumeSet())
                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_TAG_INFO, _("yes"));
        }
        if (!fileInfo.isVolumeSet()) {
            runCommand = APP_TOOL_EXECUTABLE + _T(" -s s \"") + filenameInput.GetFullPath() + _T("\"");
            wxExecute(runCommand, m_inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            processOutputString(fileIterator);
            mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_TAG_INFO, _T(""));
        }
    }

    // Set gain volume
    if (m_workType == TOOL_GAIN && fileInfo.getGainChange() != 0) {
        // Execute Gain
        if (mp_configBase->getConstantGainEnabled())
            runCommand = fullCommand + _T(" ") + mp_configBase->getStringToolOptionsGain() + _T(" \"") + filenameInput.GetFullPath() + _T("\"");
        else
            runCommand = fullCommand + _T(" ") + mp_configBase->getStringToolOptionsGain() + _T(" -g ") + wxString::Format(_T("%i "), fileInfo.getGainChange()) + _T(" \"") + filenameInput.GetFullPath() + _T("\"");

        wxExecute(runCommand, m_inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        m_inputString.Clear();

        // Read file info after gain / Write tag gain (bug found on mp3gain linux)
        runCommand = fullCommand + _T(" \"") + filenameInput.GetFullPath() + _T("\"");
        wxExecute(runCommand, m_inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        switch (mp_configBase->getTagOptions()) {
            case 0:
            case 1:
                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_TAG_INFO, _("yes"));
                break;
            case 2:
                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_TAG_INFO, _T(""));
                break;
        }

        // Updates the list
        processOutputString(fileIterator);
    }

    if (m_workType == TOOL_UNDO) {
        runCommand = fullCommand + _T(" -u \"") + filenameInput.GetFullPath() + _T("\"");
        wxExecute(runCommand, m_inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
    }

    if (m_workType == TOOL_DELETE_TAG) {
        runCommand = fullCommand + _T(" -s d \"") + filenameInput.GetFullPath() + _T("\"");
        wxExecute(runCommand, m_inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
    }
}

void Progress::processOutputString(unsigned long int fileIterator) {
    FileInfo& fileInfo = mp_fileListManager->getItem(fileIterator);
    wxString tempString;

    if (!m_inputString.IsEmpty()) {
        for (unsigned int i = 0; i < m_inputString.GetCount(); i++) {
            tempString = m_inputString.Item(i);

            if (tempString.Lower().Contains(_T("track")) && tempString.Lower().Contains(_T("db change"))) {
                double dbGainValue;
                double volume;

                wxString valueString = tempString.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dbGainValue);
                volume = DEFAULT_VALUE_NormalVolumeDb / 10 - dbGainValue;

                fileInfo.setVolume(volume);

                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_VOLUME, wxString::Format(_T("%.1f"), volume));
            }// Clipping means that some value in some frame of the song is greater than +/- 32767
            else if (tempString.Lower().Contains(_T("max pcm"))) {
                double dblMaxPcmSample;
                wxString valueString = tempString.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dblMaxPcmSample);
                fileInfo.setMaxPcmSample(dblMaxPcmSample);

                if (dblMaxPcmSample > 32767) {
                    mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_CLIPPING, _("yes"));
                    mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxRED);
                } else {
                    mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_CLIPPING, _T(""));
                    mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxBLACK);
                }
                mp_fileListManager->updateGainLabels(m_dblNormalVolume, mp_configBase);
            }
        }

        // Clear the output
        m_inputString.Clear();
    }
}
