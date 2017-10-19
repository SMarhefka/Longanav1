/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
************************************************************************/

#pragma once
#include "player.h"

// human is the derived class
// this means that this class will inherits all 
// the functions from player.cpp
class human : public player
{
public:
	// the default constructor of derived class is called
	human();

	// creates a constructor for human class with the arguement
	// of a player name
	human(string a_inName);

	// creates a new human with the playerhand and the player score
	human(playerHand a_inUserHand, int a_inScore, bool a_inPassed, string a_inPlayerName);

	// default destructor
	~human();

	void human::displayInfo(gameBoard* &a_inGameBoard);

	// this is the overridden function from the player class
	void playMove(gameBoard* &a_inGameBoard, bool a_nextPlayerPassed);

	// displays the first set of options that the human has
	void printFirstOptions();

	// displays the left right options
	void printLeftRight();

	// displays the first set of options
	void displayOptions1();

	// displays the tiles that the user has
	void displayTiles();

	// executes based on the user choice
	void executeOptions();

	// diplay
	void displayOptions2();

	// find the posistion of the engine if the user
	// has a hand
	void findEnginePosition();

	// returns whether or not the user passed their turn
	bool getPassed();

	// returns the player hand
	playerHand* getHand();

private:
	// pointer to a gameboard object
	gameBoard* m_playerGameBoard;
	// temporary user choice
	int m_tempUserChoice;
	// the position of the engine
	int m_enginePosition;
	// valid tile choice
	int m_tileChoice;
	// determines wheather or not the execution was successful
	bool m_exeSucc;
};

