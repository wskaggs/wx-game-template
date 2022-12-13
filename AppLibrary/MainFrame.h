/**
 * @file MainFrame.h
 * @author Will Skaggs
 * 
 * The main window of the appilcation.
 */

#pragma once

class View;

/**
 * The main window of the application.
 */
class MainFrame : public wxFrame {
private:
    View * mView = nullptr;
    
    void OnExit(wxCommandEvent const & event);
    void OnAbout(wxCommandEvent const & event);

public:
    void Initialize();
};