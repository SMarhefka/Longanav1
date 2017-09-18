#pragma once
// default libraries
#include <vector>
// user defined libraries
#include "dominoTile.h"

class playerHand
{
public:
	// default constructor
	playerHand();
	// constructor with the player hand
	// default destructor
	~playerHand();

	// add dominoTile to the user hand
	void addTile(dominoTile tileToAdd);

	// remove dominoTile from the user hand
	void removeTile(dominoTile tileToRemove);
	
	// get tile at a certain location in the hand
	dominoTile getTilesAt(int place);

	// check to see if the hand is empty
	bool isEmpty();
	// print hand
	void printHand();

private:
	// need a shared point to avoid object slicing
	// this shared pointer will also be useful when polymorphism
	// needs to be implemented.
	vector<dominoTile> playerTiles;
};

