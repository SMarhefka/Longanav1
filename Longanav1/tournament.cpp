#include "stdafx.h"
#include "tournament.h"

// NOTE: THIS IS A WORKING VERSION BUT IT WILL BE CHANGED
tournament::tournament()
{
	m_validateInputs = new validateInput;
	m_playerList.clear();
	m_playerName = "";
	m_tournScore = 0;
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
	while (m_validateInputs->validUserInput(userChoice, 2) != true)
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
	}
	else
	{
		loadFromFile();
		playerHand* newHand = new playerHand(m_comHand);
		player* compPlayer = new computer(*newHand);
		compPlayer->getTestHand()->printHand();
	}
}

void tournament::loadFromFile()
{
	// initialize the incoming line
	string incomingLine;
	string userInput = getInputFile();
	ifstream inFile(userInput.c_str());

	while (!inFile.is_open())
	{
		cout << endl;
		cout << "Unable to open requested file please try again" << endl;
		cout << "Filename: ";
		// clear the error
		cin.clear();
		cin.ignore();
		cin >> userInput;
		userInput = appendTxt(userInput);
		// try to open the given file
		inFile.open(userInput.c_str());
	}

	// get every new line
	while (getline(inFile, incomingLine, '\n'))
	{
		// prints out the current line that we are on
		// cout << incomingLine << endl;
		regex searchCase("(((\\w)\\w+.*[:][^\\w]|[^\\s])(.*))");
		smatch matchGroup;
		// initialize the first element
		string firstChar = " ";
		// initialize the first group
		string groupOne = " ";
		// initialize the variable that will 
		string groupTwo = " ";
		// initialize the last group
		string groupFour = " ";
		
		// if the search pattern could be found
		if (regex_search(incomingLine, matchGroup, searchCase) == true)
		{
			firstChar = matchGroup[3];
			groupOne = matchGroup[1];
			groupTwo = matchGroup[2];
			groupFour = matchGroup[4];
		}
		
		setBooleans(firstChar);
		
		if (firstChar == "T")
		{
			m_tournScore = stoi(groupFour);
		}
		if (firstChar == "R")
		{
			m_inRoundNum = stoi(groupFour);
		}
		if (groupTwo == "Hand: ")
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
		if (firstChar == "S")
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
		if (firstChar != "L" && m_isBoard == true)
		{
			m_layoutTiles = createVector(groupOne);
			m_isBoard = false;
		}
		if (firstChar != "B" && m_isBoneYard == true)
		{
			m_boneyardTiles = createVector(groupOne);
			m_isBoneYard = false;
		}
		if (firstChar == "P")
		{
			if (groupFour.substr(0, 1) == "Y")
			{
				m_playerPassed = true;
			}
			else if (groupFour.substr(0, 1) == "N")
			{
				m_playerPassed = false;
			}
			else
			{
				m_playerPassed = NULL;
			}
		}
		if (firstChar == "N")
		{
			if (groupFour.substr(0, 1) == "C")
			{
				m_nextPlayer = 0;
			}
			else if (groupFour.substr(0, 1) == " ")
			{
				m_nextPlayer = NULL;
			}
			else
			{
				m_nextPlayer = 1;
			}
		}
	}
	inFile.close();
}

void tournament::newTournament()
{
	cout << "What is the score that you would like to play until? ";
	cin >> m_tournScore;

	while (cin.fail())
	{
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid number: ";
		cin >> m_tournScore;
	}

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

	createPlayers();

	int rndNum = 1;
	// create a newRound 
	gameRound newRound(rndNum, m_playerList, getTourScore());
	// newRound.setPlayerVec(m_playerList);
	// start a new gameRound
	newRound.setUpRound();
}

void tournament::createPlayers()
{
	// this will create a new computer object
	player* comPlayer = new computer();

	// this will be the human player
	player* humanPlayer = new human(m_playerName);

	// place the players in a vecor
	m_playerList.push_back(comPlayer);
	m_playerList.push_back(humanPlayer);
}

string tournament::getInputFile()
{
	string fileName;
	cout << "Enter name of the file that you want to load from" << endl;
	cout << "Filename: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> fileName;

	while (m_validateInputs->validFileName(fileName) != true)
	{
		cout << "Invalid Filename - Please enter a valid filename" << endl;
		cout << "Filename: ";
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> fileName;
		cout << endl;
	}
	/*----Get File Info----*/

	/*----Check for '.txt' in filename----*/
	fileName = appendTxt(fileName);
	/*----Check for '.txt' in filename----*/

	// return the fileName
	return fileName;
}

string tournament::appendTxt(string a_inFileName)
{
	string outputFile = a_inFileName;
	regex fileEnding("(.txt$)");
	/*----Check for '.txt' in filename----*/
	if (regex_match(outputFile, fileEnding) != true)
	{
		outputFile.append(".txt");
	}
	/*----Check for '.txt' in filename----*/

	return outputFile;
}

void tournament::printScore()
{
	cout << "Tournament Score: " << m_tournScore << "\n";
}

int tournament::getTourScore()
{
	return m_tournScore;
}

void tournament::setBooleans(string a_inElementOne)
{
	if (a_inElementOne == "C")
	{
		m_isComputer = true;
	}
	else if (a_inElementOne == "L")
	{
		m_isBoard = true;
	}
	else if (a_inElementOne == "B")
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

