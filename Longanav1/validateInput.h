#pragma once
#include <string>
#include "dominoTile.h"
using namespace std;

class validateInput
{
public:
	// check to see if the user made a valid entry
	bool checkLeftSide(dominoTile a_inTile, dominoTile a_btileLeft);
	bool checkRightSide(dominoTile a_inTile, dominoTile a_btileRight);
};