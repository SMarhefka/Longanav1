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
	// This function should take in a player's hand
	virtual void playMove();

	string getName();

	virtual playerHand* getHand();

protected:
	playerHand currentHand;
	string playerType;
	int score;
};