/**
 * @file View.cpp
 * @author Will Skaggs
 */

#include "pch.h"
#include <memory>
#include <cmath>
#include <string>
#include "View.h"

/**
 * Initialize this view window
 * 
 * @param parent the parent of this window
 */
void View::Initialize(wxFrame * parent) {
    Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    Bind(wxEVT_PAINT, &View::OnPaint, this);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

/**
 * Handler for a paint/redraw request
 * 
 * @param event the paint event context
 */
void View::OnPaint(wxPaintEvent const & event) {
    // clear the current window
    wxAutoBufferedPaintDC dc(this);
    dc.SetBackground(*wxBLACK_BRUSH);
    dc.Clear();

    // create the context to draw on
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
    graphics->SetInterpolationQuality(wxINTERPOLATION_BEST);

    /** The code below is to draw the red rectangle and is considered temporary **/

    // calculate the proper scaling factor to maintain aspect ratio of virtual screen
    wxSize windowSize = GetClientSize();
    double scaleW = static_cast<double>(windowSize.x) / mVirtual.x;
    double scaleH = static_cast<double>(windowSize.y) / mVirtual.y;
    wxSize virtualSize =  mVirtual * std::min(scaleW, scaleH);

    // draw virtual screen
    graphics->PushState();
    graphics->SetBrush(*wxRED_BRUSH);
    graphics->Translate(windowSize.x / 2, windowSize.y / 2);
    graphics->DrawRectangle(-virtualSize.x / 2, -virtualSize.y / 2, virtualSize.x, virtualSize.y);
    graphics->PopState();
}