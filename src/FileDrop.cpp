/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileDrop.hpp"

FileDrop::FileDrop(ListCtrlManager *listCtrlManager)
    : mp_listCtrlManager(listCtrlManager) {
}

FileDrop::~FileDrop() {
}

bool FileDrop::OnDropFiles(wxCoord, wxCoord, const wxArrayString &filenames) {
    mp_listCtrlManager->insertFilesAndDir(filenames);
    return true;
}
