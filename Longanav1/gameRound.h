#pragma once
#include "human.h"
#include "computer.h"
#include "boneYard.h"
#include "gameBoard.h"

class gameRound
{
public:
	// default constructor
	gameRound();

	gameRound(int a_roundNumber, vector<player*> &a_gamePlayers);

	// default destructor
	~gameRound();

	void setUpRound();

	void setEngine();

	// function to set the name of the player
	// void setPlayerVec(vector<player*> inPlayers);

	// distrubute 8 tiles to each player
	void distributeTiles();

	// this function will implement the entire gameRound
	void playRound();

	// find out who the first player in the round will be
	unsigned short getFirstPlayer();

	bool roundOver();

private:
	vector<player*> m_gamePlayers;
	// creates a new boneYard
	boneYard newBoneYard;
	// creates a new gameBoard;
	gameBoard newGameBoard;
	// this variable keeps track of the engine for
	// the round
	int m_engine;
	int m_roundNum;
	unsigned short m_playerIndex;
};