#include "stdafx.h"
#include "gameRound.h"
#include <string>

gameRound::gameRound()
{
	// test to make sure that the round 
	// cout << "newRound constructor called\n";
}

gameRound::gameRound(int &a_roundNumber, vector<player*> &a_gamePlayers)
{
	m_roundNum = a_roundNumber;
	m_gamePlayers = a_gamePlayers;
}

gameRound::~gameRound()
{
}

void gameRound::setUpRound()
{
	// set the engine for the corresponding round
	setEngine();
	// distribute 8 tiles to each tile
	distributeTiles();
	// figure out the first player
	m_playerIndex = getFirstPlayer();

	m_gamePlayers.at(m_playerIndex)->setEngineFRound(m_engine);

	playRound();
}

// 9/19 10:30 implemented setEngine
void gameRound::setEngine()
{
	int a_count = 1;
	int a_engineCount = 6;
	while (a_count != m_roundNum)
	{
		if (a_engineCount == 0)
		{
			// reset the engine count
			a_engineCount = 6;
		}
		else
		{
			// reduce engine count by 1
			a_engineCount--;
		}

		a_count++;
	}
	m_engine = a_engineCount;
}

void gameRound::distributeTiles()
{
	// distribute 8 tiles to each player
	for (unsigned short nextPlayerIndex = 0; nextPlayerIndex < 2; nextPlayerIndex++)
	{
		for (int count = 0; count <= 7; count++)
		{
			// then you want to give each player 1 tiles
			m_gamePlayers.at(nextPlayerIndex)->getHand()->addTileToHand(newBoneYard.dealTile());
			// just to check I want to make sure that that it prints correctly
			// gamePlayers.at(nextPlayerIndex)->getHand()->getTilesAt(count).printTile();
		}
		// Used for testing purposes
		// cout << "Player Name: " << m_gamePlayers.at(nextPlayerIndex)->getName() << endl;
		// m_gamePlayers.at(nextPlayerIndex)->getHand()->printHand();
		// cout << endl;
	}
}

unsigned short gameRound::getFirstPlayer()
{
	while ((m_gamePlayers.at(0)->getHand()->hasEngine(m_engine)) == false && 
		(m_gamePlayers.at(1)->getHand()->hasEngine(m_engine)) == false)
	{
		// a_testBool = newBoneYard.isEmpty();
		if(!newBoneYard.isEmpty())
		// give the computer a tile
		m_gamePlayers.at(0)->getHand()->addTileToHand(newBoneYard.dealTile());
		// m_gamePlayers.at(0)->getHand()->printHand();
		// give the player a tile
		m_gamePlayers.at(1)->getHand()->addTileToHand(newBoneYard.dealTile());
		// m_gamePlayers.at(1)->getHand()->printHand();
	}

	// if the computer has the engine then the 
	// first player will be set to 0
	if (m_gamePlayers.at(0)->getHand()->hasEngine(m_engine))
	{
		return 0;
	}
	// otherwise we can safetly assume that the
	// player hand has the engine
	return 1;
}

void gameRound::playRound()
{
	while (!(roundOver() == true))
	{
		// print whos move it is
		cout << "Current Player: " << m_gamePlayers.at(m_playerIndex)->getName() << endl;
		// play the move of the current player
		m_gamePlayers.at(m_playerIndex)->playMove(newGameBoard);

		if (m_gamePlayers.at(m_playerIndex)->getAddSide() == 'L')
		{
			dominoTile playerTile = m_gamePlayers.at(m_playerIndex)->getUserOption();
			newGameBoard.addToLeft(playerTile);
			m_gamePlayers.at(m_playerIndex)->getHand()->removeTile(playerTile);
		}
		else if(m_gamePlayers.at(m_playerIndex)->getAddSide() == 'R')
		{
			dominoTile playerTile = m_gamePlayers.at(m_playerIndex)->getUserOption();
			newGameBoard.addToRight(playerTile);
			m_gamePlayers.at(m_playerIndex)->getHand()->removeTile(playerTile);
		}
		// print the board
		newGameBoard.printToScreen();
		// get the next player
		m_playerIndex = (m_playerIndex + 1) % int(m_gamePlayers.size());
	}
}

bool gameRound::roundOver()
{
	if (m_gamePlayers.at(0)->getHand()->getHandSize() == 0)
	{
		cout << "The computer wins!\n";
		return true;
	}
	if (m_gamePlayers.at(1)->getHand()->getHandSize() == 0)
	{
		cout << m_gamePlayers.at(1)->getName() << " wins!\n";
		return true;
	}
	return false;
}