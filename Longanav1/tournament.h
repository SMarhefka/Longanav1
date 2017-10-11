#pragma once
#include "gameRound.h"
// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

class tournament
{
public:
	tournament();
	~tournament();

	void loadUserOptions();

	// create a new tournament
	void newTournament();

	// function to create players
	void createPlayers();

	// loads in a previous tournament
	void loadFromFile();

	// get the file information needed
	string getInputFile();

	// print the tournament score
	void printScore();

	// return the tournament score
	int getTourScore();

	// This creates a vector
	vector<dominoTile> createVector(string a_inLine);

private:
	vector<player*> m_playerList;
	
	int m_tempUserChoice;

	string m_playerName;

	/*--------Variables that will be used when file is read in----------*/
	// This will keep track of the tournament score
	int m_tournScore;
	// This is going to be the variable for the round number
	int m_inRoundNum;

	// this boolean will be true if we are loading up the
	// computer variables
	bool m_isComputer;
	// This is going to be the vector for the computerHand
	vector<dominoTile> m_comHand;
	// this will store the commputer score
	int m_computerScore;

	// this boolean will be true if and when we are loading up
	// the player variables
	bool m_isHuman;
	// This is going to be the vector for the playerHand
	vector<dominoTile> m_playerHand;
	// this will store the player score
	int m_playerScore;

	// this boolean will be true if and when we are loading up
	// the board from the file
	bool m_isBoard;
	// these will be the tiles stored into the layout
	vector<dominoTile> m_layoutTiles;

	// this boolean will be true if and when we are loading up
	// the board from the file
	bool m_isBoneYard;
	// these will be the domino tiles that will be used for the boneYard
	vector<dominoTile> m_boneyardTiles;

	// this boolean sets the player passed variable
	bool m_playerPassed;

	// this variable sets the next player
	int m_nextPlayer;
	/*--------Variables that will be used when file is read in----------*/
};