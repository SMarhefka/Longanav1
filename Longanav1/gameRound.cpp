#include "stdafx.h"
#include "gameRound.h"
#include "tournament.h"

gameRound::gameRound()
{
}

gameRound::gameRound(bool a_isNewRound, int &a_roundNumber, vector<player*> &a_gamePlayers, int a_inTourScore)
{
	m_isNewRound = a_isNewRound;
	m_roundNumber = a_roundNumber;
	m_gamePlayers = a_gamePlayers;
	m_engineVal = getEngine();
	m_inTourScore = a_inTourScore;
	m_playerIndex = 0;
	m_newBoneYard = new boneYard();
	// create a new validate object
	m_newValidate = new validateInput();
	m_fileFunctions = new fileFunctions();
}

gameRound::gameRound(bool a_isNewRound, int &a_roundNumber, vector<player*> &a_gamePlayers, int a_inTourScore, vector<dominoTile> &a_inBoneYardTiles, short a_inNextPlayer)
{
	m_isNewRound = a_isNewRound;
	m_roundNumber = a_roundNumber;
	m_gamePlayers = a_gamePlayers;
	m_engineVal = getEngine();
	m_inTourScore = a_inTourScore;
	m_newBoneYard = new boneYard(a_inBoneYardTiles);
	m_playerIndex = a_inNextPlayer;
	// create a new validate object
	m_newValidate = new validateInput();
	m_fileFunctions = new fileFunctions();
}

void gameRound::setUpRound()
{
	if (m_isNewRound == true)
	{
		// set the engine for the corresponding round
		// getEngine();
		// distribute 8 tiles to each tile
		distributeTiles();
		// ask the user if they would like to save their game
		askToSave();
		// if the user selects to save the file then we just want
		// to print everything to the file
		if (m_saveSelection == 'Y')
		{
			executeSave(-1);
		}
		// figure out the first player
		// m_playerIndex = getFirstPlayer();
	}
	else if (m_isNewRound = true || m_playerIndex == -1)
	{
		// figure out the first player
		m_playerIndex = getFirstPlayer();
	}
	// play the round
	playRound();
}

// 9/19 10:30 implemented setEngine
int gameRound::getEngine()
{
	int a_count = 1;
	int a_engineCount = 6;
	while (a_count != m_roundNumber)
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
			m_gamePlayers.at(nextPlayerIndex)->getHand()->addTileToHand(m_newBoneYard->dealTile());
		}
	}
}

bool gameRound::engineInHands()
{
	int numHands = 0;

	// go through each hand
	for (int count = 0; count < m_gamePlayers.size(); count++)
	{
		// the player doesn't have the engine
		if (m_gamePlayers.at(count)->getHand()->hasEngine(m_engineVal) == false)
		{
			// increase numHands by 1
			numHands++;
		}
	}
	// if the number of hands (without an engine) == the number of players
	// then nobody has the engine
	if (numHands == (m_gamePlayers.size() - 1))
	{
		return false;
	}
	return true;
}

unsigned short gameRound::getFirstPlayer()
{
	/*
	while ((m_gamePlayers.at(0)->getHand()->hasEngine(m_engineVal)) == false && (m_gamePlayers.at(1)->getHand()->hasEngine(m_engineVal)) == false)
	*/
	while (engineInHands() == false)
	{
		// a_testBool = newBoneYard.isEmpty();
		if (!m_newBoneYard->isEmpty())
		{
			// give the computer a tile
			m_gamePlayers.at(0)->getHand()->addTileToHand(m_newBoneYard->dealTile());
			// m_gamePlayers.at(0)->getHand()->printHand();
			// give the player a tile
			m_gamePlayers.at(1)->getHand()->addTileToHand(m_newBoneYard->dealTile());
			// m_gamePlayers.at(1)->getHand()->printHand();
		}
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
		/*
		cout << "Before Play" << endl;
		cout << "Current Player: " << m_gamePlayers.at(m_playerIndex)->getName() << endl;
		cout << "Hand: " << endl;
		m_gamePlayers.at(m_playerIndex)->getHand()->printHand();
		cout << endl;

		int nextPlayer = (m_playerIndex + 1) % int(m_gamePlayers.size());
		
		cout << "Next Player: " << m_gamePlayers.at(nextPlayer)->getName() << endl;
		cout << "Hand: " << endl;
		m_gamePlayers.at(nextPlayer)->getHand()->printHand();
		cout << endl;
		*/

		// play the move of the current player
		m_gamePlayers.at(m_playerIndex)->playMove(newGameBoard);

		if (m_gamePlayers.at(m_playerIndex)->getPassCount() == 1)
		{
			if (!m_newBoneYard->isEmpty())
			{
				m_gamePlayers.at(m_playerIndex)->getHand()->addTileToHand(m_newBoneYard->dealTile());
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

		nextPlayer = (m_playerIndex + 1) % int(m_gamePlayers.size());

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
			executeSave(m_playerIndex);
		}

		// get the next player
		m_playerIndex = (m_playerIndex + 1) % int(m_gamePlayers.size());
	}
}

void gameRound::executeSave(short a_inSaveOption)
{
	if (a_inSaveOption < 0)
	{
		// print everything to the file
		printToFile(-1);
	}
	else
	{
		// print everything to the file
		printToFile(a_inSaveOption);
	}
	m_saveSelection = ' ';
	cout << "Saved to file successfully!" << endl;
	// wait for the system
	system("pause");
	// exit successfully
	exit(0);
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
	if (m_newBoneYard->getSize() == 0 && m_gamePlayers.at(0)->getPassed() == true && m_gamePlayers.at(1)->getPassed() == true)
	{
		return true;
	}
	return false;
}

void gameRound::printRoundNum()
{
	// Print the round number
	cout << "Round No.: " << m_roundNumber;
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
	while (m_newValidate->validSaveInput(m_saveSelection) != true)
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input - Please Enter Y/N: ";
		cin >> m_saveSelection;
	}
}

