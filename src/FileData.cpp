/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileData.hpp"

FileData::FileData(const wxString &fileName)
    : m_fileName(fileName), m_volumeSet(false) {
}

FileData::~FileData() {
}

// Sets..

void FileData::setVolume(const double &value) {
    m_volume = value;
    m_volumeSet = true;
}

void FileData::setMaxPcmSample(const double &value) {
    m_maxPcmSample = value;
}

void FileData::setGainChange(const int &value) {
    m_gainChange = value;
}

void FileData::volumeReset() {
    m_volumeSet = false;
}

// Gets..

wxFileName FileData::getFileName() const {
    return m_fileName;
}

double FileData::getVolume() const {
    return m_volume;
}

double FileData::getMaxPcmSample() const {
    return m_maxPcmSample;
}

int FileData::getGainChange() const {
    return m_gainChange;
}

bool FileData::isVolumeSet() const {
    return m_volumeSet;
}
