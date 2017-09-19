#include "stdafx.h"
#include "dominoTile.h"



// default constructor
dominoTile::dominoTile()
{
}

// default destructor
dominoTile::~dominoTile()
{
}

//this will create a new domino tile with a set left and right
dominoTile::dominoTile(int a_leftSide, int a_rightSide)
{
	m_leftSide = a_leftSide;
	m_rightSide = a_rightSide;
}

//this will return the left-hand side of the tile
int dominoTile::getLeftSide()
{
	return m_leftSide;
}

//this will return the right-hand side of the tile
int dominoTile::getRightSide()
{
	return m_rightSide;
}

// this will retrieve the tile object
// THIS IS CURRENTLY NOT WORKING
dominoTile dominoTile::getTile()
{
	dominoTile tempDomino(m_leftSide, m_rightSide);
	return tempDomino;
}

// setter function created for testing purposes
void dominoTile::setTile(int a_leftSide, int a_rightSide)
{
	m_leftSide = a_leftSide;
	m_rightSide = a_rightSide;
}

// will evaluate this statement and determine weather it is
// true or false
bool dominoTile::isDouble()
{
	return (m_leftSide == m_rightSide);
}

// this function will display the tile information on the console
void dominoTile::printTile()
{
	cout << m_leftSide << " - " << m_rightSide << " ";
}

// this function will reverse the tile
void dominoTile::reverseTile()
{
	// create a temporary variable and set it to the left-hand side
	int m_tempPip = m_leftSide;
	// then set the left-hand side = to the right-hand side
	m_leftSide = m_rightSide;
	// finally set the right-hand side to the temporary variable
	m_rightSide = m_tempPip;
}

int dominoTile::tileSum()
{
	int m_sumPips;
	m_sumPips = m_leftSide + m_rightSide;
	return m_sumPips;
}
