/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef DNDFILE_H
#define DNDFILE_H

#include "FileInfo.h"
#include "Global.h"
#include <wx/tokenzr.h>
#include <wx/dir.h>
#include <wx/dnd.h>
#include <wx/listctrl.h>
#include <wx/filename.h>

class DndFile : public wxFileDropTarget
{
public:
    DndFile(wxListCtrl *owner, ArrayOfFiles *lstFilesData);
    virtual ~DndFile();
    virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);
    void InsertFileList(const wxArrayString& filenames);
    void InsertFileListDir(const wxString& dirname);

protected:

private:
    bool CheckValidExtension(const wxFileName& file);
    wxListCtrl *m_owner;
    ArrayOfFiles *lstFilesData;
};

#endif
