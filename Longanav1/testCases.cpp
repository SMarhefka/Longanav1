#include "stdafx.h"
#include "testCases.h"


testCases::testCases()
{
}


testCases::~testCases()
{
}

// Simple test to make sure that the domino Class works correctly
void testCases::testDomino()
{
	dominoTile newDomino(2, 5);
	cout << "left-side " << newDomino.getLeftSide() << "\n";
	cout << "right-side " << newDomino.getRightSide() << "\n";
	//Error here
	//cout << "get tile " << newDomino.getTile() << "\n";
	newDomino.printTile();
	system("pause");
	cout << "left-side " << newDomino.getLeftSide() << "\n";
	cout << "right-side " << newDomino.getRightSide() << "\n";
	newDomino.printTile();
	system("pause");
	newDomino.reverseTile();
	cout << "left-side " << newDomino.getLeftSide() << "\n";
	cout << "right-side " << newDomino.getRightSide() << "\n";
	newDomino.printTile();
	system("pause");
}

// Simple test to make sure that the boneYard class works correctly
//void testCases::testBoneYard()
//{
//	boneYard newBoneYard;
//	newBoneYard.createBoneYard();
//	newBoneYard.printBoneYard();
//	cout << "\n";
//
//	newBoneYard.shuffleBoneYard();
//	cout << newBoneYard.getSize() << "\n";
//	newBoneYard.printBoneYard();
//	cout << "\n";
//
//	newBoneYard.removeTile();
//	cout << newBoneYard.getSize() << "\n";
//	newBoneYard.printBoneYard();
//	cout << "\n";
//
//	system("pause");
//	newBoneYard.~boneYard();
//	cout << newBoneYard.getSize() << "\n";
//	if (newBoneYard.isEmpty() == true)
//	{
//		cout << "boneyard is empty\n";
//	}
//	else
//	{
//		cout << "boneyard is not empty\n";
//	}
//	cout << "\n";
//	system("pause");
//}