#include "GUI.h"

int GUI::evaluate(int depth)
{
	// Checking for Rows for X or O victory. 
	for (int row = 0; row < 3; row++)
	{
		if (board[row][0] == board[row][1] &&
			board[row][1] == board[row][2])
		{
			if (board[row][0] == 'x')
				return +10;
			else if (board[row][0] == 'o')
				return -10;
		}
	}

	// Checking for Columns for X or O victory. 
	for (int col = 0; col < 3; col++)
	{
		if (board[0][col] == board[1][col] &&
			board[1][col] == board[2][col])
		{
			if (board[0][col] == 'x')
				return +10;

			else if (board[0][col] == 'o')
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory. 
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'x')
			return +10;
		else if (board[0][0] == 'o')
			return -10;
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'x')
			return +10;
		else if (board[0][2] == 'o')
			return -10;
	}

	// Else if none of them have won then return 0 
	return 0;
}

GUI::GUI() : MyFrame1(NULL) {

	wxInitAllImageHandlers();

	m_nic.LoadFile("nic.bmp", wxBITMAP_TYPE_BMP);
	if (!m_nic.IsOk()) {
		wxLogMessage(wxT("bitmap could not be loaded"));
	}

	m_x.LoadFile("ex.bmp", wxBITMAP_TYPE_BMP);
	if (!m_x.IsOk()) {
		wxLogMessage(wxT("bitmap could not be loaded"));
	}

	m_o.LoadFile("o.bmp", wxBITMAP_TYPE_BMP);
	if (!m_o.IsOk()) {
		wxLogMessage(wxT("bitmap could not be loaded"));
	}

	if (machineFirst==false)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = 'n';

				buttons[i][j]->SetBitmap(m_nic);

			}
	}
	else
	{
		m_stop = false;
		machineMove();
	}
	
	
	}

void GUI::humanMove(wxBitmapButton* button, char& cell)
{
	m_stop = false;
	button->SetBitmap(m_o);

	cell = 'o';
	m_player = bot;
	check();

}

void GUI::machineMove()
{
	if (!m_stop)
	{
		int bestScore = -10000;
		int x = -1, y = -1; // best move coordinats
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board[i][j] == 'n')
				{
					board[i][j] = 'x';
					int score = minimax( 0, false);
					board[i][j] = 'n';
					if (score > bestScore)
					{
						bestScore = score;
						x = i;
						y = j;
					}
					
				}

		if (x >= 0 && y >= 0) 
		{
			buttons[x][y]->SetBitmap(m_x);
			board[x][y] = 'x';
		}
	}
	m_player = human;
	check();

}

int GUI::minimax(int depth, bool isMax)
{
	
	int score = evaluate(depth);
 
	if (score > 0)
		return score;

	if (score == -10)
		return score;

	if (board[0][0] != 'n' && board[0][1] != 'n' && board[0][2] != 'n' && board[1][0] != 'n' &&
		board[1][1] != 'n' && board[1][2] != 'n' && board[2][0] != 'n' && board[2][1] != 'n' && board[2][2] != 'n')
		return 0;

	if (isMax) {
		
		int bestScore = -10000;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board[i][j] == 'n')
				{
					board[i][j] = 'x';
					int score = minimax(depth + 1, false);
					board[i][j] = 'n';
					bestScore = std::max(score, bestScore);
				}
		return bestScore;
	}
	else
	{
		
		int bestScore = 10000;
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++) 
				if (board[i][j] == 'n')
				{
					board[i][j] = 'o';

					int score = minimax(depth + 1, true);
					board[i][j] = 'n';
					bestScore = std::min(score, bestScore);
				}
		return bestScore;
	}
}

void GUI::block()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(board[i][j]=='n')
				buttons[i][j]->Disable();
		}
	}
}

void GUI::unblock()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			buttons[i][j]->Enable();
		}
	}
}

bool GUI::check(bool show)
{
	if ((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 'n') ||
		(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 'n') ||
		(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 'n') ||
		(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] != 'n') ||
		(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != 'n') ||
		(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 'n') ||
		(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 'n') ||
		(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 'n'))
	{

		if (m_player == human)
		{
			if (show)
			{
				block();
				wxLogMessage(wxT("The end of the game. Bot wins!"));
				return true;
			}
		}
		else
		{
			if (show)
			{
				block();
				wxLogMessage(wxT("The end of the game. Human wins!"));
				return true;
			}
		}
	
	}

	if (board[0][0] != 'n' && board[0][1] != 'n' && board[0][2] != 'n' && board[1][0] != 'n' && 
		board[1][1] != 'n' && board[1][2] != 'n' && board[2][0] != 'n' && board[2][1] != 'n' && board[2][2] != 'n')
	{
		if (show)
		{
			block();
			wxLogMessage(wxT("The end of the game. Tie!"));
		}
		return true;
	}

	return false;
}


///reseting of the game
void GUI::reset_on_click(wxCommandEvent& event)
{
	unblock();
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = 'n';
			buttons[i][j]->SetBitmap(m_nic);
		}
	m_stop = true;		
}

void GUI::p1_on_click(wxCommandEvent& event)
{
	if (board[0][0] == 'n')
		if (m_player == human) 
		{
			humanMove(buttons[0][0], board[0][0]);
			machineMove();
		}
}

void GUI::p2_on_click(wxCommandEvent& event)
{
	if (board[0][1] == 'n')
		if (m_player == human)
		{
			humanMove(buttons[0][1], board[0][1]);
			machineMove();
		}
}

void GUI::p3_on_click(wxCommandEvent & event)
{
	if (board[0][2] == 'n')
		if (m_player == human) 
		{
			humanMove(buttons[0][2], board[0][2]);
			machineMove();
		}
}

void GUI::p4_on_click(wxCommandEvent & event)
{
	if (board[1][0] == 'n')
		if (m_player == human)
		{
			humanMove(buttons[1][0], board[1][0]);
			machineMove();
		}

}

void GUI::p5_on_click(wxCommandEvent & event)
{
	if (board[1][1] == 'n')
		if (m_player == human)
		{
			humanMove(buttons[1][1], board[1][1]);
			machineMove();
		}
}

void GUI::p6_on_click(wxCommandEvent & event)
{
	if (board[1][2] == 'n')
		if (m_player == human)
		{
			humanMove(buttons[1][2], board[1][2]);
			machineMove();
		}
}

void GUI::p7_on_click(wxCommandEvent & event)
{
	if (board[2][0] == 'n')
		if (m_player == human)
		{
			humanMove(buttons[2][0], board[2][0]);
			machineMove();
		}
}

void GUI::p8_on_click(wxCommandEvent & event)
{
	if (board[2][1] == 'n')
		if (m_player == human)
		{
			humanMove(buttons[2][1], board[2][1]);
			machineMove();
		}
}


void GUI::p9_on_click(wxCommandEvent & event)
{
	if (board[2][2] == 'n')
		if (m_player == human)
		{
			humanMove(buttons[2][2], board[2][2]);
			machineMove();
		}

}