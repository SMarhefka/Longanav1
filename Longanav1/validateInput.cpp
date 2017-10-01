#include "stdafx.h"
#include "validateInput.h"

// this checks the right hand side of the board
// a_inTile: this is the user tile
// a_btileLeft: this is the left most tile of the board
bool validateInput::leftSideOnly(dominoTile a_btileLeft, dominoTile a_inTile)
{
	if ((a_btileLeft.getLeftSide() == a_inTile.getLeftSide()))
	{
		return true;
	}
	return false;
}

// this checks the left hand side of the board
// a_inTile: this is the user tile
// a_btileLeft: this is the left most tile of the board
bool validateInput::checkLeftSide(dominoTile a_btileLeft, dominoTile a_inTile)
{
	// if the left side of the tile on the board 
	// is the same as the left side of the user tile 
	// then the selection is valid
	 if ((a_btileLeft.getLeftSide() == a_inTile.getLeftSide()))
	{
		return true;
	}

	// if the left side of the tile on the board 
	// is the same as the right side of the user tile 
	// then the selection is valid
	if ((a_btileLeft.getLeftSide() == a_inTile.getRightSide()))
	{
		return true;
	}
	return false;


}

// this checks the right hand side of the board
// a_inTile: this is the user tile
// a_btileLeft: this is the left most tile of the board
bool validateInput::rightSideOnly(dominoTile a_btileRight, dominoTile a_inTile)
{
	if ((a_btileRight.getRightSide() == a_inTile.getRightSide()))
	{
		return true;
	}
	return false;
}

// this checks the right hand side of the board
// a_inTile: this is the user tile
// a_btileLeft: this is the left most tile of the board
bool validateInput::checkRightSide(dominoTile a_btileRight, dominoTile a_inTile)
{
	// if the right side of the tile on the board 
	// is the same as the left side of the user tile 
	// then the selection is valid
	if ((a_btileRight.getRightSide() == a_inTile.getLeftSide()))
	{
		return true;
	}
	// if the right side of the tile on the board 
	// is the same as the right side of the user tile 
	// then the selection is valid
	if ((a_btileRight.getRightSide() == a_inTile.getRightSide()))
	{
		return true;
	}
	return false;
}

bool validateInput::validSideInput(char & a_inSide)
{
	if (toupper(a_inSide) == 'L' || toupper(a_inSide) == 'R' || toupper(a_inSide) == 'B')
	{
		return true;
	}
	return false;
}

bool validateInput::validSideCheck(dominoTile & a_inTile, char & a_inSide, string & a_inpName, bool & a_inPassed)
{
	bool valid = NULL;
	if (a_inpName == "Computer")
	{
		if (a_inSide == 'L' && (a_inTile.isDouble() == true ||
			a_inPassed == true))
		{
			valid = true;
		}
		else if (a_inSide == 'R')
		{
			valid = true;
		}
	}
	else if (a_inpName != "Computer")
	{
		if (a_inSide == 'R' && (a_inTile.isDouble() == true ||
			a_inPassed == true))
		{
			valid = true;
		}
		else if (a_inSide == 'L')
		{
			valid = true;
		}
	}
	else
	{
		valid = false;
	}
	return valid;
}

bool validateInput::validEnginePlacement(dominoTile & a_inTile, int & a_inEngine)
{
	if (a_inTile.isDouble() == true && a_inTile.getLeftSide() == a_inEngine)
	{
		return true;
	}
	return false;
}

