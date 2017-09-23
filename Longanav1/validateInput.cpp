#include "stdafx.h"
#include "validateInput.h"

bool validateInput::checkLeftSide(dominoTile a_inTile, dominoTile a_btileLeft)
{
	if ((a_inTile.getLeftSide() == a_btileLeft.getLeftSide()) ||
		(a_inTile.getLeftSide() == a_btileLeft.getRightSide()) ||
		(a_inTile.getRightSide() == a_btileLeft.getLeftSide()) ||
		(a_inTile.getRightSide() == a_btileLeft.getRightSide()))
	{
		return true;
	}
	return false;
}

bool validateInput::checkRightSide(dominoTile a_inTile, dominoTile a_btileRight)
{
	if ((a_inTile.getLeftSide() == a_btileRight.getLeftSide()) ||
		(a_inTile.getLeftSide() == a_btileRight.getRightSide()) ||
		(a_inTile.getRightSide() == a_btileRight.getLeftSide()) ||
		(a_inTile.getRightSide() == a_btileRight.getRightSide()))
	{
		return true;
	}
	return false;
}
