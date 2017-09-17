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

	cout << "What would you like to be called? ";
	cin >> playerName;

	if (playerName == "" || playerName.length() < 2)
	{
		playerName = "Player 1";
	}

	//set the players Name in round
	//setName();

	// start a new gameRound
	newRound.setUpRound();
}

void tournament::printScore()
{
	cout << "Tournament Score: " << this->tournamentScore << "\n";
}

//void tournament::setName()
//{
//	newRound.setPlayerName(playerName);
//}

//void tournament::startNewGame(bool isNewGame, string a_whoWonLastRound)
//{
//}