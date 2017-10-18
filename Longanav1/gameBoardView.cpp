#include "stdafx.h"
#include "gameBoardView.h"

gameBoardView::gameBoardView()
{
}

gameBoardView::~gameBoardView()
{
}

/************************************************************************
Function Name: computer(playerHand a_inUserHand, int a_inScore,
bool a_inComPassed, bool a_inPlyerPassed) :
player(a_inUserHand, a_inScore, a_inComPassed,
a_inPlyerPassed)

Purpose: Overload the computer constructor.  This will create a new
Computer player object with a specific hand, score and information
on any passed moves.  This function is called when a file is loaded
to start the gameplay
Parameters:
playerHand a_inUserHand --> the hand of the computer player
int a_inScore --> the score of the computer player
bool a_inComPassed --> if the computer player has passed their turn
bool a_inPlyerPassed --> if the human player has passed their turn

Return Value: Constructor
Local Variables: None

Algorithm:
1. set m_playerName to Computer

Assistance Received: Elliot Barinber, Joshua Long
- Was initially trying to create the board view using all vectors and
  both helped explain how a queues worked. It helped me determine that
  a queue would work better than vectors
************************************************************************/
void gameBoardView::getBoard(vector<dominoTile> &a_inBoard)
{
	deleteLines();
	
	m_secondLine.push_back("L");

	// for (auto item = a_leftSide.begin(); item != a_leftSide.end(); item++)
	for (auto item = a_inBoard.begin(); item != a_inBoard.end(); item++)
	{
		if (item->isDouble() == true)
		{
			m_secondLine.push_back(" ");
			m_firstLine.push(to_string(item->getLeftSide()));
			m_secondLine.push_back("|");
			m_thirdLine.push(to_string(item->getRightSide()));
		}
		else
		{
			m_secondLine.push_back(" ");
			m_secondLine.push_back(to_string(item->getLeftSide()));
			m_secondLine.push_back("-");
			m_secondLine.push_back(to_string(item->getRightSide()));
		}
	}
	m_secondLine.push_back(" R");
}

void gameBoardView::printBrdToScreen(vector<dominoTile> &a_inBoard)
{
	getBoard(a_inBoard);
	for (int item = 0; item < m_secondLine.size(); item++)
	{
		if (m_secondLine.at(item) == "|")
		{
			cout << m_firstLine.front();
			m_firstLine.pop();
		}
		else
		{
			cout << " ";
		}
	}
	cout << endl;
	for (int item = 0; item < m_secondLine.size(); item++)
	{
		cout << m_secondLine.at(item);
	}
	cout << endl;
	for (int item = 0; item < m_secondLine.size(); item++)
	{
		if (m_secondLine.at(item) == "|")
		{
			cout << m_thirdLine.front();
			m_thirdLine.pop();
		}
		else
		{
			cout << " ";
		}
	}
	cout << endl;
}

void gameBoardView::printBrdToFile(ofstream & a_inStream, vector<dominoTile>& a_inBoard)
{
	// delete lines
	deleteLines();
	
	// print out the left part
	a_inStream << "    " << "L ";
	// go throught the merged vector
	for (int countVal = 0; countVal < a_inBoard.size(); countVal++)
	{
		// print out the left side to the file
		a_inStream << a_inBoard.at(countVal).getLeftSide();
		// print out the dash to the output file
		a_inStream << "-";
		// print out the right hand side to the output file
		a_inStream << a_inBoard.at(countVal).getRightSide();
		a_inStream << " ";
	}
	a_inStream << "R";
}

void gameBoardView::deleteLines()
{
	while (!m_firstLine.empty())
	{
		m_firstLine.pop();
	}
	while (!m_secondLine.empty())
	{
		m_secondLine.pop_back();
	}
	while (!m_thirdLine.empty())
	{
		m_thirdLine.pop();
	}
}
