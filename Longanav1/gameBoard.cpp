#include "stdafx.h"
#include "gameBoard.h"

gameBoard::gameBoard()
{
}

gameBoard::gameBoard(vector<dominoTile> a_inGameBoard)
{
	m_boardVector = a_inGameBoard;
}

void gameBoard::addToLeft(dominoTile a_tileToAdd)
{
	if (m_boardVector.size() == 0)
	{
		m_boardVector.push_back(a_tileToAdd);
	}
	else
	{
		insertAt = m_boardVector.begin();
		insertAt = m_boardVector.insert(insertAt, a_tileToAdd);
	}
}

void gameBoard::addToRight(dominoTile a_tileToAdd)
{
	// rightSide.push_back(a_tileToAdd);
	m_boardVector.push_back(a_tileToAdd);
}

// this gets the right most tile to be compared
int gameBoard::boardRightValue()
{
	// create a new temporary dominoTile
	if (!isBoardEmpty())
	{
		return m_boardVector.at(m_boardVector.size() - 1).getRightSide();
	}
}

int gameBoard::boardLeftValue()
{
	// if the board is not empty
	if (!isBoardEmpty())
	{
		// return the 
		return m_boardVector.at(0).getLeftSide();
	}
}

bool gameBoard::isBoardEmpty()
{
	return m_boardVector.size() == 0;
}

void gameBoard::printToScreen()
{
	m_boardView.printBrdToScreen(m_boardVector);
}

void gameBoard::printBoardToFile(ofstream & a_inStream)
{
	m_boardView.printBrdToFile(a_inStream, m_boardVector);
}

gameBoard::~gameBoard()
{
}