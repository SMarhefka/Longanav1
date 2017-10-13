#pragma once
#include "gameRound.h"
#include "fileFunctions.h"
// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>
#include <cstring>

class tournament
{
public:
	tournament();
	~tournament();

	void loadUserOptions();

	// create a new tournament
	void newTournament();

	// function to create players
	void createPlayers(bool a_isNewGame);

	// loads in a previous tournament
	void loadFromFile();

	void playTournament(bool a_isNewGame);

	// print the tournament score
	void printScore();

	void setBooleans(string a_inElementOne);

	// This creates a vector
	vector<dominoTile> createVector(string a_inLine);

	bool tournamentOver();

	//boneYard* createBoard(vector<dominoTile> a_inLayoutTiles);

private:
	gameRound * newRound;
	gameBoard* m_loadGameBoard;
	// creates a new validation class
	validateInput* m_validateInputs;
	fileFunctions* m_fileFunctions;
	// creates a new vector of players
	vector<player*> m_playerList;

	string m_playerName;

	// This will keep track of the tournament score
	int m_tournScore;
	// This is going to be the variable for the round number
	int m_roundNum;

	/*--------Variables that will be used when file is read in----------*/
	// this boolean will be true if we are loading up the
	// computer variables
	bool m_isComputer;
	// This is going to be the vector for the computerHand
	vector<dominoTile> m_comHand;
	// this will store the commputer score
	int m_computerScore;

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
	string m_playerPassed;

	// this variable sets the next player
	string m_nextPlayer;
	/*--------Variables that will be used when file is read in----------*/
};