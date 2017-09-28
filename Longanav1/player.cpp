#include "stdafx.h"
#include "player.h"

//for testing only
#include <string>

// this is the base class
player::player()
{
	m_playerName = "Computer";
	m_score = 0;
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
			if ((getHand()->getTilesAt(count).isDouble() == true) && (getHand()->getTilesAt(count).getLeftSide() == m_inEngine))
			{
				m_userSelection = getHand()->getTilesAt(count);
				m_whichSide = 'R';
				//m_userChoice = count;
			}
		}
		setUserOptions(m_userSelection, m_whichSide);
		// place the tile on the board
		// a_inGameBoard.addToRight(m_currentHand.getTilesAt(m_userChoice));
		// remove the tile from the players hand
		// m_currentHand.removeTile(m_currentHand.getTilesAt((m_userChoice)));
	}
	// otherwise
	else
	{
		// run checkPass 
	}
}

// This checks every senario 
bool player::checkMove(gameBoard &a_inGameBoard)
{
	int handSize = m_currentHand.getHandSize();
	// if both the left and right sides are empty then
	// check to see if the user has the engine
	if (m_currentHand.hasEngine(m_inEngine) == true)
	{
		return true;
	}
	else
	{
		// go though every element
		for (auto item = 0; item < handSize; item++)
		{
			if (checkTileSelection(a_inGameBoard, item) == true)
			{
				// then set the valid move to true
				return true;
			}
		}
	}
	return false;
}

bool player::checkTileSelection(gameBoard &a_inGameBoard, int &a_userChoice)
{
	// if the user selects a double or if the computer passed it's turn
	// then you need to check both sides of the board
	if (m_currentHand.getTilesAt(a_userChoice).isDouble() == true || getPassed() == true)
	{
		if (m_checkInput.checkLeftSide(a_inGameBoard.getLeftMostTile(), m_currentHand.getTilesAt(a_userChoice)) == true)
		{
			return true;
		}
		if (m_checkInput.checkRightSide(a_inGameBoard.getRightMostTile(), m_currentHand.getTilesAt(a_userChoice)) == true)
		{
			return true;
		}
	}
	else if (m_playerName == "Computer")
	{
		// otherwise just check the left side of the board (this is just for the human)
		if (m_checkInput.checkRightSide(a_inGameBoard.getRightMostTile(), m_currentHand.getTilesAt(a_userChoice)) == true)
		{
			return true;
		}
	}
	else
	{
		if (m_checkInput.checkLeftSide(a_inGameBoard.getLeftMostTile(), m_currentHand.getTilesAt(a_userChoice)) == true)
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

bool player::getPassed()
{
	return m_playerPass;
}

dominoTile player::getUserOption()
{
	return m_userSelection;
}

char player::getAddSide()
{
	return m_whichSide;
}

void player::setEngineFRound(int & a_inEngine)
{
	m_inEngine = a_inEngine;
}

void player::setPassed(bool a_playerPass)
{
	m_playerPass = a_playerPass;
}

void player::setUserOptions(dominoTile & a_userTile, char & a_incomingSide)
{
	m_userSelection = a_userTile;
	m_whichSide = a_incomingSide;
}