void gameRound::printToFile(short a_inPlayerIndex)
{
	short currPlayerIndex;
	short nextPlayerIndex;

	if (a_inPlayerIndex == -1)
	{
		currPlayerIndex = 0;
	}
	else
	{
		nextPlayerIndex = a_inPlayerIndex;
	}

	nextPlayerIndex = (currPlayerIndex + 1) % int(m_gamePlayers.size());
	/*--------------------print everything out to the file------------------*/

	/*-------------------Get File Info---------------------*/
	string userMessage = "Enter name of the file that you want to save to: ";
	string userFileName = m_fileFunctions->getFileFromUser(userMessage);
	ofstream outputFile(userFileName.c_str());

	// test the name of the the outputFile
	// cout << userFileName << endl;

	while (!outputFile.is_open())
	{
		cout << endl;
		cout << "Unable to open requested file. Please provide another file. " << endl;
		cout << "Filename: ";
		// clear the error
		cin.clear();
		cin.ignore();
		cin >> userFileName;
		userFileName = m_fileFunctions->appendTxt(userFileName);
		// try to open the given file
		outputFile.open(userFileName.c_str());
	}
	/*-------------------Get File Info---------------------*/

	// Print out the tournament score
	outputFile << "Tournament Score: " << m_inTourScore << "\n";
	// Print out the current round number
	outputFile << "Round No.: " << m_roundNumber << endl;
	// Create a space
	outputFile << endl;
	// print computer hand and score to file
	outputFile << "Computer: " << endl;
	outputFile << "    " << "Hand: ";
	if (currPlayerIndex == 0)
	{
		m_gamePlayers.at(currPlayerIndex)->getHand()->printHandToFile(outputFile);
	}
	else
	{
		m_gamePlayers.at(nextPlayerIndex)->getHand()->printHandToFile(outputFile);
	}
	outputFile << endl;
	// print the scores
	outputFile << "    " << "Score: ";
	if (currPlayerIndex == 0)
	{
		outputFile << m_gamePlayers.at(currPlayerIndex)->getScore();
	}
	else
	{
		outputFile << m_gamePlayers.at(nextPlayerIndex)->getScore();
	}
	// Create a space
	outputFile << endl << endl;
	// print human hand and score to file
	outputFile << "Human: " << endl;
	outputFile << "    " << "Hand: ";
	if (currPlayerIndex == 0)
	{
		m_gamePlayers.at(nextPlayerIndex)->getHand()->printHandToFile(outputFile);
	}
	else
	{
		m_gamePlayers.at(currPlayerIndex)->getHand()->printHandToFile(outputFile);
	}
	// Create a space
	outputFile << endl;
	outputFile << "    " << "Score: ";
	if (currPlayerIndex == 0)
	{
		outputFile << m_gamePlayers.at(nextPlayerIndex)->getScore();
	}
	else
	{
		outputFile << m_gamePlayers.at(currPlayerIndex)->getScore();
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
	m_newBoneYard->printBoneYard(outputFile);
	// Create a space
	outputFile << endl << endl;
	// print if the previous player passed
	outputFile << "Previous Player Passed: ";
	// if the current player is the computer then the previous
	// player is the human.  With the way my get passed works
	// it returns if the previous player has passed 
	if (a_inPlayerIndex == -1)
	{
		outputFile << " ";
	}
	else
	{
		if (m_gamePlayers.at(currPlayerIndex)->getPassed() == true)
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
		outputFile << " ";
	}
	else
	{
		outputFile << m_gamePlayers.at(nextPlayerIndex)->getName() << endl;
	}
	outputFile.close();
	/*---------------print everything out to the file----------------*/
}

gameRound::~gameRound()
{
	delete m_newBoneYard;
	delete m_newValidate;
}
