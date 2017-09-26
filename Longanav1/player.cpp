#include "stdafx.h"
#include "player.h"

//for testing only
#include <string>

// this is the base class
player::player()
{
	// cout << "this is a player\n";
	m_playerName = "Computer";
}

player::~player()
{
}

void player::playMove(gameBoard &a_inGameBoard)
{
	// cout << "I'm playing as: " << m_playerName << " and I am in player player::playMove() function\n";
	// if the current hand contains the engine then
	if (getHand()->hasEngine(m_inEngine) == true)
	{
		int handSize = m_currentHand.getHandSize();
		// find the domino tile that has the engine
		for (int count = 0; count < handSize; count++)
		{
			if ((getHand()->getTilesAt(count).isDouble() == true) && (getHand()->getTilesAt(count).getLeftSide() == 6))
			{
				m_userChoice = count;
			}
		}
		// place the tile on the board
		a_inGameBoard.addToRight(m_currentHand.getTilesAt(m_userChoice));
		// remove the tile from the players hand
		m_currentHand.removeTile(m_currentHand.getTilesAt((m_userChoice)));
	}
	// otherwise
	else
	{
		// run checkPass 
	}
}

bool player::checkTileSelection(gameBoard &a_inGameBoard, int &a_userChoice)
{
	// if the user selects a double or if the computer passed it's turn
	// then you need to check both sides of the board
	if ((m_currentHand.getTilesAt(a_userChoice).isDouble() == true || getPassed() == true) && 
		a_inGameBoard.isRightEmpty()==true)
	{
		if (m_checkInput.checkLeftSide(a_inGameBoard.getLeftMostTile(), m_currentHand.getTilesAt(a_userChoice)) == true)
		{
			return true;
		}
	}
	else if ((m_currentHand.getTilesAt(a_userChoice).isDouble() == true || getPassed() == true) &&
		a_inGameBoard.isLeftEmpty() == true)
	{
		if (m_checkInput.checkRightSide(m_currentHand.getTilesAt(a_userChoice), a_inGameBoard.getRightMostTile()) == true)
		{
			return true;
		}
	}
	else if (m_currentHand.getTilesAt(a_userChoice).isDouble() == true || getPassed() == true)
	{
		if (m_checkInput.checkLeftSide(m_currentHand.getTilesAt(a_userChoice), a_inGameBoard.getLeftMostTile()) == true)
		{
			return true;
		}
		if (m_checkInput.checkRightSide(m_currentHand.getTilesAt(a_userChoice), a_inGameBoard.getRightMostTile()) == true)
		{
			return true;
		}
	}
	else
	{
		// otherwise just check the left side of the board (this is just for the human)
		if (m_checkInput.checkRightSide(m_currentHand.getTilesAt(a_userChoice), a_inGameBoard.getLeftMostTile()) == true)
		{
			return true;
		}
	}
	// if none of these work then return false
	// this means that the tile will not work
	return false;
}

string player::getName()
{
	return string(m_playerName);
}

playerHand* player::getHand()
{
	// cout << "Playing as: " << playerType << " I'm in the player::getHand method\n";
	return &m_currentHand;
}

void player::setPassed(bool a_playerPass)
{
	m_playerPass = a_playerPass;
}

void player::setUserOptions(int a_indexNumber)
{
	m_userChoice = a_indexNumber;
}


bool player::getPassed()
{
	return m_playerPass;
}

int player::getUserOption()
{
	return m_userChoice;
}

short player::getAddSide()
{
	return m_whichSide;
}

void player::setEngineFRound(int & a_inEngine)
{
	m_inEngine = a_inEngine;
}

bool player::checkPass(gameBoard &a_inNewGameBoard)
{
	int handSize = m_currentHand.getHandSize();
	// go though every element
	for (auto item = 0; item < handSize; item++)
	{
		// if the left side is false (meaning there are no matches)
		// and the right side is false (meaning that there are no matches)
		// then set the checkPassed
		if (m_checkInput.checkLeftSide(m_currentHand.getTilesAt(item),
			a_inNewGameBoard.getLeftMostTile()) == false &&
			m_checkInput.checkLeftSide(m_currentHand.getTilesAt(item),
				a_inNewGameBoard.getLeftMostTile()) == false)
		{
			return true;
		}
	}
	return false;
}

