#pragma once
//#include "player.h"
#include "human.h"
#include "computer.h"
#include "boneYard.h"
#include "playerHand.h"

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

	// creates the boneYard
	boneYard newBoneYard = boneYard();
	// gets the first player
	unsigned short getFirstPlayer(int listSize);

	// deal 8 tiles to each of the players
	void initializeHand(player * currentPlayer);

	// function to start the round
	// void playMove(player * currentPlayer, string optional = "unknown");

	

private:
	vector< player*> playerList;
};