// Longanav1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
//#include "testCases.h"
#include "round.h"

int main()
{
	//testCases newTest;
	//newTest.testBoneYard();
	//newTest.testDomino();

	class round newRound;
	newRound.playRound();

	playerHand currentPlayer;
	dominoTile newTile;
	//currentPlayer.addTile(newTile);
	currentPlayer.addTile();
	currentPlayer.printHand();
	
	//newTile.setTile(5, 5);


	system("pause");

	return 0;
}