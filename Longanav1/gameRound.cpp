#include "stdafx.h"
#include "gameRound.h"
#include <string>

gameRound::gameRound()
{
	// test to make sure that the round 
	// cout << "newRound constructor called\n";
}

gameRound::gameRound(int a_roundNumber)
{
	m_roundNum = a_roundNumber;
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

void gameRound::setEngine()
{

	if (m_roundNum == 1)
	{
		m_engine = 6;
	}
}

void gameRound::setPlayerVec(vector<player*> a_inPlayers)
{
	m_gamePlayers.push_back(a_inPlayers.at(0));
	m_gamePlayers.push_back(a_inPlayers.at(1));
}

void gameRound::distributeTiles()
{
	// distribute 8 tiles to each player
	for (unsigned short nextPlayerIndex = 0; nextPlayerIndex < 2; nextPlayerIndex++)
	{
		for (int count = 0; count <= 7; count++)
		{
			// then you want to give each player 1 tiles
			m_gamePlayers.at(nextPlayerIndex)->getHand()->addTile(newBoneYard.dealTile());
			// just to check I want to make sure that that it prints correctly
			// gamePlayers.at(nextPlayerIndex)->getHand()->getTilesAt(count).printTile();
		}
		m_gamePlayers.at(nextPlayerIndex)->getHand()->printHand();
	}
}


void gameRound::playRound()
{
	while (!roundOver())
	{
		// print whos move it is

		m_gamePlayers.at(m_playerIndex)->getHand()->printHand();
		m_playerIndex = (m_playerIndex + 1) % int(m_gamePlayers.size());
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
		m_gamePlayers.at(0)->getHand()->addTile(newBoneYard.dealTile());
		m_gamePlayers.at(0)->getHand()->printHand();
		// give the player a tile
		m_gamePlayers.at(1)->getHand()->addTile(newBoneYard.dealTile());
		m_gamePlayers.at(1)->getHand()->printHand();

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

bool gameRound::roundOver()
{
	// bool a_roundFinished;
	if (m_gamePlayers.at(0)->getHand()->getHandSize() == 0)
	{
		return true;
	}
	if (m_gamePlayers.at(1)->getHand()->getHandSize() == 0)
	{
		return true;
	}
}