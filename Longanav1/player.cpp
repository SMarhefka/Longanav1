#include "stdafx.h"
#include "player.h"

//for testing only
#include <string>

// this is the base class
player::player()
{
	cout << "this is a player\n";
}

player::~player()
{
}

//
void player::addToBoard()
{
	cout << "I am playing as the: and I am in the add tile function\n";
}

void player::addToHand()
{
	cout << "I'm at addToHand\n";
}

void player::playMove()
{
	//cout << "I'm playing as: " << optional << " and I am in player playMove() function\n";
	cout << "I'm in player playMove()\n";
	//addToHand(compTile);	
}

