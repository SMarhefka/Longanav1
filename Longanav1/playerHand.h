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
	// check to see if the hand is empty
	bool isEmpty();
	// remove dominoTile
	void removeTile(dominoTile tileToRemove);
	// print hand
	void printHand();

private:
	// need a shared point to avoid object slicing
	// this shared pointer will also be useful when polymorphism
	// needs to be implemented.
	vector<dominoTile> playerTiles;
};

