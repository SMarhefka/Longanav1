#include "stdafx.h"
#include "gameBoardView.h"

gameBoardView::gameBoardView()
{
	// this is where all of the information will be placed
	// this function will contain all of the cout statements
	// that the users will see on the screen at they play the game
}

gameBoardView::~gameBoardView()
{
}

void gameBoardView::printBoardToScreen(playerHand &currentHand)
{
	currentHand.printHand();
}

void gameBoardView::printBoardToScreen(tournament &inScore)
{
	inScore.printScore();
}