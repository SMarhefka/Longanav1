#include "stdafx.h"
#include "player.h"

/************************************************************************
Function Name: player()

Purpose: Default Constructor
Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm:
1. initialize all private variables

Assistance Received: None
************************************************************************/
player::player()
{
	m_checkInput = new validateInput;
	m_passCount = 0;
	m_playerScore = 0;
	m_userChoice = 0;
	m_totalPips = 0;
	m_engineValue = 0;

	m_whichSide = ' ';
	m_validMove = false;
	m_passTurn = false;

	m_playerName = "Computer";

	m_boardLeft = 0;
	m_boardRight = 0;
}

/************************************************************************
Function Name: player()

Purpose: Overload Constructor
Parameters:
playerHand a_inUserHand --> sets the current players hand to incoming hand
int a_inScore --> sets the score to the incoming score
bool a_inPassed --> sets the passed variable to the incoming passed variable
Return Value: Constructor
Local Variables:
m_passCount --> the number of times that the current player has passed their turn;
m_userChoice --> the integer value that the user has chosen;
m_totalPips --> the sum of the left and right and side of a tile
m_engineValue --> the value of the engine based on the round number;
m_whichSide --> the value corresponding the the location on the board
m_validMove --> variable to determine whether a user move is valid or not;
m_boardLeft --> the left most value of the board
m_boardRight --> the right most value of the board

Algorithm:
1. initialize all private variables

Assistance Received: None
************************************************************************/
player::player(playerHand a_inUserHand, int a_inScore, bool a_inPassed)
{
	m_currentHand = a_inUserHand;
	m_playerScore = a_inScore;
	m_passTurn = a_inPassed;

	m_passCount = 0;
	m_userChoice = 0;
	m_totalPips = 0;
	m_engineValue = 0;

	m_whichSide = ' ';
	m_validMove = false;

	m_boardLeft = 0;
	m_boardRight = 0;
}

/************************************************************************
Function Name: ~player()
Purpose: Overload Constructor
Parameters: None
Local Variables:None
Algorithm: None
Assistance Received: None
************************************************************************/
player::~player()
{
}

/************************************************************************
Function Name: displayInfo(gameBoard* &a_inGameBoard)
Purpose: displays the information relevant to the current player
Parameters:
gameBoard* &a_inGameBoard --> pointer the the gameboard object

Algorithm:
1. prints all of the information relevant to the computer

Assistance Received: None
************************************************************************/
void player::displayInfo(gameBoard* &a_inGameBoard)
{
	cout << endl;
	cout << "Current Board: " << endl;
	// print the board to the screen
	a_inGameBoard->printToScreen();
	cout << endl;
	cout << "Current Hand:" << endl;
	// print the user hand
	m_currentHand.printHand();

}

