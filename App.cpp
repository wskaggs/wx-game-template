/**
 * @file App.cpp
 * @author Will Skaggs
 * 
 */
#include <pch.h>
#include "App.h"
#include <MainFrame.h>

/**
 * Initialize the application
 * 
 * @return true if the application was successfully initialized, false otherwise
 */
bool App::OnInit() {
    // if upcalled initialization failed, exit
    if (!wxApp::OnInit()) return false;

    // initialize image handlers for all formats
    wxInitAllImageHandlers();

    // create and show the main window
    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show();
    
    return true;
}