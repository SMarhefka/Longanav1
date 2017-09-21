#include "stdafx.h"
#include "human.h"

// this is the default constructor
human::human()
{
	//cout << "I'm creating a human\n";
	//humanHand = new playerHand;
}

human::human(string name)
{
	// cout << "I'm creating a human with a name: " << playerType << "\n";
	m_playerName = name;
}

human::~human()
{
}

bool human::playMove(gameBoard a_inGameBoard)
{
	gameBoard thisGameBoard = a_inGameBoard;
	//cout << "I'm playing as: " << m_playerName << " and I'm in the human::playMove() function!\n";
	// display the hand of the user
	getHand();
	// display user options
	displayInitialOptions();
	
	executeOptions(thisGameBoard);
	// returns true or false based
	// on if the move can be made succesfully
	return true;
}

void human::displayInitialOptions()
{
	int optionCount = 1;
	string userChoice;

	cout << "Please Select and Option: " << endl;
	cout << optionCount << " - Place a tile\n";
	optionCount++;
	cout << optionCount << " - Pass my turn\n";
	optionCount++;
	cout << optionCount << " - Get help\n";
	optionCount++;
	cout << optionCount << " - Exit Program (without saving)\n";
	// take in the userInput
	cout << "User Selection: ";
	cin >> userChoice;

	// validate the input
	while (m_checkInput.validateSelection(userChoice, optionCount) == false)
	{
		cin.clear();
		cin.ignore();
		optionCount = 1;
		cout << "Please choose from one of the following options: " << endl;
		cout << optionCount << " - Place a tile\n";
		optionCount++;
		cout << optionCount << " - Pass my turn\n";
		optionCount++;
		cout << optionCount << " - Get help\n";
		optionCount++;
		cout << optionCount << " - Quit Program (without saving)\n";
		// take in the userInput
		cout << "User Selection: ";
		cin >> userChoice;
	}
	m_userChoice = atoi(userChoice.c_str());
}

void human::displayTileOptions(int a_optionCount)
{
	// the user will also need to be able to see their hand
	m_currentHand.printHand();
	cout << setw(2) << a_optionCount;
	// this will display a number under each potential option
	for (a_optionCount = 2; a_optionCount < m_currentHand.getHandSize() + 1;
		a_optionCount++)
	{
		cout << setw(4) << a_optionCount;
	}
	cout << endl;
}

void human::executeOptions(gameBoard a_inGameBoard)
{
	gameBoard thisGameBoard = a_inGameBoard;
	switch (m_userChoice)
	{
	case 1:
		// call function to allow the user to place a tile
		selectTile(thisGameBoard);
		break;
	case 2:
		// if this function is called we need to check and
		// make sure that the user cannot actually make a move

	case 3:
		// This simply calls the help function from the player class
		// the help function will need the players hand in order to 
		// work
	case 4:
		exit(0);
	default:
		break;
	}
}

void human::selectTile(gameBoard a_inGameBoard)
{
	gameBoard currentBoard = a_inGameBoard;
	string userChoice;
	int optionCount = 1;
	// want to print the board for the player
	// to see their options
	currentBoard.printToScreen();
	displayTileOptions(optionCount);
	// take in the userInput
	cout << "User Selection: ";
	cin >> userChoice;
	// check to make sure that the user has entered a valid number
	// while the user doesn't provide a valid input
	while (m_checkInput.validateSelection(userChoice, optionCount) == false)
	{
		// clear the input
		cin.clear();
		cin.ignore();
		// print an error message
		cout << "Inccorect input - Please enter a value between 1 and " 
			<< m_currentHand.getHandSize() + 1 << endl;
		currentBoard.printToScreen();
		displayTileOptions(optionCount);
		// take in the userInput
		cout << "User Selection: ";
		cin >> userChoice;
	}
	// once we recieve valid input from the user then we need to make sure
	// that user can make a move with their tile

	// if the user selects a double or if the computer passed it's turn
	// then you need to check both sides of the board
}


playerHand* human::getHand()
{
	// cout << "Playing as: " << playerType << " and I am in the human::getHand()\n";
	return &m_currentHand;
}
