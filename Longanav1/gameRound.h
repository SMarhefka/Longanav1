#pragma once
#include "human.h"
#include "computer.h"
#include "boneYard.h"
#include "gameBoard.h"
#include "fileFunctions.h"

class gameRound
{
public:
	// default constructor
	gameRound();

	gameRound(bool a_isNewRound, int &a_roundNumber, vector<player*> &a_gamePlayers, int a_inTourScore);

	gameRound(bool a_isNewRound, int &a_roundNumber, vector<player*> &a_gamePlayers, int a_inTourScore, vector<dominoTile> &a_inBoneYard, short a_inNextPlayer);

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
	
	void executeSave(short a_inSaveOption);

	void printToFile(short a_inPlayerIndex);
	/*-----------------------Save to file functions----------------------*/

	//unsigned short setNextPlayer(string a_inNextPlayer);

	bool engineInHands();

private:
	// creates a new boneYard
	boneYard* m_newBoneYard;
	// create a new validation object
	validateInput* m_newValidate;
	// creates a new file functions object
	fileFunctions* m_fileFunctions;
	// creates a new gameBoard;
	gameBoard newGameBoard;

	vector<player*> m_gamePlayers;

	bool m_isNewRound;

	string m_inPassed;
	// short m_inNextPlayer;

	// this variable keeps track of the engine for 
	// the current round
	unsigned short m_playerIndex;
	// this is the engine variable
	int m_engineVal;
	// this is read in from the tournament class
	int m_roundNumber;
	// get the tournament score
	int m_inTourScore;
	// variable to keep track of save
	char m_saveSelection;
};