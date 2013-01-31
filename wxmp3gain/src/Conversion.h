/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <wx/string.h>

class Conversion
{
public:
    static void convertDotComma(wxString& str);
    static int convertDoubleToIntGain(const double& dblGainChange);
    static int getMaxNoclipMp3Gain(const double& mvarCurrMaxAmp);
private:
};

#endif
