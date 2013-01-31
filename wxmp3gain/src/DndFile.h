/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef DNDFILE_H
#define DNDFILE_H

#include "Global.h"
#include <wx/tokenzr.h>
#include <wx/dir.h>
#include <wx/dnd.h>
#include <wx/listctrl.h>
#include <wx/filename.h>

class DndFile : public wxFileDropTarget
{
public:
    DndFile (wxListCtrl *owner);
    virtual ~DndFile();
    virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);
    static void InsertFileList(wxListCtrl* m_owner, const wxArrayString& filenames);
    static void InsertFileListDir(wxListCtrl* m_owner, const wxString& dirname);

protected:

private:
    static bool CheckValidExtension(const wxFileName& file);
    wxListCtrl *m_owner;
};

#endif
