#include "stdafx.h"
#include "round.h"


round::round()
{
	// test 
	cout << "round constructor called\n";
}

round::~round()
{
}

void round::createPlayers()
{
	// this will be the computer player
	player * comPlayer = new computer();

	// this will be the human player
	player * humanPlayer = new human();

	// place the players in a vecor
	gamePlayers.push_back(comPlayer);
	gamePlayers.push_back(humanPlayer);
}

void round::initializeHand(player * currentPlayer)
{

}

void round::playRound()
{
	// first step is to create the players
	createPlayers();
	// then you want to give each player 8 tiles

	// this will make a move as a computer
	playMove(gamePlayers.at(0));

	// this will make a move as a human
	playMove(gamePlayers.at(1));
}

void round::playMove(player * currentPlayer)
{
	cout << "Current Player: " << currentPlayer << "\n";
	currentPlayer->playMove();
}
