#include "stdafx.h"
#include "player.h"

//for testing only
#include <string>

// this is the base class
player::player()
{
	m_passCount = 0;
	m_playerScore = 0;
	m_engineValue = 0;
	m_userChoice = 0;
	m_totalPips = 0;
	
	m_whichSide = NULL;

	m_playerPass = false;
	m_playerName = "Computer";
}

player::~player()
{
}

void player::playMove(gameBoard &a_inGameBoard)
{
	// if the current hand contains the engine then
	if (m_currentHand.hasEngine(m_engineValue) == true)
	{
		int handSize = m_currentHand.getHandSize();
		// find the domino tile that has the engine
		for (int count = 0; count < handSize; count++)
		{
			if ((m_currentHand.getTilesAt(count).isDouble() == true) && (getHand()->getTilesAt(count).getLeftSide() == m_engineValue))
			{
				m_userSelection = m_currentHand.getTilesAt(count);
				m_whichSide = 'R';
			}
		}
		setUserOptions(m_userSelection, m_whichSide);
		setPassed(false);
		m_passCount = 0;
	}
	// otherwise
	else
	{
		// check to see if there is a valid move that
		// the computer can make
		if (checkMove(a_inGameBoard) == true)
		{
			// get important information
			// this is the pips associated with the 
			int boardLeftmostPips = a_inGameBoard.getLeftMostTile().getLeftSide();
			int boardRightmostPips = a_inGameBoard.getRightMostTile().getRightSide();
			bool humanPassed = getPassed();

			if (!m_playOrder.empty())
			{
				m_playOrder.clear();
			}

			m_playOrder = tilePlayOrder();
			// go through the hand
			int handSize = m_currentHand.getHandSize();
			for (int count = 0; count < handSize; count++)
			{
				if (checkTileSelection(a_inGameBoard, m_playOrder.at(count)) == true)
				{
					m_userSelection = m_playOrder.at(count);
				}
			}

			char sideValue = 'L';
			if (m_checkInput.validSideCheck(m_userSelection, sideValue, m_playerName, humanPassed) == true)
			{
				m_whichSide = sideValue;
				if (m_checkInput.leftSideOnly(a_inGameBoard.getLeftMostTile(), m_userSelection) == true)
				{
					m_userSelection = m_userSelection;
				}
				else
				{
					m_userSelection = m_userSelection.reverseTile();
				}
			}
			sideValue = 'R';
			if (m_checkInput.validSideCheck(m_userSelection, sideValue, m_playerName, humanPassed) == true)
			{
				m_whichSide = sideValue;
				if (m_checkInput.rightSideOnly(a_inGameBoard.getRightMostTile(), m_userSelection) == true)
				{
					m_userSelection = m_userSelection.reverseTile();
				}
				else
				{
					m_userSelection = m_userSelection;
				}
			}
		}
		// if there is no valid move
		if (checkMove(a_inGameBoard) == false)
		{
			// increase the pass count by 1
			m_passCount++;
			// if the pass count is > 1
			// so if the move has been passed twice
			if (m_passCount > 1)
			{
				// then set the passed variable to true
				setPassed(true);
			}
		}

		// run checkPass
		//m_userSelection = m_currentHand.getTilesAt(0);
		//m_whichSide = 'R';
		setUserOptions(m_userSelection, m_whichSide);
		setPassed(false);
	}
}

