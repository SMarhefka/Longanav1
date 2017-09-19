#pragma once
#include "gameBoard.h"
#include "tournament.h"

// The purpose of this class will be to print the following to the console:
// - the tournament score
// - the computer's hand
// - the player's hand
// - the board itself
// - if the current player passed their turn
// - the tiles remaining in the boneyard
class gameBoardView
{
public:
	// takes in the gameBoard and prints the gameBoard to the screen
	gameBoardView();
	~gameBoardView();

	// one thing that should happen is that the gameBoard should be printed to the screen
	void printBoardToScreen(playerHand &currentHand);
};