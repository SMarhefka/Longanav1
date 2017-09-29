#pragma once
#include <iostream>
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
	// default destuctor
	~player();
	
	// This is only a test at this point
	// I am not passing this by reference because I
	// don't plan on modifying the game board in the
	// player class
	virtual void playMove(gameBoard &a_inGameBoard);

	virtual bool checkTileSelection(gameBoard &a_inGameBoard, int &a_userChoice);

	// check for valid moves
	virtual bool checkMove(gameBoard &a_inGameBoard);

	// This will return the name of the current player
	string getName();

	virtual playerHand* getHand();

	void setPassed(bool a_playerPass);

	void setUserOptions(dominoTile & a_userTile, char & a_incomingSide);

	bool getPassed();

	dominoTile getUserOption();

	char getAddSide();

	void setEngineFRound(int &a_inEngine);

protected:
	// creates a new instance of validate 
	validateInput m_checkInput;
	// creates a new player hand
	playerHand m_currentHand;
	dominoTile m_userSelection;
	// playerHand
	string m_playerName;

	bool m_playerPass;
	
	int m_inEngine;
	int m_userChoice;
	int m_score;

	char m_whichSide;
};