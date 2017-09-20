#include "stdafx.h"
#include "player.h"

//for testing only
#include <string>

// this is the base class
player::player()
{

	// cout << "this is a player\n";
	playerType = "computer";
}

player::~player()
{
}

// 9/19 10:15 implemented an add to board function
void player::addToBoard(gameBoard &newGameBoard)
{
	int userChoice = 2;
	cout << "I am playing as the: " << playerType << " and I am in the player::addToBoard function\n";
	newGameBoard.addToLeft(currentHand.getTilesAt(userChoice));
	userChoice = 3;
	newGameBoard.addToLeft(currentHand.getTilesAt(userChoice));
	newGameBoard.printToScreen();
	currentHand.removeTile(currentHand.getTilesAt(userChoice));
}

void player::addToHand()
{
	cout << "I'm playing as: " << playerType << " and I am in player player::addToHand() function\n";
}

void player::playMove()
{
	cout << "I'm playing as: " << playerType << " and I am in player player::playMove() function\n";
	// cout << "I'm in player playMove()\n";
}

string player::getName()
{
	return string(playerType);
}

playerHand* player::getHand()
{
	// cout << "Playing as: " << playerType << " I'm in the player::getHand method\n";
	return &currentHand;
}

