

#include "stdafx.h"
#include "tournament.h"

// NOTE: THIS IS A WORKING VERSION BUT IT WILL BE CHANGED
tournament::tournament()
{
	m_validateInputs = new validateInput;
	m_fileFunctions = new fileFunctions;

	m_playerList.clear();

	m_playerName = "";
	m_tournScore = 0;
	m_roundNum = 0;
}

tournament::~tournament()
{
	m_playerList.clear();
}

void tournament::loadUserOptions()
{
	string userChoice;

	cout << "|***************************************************|" << endl;
	cout << "|                    Longana Game 2017              |" << endl;
	cout << "|***************************************************|" << endl;
	cout << endl;

	cout << "Please choose from one of the following options:" << endl;
	cout << "1. Start New Game" << endl;
	cout << "2. Load Previous Game" << endl;
	cout << "User Selection: ";
	cin >> userChoice;

	userChoice = userChoice.substr(0, 1);
	
	// validate the input
	while (m_validateInputs->validUserSelection(userChoice, 2) != true)
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore();
		cout << endl;
		cout << "Invalid Input - Please select one of the following:" << endl;
		cout << "1. Start New Game" << endl;
		cout << "2. Load Previous Game" << endl;
		cout << "User Selection: ";
		cin >> userChoice;	
		// Get just the firt value
		userChoice = userChoice.substr(0, 1);
	}
	cout << endl;

	if (stoi(userChoice) == 1)
	{
		newTournament();
		createPlayers(true);
		playTournament(true);
	}
	else
	{
		// load and gather all of the information from the file
		loadFromFile();
		// create players from the file information
		createPlayers(false);
		playTournament(false);
	}
	
}

void tournament::loadFromFile()
{
	// initialize the incoming line
	string incomingLine;
	string outputMessage = "Enter name of the file that you want to load from";
	string userInput = m_fileFunctions->getFile(outputMessage);
	ifstream inFile(userInput.c_str());
	int lineWithText = 0;

	while (!inFile.is_open())
	{
		cout << endl;
		cout << "Unable to open requested file please try again" << endl;
		cout << "Filename: ";
		// clear the error
		cin.clear();
		cin.ignore();
		cin >> userInput;
		userInput = m_fileFunctions->appendTxt(userInput);
		// try to open the given file
		inFile.open(userInput.c_str());
	}

	// get every new line
	while (getline(inFile, incomingLine, '\n'))
	{
		// prints out the current line that we are on
		// cout << incomingLine << endl;
		// going to change to: 
		regex searchCase("((\\w)\\w+) ?(.*)[.:]+ ?(([A-Z])?.*)|([\\w\\d-\\d]+?.*)");
		smatch matchGroup;
		// initialize the first group which is: ((\w)\w+)
		string groupOne = " ";
		// initialize the second group which is: (\\w)
		string groupTwo = " ";
		// initialize the third group which is: (.*)
		string groupThree = " ";
		// initialize the fourth group which is: (([A-Z])?.*)
		string groupFour = " ";
		// initialize the fifth group which is: ([A-Z])
		string groupFive = " ";
		// initialize the last group which is: ([\w\d-\d]+?.*)
		string groupSix = " ";
		
		// if the search pattern could be found
		if (regex_search(incomingLine, matchGroup, searchCase) == true)
		{
			lineWithText++;

			groupOne = matchGroup[1];
			groupTwo = matchGroup[2];
			groupThree = matchGroup[3];
			groupFour = matchGroup[4];
			groupFive = matchGroup[5];
			groupSix = matchGroup[6];
			
			// Placed for testing purposes
			cout << "Line " << lineWithText << ": " << incomingLine << endl;

			setBooleans(groupOne);

			if (groupTwo == "T" && groupThree == "Score")
			{
				m_tournScore = stoi(groupFour);
			}
			if (groupTwo == "R" && groupThree == "No.")
			{
				m_roundNum = stoi(groupFour);
			}
			if (lineWithText == 6)
			{
				m_playerName = groupOne;
			}
			if (groupOne == "Hand")
			{	
				if(m_isComputer == true)
				{
					m_comHand = createVector(groupFour);
				}
				else
				{
					m_playerHand = createVector(groupFour);
				}
			}
			if (groupOne == "Score")
			{
				if (m_isComputer == true)
				{
					m_computerScore = stoi(groupFour);
					m_isComputer = false;
				}
				else
				{
					m_playerScore = stoi(groupFour);
				}
			}
			if (lineWithText == 10 && m_isBoard == true)
			{
				// these will be the tiles stored into the layout
				m_layoutTiles = createVector(groupSix);
				m_isBoard = false;
			}
			if (lineWithText == 12 && m_isBoneYard == true)
			{
				// these will be the domino tiles that will be used for the boneYard
				m_boneyardTiles = createVector(groupSix);
				m_isBoneYard = false;
			}
			if (groupTwo == "P" && groupOne == "Previous")
			{
				m_playerPassed = groupFive;
			}
			if (groupTwo == "N" && groupOne == "Next")
			{
				if (groupFive == " ")
				{
					m_nextPlayer = -1;
				}
				else if (groupFive == "C")
				{
					m_nextPlayer = 0;
				}
				else
				{
					m_nextPlayer = 1;
				}
			}
		}
	}
	inFile.close();
}

