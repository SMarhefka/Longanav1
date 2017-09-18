#pragma once
#include "gameRound.h"
#include "gameBoard.h"

class tournament
{
public:
	tournament();
	~tournament();

	void beginTournament();

	// function to create players
	void createPlayers();

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
	vector<player *> playerList;
	gameBoard newGameBoard;
	// create a new gameRound
	// gameRound newRound;
	string playerName;
};