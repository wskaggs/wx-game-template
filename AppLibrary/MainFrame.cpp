/**
 * @file MainFrame.cpp
 * @author Will Skaggs
 */

#include "pch.h"
#include <string>
#include "MainFrame.h"
#include "View.h"

/**
 * Initialize this window
 */
void MainFrame::Initialize() {
    // Create the frame
    Create(nullptr, wxID_ANY, L"GUI Template");

    //
    // Menubar
    //
    auto menuBar = new wxMenuBar();
    SetMenuBar(menuBar);

    // File menu
    auto fileMenu = new wxMenu();
    menuBar->Append(fileMenu, L"&File");

    fileMenu->Append(wxID_EXIT, L"E&xit\tAlt-X", L"Quit this program");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);

    // level menu
    auto helpMenu = new wxMenu();
    menuBar->Append(helpMenu, L"&Help");

    helpMenu->Append(wxID_ABOUT, L"&About\tF1", L"Show about dialog");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

    //
    // Status Bar
    //
    CreateStatusBar();
    
    //
    // View
    //
    auto sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);

    mView = new View();
    mView->Initialize(this);
    sizer->Add(mView, 1, wxEXPAND|wxALL);

    Layout();
}

/**
 * Handler for File > Exit
 * 
 * @param event the command selected event
 */
void MainFrame::OnExit(wxCommandEvent const & event) {
    Close(true);
}

/**
 * Handler for Help > About
 * 
 * @param event the command selected event
 */
void MainFrame::OnAbout(wxCommandEvent const & event) {
    wxMessageBox(L"A basic wxWidgets GUI template", L"About this template", wxOK, this);
}