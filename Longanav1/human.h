#pragma once
#include "player.h"
#include <string>

// human is the derived class
// this means that this class will inherits all 
// the functions from player.cpp
class human : public player
{
public:
	// the default constructor of derived class is called
	human();
	// creates a constructor for human class with the arguement
	// of a player name
	human(string name);

	~human();

	// this is the overridden function from player the
	// player class
	void playMove();

private:
	string humanName;
};
