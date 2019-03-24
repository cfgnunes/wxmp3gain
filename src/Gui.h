///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/timer.h>
#include <wx/frame.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/radiobut.h>
#include <wx/slider.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_ADD_FOLDER 1000
#define ID_ADD_FILES 1001
#define ID_EXIT 1002
#define ID_REMOVE_FILES 1003
#define ID_CLEAR_LIST 1004
#define ID_SETTINGS 1005
#define ID_ANALYZE 1006
#define ID_CLEAR_ANALYSIS 1007
#define ID_GAIN 1008
#define ID_UNDO_GAIN 1009
#define ID_DELETE_TAG 1010
#define ID_WEBSITE 1011
#define ID_TOOL_WEBSITE 1012
#define ID_ABOUT 1013

///////////////////////////////////////////////////////////////////////////////
/// Class Main
///////////////////////////////////////////////////////////////////////////////
class Main : public wxFrame 
{
	private:
	
	protected:
		wxBoxSizer* g_boxMain;
		wxPanel* m_panel4;
		wxBoxSizer* g_boxNormalVolume;
		wxStaticText* m_staticText9;
		wxTextCtrl* g_txtNormalVolume;
		wxStaticText* m_staticText10;
		wxBoxSizer* g_boxConstantGain;
		wxStaticText* m_staticText11;
		wxStaticText* g_lblConstantGain;
		wxListCtrl* g_lstFiles;
		wxGauge* g_gugProgress;
		wxButton* g_btnStop;
		wxMenuBar* g_mainMenuBar;
		wxMenu* g_mnbFile;
		wxMenu* g_mnbEdit;
		wxMenu* g_mnbAnalysis;
		wxMenu* g_mnuGain;
		wxMenu* g_mnbHelp;
		wxStatusBar* g_mainStatusBar;
		wxToolBar* g_mainToolBar;
		wxToolBarToolBase* g_tbAddFolder; 
		wxToolBarToolBase* g_tbAddFiles; 
		wxToolBarToolBase* g_tbRemoveFiles; 
		wxToolBarToolBase* g_tbClearList; 
		wxToolBarToolBase* g_tbAnalyze; 
		wxToolBarToolBase* g_tbGain; 
		wxToolBarToolBase* g_tbSettings; 
		wxToolBarToolBase* g_tbAbout; 
		wxMenu* g_mainMenu;
		wxTimer m_timer1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OntxtNormalVolumeTextKillFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnlstFilesDeleteItem( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesInsertItem( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesItemSelect( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesItemRClick( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesKeyDown( wxListEvent& event ) { event.Skip(); }
		virtual void btnProcessStop( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuAddDirectory( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuAddFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuRemoveFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuClearList( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuSettings( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuAnalyze( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuClearAnalysis( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuGain( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuUndoGain( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuDeleteTag( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuToolWebsite( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuWebsite( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer1Trigger( wxTimerEvent& event ) { event.Skip(); }
		
	
	public:
		
		Main( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 790,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Main();
		
		void MainOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( g_mainMenu, event.GetPosition() );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Settings
///////////////////////////////////////////////////////////////////////////////
class Settings : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panel1;
		wxCheckBox* g_chkAutoLower;
		wxCheckBox* g_chkWorkOnTemporaryFile;
		wxCheckBox* g_chkPreserveTime;
		wxCheckBox* g_chkForceInput;
		wxPanel* m_panel2;
		wxRadioButton* g_optTagAPE;
		wxRadioButton* g_optTagID3;
		wxRadioButton* g_optTagSKIP;
		wxCheckBox* g_chkTagFORCE;
		wxPanel* m_panel3;
		wxCheckBox* g_chkConstantGain;
		wxStaticText* m_staticText13;
		wxSlider* g_sldConstantGain;
		wxStaticText* g_lblConstantGain;
		wxRadioButton* g_optBothChannel;
		wxRadioButton* g_optLeftChannel;
		wxRadioButton* g_optRightChannel;
		wxButton* g_btnDefault;
		wxButton* g_btnOK;
		wxButton* g_btnCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void updateDisabledControlsEvent( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnsldConstantGainCmdSliderUpdated( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnbtnDefaultClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnOKClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Settings( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~Settings();
	
};

#endif //__GUI_H__
