/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "DndFile.h"

DndFile::DndFile(wxListCtrl *owner, ArrayOfFiles *lstFilesData) : mp_owner(owner), mp_lstFilesData(lstFilesData) {
}

DndFile::~DndFile() {
}

bool DndFile::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames) {
    wxArrayString files;

    // Check if is a directory or a file
    for (size_t n = 0; n < filenames.GetCount(); n++) {
        wxString filename = filenames[n];
        if (wxFileName::DirExists(filename))
            insertFileListDir(filename);
        else
            files.Add(filename);
    }
    insertFileList(files);

    return true;
}

void DndFile::insertFileList(const wxArrayString& filenames) {
    wxFileName file;
    size_t nFiles = filenames.GetCount();

    // Add files in wxListCtrl
    for (size_t n = 0; n < nFiles; n++) {
        file.SetFullName(filenames[n]);

        if (checkValidExtension(file)) {
            // Don't insert repeated filenames
            bool repeated = false;
            for (int i = 0; i < mp_owner->GetItemCount(); i++) {
                FileInfo& fileInfo = mp_lstFilesData->Item(i);
                wxFileName filenameInput = fileInfo.getFileName();
                if (filenameInput.GetFullPath() == filenames[n]) {
                    repeated = true;
                }
            }
            if (!repeated) {
                mp_owner->InsertItem(mp_owner->GetItemCount(), file.GetFullName());
                mp_lstFilesData->Add(new FileInfo(filenames[n]));
            }
        }
    }
}

void DndFile::insertFileListDir(const wxString& dirname) {
    wxArrayString files;
    wxDir::GetAllFiles(dirname, &files);

    insertFileList(files);
}

bool DndFile::checkValidExtension(const wxFileName& file) {
    wxStringTokenizer strToken(APP_OPEN_EXT, _T(";"));
    while (strToken.HasMoreTokens()) {
        wxString token = strToken.GetNextToken();

        if (file.GetExt().CmpNoCase(token) == 0)
            return true;
    }
    return false;
}
