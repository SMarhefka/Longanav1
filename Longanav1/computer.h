/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once
#include "player.h"

class computer : public player
{
public:
	// Default constructor
	computer();

	// Overloaded constructor
	computer(playerHand a_inUserHand, int a_inScore, bool a_inComPassed);

	// Default destructor
	~computer(); 
};