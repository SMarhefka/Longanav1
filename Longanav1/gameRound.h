#pragma once
#include "human.h"
#include "computer.h"
#include "boneYard.h"
#include "gameBoard.h"
#include <string>
#include <ostream>
//fstream: Stream class to both read and write from/to files.
#include <fstream>

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

	void printRoundNum();
	
	/*-----------------------Save to file functions----------------------*/
	void askToSave();

	bool validSaveInput(char a_inSave);

	string getOutputFile();

	void printToFile(int a_inPlayerIndex);
	/*-----------------------Save to file functions----------------------*/

private:
	// creates a new boneYard
	boneYard* newBoneYard;
	// creates a new gameBoard;
	gameBoard newGameBoard;

	vector<player*> m_gamePlayers;
	// this variable keeps track of the engine for 
	// the current round
	unsigned short m_playerIndex;
	// this is the engine variable
	int m_engineVal;
	// this is read in from the tournament class
	int m_roundNum;
	// get the tournament score
	int m_inTourScore;
	// variable to keep track of save
	char m_saveSelection;
};