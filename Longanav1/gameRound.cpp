#include "stdafx.h"
#include "gameRound.h"
#include "tournament.h"

gameRound::gameRound()
{
}

gameRound::gameRound(int &a_roundNumber, vector<player*> &a_gamePlayers, int a_inTouScore)
{
	newBoneYard = new boneYard();
	m_roundNum = a_roundNumber;
	m_gamePlayers = a_gamePlayers;
	m_engineVal = getEngine();
	m_inTourScore = a_inTouScore;
	m_playerIndex = 0;
}

void gameRound::setUpRound()
{
	// set the engine for the corresponding round
	getEngine();
	// distribute 8 tiles to each tile
	distributeTiles();
	// ask the user if they would like to save their game
	askToSave();
	// if the user selects to save the file then we just want
	// to print everything to the file
	if (m_saveSelection == 'Y')
	{
		// print everything to the file
		printToFile(-1);
		m_saveSelection = ' ';
		cout << "Saved File Successfully!" << endl;
		// wait for the system
		system("pause");
		// exit successfully
		exit(0);
	}

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
			m_gamePlayers.at(nextPlayerIndex)->getHand()->addTileToHand(newBoneYard->dealTile());
		}
	}
}

unsigned short gameRound::getFirstPlayer()
{
	while ((m_gamePlayers.at(0)->getHand()->hasEngine(m_engineVal)) == false && 
		(m_gamePlayers.at(1)->getHand()->hasEngine(m_engineVal)) == false)
	{
		// a_testBool = newBoneYard.isEmpty();
		if(!newBoneYard->isEmpty())
		// give the computer a tile
		m_gamePlayers.at(0)->getHand()->addTileToHand(newBoneYard->dealTile());
		// m_gamePlayers.at(0)->getHand()->printHand();
		// give the player a tile
		m_gamePlayers.at(1)->getHand()->addTileToHand(newBoneYard->dealTile());
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
		cout << "Hand: " << endl;
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
		cout << "Hand: " << endl;
		m_gamePlayers.at(nextPlayer)->getHand()->printHand();
		cout << endl;

		// play the move of the current player
		m_gamePlayers.at(m_playerIndex)->playMove(newGameBoard);

		if (m_gamePlayers.at(m_playerIndex)->getPassCount() == 1)
		{
			if (!newBoneYard->isEmpty())
			{
				m_gamePlayers.at(m_playerIndex)->getHand()->addTileToHand(newBoneYard->dealTile());
				m_gamePlayers.at(m_playerIndex)->playMove(newGameBoard);
			}
			else
			{
				cout << "The Boneyard is empty.  Going to the next player\n";
			}
		}
		if (m_gamePlayers.at(m_playerIndex)->getSelectedSide() == 'L')
		{
			// create a new tile and set it to the user selection
			dominoTile playerTile = m_gamePlayers.at(m_playerIndex)->getSelectedTile();
			newGameBoard.addToLeft(playerTile);
			m_gamePlayers.at(m_playerIndex)->getHand()->removeTile(playerTile);
			// m_gamePlayers.at(m_playerIndex)->getHand()->printHand();
			cout << endl;
		}
		else if(m_gamePlayers.at(m_playerIndex)->getSelectedSide() == 'R')
		{
			// create a new tile and set it to the user selection
			dominoTile playerTile = m_gamePlayers.at(m_playerIndex)->getSelectedTile();
			newGameBoard.addToRight(playerTile);
			m_gamePlayers.at(m_playerIndex)->getHand()->removeTile(playerTile);
			cout << endl;
		}
		/*
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
		*/
		// print the board
		cout << "Current Board:" << endl;
		newGameBoard.printToScreen();

		// ask the user if they would like to save their game
		askToSave();
		// if the user selects to save the file then we just want
		// to print everything to the file
		if (m_saveSelection == 'Y')
		{
			// print everything to the file
			printToFile(m_playerIndex);
			m_saveSelection = ' ';
			cout << "Saved to file successfully!" << endl;
			// wait for the system
			system("pause");
			// exit successfully
			exit(0);
		}

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
	if (newBoneYard->getSize() == 0 && m_gamePlayers.at(0)->getPassed() == true && m_gamePlayers.at(0)->getPassed() == true)
	{
		return true;
	}
	return false;
}

void gameRound::printRoundNum()
{
	// Print the round number
	cout << "Round No.: " << m_roundNum;
	// Print an empty space
	cout << endl;
}

void gameRound::askToSave()
{
	// save everything up until this point
	cout << "Would you like to save? (Y/N) ";
	//ignore all characters left in the buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> m_saveSelection;

	// while the input fails
	while (validSaveInput(m_saveSelection) != true)
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input - Please Enter Y/N: ";
		cin >> m_saveSelection;
	}
}

