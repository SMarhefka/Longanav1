#pragma once
#include "playerHand.h"
#include <iostream>

using namespace std;

class player
{
public:
	// default constuctor
	player();
	// default destuctor
	~player();
	
	// This is only a test at this point
	// This function should take in a player's hand
	virtual void playTest();

};

