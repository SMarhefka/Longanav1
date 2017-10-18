/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#include "stdafx.h"
#include "computer.h"

/************************************************************************
Function Name: computer()
Purpose: Default constructor
Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm: None
Assistance Received: None
************************************************************************/
// default constructor
computer::computer()
{
}

/************************************************************************
Function Name: computer(playerHand a_inUserHand, int a_inScore, 
						bool a_inComPassed, bool a_inPlyerPassed) : 
						player(a_inUserHand, a_inScore, a_inComPassed, 
						a_inPlyerPassed)

Purpose: Overload the computer constructor.  This will create a new
		 Computer player object with a specific hand, score and information
		 on any passed moves.  This function is called when a file is loaded
		 to start the gameplay
Parameters:
playerHand a_inUserHand --> the hand of the computer player
int a_inScore --> the score of the computer player
bool a_inComPassed --> if the computer player has passed their turn
bool a_inPlyerPassed --> if the human player has passed their turn

Return Value: Constructor
Local Variables: None

Algorithm:
1. set m_playerName to Computer

Assistance Received: None
************************************************************************/
computer::computer(playerHand a_inUserHand, int a_inScore, bool a_inComPassed) : player(a_inUserHand, a_inScore, a_inComPassed)
{
	m_playerName = "Computer";
};

/************************************************************************
Function Name: computer()
Purpose: Default destructor
Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm: None
Assistance Received: None
************************************************************************/
computer::~computer()
{
}