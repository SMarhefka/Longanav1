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

void gameBoardView::gatherInputs(vector<dominoTile> &a_leftSide, vector<dominoTile> &a_rightSide)
{
	cout << endl;
	// cout << "Current Board:" << endl;
	deleteLines();

	m_secondLine.push_back("L");

	for (auto item = a_leftSide.begin(); item != a_leftSide.end(); item++)
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

	for (auto item = a_rightSide.begin(); item != a_rightSide.end(); item++)
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

void gameBoardView::printBrdToScreen(vector<dominoTile> &a_leftSide, vector<dominoTile> &a_rightSide)
{
	gatherInputs(a_leftSide, a_rightSide);
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


