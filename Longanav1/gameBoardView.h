#pragma once
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>
#include "dominoTile.h"

using namespace std;

// The purpose of this class will be to print the following to the console:
// - the tournament score
// - the computer's hand
// - the player's hand
// - the board itself
// - if the current player passed their turn
// - the tiles remaining in the boneyard
class gameBoardView
{
public:
	// takes in the gameBoard and prints the gameBoard to the screen
	gameBoardView();
	~gameBoardView();

	// one thing that should happen is that the gameBoard should be printed to the screen
	void gatherInputs(vector<dominoTile> &a_leftSide, vector<dominoTile> &a_rightSide);
	
	void deleteLines();

	vector<dominoTile> combineSides(vector<dominoTile> &a_leftSide, vector<dominoTile> &a_rightSide);
	
	void printBrdToScreen(vector<dominoTile> &a_leftSide, vector<dominoTile> &a_rightSide);

private:
	queue<string> m_firstLine;
	vector<string> m_secondLine;
	queue<string> m_thirdLine;
	vector<dominoTile> m_mergeSides;
};