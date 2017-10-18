#include "stdafx.h"
#include "validateInput.h"

// this checks the left side value of the board against the right side of
// the users tile
// a_inTile: this is the user tile
// a_boardLeftVal: this is the left value of the board
bool validateInput::leftSide1(int a_boardLeftVal, dominoTile a_inUserTile)
{
	// if the board left side value is the same 
	// as the left side value of the user tile
	if ((a_boardLeftVal == a_inUserTile.getLeftSide()))
	{
		// if this returns true then the tile would need 
		// to be reversed
		return true;
	}
	return false;
}

// this checks the left side value of the board against the left side of
// the users tile
// a_inTile: this is the user tile
// a_boardLeftVal: this is the left value of the board
bool validateInput::leftSide2(int a_boardLeftVal, dominoTile a_inUserTile)
{
	// if the board left side value is the same 
	// as the right side value of the user tile
	if ((a_boardLeftVal == a_inUserTile.getRightSide()))
	{
		// then the selection is valid 
		// but we will need to reverse the tile
		return true;
	}
	return false;
}

// this checks the right side value of the board against the left side of
// the users tile
// a_inTile: this is the user tile
// a_boardLeftVal: this is the left value of the board
bool validateInput::rightSide1(int a_boardRightVal, dominoTile a_inUserTile)
{
	// if the board right side value is the same 
	// as the left side value of the user tile
	if ((a_boardRightVal == a_inUserTile.getLeftSide()))
	{
		// if this returns true then the tile would not 
		// need to be reversed
		return true;
	}
	return false;
}

// this checks the right hand side of the board
// a_inTile: this is the user tile
// a_btileLeft: this is the left most tile of the board
bool validateInput::rightSide2(int a_boardRightVal, dominoTile a_inUserTile)
{
	// if the board right side value is the same 
	// as the right side value of the user tile
	if ((a_boardRightVal == a_inUserTile.getRightSide()))
	{
		// if this returns true
		// however the tile would need to be reversed
		return true;
	}
	return false;
}

bool validateInput::validSideInput(char a_inSide)
{
	if (toupper(a_inSide) == 'L' || toupper(a_inSide) == 'R' || toupper(a_inSide) == 'B')
	{
		return true;
	}
	return false;
}

bool validateInput::validSideCheck(dominoTile a_inUserTile, char a_inSide, string a_inName, bool a_inPassed)
{
	if (a_inName == "Computer")
	{
		if (a_inUserTile.isDouble() == true || a_inPassed == true)
		{
			if (a_inSide == 'L')
			{
				return true;
			}
		}
		else if (a_inSide == 'R')
		{
			return true;
		}
	}
	else if (a_inName != "Computer")
	{
		if (a_inUserTile.isDouble() == true || a_inPassed == true)
		{
			if (a_inSide == 'R')
			{
			
					return true;
			}
		}
		else if (a_inSide == 'L')
		{
			return true;
		}
	}
	return false;
}

bool validateInput::validEnginePlacement(dominoTile & a_inUserTile, int & a_inEngine)
{
	if (a_inUserTile.isDouble() == true && a_inUserTile.getLeftSide() == a_inEngine)
	{
		return true;
	}
	return false;
}

bool validateInput::validUserSelection(string a_userInput, int a_inMaxOptions)
{
	string testInput = a_userInput;
	regex digitSearch("(^\\d+)");
	smatch matchElement;

	if (regex_match(testInput, matchElement, digitSearch))
	{
		if (stoi(matchElement[1]) >= 1 && stoi(matchElement[1]) <= a_inMaxOptions)
		{
			return true;
		}
	}
	return false;
}

bool validateInput::validInputNumber(string a_userInput)
{
	string testInput = a_userInput;
	regex digitSearch("(^\\d+)");

	if (regex_match(testInput, digitSearch))
	{
		return true;
	}
	return false;
}

bool validateInput::validSaveInput(char a_inSave)
{
	if (toupper(a_inSave) == 'Y' || toupper(a_inSave) == 'N')
	{
		return true;
	}
	return false;
}
