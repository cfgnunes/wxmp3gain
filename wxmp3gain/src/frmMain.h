/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMMAIN_H
#define FRMMAIN_H

#include "ConfigBase.h"
#include "FileInfo.h"

//(*Headers(frmMain)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class frmMain : public wxFrame
{
public:

    frmMain(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~frmMain();

    //(*Declarations(frmMain)
    wxToolBarToolBase* ToolBarItem4;
    wxMenuItem* MenuItem8;
    wxToolBar* ToolBar1;
    wxMenu Menu1;
    wxMenuItem* MenuItem7;
    wxToolBarToolBase* ToolBarItem3;
    wxStaticText* StaticText2;
    wxMenuItem* MenuItem14;
    wxMenuItem* MenuItem15;
    wxPanel* Panel1;
    wxStaticText* StaticText1;
    wxMenuItem* MenuItem17;
    wxStaticText* StaticText3;
    wxMenuItem* MenuItem13;
    wxToolBarToolBase* ToolBarItem6;
    wxMenuItem* MenuItem12;
    wxToolBarToolBase* ToolBarItem1;
    wxMenu* Menu7;
    wxStaticText* lblConstantGain;
    wxStatusBar* StatusBar1;
    wxToolBarToolBase* ToolBarItem5;
    wxTextCtrl* txtNormalVolume;
    wxListCtrl* lstFiles;
    wxToolBarToolBase* ToolBarItem8;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem16;
    wxMenu* Menu6;
    wxMenuItem* MenuItem18;
    wxToolBarToolBase* ToolBarItem2;
    wxToolBarToolBase* ToolBarItem7;
    //*)
    wxBoxSizer* boxNormalVolume;
    wxBoxSizer* boxConstantGain;
    wxBoxSizer* boxMain;
    static void updateGainLabels(wxListCtrl* listFilesUpdate, ConfigBase* configBaseUpdate, ArrayOfFiles* lstFilesDataUpdate, const double& dblNormalVolumeUpdate);

protected:

    //(*Identifiers(frmMain)
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT4;
    static const long ID_LISTCTRL2;
    static const long ID_PANEL1;
    static const long ID_MENUITEM17;
    static const long ID_MENUITEM2;
    static const long ID_MENUITEM1;
    static const long ID_MENUITEM3;
    static const long ID_MENUITEM4;
    static const long ID_MENUITEM6;
    static const long ID_MENUITEM14;
    static const long ID_MENUITEM15;
    static const long ID_MENUITEM16;
    static const long ID_MENUITEM7;
    static const long ID_MENUITEM8;
    static const long ID_MENUITEM10;
    static const long ID_MENUITEM11;
    static const long ID_MENUITEM9;
    static const long ID_STATUSBAR1;
    static const long ID_TOOLBARITEM8;
    static const long ID_TOOLBARITEM1;
    static const long ID_TOOLBARITEM2;
    static const long ID_TOOLBARITEM3;
    static const long ID_TOOLBARITEM4;
    static const long ID_TOOLBARITEM5;
    static const long ID_TOOLBARITEM6;
    static const long ID_TOOLBARITEM7;
    static const long ID_TOOLBAR1;
    static const long ID_MENUITEM18;
    static const long ID_MENUITEM5;
    static const long ID_MENUITEM12;
    static const long ID_MENUITEM13;
    //*)

private:

    //(*Handlers(frmMain)
    void mnuAddFiles(wxCommandEvent& event);
    void mnuExit(wxCommandEvent& event);
    void mnuClearList(wxCommandEvent& event);
    void mnuRemoveFiles(wxCommandEvent& event);
    void OnlstFilesClick(wxListEvent& event);
    void OnlstFilesItemRClick(wxListEvent& event);
    void mnuAbout(wxCommandEvent& event);
    void mnuWebsite(wxCommandEvent& event);
    void mnuToolWebsite(wxCommandEvent& event);
    void mnuSettings(wxCommandEvent& event);
    void mnuScan(wxCommandEvent& event);
    void mnuFix(wxCommandEvent& event);
    void OntxtNormalVolumeText(wxCommandEvent& event);
    void OnlstFilesInsertItem(wxListEvent& event);
    void OnlstFilesDeleteItem(wxListEvent& event);
    void mnuClearAnalysis(wxCommandEvent& event);
    void mnuUndoGain(wxCommandEvent& event);
    void mnuRemoveTags(wxCommandEvent& event);
    void mnuAddDirectory(wxCommandEvent& event);
    //*)

    void OntxtNormalVolumeTextKillFocus(wxFocusEvent& event);
    void updateStatusBar();
    void updateTxtNormalVolumeDb();
    void updateDisabledControls();
    void loadResources();
    ConfigBase *configBase;
    ArrayOfFiles *lstFilesData;
    double dblNormalVolume;

    DECLARE_EVENT_TABLE()
};

#endif
