#include "stdafx.h"
#include "tournament.h"

// NOTE: THIS IS A WORKING VERSION
tournament::tournament()
{
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
	int userChoice;

	cout << "|***************************************************|" << endl;
	cout << "|                    Longana Game 2017              |" << endl;
	cout << "|***************************************************|" << endl;
	cout << endl;

	cout << "Please choose from one of the following options:" << endl;
	cout << "1. Start New Game" << endl;
	cout << "2. Load Previous Game" << endl;
	cout << "User Selection: ";
	cin >> userChoice;

	// validate the input
	while (userChoice < 1 || userChoice > 2)
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
	}
	cout << endl;

	m_tempUserChoice = userChoice;
	if (m_tempUserChoice == 1)
	{
		newTournament();
	}
	else
	{
		loadFromFile();
	}
}

void tournament::loadFromFile()
{
	// initialize the incoming line
	string incomingLine;
	string userInput;
	
	userInput = getInputFile();
	
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

		/*----Check for '.txt' in filename----*/
		int findPos = int(userInput.find(".txt"));
		if (findPos < 0)
		{
			userInput.append(".txt");
		}
		/*----Check for '.txt' in filename----*/
		cout << endl;
		// OPENED THE FILE AT THIS POINT
		// CAN'T FORGET TO CLOSE IT.
		inFile.open(userInput.c_str());
	}

	// initialize the linecount to 0
	int lineCount = 0;
	// initialize the search varaible to false
	bool searchFound = false;
	// get every new line
	while (getline(inFile, incomingLine, '\n'))
	{
		// increase the linecount by 1
		lineCount++;
		// prints out the current line that we are on
		cout << incomingLine << endl;

		// This will search for any two words with either a . or a :
		// used for tournamennt score and round number
		regex matchCase("([[:w:]])([[:w:]]+ )([[:w:]]+.: )([[:d:]]+)");
		smatch matchString;
		// sets if the pattern could be found
		searchFound = regex_search(incomingLine, matchString, matchCase);

		// ((\w)\w+)(.*):\W
		// group 1 = ((\w)\w+)
		// group 2 = (\w)
		// group 3 = (.*)
		if (searchFound == true)
		{
			if (matchString[1] == "T")
			{
				m_tournScore = stoi(matchString[4]);
			}
			if (matchString[3] == "No.: ")
			{
				m_inRoundNum = stoi(matchString[4]);
			}
		}
		else
		{
			// otherwise the pattern to look out for is: ([[:w:]]+:)"
			// this pattern is going to be used to find all of the other
			// variables that we need
			regex matchCase("([[:w:]])([[:w:]]+:)");
			smatch matchString;
			searchFound = regex_search(incomingLine, matchString, matchCase);

			/*-------------------------Retrieves Computer Hand and Score----------------------*/
			// checks to see if the current line says computer
			if (searchFound == true && matchString[1] == "C")
			{
				m_isComputer = true;
			}
			// if it is the computer and it is the hand
			if (m_isComputer == true && matchString[1] == "H")
			{
				regex tilePattern("([[:d:]])-([[:d:]])");
				for (sregex_iterator it = sregex_iterator(incomingLine.begin(), incomingLine.end(), tilePattern);
					it != sregex_iterator(); ++it)
				{
					smatch a_matched = *it;
					if (a_matched[1].matched && a_matched[2].matched)
					{
						//cout << "    " << a_matched[1] << "-" << a_matched[2] << endl;
						dominoTile * newTile = new dominoTile(stoi(a_matched[1]), stoi(a_matched[2]));
						m_comHand.push_back(*newTile);
						delete newTile;
					}
				}
			}
			else if (m_isComputer == true && matchString[1] == "S")
			{
				regex newMatch("([[:w:]]+.: )([[:d:]]+)");
				smatch newString;
				bool newSearch = regex_search(incomingLine, newString, newMatch);
				if (newSearch == true)
				{
					m_computerScore = stoi(newString[2]);
				}
			}
			/*-------------------------Retrieves Computer Hand and Score----------------------*/

			/*-------------------------Retrieves Human Hand and Score----------------------*/
			string humanString = matchString[1].str() + matchString[2].str();
			// checks to see if the current line says Human
			if (searchFound == true && humanString == "Human:" || humanString != "Computer:")
			{
				m_isHuman = true;
				if (humanString != "Human:")
				{
					regex newPattern("([[:w:]]+)");
					smatch newResult;
					regex_search(incomingLine, newResult, newPattern);
					m_playerName = (newResult[1]);
				}
			}
			// if it is the computer and it is the hand
			if (m_isHuman == true && matchString[1] == "H")
			{
				regex tilePattern("([[:d:]])-([[:d:]])");
				for (sregex_iterator it = sregex_iterator(incomingLine.begin(), incomingLine.end(), tilePattern);
					it != sregex_iterator(); ++it)
				{
					smatch a_matched = *it;
					if (a_matched[1].matched && a_matched[2].matched)
					{
						//cout << "    " << a_matched[1] << "-" << a_matched[2] << endl;
						dominoTile * newTile = new dominoTile(stoi(a_matched[1]), stoi(a_matched[2]));
						m_playerHand.push_back(*newTile);
						delete newTile;
					}
				}
			}
			else if (m_isHuman == true && matchString[1] == "S")
			{
				regex newMatch("([[:w:]]+.: )([[:d:]]+)");
				smatch newString;
				bool newSearch = regex_search(incomingLine, newString, newMatch);
				if (newSearch == true)
				{
					m_playerScore = stoi(newString[2]);
				}
			}
			/*-------------------------Retrieves Human Hand and Score----------------------*/

			/*--------------------------Retrieve the board from file--------------------------------*/
			// checks to see if the current line says Layout
			if (searchFound == true && matchString[1] == "L")
			{
				m_isBoard = true;
			}

			if (m_isBoard == true)
			{
				regex tilePattern("([[:d:]])-([[:d:]])");
				for (sregex_iterator it = sregex_iterator(incomingLine.begin(), incomingLine.end(), tilePattern);
					it != sregex_iterator(); ++it)
				{
					smatch a_matched = *it;
					if (a_matched[1].matched && a_matched[2].matched)
					{
						//cout << "    " << a_matched[1] << "-" << a_matched[2] << endl;
						dominoTile * newTile = new dominoTile(stoi(a_matched[1]), stoi(a_matched[2]));
						m_layoutTiles.push_back(*newTile);
						delete newTile;
					}
				}
			}
			/*--------------------------Retrieve the board--------------------------------*/

			/*--------------------------Retrieves the boneYard--------------------------------*/
			// checks to see if the current line says Layout
			if (searchFound == true && matchString[1] == "B")
			{
				m_isBoneYard = true;
			}

			if (m_isBoneYard == true)
			{
				regex tilePattern("([[:d:]])-([[:d:]])");
				for (sregex_iterator it = sregex_iterator(incomingLine.begin(), incomingLine.end(), tilePattern);
					it != sregex_iterator(); ++it)
				{
					smatch a_matched = *it;
					if (a_matched[1].matched && a_matched[2].matched)
					{
						//cout << "    " << a_matched[1] << "-" << a_matched[2] << endl;
						dominoTile * newTile = new dominoTile(stoi(a_matched[1]), stoi(a_matched[2]));
						m_boneyardTiles.push_back(*newTile);
						delete newTile;
					}
				}
			}
			/*--------------------------Retrieves the boneYard--------------------------------*/

			/*--------------------------Previous Player Passed--------------------------------*/
			if (searchFound == true && matchString[1] == "P")
			{
				regex passedCase("([[:w:]]+: )([[:w:]]");
				smatch matchElement;
				regex_search(incomingLine, matchElement, passedCase);
				if (matchElement[2] == "N")
				{
					m_playerPassed = false;
				}
				else if (matchElement[2] == "Y")
				{
					m_playerPassed = true;
				}
				else
				{
					cout << "Player Passed Error" << endl;
				}
			}
			/*--------------------------Previous Player Passed--------------------------------*/

			/*--------------------------Get the Next Player--------------------------------*/
			if (searchFound == true && matchString[1] == "N")
			{
				regex passedCase("([[:w:]]+: )([[:w:]]");
				smatch matchElement;
				regex_search(incomingLine, matchElement, passedCase);
				if (matchElement[2] == "C")
				{
					m_nextPlayer = 0;
				}
				else if (matchElement[2] == "H" || m_playerName.substr(0, 1) == matchElement[2])
				{
					m_nextPlayer = 1;
				}
				else
				{
					cout << "Next Player Error" << endl;
				}
			}
			/*--------------------------Previous Player Passed--------------------------------*/

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
	while (cin.fail())
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
	int findPos = int(fileName.find(".txt"));
	if (findPos < 0)
	{
		fileName.append(".txt");
	}
	/*----Check for '.txt' in filename----*/

	// return the fileName
	return fileName;
}

void tournament::printScore()
{
	cout << "Tournament Score: " << m_tournScore << "\n";
}

int tournament::getTourScore()
{
	return m_tournScore;
}

