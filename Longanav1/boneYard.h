/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once
#include "dominoTile.h"

class boneYard
{
public:
	// Default constructor
	boneYard();

	// Overload constructor
	boneYard(vector<dominoTile> &a_inBoneYard);

	// Creates the boneYard that will be used during gameplay
	void createBoneYard();

	// Shuffles the 28 tiles that are created initally in the boneyard
	void shuffleBoneYard();

	// Deals a to the player
	dominoTile dealTile();

	// Removes a tile from the boneYard
	void removeTile();
	
	// Checks to see if the boneYard is empty
	bool isEmpty();

	// get the size of the boneYard
	int getSize();

	// Prints the values stored in the boneYard to the console
	void printBoneYard();

	// Prints the values stored in the boneYard to a specific file
	void printBoneYard(ofstream & a_inStream);

	// default destructor
	~boneYard();

private:
	vector<dominoTile> unusedDominos;
};
