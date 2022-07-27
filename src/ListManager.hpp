/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef LIST_MANAGER_HPP
#define LIST_MANAGER_HPP

#include "AppSettings.hpp"
#include "FileData.hpp"

#include <list>
#include <wx/arrstr.h>
#include <wx/filename.h>
#include <wx/listctrl.h>

class ListManager {
  public:
    ListManager(wxListCtrl *listCtrl);
    virtual ~ListManager();

    void insertFilesAndDir(const wxArrayString &filenames);
    void insertFiles(const wxArrayString &filenames);
    void insertDir(const wxString &dirname);
    void deleteItem(unsigned long int index);
    void clear();
    long unsigned int size();
    FileData &getFileData(unsigned long int index);
    wxListCtrl &getListCtrl();
    void updateGainLabels(const double &dblNormalVolumeUpdate, AppSettings *appSettings);

  private:
    bool checkValidExtension(const wxFileName &file) const;

    wxListCtrl *mp_listCtrl;
    std::list<FileData> *mp_filesData;
};

#endif // LIST_MANAGER_HPP
