/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileListManager.hpp"
#include "Constants.hpp"
#include "Conversion.hpp"

#include <wx/dir.h>
#include <wx/tokenzr.h>

FileListManager::FileListManager(wxListCtrl *owner)
    : mp_owner(owner) {
    mp_lstFilesData = new std::list<FileInfo>();
}

FileListManager::~FileListManager() {
    delete mp_lstFilesData;
}

void FileListManager::insertFilesAndDir(const wxArrayString &filenames) {
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

void FileListManager::insertFiles(const wxArrayString &filenames) {
    unsigned long int nFiles = filenames.GetCount();

    // Add files in wxListCtrl
    for (unsigned long int n = 0; n < nFiles; n++) {
        wxFileName file(filenames[n]);

        if (checkValidExtension(file)) {
            // Don't insert repeated filenames
            bool repeated = false;

            unsigned long int i = 0;
            for (std::list<FileInfo>::iterator fileInfo = mp_lstFilesData->begin();
                 fileInfo != mp_lstFilesData->end(); fileInfo++, i++) {
                wxFileName filenameInput = (*fileInfo).getFileName();
                if (filenameInput.GetFullPath() == filenames[n]) {
                    repeated = true;
                }
            }
            if (!repeated) {
                mp_owner->InsertItem(mp_owner->GetItemCount(), file.GetFullName());
                mp_owner->SetItem(i, 1, file.GetPath());
                mp_lstFilesData->push_back(FileInfo(filenames[n]));
            }
        }
    }
}

void FileListManager::insertDir(const wxString &dirname) {
    wxArrayString files;
    wxDir::GetAllFiles(dirname, &files);

    insertFiles(files);
}

bool FileListManager::checkValidExtension(const wxFileName &file) const {
    wxStringTokenizer strToken(APP_OPEN_EXT, _T(";"));
    while (strToken.HasMoreTokens()) {
        wxString token = strToken.GetNextToken();

        if (file.GetExt().CmpNoCase(token) == 0)
            return true;
    }
    return false;
}

void FileListManager::deleteItem(unsigned long int index) {
    std::list<FileInfo>::iterator fileInfo = mp_lstFilesData->begin();
    std::advance(fileInfo, index);
    mp_lstFilesData->erase(fileInfo);
}

void FileListManager::clear() {
    mp_owner->DeleteAllItems();
    mp_lstFilesData->clear();
}

long unsigned int FileListManager::size() {
    return mp_lstFilesData->size();
}

FileInfo &FileListManager::getItem(unsigned long int index) {
    std::list<FileInfo>::iterator fileInfo = mp_lstFilesData->begin();
    std::advance(fileInfo, index);
    return *fileInfo;
}

wxListCtrl &FileListManager::getOwner() {
    return *mp_owner;
}

void FileListManager::updateGainLabels(const double &dblNormalVolumeUpdate, ConfigBase *configBase) {
    for (unsigned long int i = 0; i < mp_lstFilesData->size(); i++) {
        FileInfo &fileInfo = getItem(i);

        if (!fileInfo.isVolumeSet())
            continue;

        // Update GainChange
        if (configBase->getConstantGainEnabled()) {
            fileInfo.setGainChange(configBase->getConstantGainValue());
        } else {
            double dblGainChange = (dblNormalVolumeUpdate - fileInfo.getVolume()) / VALUE_5LOG2;
            int intGainChange = Conversion::convertDoubleToIntGain(dblGainChange);
            fileInfo.setGainChange(intGainChange);
        }

        // Correct gain if has clipping
        if (configBase->getAutoLowerEnabled()) {
            int maxNoclipMp3Gain = Conversion::getMaxNoclipMp3Gain(fileInfo.getMaxPcmSample());
            if (fileInfo.getGainChange() > maxNoclipMp3Gain)
                fileInfo.setGainChange(maxNoclipMp3Gain);
        }

        // Update the list itens
        mp_owner->SetItem(i, ID_LIST_GAIN_MP3, wxString::Format(_T("%i"), fileInfo.getGainChange()));
        mp_owner->SetItem(i, ID_LIST_GAIN_DB, wxString::Format(_T("%.1f"), fileInfo.getGainChange() * VALUE_5LOG2));
    }
}
