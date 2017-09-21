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
	int userChoice = 2;
	cout << "I am playing as the: " << m_playerName << " and I am in the player::addToBoard function\n";
	if (m_playerName == "Computer")
	{
		newGameBoard.addToLeft(m_currentHand.getTilesAt((userChoice - 1)));
	}
	else
	{
		newGameBoard.addToRight(m_currentHand.getTilesAt((userChoice - 1)));
	}
	m_currentHand.removeTile(m_currentHand.getTilesAt((userChoice - 1)));
}

void player::addToHand()
{
	cout << "I'm playing as: " << m_playerName << " and I am in player player::addToHand() function\n";
}

bool player::playMove(gameBoard newGameBoard)
{
	cout << "I'm playing as: " << m_playerName << " and I am in player player::playMove() function\n";
	// cout << "I'm in player playMove()\n";
	return true;
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

bool player::getPassed()
{
	return m_playerPass;
}

