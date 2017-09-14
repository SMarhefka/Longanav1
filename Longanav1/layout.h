#pragma once
#include <vector>
#include "dominoTile.h"

class layout
{
public:
	layout();

	~layout();

	// stores the information that will be printed to the screen

	// update the board after a user plays
	void updateBoard();

private:
	vector<dominoTile> boardLeft;
	vector<dominoTile> boardRight;
};