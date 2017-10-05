#pragma once
#include "human.h"
#include "computer.h"
#include "boneYard.h"
#include "gameBoard.h"
#include <string>

class gameRound
{
public:
	// default constructor
	gameRound();

	gameRound(int &a_roundNumber, vector<player*> &a_gamePlayers, int a_inTourScore);

	// default destructor
	~gameRound();

	void setUpRound();

	int getEngine();

	// distrubute 8 tiles to each player
	void distributeTiles();

	// this function will implement the entire gameRound
	void playRound();

	// find out who the first player in the round will be
	unsigned short getFirstPlayer();

	bool roundOver();

	bool getSave();

	void setSave(char a_saveSelection);

	void printRoundNum();
	
	bool validSave(char a_inSave);

	void askToSave();

	/*-----------------------Save to file functions----------------------*/


private:
	vector<player*> m_gamePlayers;
	// creates a new boneYard
	//boneYard* newBoneYard;
	boneYard newBoneYard;
	// creates a new gameBoard;
	//gameBoard* newGameBoard;
	gameBoard newGameBoard;
	// this variable keeps track of the engine for 
	// the current round
	int m_engineVal;
	// this is read in from the tournament class
	int m_roundNum;
	int m_inTourScore;
	unsigned short m_playerIndex;
	char m_saveSelection;
	bool m_saveGame;
};