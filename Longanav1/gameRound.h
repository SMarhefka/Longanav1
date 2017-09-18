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

	void setUpRound();

	// function to set the name of the player
	void setPlayerVec(vector<player*> inPlayers);

	// distrubute 8 tiles to each player
	void distributeTiles();

	// this function will implement the entire gameRound
	void playRound();

	// find out who the first player in the round will be
	unsigned short getFirstPlayer();

	//bool roundOver();

private:
	vector<player*> gamePlayers;
	// create a new boneYard
	boneYard newBoneYard;

	int engine;
};