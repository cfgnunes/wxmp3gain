/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FILELISTMANAGER_H
#define FILELISTMANAGER_H

#include "FileInfo.h"
#include "ConfigBase.h"

#include <wx/listctrl.h>
#include <wx/arrstr.h>
#include <wx/filename.h>
#include <list>

class FileListManager {
public:
    FileListManager(wxListCtrl *owner);

    virtual ~FileListManager();

    void insertFilesAndDir(const wxArrayString &filenames);

    void insertFiles(const wxArrayString &filenames);

    void insertDir(const wxString &dirname);

    void deleteItem(unsigned long int index);

    void clear();

    long unsigned int size();

    FileInfo &getItem(unsigned long int index);

    wxListCtrl &getOwner();

    void updateGainLabels(const double &dblNormalVolumeUpdate, ConfigBase *configBase);

private:
    bool checkValidExtension(const wxFileName &file) const;

    wxListCtrl *mp_owner;
    std::list<FileInfo> *mp_lstFilesData;
};

#endif // FILELISTMANAGER_H
