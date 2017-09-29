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

	bool rightSideOnly(dominoTile a_btileRight, dominoTile a_inTile);
	bool checkRightSide(dominoTile a_btileRight, dominoTile a_inTile);
};