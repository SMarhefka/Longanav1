#include "stdafx.h"
#include "gameRound.h"
#include <string>

gameRound::gameRound()
{
	// test to make sure that the round 
	// cout << "newRound constructor called\n";
}

gameRound::~gameRound()
{
}

void gameRound::setUpRound()
{
	distributeTiles();

	getFirstPlayer();
}

void gameRound::setPlayerVec(vector<player*> inPlayers)
{
	gamePlayers.push_back(inPlayers.at(0));
	gamePlayers.push_back(inPlayers.at(1));
}

void gameRound::distributeTiles()
{
	// distribute 8 tiles to each player
	for (unsigned short nextPlayerIndex = 0; nextPlayerIndex < 2; nextPlayerIndex++)
	{
		for (int count = 0; count <= 8; count++)
		{
			// then you want to give each player 1 tiles
			gamePlayers.at(nextPlayerIndex)->getHand()->addTile(newBoneYard.dealTile());
			// just to check I want to make sure that that it prints correctly
			// gamePlayers.at(nextPlayerIndex)->getHand()->getTilesAt(count).printTile();
		}
		gamePlayers.at(nextPlayerIndex)->getHand()->printHand();
	}
}


void gameRound::playRound()
{
	// print whos move it is
}

unsigned short gameRound::getFirstPlayer()
{

	// check to see to see if the computer hand has the
	return 0;
}