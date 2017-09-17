#include "stdafx.h"
#include "gameRound.h"
#include <string>

gameRound::gameRound()
{
	// test to make sure that the round 
	cout << "newRound constructor called\n";
}

gameRound::~gameRound()
{
}

void gameRound::setUpRound()
{
	// first step is to create the players
	createPlayers();
	
	// distribute 8 tiles to each player
	for (unsigned short nextPlayerIndex = 0; nextPlayerIndex < 2; nextPlayerIndex++)
	{
		for (int count = 0; count <= 8; count++)
		{
			// then you want to give each player 1 tiles
			playerList.at(nextPlayerIndex)->getHand()->addTile(newBoneYard.dealTile());
			// just to check I want to make sure that that it prints correctly
		}
		playerList.at(nextPlayerIndex)->getHand()->printHand();
	}

	// initialize the index to the computer first
	// unsigned short nextPlayerIndex = 0;

	//nextPlayerIndex = nextPlayerIndex + 1;

	/*for (int count = 0; count <= 8; count++)
	{
		// then you want to give each player 1 tiles
		playerList.at(nextPlayerIndex)->getHand()->addTile(newBoneYard.dealTile());
		// just to check I want to make sure that that it prints correctly
		playerList.at(nextPlayerIndex)->getHand()->printHand();
	}*/
	
	//playerList.at(nextPlayerIndex)->playMove();

	
}

void gameRound::createPlayers()
{
	// this will be the computer player
	player * comPlayer = new computer();

	// this will be the human player
	player * humanPlayer = new human("Player 1");

	// place the players in a vecor
	playerList.push_back(comPlayer);
	playerList.push_back(humanPlayer);
}

//void gameRound::createPlayerHands(unsigned short nextPlayerIndex)
//{
//	// set the current player to the corresponding index in player
//	for (int i = 0; i <= 8; i++)
//	{
//		playerList.at(nextPlayerIndex)->getHand()->addTile(newBoneYard.dealTile());
//	}
//}

void gameRound::playRound()
{
}

unsigned short gameRound::getFirstPlayer(int listSize)
{
	// check to see to see if the computer hand has the
	return 0;
}