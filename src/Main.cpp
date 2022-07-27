/*
 * wxMP3gain - A free front-end for MP3gain.
 * Copyright (C) 2012-2019 Cristiano Fraga G. Nunes
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Main.h"
#include "Constants.h"
#include "GuiFrameMain.h"

IMPLEMENT_APP(Main)

bool Main::OnInit() {
    // Load language translation
    mp_locale = new wxLocale(wxLocale::GetSystemLanguage());
    mp_locale->AddCatalogLookupPathPrefix(GetResourceDir() + _T("po"));
    mp_locale->AddCatalog(_T("wxmp3gain"));

    wxInitAllImageHandlers();
    GuiFrameMain *guiFrameMain = new GuiFrameMain(0);

    // Read command line files
    mp_filesCmdLine = new wxArrayString();
    for (int i = 1; i < argc; i++)
        mp_filesCmdLine->Add(wxString(argv[i]));
    guiFrameMain->setFilesCmdLine(*mp_filesCmdLine);

    guiFrameMain->Show();
    SetTopWindow(guiFrameMain);
    return true;
}
