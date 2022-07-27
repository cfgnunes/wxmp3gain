/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FILE_DROP_HPP
#define FILE_DROP_HPP

#include "FileData.hpp"
#include "ListManager.hpp"

#include <wx/dnd.h>

class FileDrop : public wxFileDropTarget {
  public:
    FileDrop(ListManager *listManager);
    virtual ~FileDrop();

    virtual bool OnDropFiles(wxCoord, wxCoord, const wxArrayString &filenames);

  private:
    ListManager *mp_listManager;
};

#endif // FILE_DROP_HPP
