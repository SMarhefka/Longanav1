#include "stdafx.h"
#include "tournament.h"

tournament::tournament()
{
	string m_playerName = "";
	int m_tournScore = 0;
}

tournament::~tournament()
{
}

void tournament::beginTournament()
{
	cout << "Welcome to Longana! What is the score that you would like to play until? ";
	cin >> m_tournScore;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid number: ";
		cin >> m_tournScore;
	}

	cout << "What name would you like to use? ";
	cin >> m_playerName;
	if (m_playerName.length() <= 2)
	{
		m_playerName = "Player 1";
	}
	cout << endl;

	createPlayers();

	int rndNum = 1;
	// create a newRound 
	gameRound newRound = gameRound(rndNum, m_playerList);
	// newRound.setPlayerVec(m_playerList);
	// start a new gameRound
	newRound.setUpRound();
}

void tournament::createPlayers()
{
	// this will create a new computer object
	player * comPlayer = new computer();

	// this will be the human player
	player * humanPlayer = new human(m_playerName);

	// place the players in a vecor
	m_playerList.push_back(comPlayer);
	m_playerList.push_back(humanPlayer);
}

void tournament::printScore()
{
	cout << "Tournament Score: " << m_tournScore << "\n";
}