#include "stdafx.h"
#include "gameBoardView.h"

gameBoardView::gameBoardView()
{
	// this is where all of the information will be placed
	// this function will contain all of the cout statements
	// that the users will see on the screen at they play the game
}

gameBoardView::~gameBoardView()
{
}

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


