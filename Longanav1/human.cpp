#include "stdafx.h"
#include "human.h"

// this is the default constructor
human::human()
{
	//cout << "I'm creating a human\n";
	m_playerName = "Human";
	m_playerScore = 0;
	m_tempUserChoice = 0;
	m_enginePosition = 0;
	m_tileChoice = 0;
	m_exeSucc = false;
}

human::human(string a_inName)
{
	// cout << "I'm creating a human with a name: " << playerType << "\n";
	m_playerName = a_inName;
	m_playerScore = 0;
	m_tempUserChoice = 0;
	m_enginePosition = 0;
	m_tileChoice = 0;
	m_exeSucc = false;
}

human::~human()
{
}

void human::playMove(gameBoard &a_inGameBoard)
{
	gameBoard thisGameBoard = a_inGameBoard;
	// if the hand has the engine
	if (m_currentHand.hasEngine(m_engineValue) == true)
	{
		findEnginePosition();
		m_validMove = true;
	}
	// check for a valid move
	else if (checkMove(thisGameBoard) == true)
	{
		m_validMove = true;
	}
	// Otherwise there is no valid move
	else
	{
		m_validMove = false;
	}
	// display the first set of user options
	displayOptions1(thisGameBoard);
	// execute the possible options
	executeOptions(thisGameBoard);
	// while the execution is false
	while (m_exeSucc == false)
	{
		displayOptions1(thisGameBoard);
		executeOptions(thisGameBoard);
	}
	// if there was a valid move
	if (m_validMove == true)
	{
		// at this point the execution was successfull
		// now we just have to add the tile to the board
		// set the userOptions
		setUserOptions(m_userSelection, m_whichSide);
		// because the execution was successful I can also set
		// the passed variable to false
		m_HumanPass = false;
		// I also want to reset the pass count
		m_passCount = 0;
	}
}

void human::printFirstOptions()
{
	m_tempUserChoice = 1;
	cout << m_tempUserChoice << " - Place Tile\n";
	m_tempUserChoice++;
	cout << m_tempUserChoice << " - Pass Turn\n";
	m_tempUserChoice++;
	cout << m_tempUserChoice << " - Get Help\n";
	// take in the userInput
	cout << "User Selection: ";
}

void human::printLeftRight()
{
	cout << "\nNOTE: Press B To Go To The Previous Menu \n";
	cout << "Which Side - Left/Right: ";
	//ignore all characters left in the buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> m_whichSide;

	// while the input fails
	while (m_checkInput->validSideInput(m_whichSide) != true)
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nNOTE: Press B To Go To The Previous Menu \n";
		cout << "Please Enter - Left or Right: ";
		cin >> m_whichSide;
	}
	// set the side that the user selected to uppercase
	m_whichSide = toupper(m_whichSide);
}

void human::displayOptions1(gameBoard &a_inGameBoard)
{
	int userChoice;
	gameBoard thisGameBoard = a_inGameBoard;

	// print the board to the screen
	thisGameBoard.printToScreen();
	// print the user hand
	displayTiles();

	cout << "\nPlease Select an Option:\n";
	printFirstOptions();

	//ignore all characters left in the buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
 	cin >> userChoice;

	// validate the input
	while (userChoice < 1 || userChoice > m_tempUserChoice)
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nPlease Select a Valid Option\n";
		printFirstOptions();
		cin >> userChoice;
		cout << endl;
	}
	m_tempUserChoice = userChoice;
}

