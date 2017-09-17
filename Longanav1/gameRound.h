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

	// function to create players
	// void createPlayers();

	// distrubute 8 tiles to each player
	void distributeTiles();


	// this function will implement the entire gameRound
	void playRound();

	// gets the first player
	unsigned short getFirstPlayer(int listSize);

	//bool roundOver();

private:
	vector<player*> gamePlayers;
	// create a new boneYard
	boneYard newBoneYard;
};