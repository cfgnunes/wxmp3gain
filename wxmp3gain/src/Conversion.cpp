/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "Conversion.h"

#include <cmath>

void Conversion::convertDotComma(wxString& str) {
    // Convert between DOT/COMMA if necessary [workaround to use .ToDouble]
    if (wxString::Format(_T("%.1f"), 1.1)[1] == ',')
        str.Replace(_T("."), _T(","));
    else
        str.Replace(_T(","), _T("."));
}

int Conversion::convertDoubleToIntGain(const double& dblGainChange) {
    int intGainChange;

    // From mp3gain code...
    if (fabs(dblGainChange) - (double) ((int) (fabs(dblGainChange))) < 0.5)
        intGainChange = (int) (dblGainChange);
    else
        intGainChange = (int) (dblGainChange) + (dblGainChange < 0 ? -1 : 1);
    // ...end

    return intGainChange;
}

int Conversion::getMaxNoclipMp3Gain(const double& mvarCurrMaxAmp) {
    int MaxNoclipMp3Gain;
    double dblAdjust;

    // From mp3gain GUI vb6 code...
    if ((mvarCurrMaxAmp < 1000000.0) && (mvarCurrMaxAmp > 0)) {
        dblAdjust = 4.0 * log10(32767.0 / mvarCurrMaxAmp) / log10(2);
        if ((double) ((int) (dblAdjust)) > dblAdjust)
            MaxNoclipMp3Gain = (int) (dblAdjust) - 1;
        else
            MaxNoclipMp3Gain = (int) (dblAdjust);
    } else {
        MaxNoclipMp3Gain = 0;
    }
    // ...end

    return MaxNoclipMp3Gain;
}
