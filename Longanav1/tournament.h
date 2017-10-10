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

	void loadFromFile();

	// create a new tournament
	void newTournament();

	// function to create players
	void createPlayers();

	// get the file information needed
	string getInputFile();

	// print the tournament score
	void printScore();

	// return the tournament score
	int getTourScore();

	// provide the user with game options.  These include starting a new game or loading
	// in a previous game
	// void gameOptions();

	// function that will handle a new game
	// void startNewGame(bool isNewGame, string a_whoWonLastRound);

	// function that will handle a file that is loaded in
	// void loadGameFromFile();

private:
	vector<player*> m_playerList;
	int m_tempUserChoice;
	string m_playerName;
	// This will keep track of the tournament score
	int m_tournScore;
	// This is going to be the variable for the round number
	int m_inRoundNum;
	// This is going to be the vector for the computerHand
	vector<dominoTile> m_comHand;
	// This is going to be the vector for the playerHand
	vector<dominoTile> m_playerHand;
	// this boolean will be true if we are loading up the
	// computer variables
	bool m_isComputer;
	// this boolean will be true if and when we are loading up
	// the player variables
	bool m_isHuman;
	// this will store the commputer score
	int m_computerScore;
	// this will store the player score
	int m_playerScore;
};