/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ListCtrlManager.hpp"
#include "Constants.hpp"
#include "Conversion.hpp"

#include <wx/dir.h>
#include <wx/tokenzr.h>

ListCtrlManager::ListCtrlManager(wxListCtrl *listCtrl) : mp_listCtrl(listCtrl) {
    mp_filesData = new std::list<FileData>();
}

ListCtrlManager::~ListCtrlManager() {
    delete mp_filesData;
}

void ListCtrlManager::insertFilesAndDir(const wxArrayString &filenames) {
    wxArrayString files;

    // Check if is a directory or a file
    for (unsigned long int n = 0; n < filenames.GetCount(); n++) {
        wxString filename = filenames[n];
        if (wxFileName::DirExists(filename))
            insertDir(filename);
        else
            files.Add(filename);
    }
    insertFiles(files);
}

void ListCtrlManager::insertFiles(const wxArrayString &filenames) {
    unsigned long int nFiles = filenames.GetCount();

    // Add files in wxListCtrl
    for (unsigned long int n = 0; n < nFiles; n++) {
        wxFileName file(filenames[n]);

        if (checkValidExtension(file)) {
            // Don't insert repeated filenames
            bool repeated = false;

            unsigned long int i = 0;
            for (std::list<FileData>::iterator fileData = mp_filesData->begin(); fileData != mp_filesData->end(); fileData++, i++) {
                wxFileName filenameInput = (*fileData).getFileName();
                if (filenameInput.GetFullPath() == filenames[n]) {
                    repeated = true;
                }
            }
            if (!repeated) {
                mp_listCtrl->InsertItem(mp_listCtrl->GetItemCount(), file.GetFullName());
                mp_listCtrl->SetItem(i, 1, file.GetPath());
                mp_filesData->push_back(FileData(filenames[n]));
            }
        }
    }
}

void ListCtrlManager::insertDir(const wxString &dirname) {
    wxArrayString files;
    wxDir::GetAllFiles(dirname, &files);

    insertFiles(files);
}

bool ListCtrlManager::checkValidExtension(const wxFileName &file) const {
    wxStringTokenizer strToken(APP_OPEN_EXT, _T(";"));
    while (strToken.HasMoreTokens()) {
        wxString token = strToken.GetNextToken();

        if (file.GetExt().CmpNoCase(token) == 0)
            return true;
    }
    return false;
}

void ListCtrlManager::deleteItem(unsigned long int index) {
    std::list<FileData>::iterator fileData = mp_filesData->begin();
    std::advance(fileData, index);
    mp_filesData->erase(fileData);
}

void ListCtrlManager::clear() {
    mp_listCtrl->DeleteAllItems();
    mp_filesData->clear();
}

long unsigned int ListCtrlManager::size() {
    return mp_filesData->size();
}

FileData &ListCtrlManager::getFileData(unsigned long int index) {
    std::list<FileData>::iterator fileData = mp_filesData->begin();
    std::advance(fileData, index);
    return *fileData;
}

wxListCtrl &ListCtrlManager::getListCtrl() {
    return *mp_listCtrl;
}

void ListCtrlManager::updateGainLabels(const double &dblNormalVolumeUpdate, AppSettings *appSettings) {
    for (unsigned long int i = 0; i < mp_filesData->size(); i++) {
        FileData &fileData = getFileData(i);

        if (!fileData.isVolumeSet())
            continue;

        // Update GainChange
        if (appSettings->getConstantGainEnabled()) {
            fileData.setGainChange(appSettings->getConstantGainValue());
        } else {
            double dblGainChange = (dblNormalVolumeUpdate - fileData.getVolume()) / VALUE_5LOG2;
            int intGainChange = Conversion::convertDoubleToIntGain(dblGainChange);
            fileData.setGainChange(intGainChange);
        }

        // Correct gain if has clipping
        if (appSettings->getAutoLowerEnabled()) {
            int maxNoclipMp3Gain = Conversion::getMaxNoclipMp3Gain(fileData.getMaxPcmSample());
            if (fileData.getGainChange() > maxNoclipMp3Gain)
                fileData.setGainChange(maxNoclipMp3Gain);
        }

        // Update the list itens
        mp_listCtrl->SetItem(i, ID_LIST_GAIN_MP3, wxString::Format(_T("%i"), fileData.getGainChange()));
        mp_listCtrl->SetItem(i, ID_LIST_GAIN_DB, wxString::Format(_T("%.1f"), fileData.getGainChange() * VALUE_5LOG2));
    }
}
