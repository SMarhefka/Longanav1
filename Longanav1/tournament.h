#pragma once
#include "gameRound.h"

class tournament
{
public:
	tournament();
	~tournament();

	void beginTournament();

	void setName();

	void printScore();
	// provide the user with game options.  These include starting a new game or loading
	// in a previous game
	// void gameOptions();

	// function that will handle a new game
	// void startNewGame(bool isNewGame, string a_whoWonLastRound);

	// function that will handle a file that is loaded in
	// void loadGameFromFile();
private:
	int tournamentScore;
	string playerName;
	gameRound newRound;
};