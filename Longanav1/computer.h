#pragma once
#include "player.h"

class computer : public player
{
public:
	// default constructor
	computer();

	computer(playerHand &a_inUserHand) : player(a_inUserHand) {};
	// default destructor
	~computer();
private:
	// playerHand computerHand;
};