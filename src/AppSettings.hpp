/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIG_BASE_HPP
#define CONFIG_BASE_HPP

#include <wx/config.h>
#include <wx/string.h>

class AppSettings {
  public:
    AppSettings(const wxString &appName = wxEmptyString);
    ~AppSettings();

    void setDefaultConfig();
    void setConfigFlush();
    wxString getStringToolOptions() const;
    wxString getStringToolOptionsTag() const;
    wxString getStringToolOptionsGain() const;

    // Gets
    wxString getAppVersion() const;
    wxString getLastOpenDir() const;
    int getNormalVolumeDb() const;
    bool getAutoLowerEnabled() const;
    bool getForceInputEnabled() const;
    int getTagOptions() const;
    bool getTagForceEnabled() const;
    bool getConstantGainEnabled() const;
    int getConstantGainValue() const;
    int getChannelGainMode() const;

    // Sets
    void setAppVersion(wxString value);
    void setLastOpenDir(wxString value);
    void setNormalVolumeDb(int value);
    void setAutoLowerEnabled(bool value);
    void setForceInputEnabled(bool value);
    void setTagOptions(int value);
    void setTagForceEnabled(bool value);
    void setConstantGainEnabled(bool value);
    void setConstantGainValue(int value);
    void setChannelGainMode(int value);

  private:
    wxConfig *mp_config;
};

#endif // CONFIG_BASE_HPP
