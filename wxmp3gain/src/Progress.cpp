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

    wxProgressDialog dialog(wxT("Working progress"), wxT("Wait..."), maxValue, parent, wxPD_CAN_ABORT | wxPD_APP_MODAL | wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME);
    dialog.Update(0, wxString::Format(wxT("Processed 0 files of %i."), maxValue));
    for (int i = 0; i < maxValue; i++)
    {
        ProcessFile(i);

        cont = dialog.Update(i + 1, wxString::Format(wxT("Processed %i files of %i."), i + 1, maxValue));
        if (!cont)
        {
            if (wxMessageBox(wxT("Do you want to stop process now?"), wxT("Question"), wxYES_NO | wxICON_QUESTION) == wxYES)
                break;
            dialog.Resume();
        }
    }
}

void Progress::ProcessFile(int fileIterator)
{
    wxString fullCommand = configBase->getToolExecutable() + wxT(" ") + configBase->getStringToolOptions() + wxT(" ") + configBase->getStringToolOptionsTag();
    wxString runCommand;
    FileInfo fileInfo = lstFilesData->Item(fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    if (workType == TOOL_GAIN || workType == TOOL_ANALYSIS)
    {
        // Get old volume values (try read tag info first [if enabled tag read] )
        if (!fileInfo.isVolumeSet() && configBase->getTagOptions() != 2 && !configBase->getTagForceEnabled())
        {
            runCommand = fullCommand + wxT(" -s c \"") + filenameInput.GetFullPath() + wxT("\"");
            wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            ProcessOutputString(fileIterator);
            if (fileInfo.isVolumeSet())
                listFiles->SetItem(fileIterator, 5, wxT("yes"));
        }
        if (!fileInfo.isVolumeSet())
        {
            runCommand = configBase->getToolExecutable() + wxT(" -s s \"") + filenameInput.GetFullPath() + wxT("\"");
            wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
            ProcessOutputString(fileIterator);
            listFiles->SetItem(fileIterator, 5, wxT(""));
        }
    }

    // Set gain volume
    if (workType == TOOL_GAIN && fileInfo.getGainChange() != 0)
    {
        // Execute Gain
        if (configBase->getConstantGainEnabled())
            runCommand = fullCommand + wxT(" ") + configBase->getStringToolOptionsGain() + wxT(" \"") + filenameInput.GetFullPath() + wxT("\"");
        else
            runCommand = fullCommand + wxT(" ") + configBase->getStringToolOptionsGain() + wxT(" -g ") + wxString::Format(wxT("%i "), fileInfo.getGainChange()) + wxT(" \"") + filenameInput.GetFullPath() + wxT("\"");

        wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        inputString.Clear();

        // Read file info after gain / Write tag gain (bug found on mp3gain linux)
        runCommand = fullCommand + wxT(" \"") + filenameInput.GetFullPath() + wxT("\"");
        wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
        switch (configBase->getTagOptions())
        {
        case 0:
        case 1:
            listFiles->SetItem(fileIterator, 5, wxT("yes"));
            break;
        case 2:
            listFiles->SetItem(fileIterator, 5, wxT(""));
            break;
        }
        // Updates the list
        ProcessOutputString(fileIterator);
    }

    if (workType == TOOL_UNDO)
    {
        runCommand = fullCommand + wxT(" -u \"") + filenameInput.GetFullPath() + wxT("\"");
        wxExecute(runCommand, inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);
    }

    if (workType == TOOL_DELETE_TAG)
    {
        runCommand = fullCommand + wxT(" -s d \"") + filenameInput.GetFullPath() + wxT("\"");
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

            if (tempString.Lower().Contains(wxT("track")) && tempString.Lower().Contains(wxT("db change")))
            {
                double dbGainValue;
                double volume;

                wxString valueString = tempString.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dbGainValue);
                volume = DEFAULT_VALUE_NormalVolumeDb / 10 - dbGainValue;

                fileInfo.setVolume(volume);
                listFiles->SetItem(fileIterator, 1, wxString::Format(wxT("%.1f"), volume));
            }
                // Clipping means that some value in some frame of the song is greater than +/- 32767
            else if (tempString.Lower().Contains(wxT("max pcm")))
            {
                double dblMaxPcmSample;
                wxString valueString = tempString.AfterFirst(':').Trim();
                Conversion::convertDotComma(valueString);
                valueString.ToDouble(&dblMaxPcmSample);
                fileInfo.setMaxPcmSample(dblMaxPcmSample);

                if (dblMaxPcmSample > 32767)
                {
                    listFiles->SetItem(fileIterator, 2, wxT("Yes"));
                    listFiles->SetItemTextColour(fileIterator, *wxRED);
                }
                else
                {
                    listFiles->SetItem(fileIterator, 2, wxT(""));
                    listFiles->SetItemTextColour(fileIterator, *wxBLACK);
                }
                frmMain::updateGainLabels(listFiles, configBase, lstFilesData, dblNormalVolume);
            }
        }

        // Clear the output
        inputString.Clear();
    }
}
