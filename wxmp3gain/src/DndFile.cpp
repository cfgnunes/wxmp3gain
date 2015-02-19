/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "DndFile.h"

DndFile::DndFile(FileListManager *fileListManager) : mp_fileListManager(fileListManager) {
}

DndFile::~DndFile() {
}

bool DndFile::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames) {
    mp_fileListManager->insertFilesAndDir(filenames);
    return true;
}
