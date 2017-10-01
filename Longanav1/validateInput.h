#pragma once
#include <string>
#include "dominoTile.h"
using namespace std;

class validateInput
{
public:
	// check the left side only
	bool leftSideOnly(dominoTile a_btileLeft, dominoTile a_inTile);
	// check the left side of the board
	bool checkLeftSide(dominoTile a_btileLeft, dominoTile a_inTile);
	// checks the right side only
	bool rightSideOnly(dominoTile a_btileRight, dominoTile a_inTile);
	// checks the right side of the board and compares
	// it against the users hand
	bool checkRightSide(dominoTile a_btileRight, dominoTile a_inTile);
	// checks the user input 
	bool validSideInput(char & a_inSide);
	// checks to see if the tile can be placed on the given side
	bool validSideCheck(dominoTile & a_inTile, char & a_inSide, string & a_inpName, bool & a_inPassed);
	// checks to make sure that the user placed the engine correctly
	bool validEnginePlacement(dominoTile & a_inTile, int & a_inEngine);
};