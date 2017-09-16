#include "stdafx.h"
#include "human.h"

// to delete
#include <string>

// this is the default constructor
human::human()
{
	cout << "this is a human\n";
}

human::human(string name)
{
	humanName = name;
}

human::~human()
{
}

void human::playMove()
{
	// cout << "I'm playing as: " << optional << " and I'm in the human playMove() function!\n";
	cout << "I'm going into add tile from HUMAN\n";
	// addToHand(humanTile);
	
}
