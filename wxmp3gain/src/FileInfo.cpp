/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileInfo.h"

// LIST (start)
#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfFiles);
// LIST (end)

FileInfo::FileInfo(const wxString& fileName) : m_fileName(fileName), m_volumeSet(false) {
}

FileInfo::~FileInfo() {
}

// Sets..

void FileInfo::setVolume(const double& value) {
    m_volume = value;
    m_volumeSet = true;
}

void FileInfo::setMaxPcmSample(const double& value) {
    m_maxPcmSample = value;
}

void FileInfo::setGainChange(const int& value) {
    m_gainChange = value;
}

void FileInfo::volumeReset() {
    m_volumeSet = false;
}

// Gets..

wxFileName FileInfo::getFileName() {
    return m_fileName;
}

double FileInfo::getVolume() {
    return m_volume;
}

double FileInfo::getMaxPcmSample() {
    return m_maxPcmSample;
}

int FileInfo::getGainChange() {
    return m_gainChange;
}

bool FileInfo::isVolumeSet() {
    return m_volumeSet;
}
