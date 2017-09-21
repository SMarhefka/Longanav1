#pragma once
#include <iostream>
#include "playerHand.h"
#include "boneyard.h"
#include "gameBoard.h"

using namespace std;

class player
{
public:
	// default constuctor
	player();
	// default destuctor
	~player();
	
	// this function will place a tile onto the board
	virtual void addToBoard(gameBoard &newGameBoard);
	// this function will a
	virtual void addToHand();

	// This is only a test at this point
	// I am not passing this by reference because I
	// don't plan on modifying the game board in the
	// player class
	virtual bool playMove(gameBoard newGameBoard);

	// This will return the name of the current player
	string getName();

	virtual playerHand* getHand();

	void setPassed(bool a_playerPass);

	bool player::getPassed();

protected:
	playerHand m_currentHand;
	string m_playerName;
	bool m_playerPass;
	int m_score;
};