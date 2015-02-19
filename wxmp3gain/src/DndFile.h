/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef DNDFILE_H
#define DNDFILE_H

#include "FileInfo.h"
#include "FileListManager.h"

#include <wx/dnd.h>

class DndFile : public wxFileDropTarget {
public:
    DndFile(FileListManager *fileListManager);
    virtual ~DndFile();
    virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);

private:
    FileListManager *mp_fileListManager;
};

#endif // DNDFILE_H
