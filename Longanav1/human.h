#pragma once
#include "player.h"
#include <iostream>
#include <iomanip>
#include <fstream>

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

	// creates a new human with the playerhand and the player score
	human(playerHand &a_inUserHand, int &a_inScore) : player(a_inUserHand, a_inScore)
	{
	};

	// default destructor
	~human();

	// this is the overridden function from the player class
	void playMove(gameBoard &a_inGameBoard);

	void printFirstOptions();

	void printLeftRight();

	// this function is specific to the human class
	void displayOptions1(gameBoard &a_inGameBoard);

	void displayTiles();

	void executeOptions(gameBoard &a_inGameBoard);

	void displayOptions2(gameBoard &a_inGameBoard);

	void findEnginePosition();

	// this is a getter function
	playerHand* getHand();

private:
	int m_tempUserChoice;
	int m_enginPosition;
	int m_tileChoice;
	bool m_exeSucc;
};