// This checks every senario 
bool player::checkMove(gameBoard &a_inGameBoard)
{
	// if the passCount is 0
	if(m_passCount == 0)
	{
		// check the entire hand
		int handSize = m_currentHand.getHandSize();
		// go though every element
		for (auto item = 0; item < handSize; item++)
		{
			if (checkTileSelection(a_inGameBoard, m_currentHand.getTilesAt(item)) == true)
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
		if (checkTileSelection(a_inGameBoard, m_currentHand.getTilesAt(m_currentHand.getHandSize() - 1)) == true)
		{
			return true;
		}
	}
	// otherwise there are no valid moves
	return false;
}

bool player::checkTileSelection(gameBoard &a_inGameBoard, dominoTile &a_inUserTile)
{
	// if the user selects a double or if the computer passed it's turn
	// then you need to check both sides of the board
	if (a_inUserTile.isDouble() == true || getPassed() == true)
	{
		if (m_checkInput.checkLeftSide(a_inGameBoard.getLeftMostTile(), a_inUserTile) == true)
		{
			return true;
		}
		if (m_checkInput.checkRightSide(a_inGameBoard.getRightMostTile(), a_inUserTile) == true)
		{
			return true;
		}
	}
	else if (m_playerName == "Computer")
	{

		if (m_checkInput.checkRightSide(a_inGameBoard.getRightMostTile(), a_inUserTile) == true)
		{
			return true;
		}
	}
	else
	{
		if (m_checkInput.checkLeftSide(a_inGameBoard.getLeftMostTile(), a_inUserTile) == true)
		{
			return true;
		}
	}
	// if none of these work then return false
	// this means that the tile will not work
	return false;
}

string player::getName()
{
	return string(m_playerName);
}

playerHand* player::getHand()
{
	// cout << "Playing as: " << playerType << " I'm in the player::getHand method\n";
	return & m_currentHand;
}

bool player::getPassed()
{
	return m_playerPass;
}

int player::getScore(int a_inNumber)
{
	m_playerScore = m_playerScore + a_inNumber;
	return m_playerScore;
}

dominoTile player::getSelectedTile()
{
	return m_userSelection;
}

char player::getSelectedSide()
{
	return m_whichSide;
}

int player::getPassCount()
{
	return m_passCount;
}

void player::getEngineFromRound(int & a_inEngine)
{
	m_engineValue = a_inEngine;
}

int player::handTotal()
{
	m_totalPips = 0;
	int handSize = m_currentHand.getHandSize();
	// go though every element
	for (auto item = 0; item < handSize; item++)
	{
		m_totalPips += m_currentHand.getTilesAt(item).tileSum();
	}
	return m_totalPips;
}

vector<dominoTile> player::tilePlayOrder()
{
	// create local vectors needed for the function
	vector<dominoTile> playList;
	vector<int> leftSideTiles;
	vector<int> rightSideTiles;

	// clear all vectors
	if (!playList.empty())
	{
		// Removes all elements from the playList (which are destroyed)
		// leaving the container with a size of 0.
		playList.clear();
	}
	else if (!leftSideTiles.empty())
	{
		// Removes all elements from the leftSideTiles (which are destroyed)
		// leaving the container with a size of 0.
		leftSideTiles.clear();
	}
	else if (!rightSideTiles.empty())
	{
		// Removes all elements from the rightSideTiles (which are destroyed)
		// leaving the container with a size of 0.
		rightSideTiles.clear();
	}

	// set leftSidTile to all 0
	for (int count = 0; count <= 6; count++)
	{
		leftSideTiles.push_back(0);
	}

	int handSize = m_currentHand.getHandSize();
	// find the domino tile that has the engine
	for (int count = 0; count < handSize; count++)
	{
		// set up a temporary tile
		dominoTile tempTile = m_currentHand.getTilesAt(count);
		// push the tile to the back of the playList
		playList.push_back(tempTile);
		// set up a rightValue
		int rightValue = tempTile.getRightSide();
		// go through the different cases
		if (rightValue == 0)
		{
			leftSideTiles[0]++;
		}
		else if (rightValue == 1)
		{
			leftSideTiles[1]++;
		}
		else if (rightValue == 2)
		{
			leftSideTiles[2]++;
		}
		else if (rightValue == 3)
		{
			leftSideTiles[3]++;
		}
		else if (rightValue == 4)
		{
			leftSideTiles[4]++;
		}
		else if (rightValue == 5)
		{
			leftSideTiles[5]++;
		}
		else if (rightValue == 6)
		{
			leftSideTiles[6]++;
		}
		// get the left hand value of the tile
		int leftValue = tempTile.getLeftSide();
		// go through every potential value
		if (rightValue == 0)
		{
			leftSideTiles[0]++;
		}
		else if (rightValue == 1)
		{
			leftSideTiles[1]++;
		}
		else if (rightValue == 2)
		{
			leftSideTiles[2]++;
		}
		else if (rightValue == 3)
		{
			leftSideTiles[3]++;
		}
		else if (rightValue == 4)
		{
			leftSideTiles[4]++;
		}
		else if (rightValue == 5)
		{
			leftSideTiles[5]++;
		}
		else if (rightValue == 6)
		{
			leftSideTiles[6]++;
		}
	}

	// reorder the tiles
	for (int count = 0; count < handSize; count++)
	{
		dominoTile tempTile;
		tempTile = playList[count];
		rightSideTiles.push_back(leftSideTiles[tempTile.getLeftSide()] + leftSideTiles[tempTile.getRightSide()]);
	}
	for (int x = 0; x < handSize - 1; x++)
	{
		for (int y = 0; y < handSize - 1; y++)
		{
			// if the value at y in the rightSide is less
			// then the value at y + 1 in the rightSide
			if (rightSideTiles[y] < rightSideTiles[y + 1])
			{
				// swap the value on the left for the value
				// on the right hand side
				swap(rightSideTiles.at(y), rightSideTiles.at(y + 1));
				swap(playList.at(y), playList.at(y + 1));
			}
		}
	}
	// return the player list
	return playList;
}

void player::setPassed(bool a_playerPass)
{
	m_playerPass = a_playerPass;
}

void player::setUserOptions(dominoTile & a_userTile, char & a_incomingSide)
{
	m_userSelection = a_userTile;
	m_whichSide = a_incomingSide;
}
