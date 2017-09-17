#pragma once
#include "human.h"
#include "computer.h"
#include "boneYard.h"

class gameRound
{
public:
	// default constructor
	gameRound();
	
	// default destructor
	~gameRound();

	//void setPlayerName(string inString);

	void setUpRound();

	// function to create players
	void createPlayers();

	//void createPlayerHands(unsigned short nextPlayerIndex);

	// this function will implement the entire gameRound
	void playRound();

	// gets the first player
	unsigned short getFirstPlayer(int listSize);

	// deal 8 tiles to each of the players

	// function to start the gameRound
	// void playMove(player * currentPlayer, string optional = "unknown");

private:
	vector<player *> playerList;
	// create a new boneYard
	boneYard newBoneYard;
};