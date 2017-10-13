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

	// overload constructor
	playerHand(vector<dominoTile> &a_inUserHand);

	// constructor with the player hand
	// default destructor
	~playerHand();

	// add dominoTile to the user hand
	void addTileToHand(dominoTile a_tileToAdd);

	// remove dominoTile from the user hand
	void removeTile(dominoTile a_tileToRemove);
	
	// get tile at a certain location in the hand
	dominoTile getTilesAt(int a_place);

	// check to see if the hand is empty
	bool isEmpty();

	// checks to see if the current hand has
	// the engine
	bool hasEngine(int & a_inEngine);

	// returns the size of the hand
	int getHandSize();

	// print hand
	void printHand();

	void printHandToFile(ofstream &a_inStream);

private:
	// need a shared point to avoid object slicing
	// this shared pointer will also be useful when polymorphism
	// needs to be implemented.
	vector<dominoTile> m_playerTiles;
};

