#pragma once
#include "player.h"

class human : public player
{
public:
	human();
	~human();

	// this is the overriddent function from player the
	// player class
	void playTest();
};

