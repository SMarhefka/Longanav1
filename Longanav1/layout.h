#pragma once
#include <vector>
#include "dominoTile.h"
#include "layout.h"

class layout
{
public:
	// this is the board itself
	layout();

	~layout();

	void printToScreen();
	
	// stores the information that will be printed to the screen

private:
	vector<dominoTile> boardLeft;
	vector<dominoTile> boardRight;
};