/************************************************************************
Function Name: playMove(gameBoard* &a_inGameBoard, bool a_nextPlayerPassed)
Purpose: displays the information relevant to the current player
Parameters:
gameBoard* &a_inGameBoard --> pointer the the gameboard object
bool a_nextPlayerPassed --> 
Algorithm:
1. reset all protected variables
2. if the computer has the engine then place it

Assistance Received: None
************************************************************************/
void player::playMove(gameBoard* &a_inGameBoard, bool a_nextPlayerPassed)
{
	// reset all variables
	resetAll();

	// if the current hand contains the engine then
	if (m_currentHand.hasEngine(m_engineValue) == true)
	{
		int handSize = m_currentHand.getHandSize();
		// find the domino tile that has the engine
		for (int count = 0; count < handSize; count++)
		{
			if ((m_currentHand.getTilesAt(count).isDouble() == true) && 
				(getHand()->getTilesAt(count).getLeftSide() == m_engineValue))
			{
				m_userSelection = m_currentHand.getTilesAt(count);
				m_whichSide = 'R';
			}
		}
		setUserOptions(m_userSelection, m_whichSide);
		printPlacement(true);
		m_passCount = 0;
		m_passTurn = false;
	}
	// otherwise
	else
	{
		m_prevPass = a_nextPlayerPassed;
		m_boardLeft = a_inGameBoard->boardLeftValue();
		m_boardRight = a_inGameBoard->boardRightValue();
		m_validMove = checkMove();

		// check to see if there is a valid move that
		// the computer can make
		if (m_validMove == true)
		{
			// get important information
			// this is the pips associated with the 
			// int boardLeftmostPips = a_inGameBoard.getLeftMostTile().getLeftSide();
			// int boardRightmostPips = a_inGameBoard.getRightMostTile().getRightSide();
			int handSize = m_currentHand.getHandSize();

			// clear the play order
			m_playOrder.clear();
			// re-do the play order
			m_playOrder = getTileOptions();
			// go through the best order
			for (int count = int(m_playOrder.size() - 1); count >= 0; count--)
			{
				if (checkTileSelection(m_boardLeft, m_boardRight, m_playOrder.at(count)) == true)
				{
					m_userSelection = m_playOrder.at(count);
					break;
				}
			}

			char sideValue = 'L';
			bool sideValid = m_checkInput->validSideCheck(m_userSelection, sideValue, m_playerName, m_prevPass);
			if (sideValid == true)
			{
				m_whichSide = sideValue;
				if (m_checkInput->leftSide1(m_boardLeft, m_userSelection) == true)
				{
					m_userSelection = m_userSelection.reverseTile();
					
				}
				else
				{
					m_userSelection = m_userSelection;
				}
			}
			else
			{
				sideValue = 'R';
				sideValid = m_checkInput->validSideCheck(m_userSelection, sideValue, m_playerName, m_prevPass);
				if (sideValid == true)
				{
					m_whichSide = sideValue;
					if (m_checkInput->rightSide1(m_boardRight, m_userSelection) == true)
					{
						m_userSelection = m_userSelection;
					}
					else
					{
						m_userSelection = m_userSelection.reverseTile();
					}
				}
			}
		}
		// if there is no valid move
		if (m_validMove == false)
		{
			m_validMove = false;
			// increase the pass count by 1
			m_passCount++;
			// if the pass count is > 1
			// so if the move has been passed twice
			if (m_passCount > 1)
			{
				m_passCount = 0;
				// then set the passed variable to true
				m_passTurn = true;
				cout << "COMPUTER STRATEGY:" << endl;
				cout << endl;
				cout << "Computer is not going to place a tile on the board";
				cout << endl;
				cout << "There are no valid tiles for the computer to place on the board";
				cout << endl << endl;
				cout << "---------------------------------------------------" << endl;
			}
			m_userChoice = 0;
			m_whichSide = ' ';
			setUserOptions(m_userSelection, m_whichSide);
		}
		// run checkPass
		//m_userSelection = m_currentHand.getTilesAt(0);
		//m_whichSide = 'R';
		if (m_validMove == true)
		{
			setUserOptions(m_userSelection, m_whichSide);
			m_passTurn = false;
			m_passCount = 0;
			printPlacement(false);
		}
	}
}

// resets all private variables
void player::resetAll()
{
	m_prevPass = false;
	m_boardLeft = 0;
	m_boardRight = 0;
	m_validMove = 0;
	m_whichSide = ' ';
	m_validMove = false;
	m_boardLeft = 0;
	m_boardRight = 0;
}

// This checks every senario 
bool player::checkMove()
{
	// if the passCount is 0
	if(m_passCount == 0)
	{
		// check the entire hand
		int handSize = m_currentHand.getHandSize();
		// go though every element
		for (auto item = 0; item < handSize; item++)
		{
			if (checkTileSelection(m_boardLeft, m_boardRight, m_currentHand.getTilesAt(item)) == true)
			{
				// then set the valid move to true
				return true;
			}
		}
	}
	// otherwise if the passCount is 1
	else if (m_passCount == 1)
	{
		// just check to see if the last tile in the hand can be played
		if (checkTileSelection(m_boardLeft, m_boardRight, m_currentHand.getTilesAt(m_currentHand.getHandSize() - 1)) == true)
		{
			return true;
		}
	}
	// otherwise there are no valid moves
	return false;
}

