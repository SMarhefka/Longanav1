#include "stdafx.h"
#include "gameRound.h"
#include <string>

gameRound::gameRound()
{
	// test to make sure that the round 
	// cout << "newRound constructor called\n";
}

gameRound::gameRound(int a_roundNumber, vector<player*> &a_gamePlayers)
{
	m_roundNum = a_roundNumber;
	m_gamePlayers = a_gamePlayers;
}

gameRound::~gameRound()
{
}

void gameRound::setUpRound()
{
	setEngine();

	distributeTiles();

	m_playerIndex = getFirstPlayer();
	
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
		m_gamePlayers.at(nextPlayerIndex)->getHand()->printHand();
	}
}

unsigned short gameRound::getFirstPlayer()
{
	// bool a_testBool;
	// a_testBool = (m_gamePlayers.at(0)->getHand()->hasEngine(m_engine));
	// a_testBool = (m_gamePlayers.at(1)->getHand()->hasEngine(m_engine));
	
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

	m_gamePlayers.at(0)->getHand()->printHand();
	m_gamePlayers.at(1)->getHand()->printHand();

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
		// call playMove() for the current player
		// m_gamePlayers.at(m_playerIndex)->playMove(newGameBoard);
		// m_gamePlayers.at(m_playerIndex)->getHand()->printHand();
		m_gamePlayers.at(m_playerIndex)->addToBoard(newGameBoard);
		m_playerIndex = (m_playerIndex + 1) % int(m_gamePlayers.size());
	}

}

bool gameRound::roundOver()
{
	// bool a_roundFinished;
	if (m_gamePlayers.at(0)->getHand()->getHandSize() == 1)
	{
		cout << "The computer wins!\n";
		return true;
	}
	if (m_gamePlayers.at(1)->getHand()->getHandSize() == 1)
	{
		cout << m_gamePlayers.at(1)->getName() << " wins!\n";
		return true;
	}
	return false;
}