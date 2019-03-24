/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>

class Application : public wxApp {
public:
    virtual bool OnInit();

private:
    wxLocale *mp_locale;
    wxArrayString *mp_filesCmdLine;
};

#endif // APPLICATION_H
