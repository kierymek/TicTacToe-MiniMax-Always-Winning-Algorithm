///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bmpbuttn.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxBitmapButton* p1_button;
		wxBitmapButton* p2_button;
		wxBitmapButton* p3_button;
		wxBitmapButton* p4_button;
		wxBitmapButton* p5_button;
		wxBitmapButton* p6_button;
		wxBitmapButton* p7_button;
		wxBitmapButton* p8_button;
		wxBitmapButton* p9_button;
		wxButton* reset_button;

		// Virtual event handlers, overide them in your derived class
		virtual void p1_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p2_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p3_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p4_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p5_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p6_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p7_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p8_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void p9_on_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void reset_on_click( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TicTacToe_minimax"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

