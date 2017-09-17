#include "stdafx.h"
#include "human.h"

// to delete
#include <string>

// this is the default constructor
human::human()
{
	cout << "I'm creating a human\n";
	//humanHand = new playerHand;
}

human::human(string name)
{
	cout << "I'm creating a human with a name: " << playerType << "\n";
	playerType = name;
}

human::~human()
{
}

void human::playMove()
{
	cout << "I'm playing as: " << playerType << " and I'm in the human::playMove() function!\n";
}

playerHand* human::getHand()
{
	cout << "Playing as: " << playerType << " and I am in the human::getHand()\n";
	return &currentHand;
}
