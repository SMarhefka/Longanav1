/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
************************************************************************/

#pragma once
#include "playerHand.h"
#include "boneyard.h"
#include "gameBoard.h"
#include "validateInput.h"


using namespace std;

class player
{
public:
	// default constuctor
	player();

	// overloaded constructor
	player(playerHand a_inUserHand, int a_inScore, bool a_inPassed);

	// default destuctor
	~player();
	
	// This is only a test at this point
	// I am not passing this by reference because I
	// don't plan on modifying the game board in the
	// player class
	virtual void playMove(gameBoard* &a_inGameBoard, bool a_nextPlayerPassed);


	void player::resetAll();

	virtual void player::displayInfo(gameBoard* &a_inGameBoard);


	virtual bool checkTileSelection(int a_boardLeftVal, int a_boardRightVal, 
									dominoTile &a_inUserTile);

	// check for valid moves
	virtual bool checkMove();

	void setEngine(int & a_inEngine);

	dominoTile getSelectedTile();

	virtual playerHand* getHand();

	string setName(string a_inName);
	// This will return the name of the current player
	string getName();

	bool getPassed();

	void addScore(int a_inNumber);

	int getScore();

	char getSelectedSide();

	int getPassCount();

	void setUserOptions(dominoTile & a_userTile, char & a_incomingSide);

	vector <dominoTile> getTileOptions();

	void printPlacement(bool a_hadEngine);

	void getHelp(gameBoard* &a_inGameBoard, bool a_nextPlayerPassed);

	// get the private variable m_gettingHelp
	bool amIGettingHelp()
	{
		return m_gettingHelp;
	}

protected:
	// creates a new instance of validate class
	validateInput* m_checkInput;
	// creates a new player hand
	playerHand m_currentHand;
	// creates a new dominoTile
	dominoTile m_userSelection;
	// new string variable that stores the player name
	string m_playerName;

	vector <dominoTile> m_playOrder;

	char m_whichSide;

	bool m_prevPass;
	bool m_passTurn;
	bool m_validMove;

	int m_engineValue;

	int m_playerScore;
	int m_userChoice;

	int m_passCount;
	int m_totalPips;

	int m_boardLeft;
	int m_boardRight;

	bool m_gettingHelp;
};