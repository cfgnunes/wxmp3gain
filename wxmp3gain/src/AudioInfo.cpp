/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "AudioInfo.h"

AudioInfo::AudioInfo(const wxString& fileName) : fileName(fileName)
{
    volumeSet = false;
}

AudioInfo::~AudioInfo()
{
    //dtor
}

//sets..
void AudioInfo::setVolume(const double& value)
{
    volume = value;
    volumeSet = true;
}

void AudioInfo::setMaxPcmSample(const double& value)
{
    maxPcmSample = value;
}

void AudioInfo::setGainChange(const int& value)
{
    gainChange = value;
}

void AudioInfo::volumeReset()
{
    volumeSet = false;
}

//gets..
double AudioInfo::getVolume()
{
    return volume;
}

double AudioInfo::getMaxPcmSample()
{
    return maxPcmSample;
}

int AudioInfo::getGainChange()
{
    return gainChange;
}

bool AudioInfo::isVolumeSet()
{
    return volumeSet;
}