bool gameRound::validSaveInput(char a_inSave)
{
	if (toupper(a_inSave) == 'Y' || toupper(a_inSave) == 'N')
	{
		return true;
	}
	return false;
}

string gameRound::getOutputFile()
{
	string fileName;
	cout << "Enter name of the file that you want to save to: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> fileName;

	while (cin.fail())
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input - Please Enter a valid filename: ";
		cin >> fileName;
	}
	/*----Get File Info----*/

	/*----Check for '.txt' in filename----*/
	int findPos = int(fileName.find(".txt"));
	if (findPos < 0)
	{
		fileName.append(".txt");
	}
	/*----Check for '.txt' in filename----*/

	// return the fileName
	return fileName;
}

void gameRound::printToFile(int a_inPlayerIndex)
{
	int currentPlayer;
	int nextPlayer;

	if (a_inPlayerIndex == -1)
	{
		currentPlayer = 0;
		nextPlayer = (currentPlayer + 1) % int(m_gamePlayers.size());
	}
	else
	{
		currentPlayer = a_inPlayerIndex;
		nextPlayer = (a_inPlayerIndex + 1) % int(m_gamePlayers.size());
	}
	
	/*----------figure out if the current player is the computer---------------*/
	bool currPlyrCom;
	if (m_gamePlayers.at(currentPlayer)->getName() == "Computer")
	{
		currPlyrCom = true;
	}
	else
	{
		currPlyrCom = false;
	}
	/*----------figure out if the current player is the computer---------------*/

	/*--------------------print everything out to the file------------------*/
	/*----Get File Info----*/
	string userFileName = getOutputFile();
	// test the name of the the outputFile
	cout << userFileName << endl;

	ofstream outputFile(userFileName.c_str());

	if (!outputFile.fail())
	{
		// Print out the tournament score
		outputFile << "Tournament Score: " << m_inTourScore << "\n";
		// Print out the current round number
		outputFile << "Round No.: " << m_roundNum << endl;
		// Create a space
		outputFile << endl;
		// print computer hand and score to file
		outputFile << "Computer: " << endl;
		outputFile << "    " << "Hand: ";
		if (currPlyrCom == true)
		{
			m_gamePlayers.at(currentPlayer)->getHand()->printHandToFile(outputFile);
		}
		else
		{
			m_gamePlayers.at(nextPlayer)->getHand()->printHandToFile(outputFile);
		}
		outputFile << endl;
		// print the scores
		outputFile << "    " << "Score: ";
		if (currPlyrCom == true)
		{
			outputFile << m_gamePlayers.at(currentPlayer)->getScore();
		}
		else
		{
			outputFile << m_gamePlayers.at(nextPlayer)->getScore();
		}
		// Create a space
		outputFile << endl << endl;
		// print human hand and score to file
		outputFile << "Human: " << endl;
		outputFile << "    " << "Hand: ";
		if (currPlyrCom == true)
		{
			m_gamePlayers.at(nextPlayer)->getHand()->printHandToFile(outputFile);
		}
		else
		{
			m_gamePlayers.at(currentPlayer)->getHand()->printHandToFile(outputFile);
		}
		// Create a space
		outputFile << endl;
		outputFile << "    " << "Score: ";
		if (currPlyrCom == true)
		{
			outputFile << m_gamePlayers.at(currentPlayer)->getScore();
		}
		else
		{
			outputFile << m_gamePlayers.at(nextPlayer)->getScore();
		}
		// Create a space
		outputFile << endl << endl;
		// print the layout to the file
		outputFile << "Layout: " << endl;
		newGameBoard.printBoardToFile(outputFile);
		// Create a space
		outputFile << endl << endl;
		// print the boneyard to file
		outputFile << "Boneyard: " << endl;
		// print the boneyard
		newBoneYard->printBoneYard(outputFile);
		// Create a space
		outputFile << endl << endl;
		// print if the previous player passed
		outputFile << "Previous Player Passed: ";
		// if the current player is the computer then the previous
		// player is the human.  With the way my get passed works
		// it returns if the previous player has passed 
		if (a_inPlayerIndex == -1)
		{
			outputFile << "";
		}
		else
		{
			if (m_gamePlayers.at(currentPlayer)->getPassed() == true)
			{
				outputFile << "Yes";
			}
			else
			{
				outputFile << "No";
			}
		}
		// Create a space
		outputFile << endl << endl;
		// print the next player
		outputFile << "Next Player: ";
		if (a_inPlayerIndex == -1)
		{
			outputFile << "";
		}
		else
		{
			outputFile << m_gamePlayers.at(nextPlayer)->getName() << endl;
		}
		outputFile.close();
	}
	else
	{
		cout << "Unable to open file\n";
	}
	/*----------print everything out to the file---------------*/
}

gameRound::~gameRound()
{
	delete newBoneYard;
}
