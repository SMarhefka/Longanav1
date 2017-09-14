#include "stdafx.h"
#include "player.h"

// this is the base class
player::player()
{
	cout << "this is a player\n";
}

player::~player()
{
}

void player::playMove()
{
	cout << "I'm in player|playTest()!\n";
}