void human::executeOptions(gameBoard &a_inGameBoard)
{
	gameBoard thisGameBoard = a_inGameBoard;
	switch (m_tempUserChoice)
	{
	case 1:
		// call function to allow the user to pick a tile
		// that will be placed on the board
		displayOptions2(thisGameBoard);
		// if the user selects 0 
		if (m_tileChoice == 0)
		{
			// this will go back to the main set of options
			m_exeSucc = false;
			break;
		}

		// this checks that the tile and side that the user 
		// selected is valid
		if (m_currentHand.hasEngine(m_engineValue) == true)
		{
			dominoTile tempTile;
			tempTile = m_currentHand.getTilesAt(m_tileChoice - 1);

			while (m_checkInput->validEnginePlacement(tempTile, m_engineValue) != true || m_whichSide != 'L')
			{
				if (m_whichSide != 'L')
				{
					cout << endl << "Invalid Side Selected\n";
				}
				else
				{
					cout << endl << "Engine not Selected\n";
				}

				displayOptions2(thisGameBoard);
				// this will go back to the main set of options
				if (m_tileChoice > 0)
				{
					tempTile = m_currentHand.getTilesAt(m_tileChoice - 1);
				}
				else
				{
					// break out of the loop
					break;
				}
			}
		}
		else if(m_currentHand.hasEngine(m_engineValue) != true)
		{
			dominoTile tempTile;
			tempTile = m_currentHand.getTilesAt(m_tileChoice - 1);
			
			while (checkTileSelection(thisGameBoard, tempTile) != true
				|| m_checkInput->validSideCheck(tempTile, m_whichSide, m_playerName, m_ComputerPass) != true)
			{
				if (checkTileSelection(thisGameBoard, tempTile) != true)
				{
					cout << "The tile you chose was invalid, please choose another tile\n";
				}
				else
				{
					cout << endl << "The side you chose was invalid\n";
				}
				// re-display the tiles that the user can choose from
				displayOptions2(thisGameBoard);
				if (m_tileChoice > 0)
				{
					tempTile = m_currentHand.getTilesAt(m_tileChoice - 1);
				}
				else
				{
					// break out of the loop
					break;
				}
			}
		}
		// if the user selects 0 
		if (m_tileChoice == 0)
		{
			// this will go back to the main set of options
			m_exeSucc = false;
			break;
		}

		m_whichSide = m_whichSide;
		m_tileChoice = m_tileChoice - 1;

		if (m_currentHand.hasEngine(m_engineValue) != true)
		{
			// if the selected side is left
			if (m_whichSide == 'L')
			{
				// if the left pips of the user tile match the left pips of the board
				if (m_checkInput->leftSideOnly(thisGameBoard.getLeftMostTile(),
					m_currentHand.getTilesAt(m_tileChoice)) == true)
				{
					// then we want to add the user tile to the board but
					// the tile has to be reversed
					m_userSelection = m_currentHand.getTilesAt(m_tileChoice).reverseTile();
				}
				else
				{
					m_userSelection = m_currentHand.getTilesAt(m_tileChoice);
				}
			}
			// if the selected side is right
			else if (m_whichSide == 'R')
			{
				// if the right pips of the user tile match the left pips of the board
				if (m_checkInput->rightSideOnly(thisGameBoard.getRightMostTile(),
					m_currentHand.getTilesAt(m_tileChoice)) == true)
				{
					// then we want to add the user tile to the board but
					// the tile has to be reversed
					m_userSelection = m_currentHand.getTilesAt(m_tileChoice).reverseTile();
				}
				else
				{
					m_userSelection = m_currentHand.getTilesAt(m_tileChoice);
				}
			}
		}
		else
		{
			m_userSelection = m_currentHand.getTilesAt(m_tileChoice);
		}
		
		// set the execution variable to successful
		m_exeSucc = true;
		break;
	case 2:
		// if this function is called we need to check and
		// make sure that the user cannot actually make a move
		if(m_validMove == false)
		{
			// increase the pass count by 1
			m_passCount++;
			// if the pass count is > 1
			// so if the move has been passed twice
			if (m_passCount > 1)
			{
				m_passCount = 0;
				// then set the passed variable to true
				m_HumanPass = true;
			}
			m_userChoice = 0;
			m_whichSide = ' ';
			setUserOptions(m_userSelection, m_whichSide);
			// set the execution variable to successful
			m_exeSucc = true;
			break;
		}
		// otherwise there is a playable tile in the user hand
		// set the execution variable to successful
		cout << endl << "There is a playable tile\n";
		m_exeSucc = false;
		break;
	case 3:
		// This simply calls the help function from the player class
		// the help function will need the players hand in order to 
		// work
		// getHelp()
	default:
		break;
	}
}

// displays the second set of options
void human::displayOptions2(gameBoard &a_inGameBoard)
{
	int userChoice;
	gameBoard thisGameBoard = a_inGameBoard;

	displayTiles();

	cout << endl << "Press 0 to go back to the previous menu \n";
	cout << "User Selection: ";

	//ignore all characters left in the buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> userChoice;

	// check to make sure that the user has entered a valid number
	// while the user doesn't provide a valid input
	while (!cin.good() || (userChoice > m_currentHand.getHandSize()))
	{
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// print an error message
		cout << endl << "Inccorect input - Please enter a value between 1 and " << m_currentHand.getHandSize() << endl;

		a_inGameBoard.printToScreen();
		cout << endl;
		displayTiles();

		cout << endl;
		cout << "Press 0 to go back to the previous menu \n";
		// take in the userInput
		cout << "User Selection: ";
		cin >> userChoice;
	}
	// once we get a valid input we will store it 
	// into a temporary variable
	m_tileChoice = userChoice;

	// if the user doesn't select 0 
	if (m_tileChoice != 0)
	{
		//then ask the user for left or right
		printLeftRight();
		if (m_whichSide == 'B')
		{
			displayOptions2(thisGameBoard);
		}
	}
}


void human::displayTiles()
{
	int a_optionCount = 1;
	cout << endl;
	// the user will also need to be able to see their hand
	cout << getName() << "'s Hand" << endl;
	m_currentHand.printHand();
	cout << setw(2) << a_optionCount;
	// this will display a number under each potential option
	for (a_optionCount = 2; a_optionCount < m_currentHand.getHandSize() + 1;
		a_optionCount++)
	{
		cout << setw(4) << a_optionCount;
	}
	cout << endl << endl;
}

void human::findEnginePosition()
{
	int numCount;
	int handsize = m_currentHand.getHandSize();
	for (numCount = 0; numCount < handsize; numCount++)
	{
		if (m_currentHand.getTilesAt(numCount).isDouble() == true && 
			m_currentHand.getTilesAt(numCount).getLeftSide() == m_engineValue)
		{
			m_enginePosition = numCount;
		}
	}
}

playerHand* human::getHand()
{
	// cout << "Playing as: " << playerType << " and I am in the human::getHand()\n";
	return & m_currentHand;
}