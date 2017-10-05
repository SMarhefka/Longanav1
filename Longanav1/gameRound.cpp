#include "stdafx.h"
#include "gameRound.h"
#include "tournament.h"

gameRound::gameRound()
{
}

gameRound::gameRound(int &a_roundNumber, vector<player*> &a_gamePlayers, int a_inTouScore)
{
	//newBoneYard = new boneYard();
	//newGameBoard = new gameBoard();

	m_roundNum = a_roundNumber;
	m_gamePlayers = a_gamePlayers;
	m_engineVal = getEngine();
	m_inTourScore = a_inTouScore;
}

gameRound::~gameRound()
{
}

void gameRound::setUpRound()
{
	// set the engine for the corresponding round
	getEngine();
	// distribute 8 tiles to each tile
	distributeTiles();
	// ask the user if they would like to save the current game
	// askToSave();

	// figure out the first player
	m_playerIndex = getFirstPlayer();
	// play the round
	playRound();
}

// 9/19 10:30 implemented setEngine
int gameRound::getEngine()
{
	int a_count = 1;
	int a_engineCount = 6;
	while (a_count != m_roundNum)
	{
		if (a_engineCount == 0)
		{
			// reset the engine count
			a_engineCount = 6;
		}
		else
		{
			// reduce engine count by 1
			a_engineCount--;
		}

		a_count++;
	}
	return a_engineCount;
}

void gameRound::distributeTiles()
{
	// distribute 8 tiles to each player
	for (unsigned short nextPlayerIndex = 0; nextPlayerIndex < 2; nextPlayerIndex++)
	{
		for (int count = 0; count <= 7; count++)
		{
			// then you want to give each player 1 tiles
			m_gamePlayers.at(nextPlayerIndex)->getHand()->addTileToHand(newBoneYard.dealTile());
		}
	}
}

unsigned short gameRound::getFirstPlayer()
{
	while ((m_gamePlayers.at(0)->getHand()->hasEngine(m_engineVal)) == false && 
		(m_gamePlayers.at(1)->getHand()->hasEngine(m_engineVal)) == false)
	{
		// a_testBool = newBoneYard.isEmpty();
		if(!newBoneYard.isEmpty())
		// give the computer a tile
		m_gamePlayers.at(0)->getHand()->addTileToHand(newBoneYard.dealTile());
		// m_gamePlayers.at(0)->getHand()->printHand();
		// give the player a tile
		m_gamePlayers.at(1)->getHand()->addTileToHand(newBoneYard.dealTile());
		// m_gamePlayers.at(1)->getHand()->printHand();
	}

	// if the computer has the engine then the 
	// first player will be set to 0
	if (m_gamePlayers.at(0)->getHand()->hasEngine(m_engineVal))
	{
		return 0;
	}
	// otherwise we can safetly assume that the
	// player hand has the engine
	return 1;
}

