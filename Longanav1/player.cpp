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

// 9/19 10:15 implemented an add to board function
void player::addToBoard(gameBoard &newGameBoard)
{
	m_userChoice = getUserOption();
	// int userChoice = 2;
	cout << "I am playing as the: " << m_playerName << " and I am in the player::addToBoard function\n";
	if (m_playerName == "Computer")
	{
		newGameBoard.addToLeft(m_currentHand.getTilesAt((m_userChoice)));
	}
	else
	{
		newGameBoard.addToRight(m_currentHand.getTilesAt((m_userChoice)));
	}
	m_currentHand.removeTile(m_currentHand.getTilesAt((m_userChoice)));
}

void player::addToHand()
{
	cout << "I'm playing as: " << m_playerName << " and I am in player player::addToHand() function\n";
}

bool player::playMove(gameBoard &newGameBoard)
{
	cout << "I'm playing as: " << m_playerName << " and I am in player player::playMove() function\n";
	// m_userChoice = 1;
	// cout << "I'm in player playMove()\n";
	return true;
}

bool player::checkTileSelection(gameBoard &a_inGameBoard, int &a_userChoice)
{
	// if the user selects a double or if the computer passed it's turn
	// then you need to check both sides of the board
	if ((m_currentHand.getTilesAt(a_userChoice).isDouble() == true || getPassed() == true) && 
		a_inGameBoard.isRightEmpty()==true)
	{
		if (m_checkInput.checkLeftSide(m_currentHand.getTilesAt(a_userChoice), a_inGameBoard.getLeftMostTile()) == true)
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

