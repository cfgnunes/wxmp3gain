/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUIDIALOGSETTINGS_H
#define GUIDIALOGSETTINGS_H

#include "Gui.h"
#include "ConfigBase.h"

class GuiDialogSettings : public DialogSettings {
public:
    GuiDialogSettings(wxWindow *parent, ConfigBase *configBase);

    virtual ~GuiDialogSettings();

protected:
    void updateDisabledControlsEvent(wxCommandEvent &event);

    void OnsldConstantGainCmdSliderUpdated(wxScrollEvent &event);

    void OnbtnDefaultClick(wxCommandEvent &event);

    void OnbtnOKClick(wxCommandEvent &event);

    void OnbtnCancelClick(wxCommandEvent &event);

private:
    void updateDisabledControls();

    void updateValueControls();

    void defaultValueControls();

    void saveValuesConfig();

    ConfigBase *mp_configBase;
};

#endif // GUIDIALOGSETTINGS_H
