/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUI_DIALOG_SETTINGS_HPP
#define GUI_DIALOG_SETTINGS_HPP

#include "../AppSettings.hpp"
#include "Gui.h"

class GuiDialogSettings : public DialogSettings {
  public:
    GuiDialogSettings(wxWindow *parent, AppSettings *appSettings);
    virtual ~GuiDialogSettings();

  protected:
    void updateDisabledControlsEvent(wxCommandEvent &event);
    void OnsldConstantGainSliderUpdated(wxScrollEvent &event);
    void OnbtnDefaultClick(wxCommandEvent &event);
    void OnbtnOKClick(wxCommandEvent &event);
    void OnbtnCancelClick(wxCommandEvent &event);

  private:
    void updateDisabledControls();
    void updateValueControls();
    void defaultValueControls();
    void saveValuesConfig();

    AppSettings *mp_appSettings;
};

#endif // GUI_DIALOG_SETTINGS_HPP