void tournament::newTournament()
{
	string userInput;
	cout << "What is the score that you would like to play until? ";
	cin >> userInput;

	while (m_validateInputs->validInputNumber(userInput) != true)
	{
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid number: ";
		cin >> userInput;
	}
	m_tournScore = stoi(userInput);

	cout << "What name would you like to use? ";
	cin >> m_playerName;
	while (cin.fail())
	{
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid string: ";
		cin >> m_playerName;
	}
	cout << endl;
}

void tournament::createPlayers(bool a_isNewGame)
{
	if (a_isNewGame == true)
	{
		// this will create a new computer object
		player* comPlayer = new computer();
		// this will be the human player
		player* humanPlayer = new human(m_playerName);

		// place the players in a vecor
		m_playerList.push_back(comPlayer);
		m_playerList.push_back(humanPlayer);
	}
	else
	{

		// creates a pointer to a new hand
		playerHand* tempHand;
		bool tempPassed = false;
		tempPassed = getPassed(m_nextPlayer, m_playerPassed, 0);
		// create a new hand with the computer tiles
		tempHand = new playerHand(m_comHand);
		// create a new player with the particular hand
		player* loadComputer = new computer(*tempHand, m_computerScore, tempPassed, !tempPassed);
		// delete the temporary hand
		delete tempHand;

		// create a new hand with the player's tiles
		tempHand = new playerHand(m_playerHand);

		// create a new player with the particular hand
		player* loadPlayer = new human(*tempHand, m_playerScore, tempPassed, !tempPassed, m_playerName);
		delete tempHand;

		// place the computer player into the playerList vector
		m_playerList.push_back(loadComputer);
		// place the human player into the playerList vector
		m_playerList.push_back(loadPlayer);
	}

}

bool tournament::getPassed(short a_inPlyrIndex, string m_playerPassed, short a_currIndex)
{
	short previousPlayer;
	if (m_playerPassed == "Y" && a_inPlyrIndex != -1)
	{
		previousPlayer = (a_inPlyrIndex + 1) % 2;
		if (previousPlayer == a_currIndex)
		{
			return true;
		}
	}
	return false;
}

void tournament::playTournament(bool a_isNewRound)
{
	while (tournamentOver() != true)
	{
		if (a_isNewRound == true)
		{
			// increase the round number by 1
			m_roundNum++;
			// create a new round
			newRound = new gameRound(a_isNewRound, m_roundNum, m_playerList, m_tournScore);
		}
		else
		{
			// create a new round with the prepared values
			newRound = new gameRound(a_isNewRound, m_roundNum, m_playerList, m_tournScore, m_boneyardTiles, m_nextPlayer);
		}
		// set up the current round
		newRound->setUpRound();
		// reset the boolean for new round so that a new round can be created
		a_isNewRound = true;
	}
}


void tournament::printScore()
{
	cout << "Tournament Score: " << m_tournScore << "\n";
}

void tournament::setBooleans(string a_inGroupOne)
{
	if (a_inGroupOne == "Computer")
	{
		m_isComputer = true;
	}
	else if (a_inGroupOne == "Layout")
	{
		m_isBoard = true;
	}
	else if (a_inGroupOne == "Boneyard")
	{
		m_isBoneYard = true;
	}
}

vector<dominoTile> tournament::createVector(string a_inLine)
{
	vector<dominoTile> outputVector;

	// The pattern to look for
	regex searchPatten("([[:d:]])-([[:d:]])");
	// Go through the line
	for (sregex_iterator it = sregex_iterator(a_inLine.begin(), a_inLine.end(), searchPatten);
		it != sregex_iterator(); ++it)
	{
		smatch toMatch = *it;
		if (toMatch[1].matched && toMatch[2].matched)
		{
			//cout << "    " << a_matched[1] << "-" << a_matched[2] << endl;
			// Create a new tile
			dominoTile* newTile = new dominoTile(stoi(toMatch[1]), stoi(toMatch[2]));
			outputVector.push_back(*newTile);
			delete newTile;
		}
	}
	// return the output vector
	return outputVector;
}

bool tournament::tournamentOver()
{
	for (int count = 0; count < m_playerList.size(); count++)
	{
		if (m_playerList.at(count)->getScore() >= m_tournScore)
		{
			return true;
		}
	}
	return false;
}
