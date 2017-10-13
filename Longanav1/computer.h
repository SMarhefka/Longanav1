#pragma once
#include "player.h"

class computer : public player
{
public:
	// default constructor
	computer();

	computer(playerHand a_inUserHand, int a_inScore, bool a_inPassed) : player(a_inUserHand, a_inScore)
	{
		m_ComputerPass = a_inPassed;
	};
	// default destructor
	~computer(); 

private:
};