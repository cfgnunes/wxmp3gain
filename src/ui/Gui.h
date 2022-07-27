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
		wxBoxSizer* gui_boxMain;
		wxBoxSizer* gui_boxNormalVolume;
		wxTextCtrl* gui_txtNormalVolume;
		wxBoxSizer* gui_boxConstantGain;
		wxStaticText* gui_lblConstantGain;
		wxListCtrl* gui_lstFiles;
		wxGauge* gui_gugProgress;
		wxButton* gui_btnStop;
		wxMenuBar* gui_mainMenuBar;
		wxMenu* gui_mnbFile;
		wxMenu* gui_mnbEdit;
		wxMenu* gui_mnbAnalysis;
		wxMenu* gui_mnuGain;
		wxMenu* gui_mnbHelp;
		wxStatusBar* gui_mainStatusBar;
		wxToolBar* gui_mainToolBar;
		wxToolBarToolBase* gui_tbAddFolder;
		wxToolBarToolBase* gui_tbAddFiles;
		wxToolBarToolBase* gui_tbRemoveFiles;
		wxToolBarToolBase* gui_tbClearList;
		wxToolBarToolBase* gui_tbAnalyze;
		wxToolBarToolBase* gui_tbGain;
		wxToolBarToolBase* gui_tbSettings;
		wxToolBarToolBase* gui_tbAbout;
		wxMenu* gui_mainMenu;
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
		this->PopupMenu( gui_mainMenu, event.GetPosition() );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogSettings
///////////////////////////////////////////////////////////////////////////////
class DialogSettings : public wxDialog
{
	private:

	protected:
		wxCheckBox* gui_chkAutoLower;
		wxCheckBox* gui_chkForceInput;
		wxRadioButton* gui_optTagAPE;
		wxRadioButton* gui_optTagID3;
		wxRadioButton* gui_optTagSKIP;
		wxCheckBox* gui_chkTagFORCE;
		wxCheckBox* gui_chkConstantGain;
		wxSlider* gui_sldConstantGain;
		wxStaticText* gui_lblConstantGain;
		wxRadioButton* gui_optBothChannel;
		wxRadioButton* gui_optLeftChannel;
		wxRadioButton* gui_optRightChannel;
		wxButton* gui_btnDefault;
		wxButton* gui_btnOK;
		wxButton* gui_btnCancel;

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

