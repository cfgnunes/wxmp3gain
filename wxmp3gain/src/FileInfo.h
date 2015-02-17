/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FILEINFO_H
#define FILEINFO_H

#include <wx/object.h>
#include <wx/string.h>
#include <wx/filename.h>

// LIST (start)
#include <wx/dynarray.h>
class FileInfo;
WX_DECLARE_OBJARRAY(FileInfo, ArrayOfFiles);
// LIST (end)

class FileInfo : public wxObject {
public:
    FileInfo(const wxString& fileName);
    virtual ~FileInfo();

    // Gets...
    wxFileName getFileName() const;
    double getVolume() const;
    double getMaxPcmSample() const;
    bool isVolumeSet() const;
    int getGainChange() const;

    // Sets...
    void setVolume(const double& value);
    void setMaxPcmSample(const double& value);
    void setGainChange(const int& value);
    void volumeReset();

private:
    wxFileName m_fileName;
    double m_volume;
    double m_maxPcmSample;
    bool m_volumeSet;
    int m_gainChange;
};

#endif // FILEINFO_H
