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

	// this is the overridden function from the player class
	void playMove(gameBoard* &a_inGameBoard, bool a_nextPlayerPassed);

	void printFirstOptions();

	void printLeftRight();

	// this function is specific to the human class
	void displayOptions1();

	void displayTiles();

	void executeOptions();

	void displayOptions2();

	void findEnginePosition();

	bool getPassed();

	// this is a getter function
	playerHand* getHand();

private:
	gameBoard* m_playerGameBoard;
	int m_tempUserChoice;
	int m_enginePosition;
	int m_tileChoice;
	bool m_exeSucc;
};

