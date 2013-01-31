/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef AUDIOINFO_H
#define AUDIOINFO_H

#include <wx/object.h>
#include <wx/string.h>

class AudioInfo : public wxObject
{
public:
    AudioInfo (const wxString& fileName);
    virtual ~AudioInfo();

    //gets...
    double getVolume();
    double getMaxPcmSample();
    bool isVolumeSet();
    int getGainChange();

    //sets...
    void setVolume(const double& value);
    void setMaxPcmSample(const double& value);
    void setGainChange(const int& value);
    void volumeReset();

private:
    wxString fileName;
    double volume;
    double maxPcmSample;
    bool volumeSet;
    int gainChange;
};

#endif
