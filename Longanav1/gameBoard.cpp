#include "stdafx.h"
#include "gameBoard.h"

gameBoard::gameBoard()
{
	//tournament.printScore();
}

gameBoard::~gameBoard()
{
}

void gameBoard::addToLeft(dominoTile a_tileToAdd)
{
	if (leftSide.size() == 0)
	{
		leftSide.push_back(a_tileToAdd);
	}
	else
	{
		insertAt = leftSide.begin();
		insertAt = leftSide.insert(insertAt, a_tileToAdd);
	}
}

void gameBoard::printToScreen()
{
	cout << "gameBoard: " << "\n";
	for (auto item = leftSide.begin(); item != leftSide.end(); item++)
	{
		cout << (item)->getLeftSide() << "-" << (item)->getRightSide() << " ";
	}
}