void gameRound::playRound()
{
	// set the engine for the computer
	m_gamePlayers.at(0)->setEngineFromRound(m_engineVal);
	// set the engine for the first player
	m_gamePlayers.at(1)->setEngineFromRound(m_engineVal);

	while (!(roundOver() == true))
	{
		// print whos move it is
		cout << "Before Play" << endl;
		cout << "Current Player: " << m_gamePlayers.at(m_playerIndex)->getName() << endl;
		cout << "Hand: ";
		m_gamePlayers.at(m_playerIndex)->getHand()->printHand();
		cout << endl;

		int nextPlayer;
		if (m_gamePlayers.at(m_playerIndex)->getName() == "Computer")
		{
			nextPlayer = m_playerIndex + 1;
		}
		else
		{
			nextPlayer = m_playerIndex - 1;
		}

		cout << "Next Player: " << m_gamePlayers.at(nextPlayer)->getName() << endl;
		cout << "Hand: ";
		m_gamePlayers.at(nextPlayer)->getHand()->printHand();
		cout << endl;

		// play the move of the current player
		m_gamePlayers.at(m_playerIndex)->playMove(newGameBoard);

		if (m_gamePlayers.at(m_playerIndex)->getPassCount() == 1)
		{
			if (!newBoneYard.isEmpty())
			{
				m_gamePlayers.at(m_playerIndex)->getHand()->addTileToHand(newBoneYard.dealTile());
				m_gamePlayers.at(m_playerIndex)->playMove(newGameBoard);
			}
			else
			{
				cout << "The Boneyard is empty.  Going to the next player\n";
			}
		}
		if (m_gamePlayers.at(m_playerIndex)->getSelectedSide() == 'L')
		{
			dominoTile playerTile;
			// get the selected tile
			playerTile = m_gamePlayers.at(m_playerIndex)->getSelectedTile();
			newGameBoard.addToLeft(playerTile);
			m_gamePlayers.at(m_playerIndex)->getHand()->removeTile(playerTile);
			// m_gamePlayers.at(m_playerIndex)->getHand()->printHand();
			cout << endl;
		}
		else if(m_gamePlayers.at(m_playerIndex)->getSelectedSide() == 'R')
		{
			dominoTile playerTile;
			// get the selected tile
			playerTile = m_gamePlayers.at(m_playerIndex)->getSelectedTile();
			newGameBoard.addToRight(playerTile);
			m_gamePlayers.at(m_playerIndex)->getHand()->removeTile(playerTile);
			cout << endl;
		}
		
		cout << "After Play" << endl;
		cout << "Current Player: " << m_gamePlayers.at(m_playerIndex)->getName() << endl;
		cout << "Hand: ";
		m_gamePlayers.at(m_playerIndex)->getHand()->printHand();
		cout << endl;

		if (m_gamePlayers.at(m_playerIndex)->getName() == "Computer")
		{
			nextPlayer = m_playerIndex + 1;
		}
		else
		{
			nextPlayer = m_playerIndex - 1;
		}

		cout << "Next Player: " << m_gamePlayers.at(nextPlayer)->getName() << endl;
		cout << "Hand: ";
		m_gamePlayers.at(nextPlayer)->getHand()->printHand();
		cout << endl;

		// print the board
		cout << "Current Board:" << endl;
		newGameBoard.printToScreen();


		// get the next player
		m_playerIndex = (m_playerIndex + 1) % int(m_gamePlayers.size());
	}
}

bool gameRound::roundOver()
{
	if (m_gamePlayers.at(0)->getHand()->getHandSize() == 0)
	{
		cout << "The computer wins!\n";
		return true;
	}
	if (m_gamePlayers.at(1)->getHand()->getHandSize() == 0)
	{
		cout << m_gamePlayers.at(1)->getName() << " wins!\n";
		return true;
	}
	if (newBoneYard.getSize() == 0 && m_gamePlayers.at(0)->getPassed() == true && m_gamePlayers.at(0)->getPassed() == true)
	{
		return true;
	}
	return false;
}

bool gameRound::getSave()
{
	return m_saveGame;
}

void gameRound::setSave(char a_saveSelection)
{
	if (m_saveSelection == 'Y')
	{
		m_saveGame = true;
	}
	else
	{
		m_saveGame = false;
	}
}

void gameRound::printRoundNum()
{
	// Print the round number
	cout << "Round No.: " << m_roundNum;
	// Print an empty space
	cout << endl;
}

bool gameRound::validSave(char a_inSave)
{
	if (toupper(a_inSave) == 'Y' || toupper(a_inSave) == 'N')
	{
		return true;
	}
	return false;
}

void gameRound::askToSave()
{
	// save everything up until this point
	cout << "Would you like to save? (Y/N) ";
	//ignore all characters left in the buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> m_saveSelection;

	// while the input fails
	while (validSave(m_saveSelection) != true)
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input - Please Enter Y/N: ";
		cin >> m_saveSelection;
	}
}

