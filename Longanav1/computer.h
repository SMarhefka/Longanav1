#pragma once
#include "player.h"

class computer : public player
{
public:
	// default constructor
	computer();

	computer(playerHand &a_inUserHand, int &a_inScore) : player(a_inUserHand, a_inScore)
	{
	};
	// default destructor
	~computer(); 
private:
	// playerHand computerHand;
};