#pragma once
#include <iostream>

using namespace std;

class player
{
public:
	// default constuctor
	player();
	// default destuctor
	~player();
	
	// this function will place a tile onto the board
	virtual void addToBoard();

	virtual void addToHand();
	// This is only a test at this point
	// This function should take in a player's hand
	virtual void playMove();
};