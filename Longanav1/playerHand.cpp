#include "stdafx.h"
#include "playerHand.h"
#include "gameRound.h"
#include <string>
#include <fstream>

// default constructor
playerHand::playerHand()
{
}

playerHand::playerHand(vector<dominoTile> & a_inUserHand)
{
	m_playerTiles = a_inUserHand;
}

// default destructor
playerHand::~playerHand()
{
	m_playerTiles.clear();
}

//void playerHand::addTile()
void playerHand::addTileToHand(dominoTile a_tileToAdd)
{
	// pushes back that tile to the end of the vector playerTiles
	m_playerTiles.push_back(a_tileToAdd);
}

// this function will be used when a player places their tile on the board
void playerHand::removeTile(dominoTile a_tileToRemove)
{
	// go through the vector and find the tile that is going to be deleted.
	for (auto item = m_playerTiles.begin(); item != m_playerTiles.end(); item++)
	{
		// cout << "item: " << item->getLeftSide() << "\n";
		// cout << "tile: " << a_tileToRemove.getLeftSide() << "\n";

		if ((item->getLeftSide() == a_tileToRemove.getLeftSide()) && ((item->getRightSide() == a_tileToRemove.getRightSide())))
		{
			m_playerTiles.erase(item);
			break;
		}
		else if ((item->getLeftSide() == a_tileToRemove.getRightSide()) && ((item->getRightSide() == a_tileToRemove.getLeftSide())))
		{
			m_playerTiles.erase(item);
			break;
		}
	}
}

dominoTile playerHand::getTilesAt(int a_place)
{
	return m_playerTiles.at(a_place);
}

// Checks to see if the players hand is empty
bool playerHand::isEmpty()
{
	return m_playerTiles.size() == 0;
}

bool playerHand::hasEngine(int & a_inEngine)
{
	for (auto item = m_playerTiles.begin(); item != m_playerTiles.end(); item++)
	{
		if ((item->isDouble() && (item->getLeftSide() == a_inEngine)))
		{
			return true;
		}
	}
	return false;
}

// returns the handsize or the number of tiles that 
// the current user has
int playerHand::getHandSize()
{
	return int(m_playerTiles.size());
}

int playerHand::handTotal()
{
	int m_totalPips = 0;
	for (auto tileItem = m_playerTiles.begin(); tileItem != m_playerTiles.end(); tileItem++)
	{
		m_totalPips += (tileItem)->tileSum();
	}

	return m_totalPips;
}

void playerHand::printHand()
{
	for (auto item = m_playerTiles.begin(); item != m_playerTiles.end(); item++)
	{
		cout << (item)->getLeftSide() << "-" << (item)->getRightSide() << " ";
	}
	cout << endl;
}

void playerHand::printHandToFile(ofstream & a_inStream)
{
	for (auto item = m_playerTiles.begin(); item != m_playerTiles.end(); item++)
	{
		a_inStream << (item)->getLeftSide() << "-" << (item)->getRightSide() << " ";
	}
	cout << endl;
}
