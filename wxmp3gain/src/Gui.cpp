///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Gui.h"

///////////////////////////////////////////////////////////////////////////

Main::Main( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	g_boxMain = new wxBoxSizer( wxVERTICAL );
	
	g_boxNormalVolume = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Normal volume (dB):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	g_boxNormalVolume->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	g_txtNormalVolume = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_boxNormalVolume->Add( g_txtNormalVolume, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("(Default 89.0 dB)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	g_boxNormalVolume->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	g_boxMain->Add( g_boxNormalVolume, 0, wxEXPAND, 5 );
	
	g_boxConstantGain = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Using constant gain: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	g_boxConstantGain->Add( m_staticText11, 0, wxALL, 5 );
	
	g_lblConstantGain = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_lblConstantGain->Wrap( -1 );
	g_boxConstantGain->Add( g_lblConstantGain, 1, wxALL, 5 );
	
	
	g_boxMain->Add( g_boxConstantGain, 0, wxEXPAND, 5 );
	
	g_lstFiles = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT );
	g_boxMain->Add( g_lstFiles, 1, wxALL|wxEXPAND, 0 );
	
	
	this->SetSizer( g_boxMain );
	this->Layout();
	g_mainMenuBar = new wxMenuBar( 0 );
	g_mnbFile = new wxMenu();
	wxMenuItem* g_mnbAddFolder;
	g_mnbAddFolder = new wxMenuItem( g_mnbFile, ID_ADD_FOLDER, wxString( wxT("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFolder );
	
	wxMenuItem* g_mnbAddFiles;
	g_mnbAddFiles = new wxMenuItem( g_mnbFile, ID_ADD_FILES, wxString( wxT("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFiles );
	
	g_mnbFile->AppendSeparator();
	
	wxMenuItem* g_mnbExit;
	g_mnbExit = new wxMenuItem( g_mnbFile, ID_EXIT, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbExit );
	
	g_mainMenuBar->Append( g_mnbFile, wxT("&File") ); 
	
	g_mnbEdit = new wxMenu();
	wxMenuItem* g_mnbRemoveFiles;
	g_mnbRemoveFiles = new wxMenuItem( g_mnbEdit, ID_REMOVE_FILES, wxString( wxT("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbRemoveFiles );
	
	wxMenuItem* g_mnbClearList;
	g_mnbClearList = new wxMenuItem( g_mnbEdit, ID_CLEAR_LIST, wxString( wxT("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbClearList );
	
	g_mnbEdit->AppendSeparator();
	
	wxMenuItem* g_mnbSettings;
	g_mnbSettings = new wxMenuItem( g_mnbEdit, ID_SETTINGS, wxString( wxT("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbSettings );
	
	g_mainMenuBar->Append( g_mnbEdit, wxT("&Edit") ); 
	
	g_mnbAnalysis = new wxMenu();
	wxMenuItem* g_mnbAnalyze;
	g_mnbAnalyze = new wxMenuItem( g_mnbAnalysis, ID_ANALYZE, wxString( wxT("Analyze") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbAnalysis->Append( g_mnbAnalyze );
	
	g_mnbAnalysis->AppendSeparator();
	
	wxMenuItem* g_mnbClearAnalysis;
	g_mnbClearAnalysis = new wxMenuItem( g_mnbAnalysis, ID_CLEAR_ANALYSIS, wxString( wxT("Clear Analysis") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbAnalysis->Append( g_mnbClearAnalysis );
	
	g_mainMenuBar->Append( g_mnbAnalysis, wxT("&Analysis") ); 
	
	g_mnuGain = new wxMenu();
	wxMenuItem* g_mnbGain;
	g_mnbGain = new wxMenuItem( g_mnuGain, ID_GAIN, wxString( wxT("Gain") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnuGain->Append( g_mnbGain );
	
	g_mnuGain->AppendSeparator();
	
	wxMenuItem* g_mnbUndoGain;
	g_mnbUndoGain = new wxMenuItem( g_mnuGain, ID_UNDO_GAIN, wxString( wxT("Undo gain changes (based on stored tag info)") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnuGain->Append( g_mnbUndoGain );
	
	wxMenuItem* g_mnbDeleteTag;
	g_mnbDeleteTag = new wxMenuItem( g_mnuGain, ID_DELETE_TAG, wxString( wxT("Delete stored tag info") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnuGain->Append( g_mnbDeleteTag );
	
	g_mainMenuBar->Append( g_mnuGain, wxT("&Gain") ); 
	
	g_mnbHelp = new wxMenu();
	wxMenuItem* g_mnbToolWebsite;
	g_mnbToolWebsite = new wxMenuItem( g_mnbHelp, ID_WEBSITE, wxString( wxT("LAME website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbToolWebsite );
	
	wxMenuItem* g_mnbWebsite;
	g_mnbWebsite = new wxMenuItem( g_mnbHelp, ID_TOOL_WEBSITE, wxString( wxT("wxLame website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbWebsite );
	
	g_mnbHelp->AppendSeparator();
	
	wxMenuItem* g_mnbAbout;
	g_mnbAbout = new wxMenuItem( g_mnbHelp, ID_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbAbout );
	
	g_mainMenuBar->Append( g_mnbHelp, wxT("&Help") ); 
	
	this->SetMenuBar( g_mainMenuBar );
	
	g_mainStatusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	g_mainToolBar = this->CreateToolBar( wxTB_HORIZONTAL|wxTB_TEXT, wxID_ANY ); 
	g_tbAddFolder = g_mainToolBar->AddTool( ID_ADD_FOLDER, wxT("Add folder"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_tbAddFiles = g_mainToolBar->AddTool( ID_ADD_FILES, wxT("Add Files"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_tbRemoveFiles = g_mainToolBar->AddTool( ID_REMOVE_FILES, wxT("Remove Files"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_tbClearList = g_mainToolBar->AddTool( ID_CLEAR_LIST, wxT("Clear List"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_mainToolBar->AddSeparator(); 
	
	g_tbAnalyze = g_mainToolBar->AddTool( ID_ANALYZE, wxT("Analyze"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_tbGain = g_mainToolBar->AddTool( ID_GAIN, wxT("Gain"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_mainToolBar->AddSeparator(); 
	
	g_tbSettings = g_mainToolBar->AddTool( ID_SETTINGS, wxT("Settings"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_tbAbout = g_mainToolBar->AddTool( ID_ABOUT, wxT("About"), wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	g_mainToolBar->Realize(); 
	
	g_mainMenu = new wxMenu();
	wxMenuItem* g_mnuAddFolder;
	g_mnuAddFolder = new wxMenuItem( g_mainMenu, ID_ADD_FOLDER, wxString( wxT("Add Folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFolder );
	
	wxMenuItem* g_mnuAddFiles;
	g_mnuAddFiles = new wxMenuItem( g_mainMenu, ID_ADD_FILES, wxString( wxT("Add Files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFiles );
	
	wxMenuItem* g_mnuRemoveFiles;
	g_mnuRemoveFiles = new wxMenuItem( g_mainMenu, ID_REMOVE_FILES, wxString( wxT("Remove Files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuRemoveFiles );
	
	wxMenuItem* g_mnuClearList;
	g_mnuClearList = new wxMenuItem( g_mainMenu, ID_CLEAR_LIST, wxString( wxT("Clear List") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuClearList );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( Main::MainOnContextMenu ), NULL, this ); 
	
	m_timer1.SetOwner( this, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	g_txtNormalVolume->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Main::OntxtNormalVolumeTextKillFocus ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( Main::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( Main::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( Main::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( Main::OnlstFilesKeyDown ), NULL, this );
	this->Connect( g_mnbAddFolder->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Connect( g_mnbAddFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Connect( g_mnbExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuExit ) );
	this->Connect( g_mnbRemoveFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Connect( g_mnbClearList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Connect( g_mnbSettings->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Connect( g_mnbAnalyze->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAnalyze ) );
	this->Connect( g_mnbClearAnalysis->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearAnalysis ) );
	this->Connect( g_mnbGain->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuGain ) );
	this->Connect( g_mnbUndoGain->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuUndoGain ) );
	this->Connect( g_mnbDeleteTag->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuDeleteTag ) );
	this->Connect( g_mnbToolWebsite->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuToolWebsite ) );
	this->Connect( g_mnbWebsite->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuWebsite ) );
	this->Connect( g_mnbAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Connect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Connect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Connect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Connect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Connect( g_tbAnalyze->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAnalyze ) );
	this->Connect( g_tbGain->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuGain ) );
	this->Connect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Connect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Connect( g_mnuAddFolder->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Connect( g_mnuAddFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Connect( g_mnuRemoveFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Connect( g_mnuClearList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( Main::OnTimer1Trigger ) );
}

Main::~Main()
{
	// Disconnect Events
	g_txtNormalVolume->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Main::OntxtNormalVolumeTextKillFocus ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( Main::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( Main::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( Main::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( Main::OnlstFilesKeyDown ), NULL, this );
	this->Disconnect( ID_ADD_FOLDER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Disconnect( ID_ADD_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Disconnect( ID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuExit ) );
	this->Disconnect( ID_REMOVE_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Disconnect( ID_CLEAR_LIST, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Disconnect( ID_SETTINGS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Disconnect( ID_ANALYZE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAnalyze ) );
	this->Disconnect( ID_CLEAR_ANALYSIS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearAnalysis ) );
	this->Disconnect( ID_GAIN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuGain ) );
	this->Disconnect( ID_UNDO_GAIN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuUndoGain ) );
	this->Disconnect( ID_DELETE_TAG, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuDeleteTag ) );
	this->Disconnect( ID_WEBSITE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuToolWebsite ) );
	this->Disconnect( ID_TOOL_WEBSITE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuWebsite ) );
	this->Disconnect( ID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Disconnect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Disconnect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Disconnect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Disconnect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Disconnect( g_tbAnalyze->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAnalyze ) );
	this->Disconnect( g_tbGain->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuGain ) );
	this->Disconnect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Disconnect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Disconnect( ID_ADD_FOLDER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Disconnect( ID_ADD_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Disconnect( ID_REMOVE_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Disconnect( ID_CLEAR_LIST, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( Main::OnTimer1Trigger ) );
	
	delete g_mainMenu; 
}

Settings::Settings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, wxT("Gain options") ), wxHORIZONTAL );
	
	g_chkAutoLower = new wxCheckBox( m_panel1, wxID_ANY, wxT("Automatically lower gain to not clip audio"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( g_chkAutoLower, 0, wxALL, 2 );
	
	
	bSizer5->Add( sbSizer5, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, wxT("MP3gain executable") ), wxHORIZONTAL );
	
	g_txtToolExecutable = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( g_txtToolExecutable, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	g_btnToolExecutable = new wxButton( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 22,22 ), 0 );
	sbSizer4->Add( g_btnToolExecutable, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer5->Add( sbSizer4, 0, wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( bSizer5 );
	m_panel1->Layout();
	bSizer5->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, wxT("General"), true );
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer61;
	sbSizer61 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("Tags options") ), wxVERTICAL );
	
	g_optTagAPE = new wxRadioButton( m_panel2, wxID_ANY, wxT("Use APEv2 tag for gain information (default)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( g_optTagAPE, 0, wxALL, 2 );
	
	g_optTagID3 = new wxRadioButton( m_panel2, wxID_ANY, wxT("Use ID3v2 tag for gain information"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( g_optTagID3, 0, wxALL, 2 );
	
	g_optTagSKIP = new wxRadioButton( m_panel2, wxID_ANY, wxT("Skip stored tag info (do not read or write tags)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( g_optTagSKIP, 0, wxALL, 2 );
	
	
	bSizer71->Add( sbSizer61, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer611;
	sbSizer611 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("Tags reading") ), wxHORIZONTAL );
	
	g_chkTagFORCE = new wxCheckBox( m_panel2, wxID_ANY, wxT("Force re-calculation (do not read tag info)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer611->Add( g_chkTagFORCE, 0, wxALL, 2 );
	
	
	bSizer71->Add( sbSizer611, 0, wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer71 );
	m_panel2->Layout();
	bSizer71->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, wxT("Tags"), false );
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Constant gain") ), wxVERTICAL );
	
	g_chkConstantGain = new wxCheckBox( m_panel3, wxID_ANY, wxT("Use constant gain without doing any analysis"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( g_chkConstantGain, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( m_panel3, wxID_ANY, wxT("Constant gain:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer15->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	g_sldConstantGain = new wxSlider( m_panel3, wxID_ANY, 0, -8, 8, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer15->Add( g_sldConstantGain, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	g_lblConstantGain = new wxStaticText( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_lblConstantGain->Wrap( -1 );
	bSizer15->Add( g_lblConstantGain, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer9->Add( bSizer15, 1, wxEXPAND, 5 );
	
	
	bSizer10->Add( sbSizer9, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer612;
	sbSizer612 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Channel") ), wxVERTICAL );
	
	g_optBothChannel = new wxRadioButton( m_panel3, wxID_ANY, wxT("Gain on both channels"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( g_optBothChannel, 0, wxALL, 2 );
	
	g_optLeftChannel = new wxRadioButton( m_panel3, wxID_ANY, wxT("Gain on left channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( g_optLeftChannel, 0, wxALL, 2 );
	
	g_optRightChannel = new wxRadioButton( m_panel3, wxID_ANY, wxT("Gain on right channel only (not for Joint Stereo mp3s)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer612->Add( g_optRightChannel, 0, wxALL, 2 );
	
	
	bSizer10->Add( sbSizer612, 0, wxEXPAND, 5 );
	
	
	m_panel3->SetSizer( bSizer10 );
	m_panel3->Layout();
	bSizer10->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, wxT("Constant gain"), false );
	m_panel4 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, wxT("Output sampling frequency") ), wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( m_panel4, wxID_ANY, wxT("File writing:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer16->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString g_chcFileWritingChoices[] = { wxT("work on original file"), wxT("work on temp file") };
	int g_chcFileWritingNChoices = sizeof( g_chcFileWritingChoices ) / sizeof( wxString );
	g_chcFileWriting = new wxChoice( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, g_chcFileWritingNChoices, g_chcFileWritingChoices, 0 );
	g_chcFileWriting->SetSelection( 0 );
	bSizer16->Add( g_chcFileWriting, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer11->Add( bSizer16, 1, wxEXPAND, 5 );
	
	g_chkPreserveTime = new wxCheckBox( m_panel4, wxID_ANY, wxT("Keep file timestamps"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( g_chkPreserveTime, 0, wxALL, 2 );
	
	g_chkForceInput = new wxCheckBox( m_panel4, wxID_ANY, wxT("Force to assume input is an MPEG 2 Layer III file"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( g_chkForceInput, 0, wxALL, 2 );
	
	
	bSizer11->Add( sbSizer11, 0, wxEXPAND, 5 );
	
	
	m_panel4->SetSizer( bSizer11 );
	m_panel4->Layout();
	bSizer11->Fit( m_panel4 );
	m_notebook1->AddPage( m_panel4, wxT("File options"), false );
	
	bSizer2->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	g_btnDefault = new wxButton( this, wxID_ANY, wxT("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnDefault, 1, wxALL, 5 );
	
	g_btnOK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnOK, 1, wxALL, 5 );
	
	g_btnCancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnCancel, 1, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	g_btnToolExecutable->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnToolExecutableClick ), NULL, this );
	g_optTagAPE->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_optTagID3->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_optTagSKIP->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_chkTagFORCE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_chkConstantGain->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_btnDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnCancelClick ), NULL, this );
}

Settings::~Settings()
{
	// Disconnect Events
	g_btnToolExecutable->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnToolExecutableClick ), NULL, this );
	g_optTagAPE->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_optTagID3->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_optTagSKIP->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_chkTagFORCE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_chkConstantGain->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::updateDisabledControlsEvent ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_sldConstantGain->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Settings::OnsldConstantGainCmdSliderUpdated ), NULL, this );
	g_btnDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnCancelClick ), NULL, this );
	
}
