#include "stdafx.h"
#include "boneYard.h"

// default constructor
boneYard::boneYard()
{
}

// default destructor
boneYard::~boneYard()
{
	// Clear the vector before we do anything
	unusedDominos.clear();
}

// Creates the boneYard that will be used during play
void boneYard::createBoneYard()
{
	// Clear the vector before we do anything
	unusedDominos.clear();

	// Print Statement just to check
	cout << "# of elements: " << unusedDominos.size() << "\n";

	// Create the 28 dominos
	for (int i = 0; i <= 6; i++) 
	{
		for (int j = i; j <= 6; j++) 
		{
			// placed for testing purposes
			// cout << "Domino: " << i << "-" << j << endl;
			unusedDominos.push_back(dominoTile(i, j));
		}
	}
	cout << "# of elements: " << unusedDominos.size() << "\n";
	
	// use srand(seed) so that we can change the seed value
	// srand(unsigned(time(0)));
	// using built-in random generator shuffle the boneyard
	// random_shuffle(unusedDominos.begin(), unusedDominos.end());

}

void boneYard::shuffleBoneYard()
{
	//use srand(seed) so that we can change the seed value
	srand(unsigned(time(0)));
	// using built-in random generator shuffle the boneyard
	random_shuffle(unusedDominos.begin(), unusedDominos.end());
}

// Checks to see if the boneYard is empty
bool boneYard::isEmpty()
{
	// return true if the boneyard is empty
	return unusedDominos.size() == 0;
}

// function passes in a the hand object
// (aka the players hand)
void boneYard::dealTile(playerHand &tileToDeal)
{
	// 
	tileToDeal.addTile(unusedDominos.back());
	// removes the tile from the boneyard
	unusedDominos.pop_back();
}

// removes a tile from the boneYard
void boneYard::removeTile()
{
	unusedDominos.pop_back();
}

// this function prints the values stored in the boneYard
void boneYard::printBoneYard()
{
	cout << "Boneyard:" << "\n";
	for (auto item = unusedDominos.begin(); item != unusedDominos.end(); item++)
	{
		cout << (item)->getLeftSide() << "-" << (item)->getRightSide() << " ";
		// Used for testing purposes
		// int index = item - unusedDominos.begin();
		/*if (index > 0 && (index + 1) % 3 == 0) 
		{
			cout << "\n";
		}*/
	}
}

int boneYard::getSize()
{
	return int(unusedDominos.size());
}



