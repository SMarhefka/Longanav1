// Longanav1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "testCases.h"
//#include "gameRound.h"
#include "tournament.h"

int main()
{
	//testCases newTest;
	//newTest.testBoneYard();
	//newTest.testDomino();

	tournament newTournament;

	newTournament.loadUserOptions();

	system("pause");

	return 0;
}