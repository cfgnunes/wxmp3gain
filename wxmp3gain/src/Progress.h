/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef PROGRESS_H
#define PROGRESS_H

#include "FileInfo.h"
#include "ConfigBase.h"
#include "Global.h"

#include <wx/listctrl.h>

enum {
    TOOL_ANALYSIS = 0,
    TOOL_GAIN = 1,
    TOOL_UNDO = 2,
    TOOL_DELETE_TAG = 3,
};

class Progress {
public:
    Progress(wxWindow* parent, ConfigBase* configBase, wxListCtrl* listFiles, ArrayOfFiles* lstFilesData, const double& dblNormalVolume, int workType);
    virtual ~Progress();
    void execute();

private:
    void processFile(int fileIterator);
    void processOutputString(int fileIterator);
    wxWindow* mp_parent;
    ConfigBase* mp_configBase;
    wxListCtrl* mp_listFiles;
    ArrayOfFiles* mp_lstFilesData;
    double m_dblNormalVolume;
    int m_workType;
    wxArrayString m_inputString;
};

#endif // PROGRESS_H