// compares the board against the given tile to see if there is anywhere that the tile can go
bool player::checkTileSelection(int a_boardLeftVal, int a_boardRightVal, dominoTile &a_inUserTile)
{
	// if the user selects a double or if the computer passed it's turn
	// then you need to check both sides of the board
	if (a_inUserTile.isDouble() == true || m_prevPass == true)
	{
		if (m_checkInput->leftSide1(a_boardLeftVal, a_inUserTile) == true || 
			m_checkInput->leftSide2(a_boardLeftVal, a_inUserTile) == true)
		{
			return true;
		}
		else if (m_checkInput->rightSide1(a_boardRightVal, a_inUserTile) == true ||
			m_checkInput->rightSide2(a_boardRightVal, a_inUserTile) == true)
		{
			return true;
		}
	}
	else if (m_playerName == "Computer")
	{

		if (m_checkInput->rightSide1(a_boardRightVal, a_inUserTile) == true ||
			m_checkInput->rightSide2(a_boardRightVal, a_inUserTile) == true)
		{
			return true;
		}
	}
	else
	{
		if (m_checkInput->leftSide1(a_boardLeftVal, a_inUserTile) == true ||
			m_checkInput->leftSide2(a_boardLeftVal, a_inUserTile) == true)
		{
			return true;
		}
	}
	// if none of these work then return false
	// this means that the tile will not work
	return false;
}

// sets the name of the players...this is mainly used when reading in the file
string player::setName(string a_inName)
{
	if (a_inName == "")
	{
		return string("Human");
	}
	return string(a_inName);
}

// retrieves the name of the current player
string player::getName()
{
	return string(m_playerName);
}

// retrieves the hand of the current player
playerHand* player::getHand()
{
	// cout << "Playing as: " << playerType << " I'm in the player::getHand method\n";
	return &m_currentHand;
}

// retrieves the passed parameter of the current player
bool player::getPassed()
{
	return m_passTurn;
}

// adds a number to a players hand 
void player::addScore(int a_inNumber)
{
	m_playerScore = m_playerScore + a_inNumber;
}

// retrieves a score from a particular palyers hand
int player::getScore()
{
	return m_playerScore;
}

// retrieves the tile selected by the user
dominoTile player::getSelectedTile()
{
	return m_userSelection;
}

// retrieves the side selected by the user
char player::getSelectedSide()
{
	return m_whichSide;
}

// retrieves the number of times the user has passed their turn
int player::getPassCount()
{
	return m_passCount;
}

// sets the engoine value based on the round number
void player::setEngine(int & a_inEngine)
{
	m_engineValue = a_inEngine;
}

// prints the computer strategy
void player::printPlacement(bool a_hadEngine)
{
	string whichSide = "";
	stringstream stringStrm;
	stringStrm << m_whichSide;
	stringStrm >> whichSide;
	cout << endl;
	cout << "COMPUTER STRATEGY:" << endl;
	cout << endl;
	cout << "Computer is going to place "; m_userSelection.printTile();

	if (m_whichSide == 'L')
	{
		whichSide = whichSide.append("eft");
	}
	else if (m_whichSide == 'R')
	{
		whichSide = whichSide.append("ight");
	}
	cout << "on the " << whichSide << " side of the board.";
	cout << endl;


	cout << "Computer placed "; m_userSelection.printTile();
	if (a_hadEngine == true)
	{
		cout << " because it was the engine needed to start the round.";
	}
	else
	{
		cout << " because it was the tile with the higest sum which was: " << m_userSelection.tileSum();
	}
	cout << endl << endl;
	cout << "---------------------------------------------------" << endl;
	cout << endl;
}


vector<dominoTile> player::getTileOptions()
{
	vector<dominoTile> playerList;
	int handSize = m_currentHand.getHandSize();

	for (int item = 0; item < handSize; item++)
	{
		playerList.push_back(m_currentHand.getTilesAt(item));
	}
	// Sort based on the tile sum
	sort(playerList.begin(), playerList.end(), [](dominoTile& t1, dominoTile& t2){
		// If the tile Sums are the same
		if (t1.tileSum() == t2.tileSum())
		{
			// then sort based on the right hand values of the tile
			return t1.getRightSide() < t2.getRightSide();
		}
		return t1.tileSum() < t2.tileSum();
	});

	cout << endl;
	cout << "Sorted Computer Hand: " << endl;
	for (int item = 0; item < playerList.size(); item++)
	{
		cout << "Tile: ";
		playerList.at(item).printTile();
		cout << " Sum: " << playerList.at(item).tileSum();
		cout << endl;
	}
	cout << endl;

	return playerList;
}

