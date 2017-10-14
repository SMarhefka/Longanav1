#pragma once
#include "dominoTile.h"

class boneYard
{
public:
	// default constructor
	boneYard();

	boneYard(vector<dominoTile> &a_inBoneYard);

	// default destructor
	~boneYard();

	// create the boneYard
	void createBoneYard();

	// shuffle the boneYard 
	// (this function may not actually need to be used)
	void shuffleBoneYard();

	// checks to see if the boneYard is empty
	bool isEmpty();

	// deals tiles to the player hand
	dominoTile dealTile();

	// remove a tile
	void removeTile();
	
	// print bonyard to the screen
	void printBoneYard();

	void printBoneYard(ofstream & a_inStream);

	// get the size of the boneYard
	int getSize();

private:
	// need a shared pointer to avoid object slicing
	// this shared pointer will also be useful when polymorphism
	// needs to be implemented.
	vector<dominoTile> unusedDominos;
};
