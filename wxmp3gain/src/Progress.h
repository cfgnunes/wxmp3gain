/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef PROGRESS_H
#define PROGRESS_H

#include "ConfigBase.h"
#include "Global.h"

#include <wx/listctrl.h>
#include <wx/hash.h>

enum
{
    TOOL_ANALYSIS   = 0,
    TOOL_GAIN       = 1,
    TOOL_UNDO       = 2,
    TOOL_DELETE_TAG = 3,
};

class Progress
{
public:
    Progress (wxWindow* parent, ConfigBase* configBase, wxListCtrl* listFiles, wxHashTable* lstHashFiles,const double& dblNormalVolume, int workType);
    virtual ~Progress();
    void Execute();

protected:

private:
    void ProcessFile(int fileIterator);
    void ProcessOutputString(int fileIterator);
    wxWindow* parent;
    ConfigBase* configBase;
    wxListCtrl* listFiles;
    wxHashTable* lstHashFiles;
    double dblNormalVolume;
    int workType;
    wxArrayString inputString;
};

#endif
