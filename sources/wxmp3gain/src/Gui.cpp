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

	g_boxMain = new wxBoxSizer( wxVERTICAL );

	wxPanel* m_panel4;
	m_panel4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	g_boxNormalVolume = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText9;
	m_staticText9 = new wxStaticText( m_panel4, wxID_ANY, _("Normal volume (dB):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	g_boxNormalVolume->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_txtNormalVolume = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_boxNormalVolume->Add( g_txtNormalVolume, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxStaticText* m_staticText10;
	m_staticText10 = new wxStaticText( m_panel4, wxID_ANY, _("(Default 89.0 dB)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	g_boxNormalVolume->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer13->Add( g_boxNormalVolume, 0, wxEXPAND, 5 );

	g_boxConstantGain = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText11;
	m_staticText11 = new wxStaticText( m_panel4, wxID_ANY, _("Using constant gain: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	g_boxConstantGain->Add( m_staticText11, 0, wxALL, 5 );

	g_lblConstantGain = new wxStaticText( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_lblConstantGain->Wrap( -1 );
	g_boxConstantGain->Add( g_lblConstantGain, 1, wxALL, 5 );


	bSizer13->Add( g_boxConstantGain, 0, wxEXPAND, 5 );

	g_lstFiles = new wxListCtrl( m_panel4, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT );
	bSizer13->Add( g_lstFiles, 1, wxALL|wxEXPAND, 0 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	g_gugProgress = new wxGauge( m_panel4, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	g_gugProgress->SetValue( 0 );
	bSizer11->Add( g_gugProgress, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_btnStop = new wxButton( m_panel4, wxID_ANY, _("&Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	g_btnStop->Enable( false );

	bSizer11->Add( g_btnStop, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer13->Add( bSizer11, 0, wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer13 );
	m_panel4->Layout();
	bSizer13->Fit( m_panel4 );
	g_boxMain->Add( m_panel4, 1, wxEXPAND, 5 );


	this->SetSizer( g_boxMain );
	this->Layout();
	g_mainMenuBar = new wxMenuBar( 0 );
	g_mnbFile = new wxMenu();
	wxMenuItem* g_mnbAddFolder;
	g_mnbAddFolder = new wxMenuItem( g_mnbFile, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFolder );

	wxMenuItem* g_mnbAddFiles;
	g_mnbAddFiles = new wxMenuItem( g_mnbFile, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFiles );

	g_mnbFile->AppendSeparator();

	wxMenuItem* g_mnbExit;
	g_mnbExit = new wxMenuItem( g_mnbFile, ID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbExit );

	g_mainMenuBar->Append( g_mnbFile, _("&File") );

	g_mnbEdit = new wxMenu();
	wxMenuItem* g_mnbRemoveFiles;
	g_mnbRemoveFiles = new wxMenuItem( g_mnbEdit, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbRemoveFiles );

	wxMenuItem* g_mnbClearList;
	g_mnbClearList = new wxMenuItem( g_mnbEdit, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbClearList );

	g_mnbEdit->AppendSeparator();

	wxMenuItem* g_mnbSettings;
	g_mnbSettings = new wxMenuItem( g_mnbEdit, ID_SETTINGS, wxString( _("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbSettings );

	g_mainMenuBar->Append( g_mnbEdit, _("&Edit") );

	g_mnbAnalysis = new wxMenu();
	wxMenuItem* g_mnbAnalyze;
	g_mnbAnalyze = new wxMenuItem( g_mnbAnalysis, ID_ANALYZE, wxString( _("Analyze") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbAnalysis->Append( g_mnbAnalyze );

	g_mnbAnalysis->AppendSeparator();

	wxMenuItem* g_mnbClearAnalysis;
	g_mnbClearAnalysis = new wxMenuItem( g_mnbAnalysis, ID_CLEAR_ANALYSIS, wxString( _("Clear analysis") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbAnalysis->Append( g_mnbClearAnalysis );

	g_mainMenuBar->Append( g_mnbAnalysis, _("&Analysis") );

	g_mnuGain = new wxMenu();
	wxMenuItem* g_mnbGain;
	g_mnbGain = new wxMenuItem( g_mnuGain, ID_GAIN, wxString( _("Gain") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnuGain->Append( g_mnbGain );

	g_mnuGain->AppendSeparator();

	wxMenuItem* g_mnbUndoGain;
	g_mnbUndoGain = new wxMenuItem( g_mnuGain, ID_UNDO_GAIN, wxString( _("Undo gain changes (based on stored tag info)\tCtrl+Z") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnuGain->Append( g_mnbUndoGain );

	wxMenuItem* g_mnbDeleteTag;
	g_mnbDeleteTag = new wxMenuItem( g_mnuGain, ID_DELETE_TAG, wxString( _("Delete stored tag info") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnuGain->Append( g_mnbDeleteTag );

	g_mainMenuBar->Append( g_mnuGain, _("&Gain") );

	g_mnbHelp = new wxMenu();
	wxMenuItem* g_mnbToolWebsite;
	g_mnbToolWebsite = new wxMenuItem( g_mnbHelp, ID_WEBSITE, wxString( _("MP3gain Website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbToolWebsite );

	wxMenuItem* g_mnbWebsite;
	g_mnbWebsite = new wxMenuItem( g_mnbHelp, ID_TOOL_WEBSITE, wxString( _("wxMP3gain Website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbWebsite );

	g_mnbHelp->AppendSeparator();

	wxMenuItem* g_mnbAbout;
	g_mnbAbout = new wxMenuItem( g_mnbHelp, ID_ABOUT, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbAbout );

	g_mainMenuBar->Append( g_mnbHelp, _("&Help") );

	this->SetMenuBar( g_mainMenuBar );

	g_mainStatusBar = this->CreateStatusBar( 3, wxSTB_SIZEGRIP, wxID_ANY );
	g_mainToolBar = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
	g_tbAddFolder = g_mainToolBar->AddTool( ID_ADD_FOLDER, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add folder"), wxEmptyString, NULL );

	g_tbAddFiles = g_mainToolBar->AddTool( ID_ADD_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add files"), wxEmptyString, NULL );

	g_tbRemoveFiles = g_mainToolBar->AddTool( ID_REMOVE_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Remove files"), wxEmptyString, NULL );

	g_tbClearList = g_mainToolBar->AddTool( ID_CLEAR_LIST, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Clear list"), wxEmptyString, NULL );

	g_mainToolBar->AddSeparator();

	g_tbAnalyze = g_mainToolBar->AddTool( ID_ANALYZE, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Analyze"), wxEmptyString, NULL );

	g_tbGain = g_mainToolBar->AddTool( ID_GAIN, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Gain"), wxEmptyString, NULL );

	g_mainToolBar->AddSeparator();

	g_tbSettings = g_mainToolBar->AddTool( ID_SETTINGS, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Settings"), wxEmptyString, NULL );

	g_tbAbout = g_mainToolBar->AddTool( ID_ABOUT, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("About"), wxEmptyString, NULL );

	g_mainToolBar->Realize();

	g_mainMenu = new wxMenu();
	wxMenuItem* g_mnuAddFolder;
	g_mnuAddFolder = new wxMenuItem( g_mainMenu, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFolder );

	wxMenuItem* g_mnuAddFiles;
	g_mnuAddFiles = new wxMenuItem( g_mainMenu, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFiles );

	wxMenuItem* g_mnuRemoveFiles;
	g_mnuRemoveFiles = new wxMenuItem( g_mainMenu, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuRemoveFiles );

	wxMenuItem* g_mnuClearList;
	g_mnuClearList = new wxMenuItem( g_mainMenu, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuClearList );

	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( FrameMain::FrameMainOnContextMenu ), NULL, this );

	m_timer1.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	g_txtNormalVolume->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FrameMain::OntxtNormalVolumeTextKillFocus ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	g_btnStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::btnProcessStop ), NULL, this );
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, g_mnbAddFolder->GetId());
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, g_mnbAddFiles->GetId());
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuExit ), this, g_mnbExit->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, g_mnbRemoveFiles->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, g_mnbClearList->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuSettings ), this, g_mnbSettings->GetId());
	g_mnbAnalysis->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAnalyze ), this, g_mnbAnalyze->GetId());
	g_mnbAnalysis->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearAnalysis ), this, g_mnbClearAnalysis->GetId());
	g_mnuGain->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuGain ), this, g_mnbGain->GetId());
	g_mnuGain->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuUndoGain ), this, g_mnbUndoGain->GetId());
	g_mnuGain->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuDeleteTag ), this, g_mnbDeleteTag->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuToolWebsite ), this, g_mnbToolWebsite->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuWebsite ), this, g_mnbWebsite->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAbout ), this, g_mnbAbout->GetId());
	this->Connect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Connect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Connect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Connect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Connect( g_tbAnalyze->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAnalyze ) );
	this->Connect( g_tbGain->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuGain ) );
	this->Connect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Connect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, g_mnuAddFolder->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, g_mnuAddFiles->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, g_mnuRemoveFiles->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, g_mnuClearList->GetId());
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );
}

FrameMain::~FrameMain()
{
	// Disconnect Events
	g_txtNormalVolume->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( FrameMain::OntxtNormalVolumeTextKillFocus ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	g_btnStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::btnProcessStop ), NULL, this );
	this->Disconnect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Disconnect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Disconnect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Disconnect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Disconnect( g_tbAnalyze->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAnalyze ) );
	this->Disconnect( g_tbGain->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuGain ) );
	this->Disconnect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Disconnect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );

	delete g_mainMenu;
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

	g_chkAutoLower = new wxCheckBox( sbSizer5->GetStaticBox(), wxID_ANY, _("Automatically lower gain to not clip audio"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( g_chkAutoLower, 0, wxALL, 2 );


	bSizer5->Add( sbSizer5, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("File options") ), wxVERTICAL );

	g_chkForceInput = new wxCheckBox( sbSizer11->GetStaticBox(), wxID_ANY, _("Force to assume input is an MPEG 2 Layer III file"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( g_chkForceInput, 0, wxALL, 2 );


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

	g_optTagAPE = new wxRadioButton( sbSizer61->GetStaticBox(), wxID_ANY, _("Use APEv2 tag for gain information (default)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( g_optTagAPE, 0, wxALL, 2 );

	g_optTagID3 = new wxRadioButton( sbSizer61->GetStaticBox(), wxID_ANY, _("Use ID3v2 tag for gain information"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( g_optTagID3, 0, wxALL, 2 );

	g_optTagSKIP = new wxRadioButton( sbSizer61->GetStaticBox(), wxID_ANY, _("Skip stored tag info (do not read or write tags)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( g_optTagSKIP, 0, wxALL, 2 );


	bSizer71->Add( sbSizer61, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer611;
	sbSizer611 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Tags reading") ), wxHORIZONTAL );

	g_chkTagFORCE = new wxCheckBox( sbSizer611->GetStaticBox(), wxID_ANY, _("Force re-calculation (do not read tag info)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer611->Add( g_chkTagFORCE, 0, wxALL, 2 );


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

	g_chkConstantGain = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Use constant gain without doing any analysis"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( g_chkConstantGain, 0, wxALL, 2 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText13;
	m_staticText13 = new wxStaticText( sbSizer9->GetStaticBox(), wxID_ANY, _("Constant gain:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer15->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_sldConstantGain = new wxSlider( sbSizer9->GetStaticBox(), wxID_ANY, 0, -8, 8, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer15->Add( g_sldConstantGain, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_lblConstantGain = new wxStaticText( sbSizer9->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_lblConstantGain->Wrap( -1 );
	bSizer15->Add( g_lblConstantGain, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer9->Add( bSizer15, 1, wxEXPAND, 5 );


	bSizer10->Add( sbSizer9, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer612;
	sbSizer612 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Channel") ), wxVERTICAL );

	g_optBothChannel = new wxRadioButton( sbSizer612->GetStaticBox(), wxID_ANY, _("Gain on both channels"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( g_optBothChannel, 0, wxALL, 2 );

	g_optLeftChannel = new wxRadioButton( sbSizer612->GetStaticBox(), wxID_ANY, _("Gain on left channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( g_optLeftChannel, 0, wxALL, 2 );

	g_optRightChannel = new wxRadioButton( sbSizer612->GetStaticBox(), wxID_ANY, _("Gain on right channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( g_optRightChannel, 0, wxALL, 2 );


	bSizer10->Add( sbSizer612, 0, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer10 );
	m_panel3->Layout();
	bSizer10->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, _("Constant gain"), false );

	bSizer2->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	g_btnDefault = new wxButton( this, wxID_ANY, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnDefault, 1, wxALL, 5 );

	g_btnOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnOK, 1, wxALL, 5 );

	g_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnCancel, 1, wxALL, 5 );


	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	g_optTagAPE->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_optTagID3->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_optTagSKIP->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkTagFORCE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkConstantGain->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_btnDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );
}

DialogSettings::~DialogSettings()
{
	// Disconnect Events
	g_optTagAPE->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_optTagID3->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_optTagSKIP->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkTagFORCE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkConstantGain->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_btnDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );

}
