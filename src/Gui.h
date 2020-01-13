///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jan  3 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/panel.h>
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
/// Class FrameMain
///////////////////////////////////////////////////////////////////////////////
class FrameMain : public wxFrame
{
	private:

	protected:
		wxBoxSizer* g_boxMain;
		wxBoxSizer* g_boxNormalVolume;
		wxTextCtrl* g_txtNormalVolume;
		wxBoxSizer* g_boxConstantGain;
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

		FrameMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 790,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~FrameMain();

		void FrameMainOnContextMenu( wxMouseEvent &event )
		{
		this->PopupMenu( g_mainMenu, event.GetPosition() );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogSettings
///////////////////////////////////////////////////////////////////////////////
class DialogSettings : public wxDialog
{
	private:

	protected:
		wxCheckBox* g_chkAutoLower;
		wxCheckBox* g_chkForceInput;
		wxRadioButton* g_optTagAPE;
		wxRadioButton* g_optTagID3;
		wxRadioButton* g_optTagSKIP;
		wxCheckBox* g_chkTagFORCE;
		wxCheckBox* g_chkConstantGain;
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

		DialogSettings( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~DialogSettings();

};