void player::setUserOptions(dominoTile & a_userTile, char & a_incomingSide)
{
	m_userSelection = a_userTile;
	m_whichSide = a_incomingSide;
}

void player::getHelp(gameBoard* &a_inGameBoard, bool a_nextPlayerPassed)
{
	resetAll();
	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << endl;
	cout << "BEST ADVISE:" << endl;
	// m_currentHand.printHand();
	// if the current hand contains the engine then
	if (m_currentHand.hasEngine(m_engineValue) == true)
	{
		int handSize = m_currentHand.getHandSize();
		// find the domino tile that has the engine
		for (int count = 0; count < handSize; count++)
		{
			if ((m_currentHand.getTilesAt(count).isDouble() == true) &&
				(getHand()->getTilesAt(count).getLeftSide() == m_engineValue))
			{
				cout << endl;
				cout << "The best tile to play is tile: ";
				m_currentHand.getTilesAt(count).printTile();
				cout << " because it is the engine";
				cout << endl;
			}
		}
	}
	// otherwise
	else
	{
		m_boardLeft = a_inGameBoard->boardLeftValue();
		m_boardRight = a_inGameBoard->boardRightValue();
		m_prevPass = a_nextPlayerPassed;
		m_validMove = checkMove();

		// check to see if there is a valid move that
		// the computer can make
		if (m_validMove == true)
		{
			// get important information
			// this is the pips associated with the 
			// int boardLeftmostPips = a_inGameBoard.getLeftMostTile().getLeftSide();
			// int boardRightmostPips = a_inGameBoard.getRightMostTile().getRightSide();
			int handSize = m_currentHand.getHandSize();

			// clear the play order
			m_playOrder.clear();
			// re-do the play order
			m_playOrder = getTileOptions();
			// go through the best order
			for (int count = int(m_playOrder.size() - 1); count >= 0; count--)
			{
				if (checkTileSelection(m_boardLeft, m_boardRight, m_playOrder.at(count)) == true)
				{
					m_userSelection = m_playOrder.at(count);
					break;
				}
			}

			char sideValue = ' ';
			if (sideValue = 'L')
			{
				bool sideValid = m_checkInput->validSideCheck(m_userSelection, sideValue, m_playerName, m_prevPass);

				if (sideValid == true)
				{
					if (m_checkInput->leftSide1(m_boardLeft, m_userSelection) == true)
					{
						m_userSelection = m_userSelection.reverseTile();
						m_whichSide = sideValue;
					}
					else if (m_checkInput->leftSide2(m_boardLeft, m_userSelection) == true)
					{
						m_userSelection = m_userSelection;
						m_whichSide = sideValue;
					}
				}
			}

			sideValue = ' ';
			if (sideValue = 'R')
			{
				bool sideValid = m_checkInput->validSideCheck(m_userSelection, sideValue, m_playerName, m_prevPass);

				if (sideValid == true)
				{
					if (m_checkInput->rightSide1(m_boardRight, m_userSelection) == true)
					{
						m_userSelection = m_userSelection;
						m_whichSide = sideValue;
					}
					else
					{
						m_userSelection = m_userSelection.reverseTile();
						m_whichSide = sideValue;
					}
				}
			}
		}
		// if there is no valid move
		if (m_validMove == false)
		{
			m_validMove = false;
			// increase the pass count by 1
			m_passCount++;
			// if the pass count is > 1
			// so if the move has been passed twice
			if (m_passCount > 1)
			{
				m_passCount = 0;
				// then set the passed variable to true
				// m_passTurn = true;
			}
			cout << endl;
			cout << "There are no valid moves you should pass your turn" << endl;
			m_passCount = 0;
			m_userChoice = 0;
			m_whichSide = ' ';
		}
		// run checkPass
		//m_userSelection = m_currentHand.getTilesAt(0);
		//m_whichSide = 'R';
		if (m_validMove == true)
		{
			cout << endl;
			cout << "The best tile to play is tile: ";
			m_userSelection.printTile();
			cout << " on the " << m_whichSide << " side of the board";
			cout << endl;
			cout << "Play this tile because it is the tile with the highest sum at: " << m_userSelection.tileSum() << endl;
		}
		cout << endl << endl;
		cout << "---------------------------------------------------" << endl;

		cout << endl;
	}
}