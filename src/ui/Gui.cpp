///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jan  3 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Gui.h"

///////////////////////////////////////////////////////////////////////////

FrameMain::FrameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	gui_boxMain = new wxBoxSizer( wxVERTICAL );

	wxPanel* m_panel4;
	m_panel4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	gui_boxNormalVolume = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText9;
	m_staticText9 = new wxStaticText( m_panel4, wxID_ANY, _("Normal volume (dB):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gui_boxNormalVolume->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_txtNormalVolume = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gui_boxNormalVolume->Add( gui_txtNormalVolume, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxStaticText* m_staticText10;
	m_staticText10 = new wxStaticText( m_panel4, wxID_ANY, _("(Default 89.0 dB)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	gui_boxNormalVolume->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer13->Add( gui_boxNormalVolume, 0, wxEXPAND, 5 );

	gui_boxConstantGain = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText11;
	m_staticText11 = new wxStaticText( m_panel4, wxID_ANY, _("Using constant gain: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	gui_boxConstantGain->Add( m_staticText11, 0, wxALL, 5 );

	gui_lblConstantGain = new wxStaticText( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblConstantGain->Wrap( -1 );
	gui_boxConstantGain->Add( gui_lblConstantGain, 1, wxALL, 5 );


	bSizer13->Add( gui_boxConstantGain, 0, wxEXPAND, 5 );

	gui_lstFiles = new wxListCtrl( m_panel4, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT );
	bSizer13->Add( gui_lstFiles, 1, wxALL|wxEXPAND, 0 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	gui_gugProgress = new wxGauge( m_panel4, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gui_gugProgress->SetValue( 0 );
	bSizer11->Add( gui_gugProgress, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_btnStop = new wxButton( m_panel4, wxID_ANY, _("&Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	gui_btnStop->Enable( false );

	bSizer11->Add( gui_btnStop, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer13->Add( bSizer11, 0, wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer13 );
	m_panel4->Layout();
	bSizer13->Fit( m_panel4 );
	gui_boxMain->Add( m_panel4, 1, wxEXPAND, 5 );


	this->SetSizer( gui_boxMain );
	this->Layout();
	gui_mainMenuBar = new wxMenuBar( 0 );
	gui_mnbFile = new wxMenu();
	wxMenuItem* gui_mnbAddFolder;
	gui_mnbAddFolder = new wxMenuItem( gui_mnbFile, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbFile->Append( gui_mnbAddFolder );

	wxMenuItem* gui_mnbAddFiles;
	gui_mnbAddFiles = new wxMenuItem( gui_mnbFile, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbFile->Append( gui_mnbAddFiles );

	gui_mnbFile->AppendSeparator();

	wxMenuItem* gui_mnbExit;
	gui_mnbExit = new wxMenuItem( gui_mnbFile, ID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbFile->Append( gui_mnbExit );

	gui_mainMenuBar->Append( gui_mnbFile, _("&File") );

	gui_mnbEdit = new wxMenu();
	wxMenuItem* gui_mnbRemoveFiles;
	gui_mnbRemoveFiles = new wxMenuItem( gui_mnbEdit, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbEdit->Append( gui_mnbRemoveFiles );

	wxMenuItem* gui_mnbClearList;
	gui_mnbClearList = new wxMenuItem( gui_mnbEdit, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbEdit->Append( gui_mnbClearList );

	gui_mnbEdit->AppendSeparator();

	wxMenuItem* gui_mnbSettings;
	gui_mnbSettings = new wxMenuItem( gui_mnbEdit, ID_SETTINGS, wxString( _("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbEdit->Append( gui_mnbSettings );

	gui_mainMenuBar->Append( gui_mnbEdit, _("&Edit") );

	gui_mnbAnalysis = new wxMenu();
	wxMenuItem* gui_mnbAnalyze;
	gui_mnbAnalyze = new wxMenuItem( gui_mnbAnalysis, ID_ANALYZE, wxString( _("Analyze") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbAnalysis->Append( gui_mnbAnalyze );

	gui_mnbAnalysis->AppendSeparator();

	wxMenuItem* gui_mnbClearAnalysis;
	gui_mnbClearAnalysis = new wxMenuItem( gui_mnbAnalysis, ID_CLEAR_ANALYSIS, wxString( _("Clear analysis") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbAnalysis->Append( gui_mnbClearAnalysis );

	gui_mainMenuBar->Append( gui_mnbAnalysis, _("&Analysis") );

	gui_mnuGain = new wxMenu();
	wxMenuItem* gui_mnbGain;
	gui_mnbGain = new wxMenuItem( gui_mnuGain, ID_GAIN, wxString( _("Gain") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnuGain->Append( gui_mnbGain );

	gui_mnuGain->AppendSeparator();

	wxMenuItem* gui_mnbUndoGain;
	gui_mnbUndoGain = new wxMenuItem( gui_mnuGain, ID_UNDO_GAIN, wxString( _("Undo gain changes (based on stored tag info)\tCtrl+Z") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnuGain->Append( gui_mnbUndoGain );

	wxMenuItem* gui_mnbDeleteTag;
	gui_mnbDeleteTag = new wxMenuItem( gui_mnuGain, ID_DELETE_TAG, wxString( _("Delete stored tag info") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnuGain->Append( gui_mnbDeleteTag );

	gui_mainMenuBar->Append( gui_mnuGain, _("&Gain") );

	gui_mnbHelp = new wxMenu();
	wxMenuItem* gui_mnbToolWebsite;
	gui_mnbToolWebsite = new wxMenuItem( gui_mnbHelp, ID_WEBSITE, wxString( _("MP3gain Website") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbHelp->Append( gui_mnbToolWebsite );

	wxMenuItem* gui_mnbWebsite;
	gui_mnbWebsite = new wxMenuItem( gui_mnbHelp, ID_TOOL_WEBSITE, wxString( _("wxMP3gain Website") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbHelp->Append( gui_mnbWebsite );

	gui_mnbHelp->AppendSeparator();

	wxMenuItem* gui_mnbAbout;
	gui_mnbAbout = new wxMenuItem( gui_mnbHelp, ID_ABOUT, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbHelp->Append( gui_mnbAbout );

	gui_mainMenuBar->Append( gui_mnbHelp, _("&Help") );

	this->SetMenuBar( gui_mainMenuBar );

	gui_mainStatusBar = this->CreateStatusBar( 3, wxSTB_SIZEGRIP, wxID_ANY );
	gui_mainToolBar = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
	gui_tbAddFolder = gui_mainToolBar->AddTool( ID_ADD_FOLDER, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add folder"), wxEmptyString, NULL );

	gui_tbAddFiles = gui_mainToolBar->AddTool( ID_ADD_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add files"), wxEmptyString, NULL );

	gui_tbRemoveFiles = gui_mainToolBar->AddTool( ID_REMOVE_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Remove files"), wxEmptyString, NULL );

	gui_tbClearList = gui_mainToolBar->AddTool( ID_CLEAR_LIST, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Clear list"), wxEmptyString, NULL );

	gui_mainToolBar->AddSeparator();

	gui_tbAnalyze = gui_mainToolBar->AddTool( ID_ANALYZE, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Analyze"), wxEmptyString, NULL );

	gui_tbGain = gui_mainToolBar->AddTool( ID_GAIN, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Gain"), wxEmptyString, NULL );

	gui_mainToolBar->AddSeparator();

	gui_tbSettings = gui_mainToolBar->AddTool( ID_SETTINGS, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Settings"), wxEmptyString, NULL );

	gui_tbAbout = gui_mainToolBar->AddTool( ID_ABOUT, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("About"), wxEmptyString, NULL );

	gui_mainToolBar->Realize();

	gui_mainMenu = new wxMenu();
	wxMenuItem* gui_mnuAddFolder;
	gui_mnuAddFolder = new wxMenuItem( gui_mainMenu, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mainMenu->Append( gui_mnuAddFolder );

	wxMenuItem* gui_mnuAddFiles;
	gui_mnuAddFiles = new wxMenuItem( gui_mainMenu, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mainMenu->Append( gui_mnuAddFiles );

	wxMenuItem* gui_mnuRemoveFiles;
	gui_mnuRemoveFiles = new wxMenuItem( gui_mainMenu, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mainMenu->Append( gui_mnuRemoveFiles );

	wxMenuItem* gui_mnuClearList;
	gui_mnuClearList = new wxMenuItem( gui_mainMenu, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mainMenu->Append( gui_mnuClearList );

	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( FrameMain::FrameMainOnContextMenu ), NULL, this );

	m_timer1.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	gui_txtNormalVolume->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FrameMain::OntxtNormalVolumeTextKillFocus ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	gui_btnStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::btnProcessStop ), NULL, this );
	gui_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, gui_mnbAddFolder->GetId());
	gui_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, gui_mnbAddFiles->GetId());
	gui_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuExit ), this, gui_mnbExit->GetId());
	gui_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, gui_mnbRemoveFiles->GetId());
	gui_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, gui_mnbClearList->GetId());
	gui_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuSettings ), this, gui_mnbSettings->GetId());
	gui_mnbAnalysis->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAnalyze ), this, gui_mnbAnalyze->GetId());
	gui_mnbAnalysis->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearAnalysis ), this, gui_mnbClearAnalysis->GetId());
	gui_mnuGain->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuGain ), this, gui_mnbGain->GetId());
	gui_mnuGain->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuUndoGain ), this, gui_mnbUndoGain->GetId());
	gui_mnuGain->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuDeleteTag ), this, gui_mnbDeleteTag->GetId());
	gui_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuToolWebsite ), this, gui_mnbToolWebsite->GetId());
	gui_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuWebsite ), this, gui_mnbWebsite->GetId());
	gui_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAbout ), this, gui_mnbAbout->GetId());
	this->Connect( gui_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Connect( gui_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Connect( gui_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Connect( gui_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Connect( gui_tbAnalyze->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAnalyze ) );
	this->Connect( gui_tbGain->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuGain ) );
	this->Connect( gui_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Connect( gui_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	gui_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, gui_mnuAddFolder->GetId());
	gui_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, gui_mnuAddFiles->GetId());
	gui_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, gui_mnuRemoveFiles->GetId());
	gui_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, gui_mnuClearList->GetId());
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );
}

FrameMain::~FrameMain()
{
	// Disconnect Events
	gui_txtNormalVolume->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FrameMain::OntxtNormalVolumeTextKillFocus ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	gui_btnStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::btnProcessStop ), NULL, this );
	this->Disconnect( gui_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Disconnect( gui_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Disconnect( gui_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Disconnect( gui_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Disconnect( gui_tbAnalyze->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAnalyze ) );
	this->Disconnect( gui_tbGain->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuGain ) );
	this->Disconnect( gui_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Disconnect( gui_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );

	delete gui_mainMenu;
}

DialogSettings::DialogSettings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxNotebook* m_notebook1;
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxPanel* m_panel1;
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Gain options") ), wxHORIZONTAL );

	gui_chkAutoLower = new wxCheckBox( sbSizer5->GetStaticBox(), wxID_ANY, _("Automatically lower gain to not clip audio"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( gui_chkAutoLower, 0, wxALL, 2 );


	bSizer5->Add( sbSizer5, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("File options") ), wxVERTICAL );

	gui_chkForceInput = new wxCheckBox( sbSizer11->GetStaticBox(), wxID_ANY, _("Force to assume input is an MPEG 2 Layer III file"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( gui_chkForceInput, 0, wxALL, 2 );


	bSizer5->Add( sbSizer11, 0, wxEXPAND, 5 );


	m_panel1->SetSizer( bSizer5 );
	m_panel1->Layout();
	bSizer5->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("General"), true );
	wxPanel* m_panel2;
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer61;
	sbSizer61 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Tags options") ), wxVERTICAL );

	gui_optTagAPE = new wxRadioButton( sbSizer61->GetStaticBox(), wxID_ANY, _("Use APEv2 tag for gain information (default)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( gui_optTagAPE, 0, wxALL, 2 );

	gui_optTagID3 = new wxRadioButton( sbSizer61->GetStaticBox(), wxID_ANY, _("Use ID3v2 tag for gain information"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( gui_optTagID3, 0, wxALL, 2 );

	gui_optTagSKIP = new wxRadioButton( sbSizer61->GetStaticBox(), wxID_ANY, _("Skip stored tag info (do not read or write tags)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( gui_optTagSKIP, 0, wxALL, 2 );


	bSizer71->Add( sbSizer61, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer611;
	sbSizer611 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Tags reading") ), wxHORIZONTAL );

	gui_chkTagFORCE = new wxCheckBox( sbSizer611->GetStaticBox(), wxID_ANY, _("Force re-calculation (do not read tag info)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer611->Add( gui_chkTagFORCE, 0, wxALL, 2 );


	bSizer71->Add( sbSizer611, 0, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer71 );
	m_panel2->Layout();
	bSizer71->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, _("Tags"), false );
	wxPanel* m_panel3;
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Constant gain") ), wxVERTICAL );

	gui_chkConstantGain = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Use constant gain without doing any analysis"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( gui_chkConstantGain, 0, wxALL, 2 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText13;
	m_staticText13 = new wxStaticText( sbSizer9->GetStaticBox(), wxID_ANY, _("Constant gain:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer15->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_sldConstantGain = new wxSlider( sbSizer9->GetStaticBox(), wxID_ANY, 0, -8, 8, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer15->Add( gui_sldConstantGain, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_lblConstantGain = new wxStaticText( sbSizer9->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblConstantGain->Wrap( -1 );
	bSizer15->Add( gui_lblConstantGain, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer9->Add( bSizer15, 1, wxEXPAND, 5 );


	bSizer10->Add( sbSizer9, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer612;
	sbSizer612 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Channel") ), wxVERTICAL );

	gui_optBothChannel = new wxRadioButton( sbSizer612->GetStaticBox(), wxID_ANY, _("Gain on both channels"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( gui_optBothChannel, 0, wxALL, 2 );

	gui_optLeftChannel = new wxRadioButton( sbSizer612->GetStaticBox(), wxID_ANY, _("Gain on left channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( gui_optLeftChannel, 0, wxALL, 2 );

	gui_optRightChannel = new wxRadioButton( sbSizer612->GetStaticBox(), wxID_ANY, _("Gain on right channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( gui_optRightChannel, 0, wxALL, 2 );


	bSizer10->Add( sbSizer612, 0, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer10 );
	m_panel3->Layout();
	bSizer10->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, _("Constant gain"), false );

	bSizer2->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	gui_btnDefault = new wxButton( this, wxID_ANY, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( gui_btnDefault, 1, wxALL, 5 );

	gui_btnOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( gui_btnOK, 1, wxALL, 5 );

	gui_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( gui_btnCancel, 1, wxALL, 5 );


	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	gui_optTagAPE->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_optTagID3->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_optTagSKIP->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkTagFORCE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkConstantGain->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_btnDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	gui_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	gui_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );
}

DialogSettings::~DialogSettings()
{
	// Disconnect Events
	gui_optTagAPE->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_optTagID3->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_optTagSKIP->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkTagFORCE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkConstantGain->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_sldConstantGain->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	gui_btnDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	gui_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	gui_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );

}
