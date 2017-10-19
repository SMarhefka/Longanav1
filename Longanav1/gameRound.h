/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

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

	// overloaded constructor
	gameRound(bool a_isNewRound, int a_inTourScore, int &a_roundNumber, vector<player*> &a_gamePlayers);

	// another overloaded constructor
	gameRound(bool a_isNewRound, int a_inTourScore, int &a_roundNumber, short a_inNextPlayer, 
			  vector<player*> &a_gamePlayers, vector<dominoTile> &a_inBoneYardTiles, 
			  vector<dominoTile> &a_inGameTiles);

	void setUpRound();

	int getEngine();

	// distrubute 8 tiles to each player
	void distributeTiles();

	// this function will implement the entire gameRound
	void playRound();

	// find out who the first player in the round will be
	short getFirstPlayer();

	// checks to see if the round is over
	bool roundOver();

	// Prints the round Number
	void printRoundNum();
	
	/*-----------------------Save to file functions----------------------*/
	void askToSave();
	
	void executeSave(short a_inSaveOption);

	void printToFile(short a_inPlayerIndex);
	/*-----------------------Save to file functions----------------------*/

	bool engineInHands();

	void finisUpRound();

	short getWinner();

	void findWhoPassed();

	bool getPrevPass()
	{
		// get the previous player
		int prevPlayer = (m_playerIndex + 1) % int(m_gamePlayers.size());
		if (m_playerIndex == 0)
		{
			return m_gamePlayers.at(prevPlayer)->getPassed();
		}
		else
		{
			return m_gamePlayers.at(prevPlayer)->getPassed();
		}
	}
	
	// default destructor
	~gameRound();

private:
	// creates a new boneYard
	boneYard* m_newBoneYard;
	// create a new validation object
	validateInput* m_newValidate;
	// creates a new file functions object
	fileFunctions* m_fileFunctions;
	// creates a new gameBoard;
	gameBoard* m_newGameBoard;
	// new vector of players
	vector<player*> m_gamePlayers;
	// checks for a new round
	bool m_isNewRound;

	string m_inPassed;

	// this variable keeps track of the engine for 
	// the current round
	short m_playerIndex;
	// this is the engine variable
	int m_engineVal;
	// this is read in from the tournament class
	int m_roundNumber;
	// get the tournament score
	int m_inTourScore;
	// variable to keep track of save
	char m_saveSelection;

	bool m_testPass;
};