/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#include "stdafx.h"
#include "dominoTile.h"

/************************************************************************
Function Name: dominoTile()
Purpose: Creates a new domino tile

Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm: None
Assistance Received: None
************************************************************************/
dominoTile::dominoTile()
{
}

/************************************************************************
Function Name: dominoTile(int a_leftSide, int a_rightSide)
Purpose: This constructor creates a new domino tile with a specific number
of pips on the both the left and right hand sides

Parameters:
int a_leftSide --> the value for the left side of the domino tile
int a_rightSide --> the value for the right side of the domino tile

Return Value: Constructor
Local Variables: None

Algorithm:
1. set m_leftSide to a_leftSide
2. set m_rightSide to a_rightSide

Assistance Received: None
************************************************************************/
dominoTile::dominoTile(int a_leftSide, int a_rightSide)
{
	m_leftSide = a_leftSide;
	m_rightSide = a_rightSide;
}

/************************************************************************
Function Name: getLeftSide()
Purpose: This function will return the left-hand value of a domino tile
Parameters:None
Return Value: int
Local Variables: None

Algorithm:
1. Return the private member variable m_leftSide
Assistance Received: None
************************************************************************/
int dominoTile::getLeftSide()
{
	return m_leftSide;
}

/************************************************************************
Function Name: getRightSide()
Purpose: This function will return the right-hand value of a domino tile
Parameters:None
Return Value: int
Local Variables: None

Algorithm:
1. Return the private member variable m_rightSide
Assistance Received: None
************************************************************************/
int dominoTile::getRightSide()
{
	return m_rightSide;
}

/************************************************************************
Function Name: isDouble()
Purpose: Determines whether or not a domino tile is a double
Parameters:None
Return Value: boolean
Local Variables: None

Algorithm:
1. Returns true if the two sides are equivilant to each other
2. Returns false if the two sides do not match each other
Assistance Received: None
************************************************************************/
bool dominoTile::isDouble()
{
	return (m_leftSide == m_rightSide);
}

/************************************************************************
Function Name: printTile()
Purpose: Prints the tile to the console
Parameters:None
Return Value: None
Local Variables: None

Algorithm:
1. Print out the left hand value followed by a '-' and then the right
hand value
Assistance Received: None
************************************************************************/
void dominoTile::printTile()
{
	cout << m_leftSide << " - " << m_rightSide << " ";
}

/************************************************************************
Function Name: reverseTile()
Purpose: Flips the left and right hand values of the domino tile
Parameters:None
Return Value: A dominoTile object

Local Variables:
int m_tempPip --> temporarily stores the left hand value of the tile

Algorithm:
1. Store the left side value of the domino tile into m_tempPip
2. Set the left side value of the tile to the right side value
3. Set the right side value to the previously stored left side value
4. Return a domino tile that the new values

Assistance Received: None
************************************************************************/
// this function will reverse the tile
dominoTile dominoTile::reverseTile()
{
	// create a temporary variable and set it to the left-hand side
	int m_tempPip = m_leftSide;
	// then set the left-hand side = to the right-hand side
	m_leftSide = m_rightSide;
	// finally set the right-hand side to the temporary variable
	m_rightSide = m_tempPip;
	return dominoTile(m_leftSide, m_rightSide);
}

/************************************************************************
Function Name: tileSum()
Purpose: Calculates the total of the tile
Parameters:None
Return Value: int
Local Variables:
int m_sumPips --> Stores the summation of the left side value plus the
right side value

Algorithm:
1. Add m_leftSide and m_rightSide together
2. Set the total to the local varaible m_sumPips
3. Return the local variable

Assistance Received: None
************************************************************************/
int dominoTile::tileSum()
{
	int m_sumPips = m_leftSide + m_rightSide;
	return m_sumPips;
}

/************************************************************************
Function Name: dominoTile::~dominoTile()
Purpose: Default destructor

Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm: None
Assistance Received: None
************************************************************************/
dominoTile::~dominoTile()
{
}
