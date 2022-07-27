/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileDrop.hpp"

FileDrop::FileDrop(ListManager *listManager) : mp_listManager(listManager) {
}

FileDrop::~FileDrop() {
}

bool FileDrop::OnDropFiles(wxCoord, wxCoord, const wxArrayString &filenames) {
    mp_listManager->insertFilesAndDir(filenames);
    return true;
}
