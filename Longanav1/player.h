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

	// This will return the name of the current player
	string getName();

	virtual playerHand* getHand();

	void setPassed(bool a_playerPass);

	void setUserOptions(int a_indexNumber);

	bool getPassed();

	int getUserOption();

	short getAddSide();

	void setEngineFRound(int &a_inEngine);

	bool checkPass(gameBoard &a_inNewGameBoard);

protected:
	validateInput m_checkInput;
	playerHand m_currentHand;
	string m_playerName;
	bool m_playerPass;
	int m_inEngine;
	int m_userChoice;
	char m_whichSide;
	int m_score;
};