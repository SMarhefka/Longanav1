#pragma once
#include "player.h"

class round
{
public:
	// default constructor
	round();
	// default destructor
	~round();

	// function to create players
	void createPlayers();

	// function to start the round
	void playMove(player * currentPlayer);

private:
	vector<player*> gamePlayers;
};