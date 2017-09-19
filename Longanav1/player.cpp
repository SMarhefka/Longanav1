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

//
void player::addToBoard()
{
	cout << "I am playing as the: " << playerType << " and I am in the player::addToBoard function\n";
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

playerHand* player::getHand()
{
	// cout << "Playing as: " << playerType << " I'm in the player::getHand method\n";
	return &currentHand;
}

