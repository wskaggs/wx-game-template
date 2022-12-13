/**
 * @file View.h
 * @author Will Skaggs
 * 
 * The root window (drawable) of the application
 */

#pragma once

#include <memory>

/**
 * The main drawable of the application.
 */
class View : public wxWindow {
private:
    wxSize mVirtual = wxSize(1600, 900); ///< The virtual size of the test canvas (REMOVE)

    void OnPaint(wxPaintEvent const & event);

public:
    void Initialize(wxFrame * parent);
};
