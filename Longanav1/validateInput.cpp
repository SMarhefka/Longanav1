#include "stdafx.h"
#include "validateInput.h"

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
