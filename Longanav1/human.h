#pragma once
#include "player.h"
#include "validateInput.h"
#include <iomanip>

// human is the derived class
// this means that this class will inherits all 
// the functions from player.cpp
class human : public player
{
public:
	// the default constructor of derived class is called
	human();

	// creates a constructor for human class with the arguement
	// of a player name
	human(string inName);

	// default destructor
	~human();

	// this is the overridden function from the player class
	bool playMove(gameBoard newGameBoard);

	// this function is specific to the human class
	void displayInitialOptions();

	void displayTileOptions(int a_optionCount);

	void executeOptions(gameBoard a_inGameBoard);

	void selectTile(gameBoard a_inGameBoard);

	// this is a getter function
	playerHand* getHand();

private:
	int m_userChoice;
	validateInput m_checkInput;
};

