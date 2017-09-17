#include "stdafx.h"
#include "tournament.h"

tournament::tournament()
{
}

tournament::~tournament()
{
}

void tournament::beginTournament()
{
	cout << "Welcome to Longana! What is the score that you would like to play until? ";
	cin >> tournamentScore;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a number: ";
		cin >> tournamentScore;
	}

	cout << "What name would you like to use? ";
	cin >> playerName;
	if (playerName.length() < 3)
	{
		playerName = "Player 1";
	}

	createPlayers();

	gameRound newRound;
	newRound.setPlayerVec(playerList);
	// start a new gameRound
	newRound.setUpRound();
}

void tournament::createPlayers()
{
	// this will be the computer player
	player * comPlayer = new computer();

	// this will be the human player
	player * humanPlayer = new human(playerName);

	// place the players in a vecor
	playerList.push_back(comPlayer);
	playerList.push_back(humanPlayer);
}

void tournament::printScore()
{
	cout << "Tournament Score: " << this->tournamentScore << "\n";
}