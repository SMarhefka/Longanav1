#include "stdafx.h"
#include "round.h"

round::round()
{
}

round::~round()
{
}

void round::createPlayers()
{
	// this will be the human player
	player * human = new player;
	// this will be the computer
	player * computer = new player;

	// place the players in a vecor
	gamePlayers.push_back(human);
	gamePlayers.push_back(computer);
}

void round::playRound()
{
	// first step is to create the players
	createPlayers();
	// then you want to give each player 8 tiles

	//

}

void round::playMove(player * currentPlayer)
{
	currentPlayer->playTest();
}
