/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/
#include "stdafx.h"
#include "boneYard.h"


/************************************************************************
Function Name: boneYard()
Purpose: Creates a new boneYard object

Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm:
1. Clear the vector before we do anything
2. Call the createBoneYard function to create 28 new tiles
3. Call the shuffleBoneYard function to randomly shuffle the 28 tiles 
   that we just created

Assistance Received: None
************************************************************************/
boneYard::boneYard()
{
	unusedDominos.clear();
	createBoneYard();
	shuffleBoneYard();
}

/************************************************************************
Function Name: boneYard(vector<dominoTile> &a_inBoneYard)
Purpose: Overloads the boneYard constructor.  This constructor is used
		 when reading in the serialization file.
Parameters:
vector<dominoTile> &a_inBoneYard --> vector of dominoTile objects passed
by reference

Return Value: Constructor
Local Variables: None
Algorithm:
1. Set the unusedDominos vector to the provided vector

Assistance Received: None
************************************************************************/
boneYard::boneYard(vector<dominoTile> &a_inBoneYard)
{
	unusedDominos = a_inBoneYard;
}

/************************************************************************
Function Name: createBoneYard()
Purpose: Creates the boneYard that will be used during play

Parameters: None
Return Value: None
Local Variables:
int leftSide --> counter for the left hand side pips
int rightSide --> counter for the right hand side pips
dominoTile* tempTile --> dominoTile object to store a new dominoTile

Algorithm:
1. Start leftSide and rightSide count at 0 and go until it reaches six
2. Create a new temporary domino tile
3. Push the tile into the unusedDominos vector that stores all of the tiles 
   that have not been used yet
4. Delete the temporary domino
Assistance Received: None
************************************************************************/
void boneYard::createBoneYard()
{
	for (int leftSide = 0; leftSide <= 6; leftSide++)
	{
		for (int rightSide = leftSide; rightSide <= 6; rightSide++)
		{
			dominoTile* tempTile = new dominoTile(leftSide, rightSide);
			unusedDominos.push_back(*tempTile);
			delete tempTile;
		}
	}
}

/************************************************************************
Function Name: shuffleBoneYard()
Purpose: Shuffles the 28 tiles that are created initally in the boneyard

Parameters: None
Return Value: None
Local Variables:None
Algorithm:
1. Use srand(seed) so that we can change the seed value
2. Using built-in function random generator, shuffle the boneyard

Assistance Received: None
************************************************************************/
void boneYard::shuffleBoneYard()
{
	srand(unsigned(time(0)));
	random_shuffle(unusedDominos.begin(), unusedDominos.end());
}

/************************************************************************
Function Name: dealTile()
Purpose: Deals a to the player

Parameters: None
Return Value: dominoTile
Local Variables:
dominoTile dealTile --> temporary dominoTile used to store a dominoTile
						until it is needed

Algorithm:
1. Create a temporary tile and set it to the last tile in the boneyard
2. Remove the last tile from the boneyard
3. Return the temporary tile to the caller function

Assistance Received: None
************************************************************************/
dominoTile boneYard::dealTile()
{
	dominoTile dealTile = unusedDominos.back();
	removeTile();
	return dealTile;
}

/************************************************************************
Function Name: removeTile()
Purpose: Removes a tile from the boneYard

Parameters: None
Return Value: None
Local Variables: None
Algorithm:
1. Remove the last tile from the boneyard

Assistance Received: None
************************************************************************/
void boneYard::removeTile()
{
	unusedDominos.pop_back();
}

/************************************************************************
Function Name: isEmpty()
Purpose: Checks to see if the boneYard is empty

Parameters: None
Return Value: bool
Local Variables:None
Algorithm:
1. Returns true if the boneyard is empty

Assistance Received: None
************************************************************************/
bool boneYard::isEmpty()
{
	return unusedDominos.size() == 0;
}

/************************************************************************
Function Name: getSize()
Purpose: Returns the size of the boneyard

Parameters: None
Return Value: int
Local Variables: None
Algorithm:
1. Return the size of the unusedDominos vector converted as an integer

Assistance Received: None
************************************************************************/ 
int boneYard::getSize()
{
	return int(unusedDominos.size());
}

/************************************************************************
Function Name: printBoneYard()
Purpose: Prints the values stored in the boneYard to the console.  This
		 is mainly used for testing purposes as the players are never
		 actually supposed to know the tiles in the boneyard

Parameters: None
Return Value: None
Local Variables:
auto itemIndex --> value of the current position in unusedDominos vector

Algorithm:
1. Print "Boneyard:" to the console
2. Go through the unusedDominos tile vector
3. Print the left hand side and right hand side values of every domino 
   tile stored in the vector to the console screen

Assistance Received: None
************************************************************************/
void boneYard::printBoneYard()
{
	cout << endl << "Boneyard:" << endl;
	for (auto itemIndex = unusedDominos.begin(); itemIndex != unusedDominos.end(); 
		itemIndex++)
	{
		cout << (itemIndex)->getLeftSide() << "-" << (itemIndex)->getRightSide() << " ";
	}
}

/************************************************************************
Function Name: printBoneYard()
Purpose: Prints the values stored in the boneYard to a specific file.
		 This function is called when the game is saved

Parameters:
ofstream & a_inStream --> a file object where the information will be
written to

Return Value: None
Local Variables:
auto itemIndex --> value of the current position in unusedDominos vector

Algorithm:
2. Go through the unusedDominos tile vector
3. Print the left hand side and right hand side values of every domino
tile stored in the vector to the specified file

Assistance Received: None
************************************************************************/
void boneYard::printBoneYard(ofstream & a_inStream)
{
	for (auto itemIndex = unusedDominos.begin(); itemIndex != unusedDominos.end();
		itemIndex++)
	{
		a_inStream << (itemIndex)->getLeftSide() << "-" << (itemIndex)->getRightSide()
				   << " ";
	}
}

/************************************************************************
Function Name: ~boneYard()
Purpose: Default destructor

Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm:
1. Clear the unusedDominos vector

Assistance Received: None
************************************************************************/
boneYard::~boneYard()
{
	unusedDominos.clear();
}
