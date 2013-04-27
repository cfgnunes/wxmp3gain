/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "Progress.h"

#include "frmMain.h"
#include "Conversion.h"

#include <wx/filename.h>
#include <wx/colour.h>
#include <wx/progdlg.h>
#include <wx/msgdlg.h>

Progress::Progress(wxWindow* parent, ConfigBase* configBase, wxListCtrl* listFiles, ArrayOfFiles* lstFilesData, const double& dblNormalVolume, int workType)
: parent(parent), configBase(configBase), listFiles(listFiles), lstFilesData(lstFilesData), dblNormalVolume(dblNormalVolume), workType(workType)
{
    //ctor
}

Progress::~Progress()
{
    //dtor
}

void Progress::Execute()
{
    int maxValue = listFiles->GetItemCount();
    bool cont = true;

    wxProgressDialog dialog(_("Progress"), _("Wait..."), maxValue, parent, wxPD_CAN_ABORT | wxPD_APP_MODAL | wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME);
    dialog.Update(0, wxString::Format(_("Processed %i files of %i."), 0, maxValue));
    for (int i = 0; i < maxValue; i++)
    {
        ProcessFile(i);

        cont = dialog.Update(i + 1, wxString::Format(_("Processed %i files of %i."), i + 1, maxValue));
        if (!cont)
        {
            if (wxMessageBox(_("Do you want to stop process now?"), APP_NAME, wxYES_NO | wxICON_QUESTION) == wxYES)
                break;
            dialog.Resume();
        }
    }
}

void Progress::ProcessFile(int fileIterator)
{
    wxString fullCommand = configBase->getToolExecutable() + _T(" ") + configBase->getStringToolOptions() + _T(" ") + configBase->getStringToolOptionsTag();
    wxString runCommand;
    FileInfo& fileInfo = lstFilesData->Item(fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    if (workType == TOOL_GAIN || workType == TOOL_ANALYSIS)
    {
        // Get old volume values (try read tag info first [if enabled tag read] )
        if (!fileInfo.isVolumeSet() && configBase->getTagOptions() != 2 && !configBase->getTagForceEnabled())
        {
            runCommand = fullCommand + _T(" -s c \"") + filenameInput.GetFullPath() + _T("\"");
            wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            ProcessOutputString(fileIterator);
            if (fileInfo.isVolumeSet())
                listFiles->SetItem(fileIterator, 5, _("yes"));
        }
        if (!fileInfo.isVolumeSet())
        {
            runCommand = configBase->getToolExecutable() + _T(" -s s \"") + filenameInput.GetFullPath() + _T("\"");
            wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            ProcessOutputString(fileIterator);
            listFiles->SetItem(fileIterator, 5, _T(""));
        }
    }

    // Set gain volume
    if (workType == TOOL_GAIN && fileInfo.getGainChange() != 0)
    {
        // Execute Gain
        if (configBase->getConstantGainEnabled())
            runCommand = fullCommand + _T(" ") + configBase->getStringToolOptionsGain() + _T(" \"") + filenameInput.GetFullPath() + _T("\"");
        else
            runCommand = fullCommand + _T(" ") + configBase->getStringToolOptionsGain() + _T(" -g ") + wxString::Format(_T("%i "), fileInfo.getGainChange()) + _T(" \"") + filenameInput.GetFullPath() + _T("\"");

        wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        inputString.Clear();

        // Read file info after gain / Write tag gain (bug found on mp3gain linux)
        runCommand = fullCommand + _T(" \"") + filenameInput.GetFullPath() + _T("\"");
        wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        switch (configBase->getTagOptions())
        {
        case 0:
        case 1:
            listFiles->SetItem(fileIterator, 5, _("yes"));
            break;
        case 2:
            listFiles->SetItem(fileIterator, 5, _T(""));
            break;
        }
        // Updates the list
        ProcessOutputString(fileIterator);
    }

    if (workType == TOOL_UNDO)
    {
        runCommand = fullCommand + _T(" -u \"") + filenameInput.GetFullPath() + _T("\"");
        wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
    }

    if (workType == TOOL_DELETE_TAG)
    {
        runCommand = fullCommand + _T(" -s d \"") + filenameInput.GetFullPath() + _T("\"");
        wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
    }
}

void Progress::ProcessOutputString(int fileIterator)
{
    FileInfo& fileInfo = lstFilesData->Item(fileIterator);
    wxString tempString;

    if (!inputString.IsEmpty())
    {
        for (unsigned int i = 0; i < inputString.GetCount(); i++)
        {
            tempString = inputString.Item(i);

            if (tempString.Lower().Contains(_T("track")) && tempString.Lower().Contains(_T("db change")))
            {
                double dbGainValue;
                double volume;

                wxString valueString = tempString.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dbGainValue);
                volume = DEFAULT_VALUE_NormalVolumeDb / 10 - dbGainValue;

                fileInfo.setVolume(volume);
                listFiles->SetItem(fileIterator, 1, wxString::Format(_T("%.1f"), volume));
            }
                // Clipping means that some value in some frame of the song is greater than +/- 32767
            else if (tempString.Lower().Contains(_T("max pcm")))
            {
                double dblMaxPcmSample;
                wxString valueString = tempString.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dblMaxPcmSample);
                fileInfo.setMaxPcmSample(dblMaxPcmSample);

                if (dblMaxPcmSample > 32767)
                {
                    listFiles->SetItem(fileIterator, 2, _("yes"));
                    listFiles->SetItemTextColour(fileIterator, *wxRED);
                }
                else
                {
                    listFiles->SetItem(fileIterator, 2, _T(""));
                    listFiles->SetItemTextColour(fileIterator, *wxBLACK);
                }
                frmMain::updateGainLabels(listFiles, configBase, lstFilesData, dblNormalVolume);
            }
        }

        // Clear the output
        inputString.Clear();
    }
}
