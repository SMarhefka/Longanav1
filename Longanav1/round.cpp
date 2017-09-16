#include "stdafx.h"
#include "round.h"
#include <string>

round::round()
{
	// test 
	cout << "round constructor called\n";
}

round::~round()
{
}

void round::playRound()
{
	// first step is to create the players
	createPlayers();
	// then you want to give each player 8 tiles
	unsigned short nextPlayerIndex = 0;
	// set the current player to the corresponding index in player
	player * currentPlayer = playerList.at(nextPlayerIndex);

	// then you want to determine the first player
	//unsigned short nextPlayerIndex = getFirstPlayer(int(playerList.size()));

	// this will make a move as a computer
	currentPlayer->playMove();

	// this will make a move as a human
	// playMove(playerList.at(1));

	// currentPlayer->playMove();
}

void round::createPlayers()
{

	// this will be the computer player
	player * comPlayer = new computer();
	// place the players in a vecor
	playerList.push_back(comPlayer);

	// this will be the human player
	player * humanPlayer = new human("Player 1");
	playerList.push_back(humanPlayer);
}

unsigned short round::getFirstPlayer(int listSize)
{
	// check to see to see if the computer hand has the
	return 0;
}

void round::initializeHand(player * currentPlayer)
{

}

//void round::playMove(player * currentPlayer, string optional)
//{
//	cout << "Playing as: " << optional << "\n";
//	currentPlayer->playMove(optional);
//}
