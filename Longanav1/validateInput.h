/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once
#include "dominoTile.h"

class validateInput
{
public:
	// check the left side only
	bool leftSide1(int a_boardLeftVal, dominoTile a_inTile);
	// check the left side of the board
	bool leftSide2(int a_boardLeftVal, dominoTile a_inTile);
	// checks the right side only
	bool rightSide1(int a_boardRightVal, dominoTile a_inTile);
	// checks the right side of the board and compares
	// it against the users hand
	bool rightSide2(int a_boardRightVal, dominoTile a_inTile);
	
	// checks the user input 
	bool validSideInput(char a_inSide);
	
	// checks to see if the tile can be placed on the given side
	bool validSideCheck(dominoTile a_inTile, char a_inSide, string a_inpName, bool a_inPassed);
	// checks to make sure that the user placed the engine correctly
	bool validEnginePlacement(dominoTile &a_inTile, int & a_inEngine);
	
	// check to see if the filename given is valid
	bool validFileName(string a_inFileName);
	
	// checks to see if the userSelected a valid option
	bool validUserSelection(string a_userInput, int a_inMaxOptions);
	
	bool validInputNumber(string a_userInput);

	// validates the user input on the save option
	bool validSaveInput(char a_inSave);
};