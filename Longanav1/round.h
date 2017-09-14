#pragma once
#include "player.h"
#include "human.h"
#include "computer.h"

class round
{
public:
	// default constructor
	round();
	// default destructor
	~round();

	// this function will implement the entire round
	void playRound();

	// function to create players
	void createPlayers();

	// deal 8 tiles to each of the players
	void initializeHand(player * currentPlayer);

	// function to start the round
	void playMove(player * currentPlayer);

private:
	vector<player*> gamePlayers;
	//player * humanPlayer;
	//player * comPlayer;
};