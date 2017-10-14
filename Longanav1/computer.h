#pragma once
#include "player.h"

class computer : public player
{
public:
	// default constructor
	computer();

	computer(playerHand a_inUserHand, int a_inScore, bool a_inComPassed, bool a_inPlyerPassed) : player(a_inUserHand, a_inScore, a_inComPassed, a_inPlyerPassed)
	{
		m_playerName = "Computer";
	};
	// default destructor
	~computer(); 

private:
};