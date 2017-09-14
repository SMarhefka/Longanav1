#pragma once
#include "player.h"

// human is the derived class
// this means that this class will inherits all 
// the functions from player.cpp
class human : public player
{
public:
	// the default constructor of derived class is called
	human();
	~human();

	// this is the overriddent function from player the
	// player class
	void playMove();
};

