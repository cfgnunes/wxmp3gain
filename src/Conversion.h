/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <wx/string.h>

class Conversion {
public:
    static void convertDotComma(wxString &str);

    static int convertDoubleToIntGain(const double &dblGainChange);

    static int getMaxNoclipMp3Gain(const double &mvarCurrMaxAmp);
};

#endif // CONVERSION_HPP
