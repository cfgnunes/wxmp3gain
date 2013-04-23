/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileInfo.h"

// LIST (start)
#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfFiles);
// LIST (end)

FileInfo::FileInfo(const wxString& fileName) : fileName(fileName)
{
    volumeSet = false;
}

FileInfo::~FileInfo()
{
    //dtor
}

//sets..

void FileInfo::setVolume(const double& value)
{
    volume = value;
    volumeSet = true;
}

void FileInfo::setMaxPcmSample(const double& value)
{
    maxPcmSample = value;
}

void FileInfo::setGainChange(const int& value)
{
    gainChange = value;
}

void FileInfo::volumeReset()
{
    volumeSet = false;
}

//gets..

wxFileName FileInfo::getFileName()
{
    return fileName;
}

double FileInfo::getVolume()
{
    return volume;
}

double FileInfo::getMaxPcmSample()
{
    return maxPcmSample;
}

int FileInfo::getGainChange()
{
    return gainChange;
}

bool FileInfo::isVolumeSet()
{
    return volumeSet;
}
