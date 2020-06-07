#pragma once
#include "MyFrame1.h"
#include <wx/wx.h>
#include <wx/wxprec.h>
#include <wx/dcbuffer.h>
#include <wx/window.h>
#include <string>
#include <wx/clipbrd.h>
#include <wx/printdlg.h>

#include <algorithm>
#include<stdlib.h>


class GUI : public MyFrame1
{
public:
	GUI();

	~GUI() {

	}

	void p1_on_click(wxCommandEvent& event) override;
	void p2_on_click(wxCommandEvent& event) override;
	void p3_on_click(wxCommandEvent& event) override;
	void p4_on_click(wxCommandEvent& event) override;
	void p5_on_click(wxCommandEvent& event) override;
	void p6_on_click(wxCommandEvent& event) override;
	void p7_on_click(wxCommandEvent& event) override;
	void p8_on_click(wxCommandEvent& event) override;
	void p9_on_click(wxCommandEvent& event) override;
	void reset_on_click(wxCommandEvent& event);

	void humanMove(wxBitmapButton* button, char& cell);
	void machineMove();
	int minimax(int depth, bool isMax);
	int evaluate(int depth);
	bool check(bool show = true);
	void reset();
	void block();
	void unblock();

protected:
	
	char board[3][3] ={'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n' };
	
	wxBitmapButton* buttons[3][3] = { p1_button,p2_button,p3_button,
									 p4_button,p5_button,p6_button,
									 p7_button,p8_button,p9_button };

	wxBitmap m_nic, m_o, m_x;
	
	enum turn { human, bot };
	turn m_player = human;
	bool m_stop = true; //flag for bot
	bool machineFirst = false; //flag who is going to start the game
};
