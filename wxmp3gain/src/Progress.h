/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef PROGRESS_H
#define PROGRESS_H

#include "FileInfo.h"
#include "ConfigBase.h"
#include "Constants.h"
#include "FileListManager.h"

#include <wx/window.h>
#include <wx/arrstr.h>

enum {
    TOOL_ANALYSIS = 0,
    TOOL_GAIN = 1,
    TOOL_UNDO = 2,
    TOOL_DELETE_TAG = 3,
};

class Progress {
public:
    Progress(wxWindow *parent, ConfigBase* configBase, FileListManager *fileListManager, double dblNormalVolume, int workType);
    virtual ~Progress();
    void execute();

private:
    void processFile(unsigned long int fileIterator);
    void processOutputString(unsigned long int fileIterator);

    wxWindow *mp_parent;
    ConfigBase *mp_configBase;
    FileListManager *mp_fileListManager;
    double m_dblNormalVolume;
    int m_workType;
    wxArrayString m_inputString;
};

#endif // PROGRESS_H
