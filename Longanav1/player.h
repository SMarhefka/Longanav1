#pragma once
#include "playerHand.h"
#include "boneyard.h"
#include "gameBoard.h"
#include "validateInput.h"


using namespace std;

class player
{
public:
	// default constuctor
	player();

	// overloaded constructor
	player(playerHand a_inUserHand, int a_inScore, bool a_inComPassed, bool a_inPlyerPassed);

	// default destuctor
	~player();
	
	// This is only a test at this point
	// I am not passing this by reference because I
	// don't plan on modifying the game board in the
	// player class
	virtual void playMove(gameBoard &a_inGameBoard);

	virtual bool checkTileSelection(gameBoard &a_inGameBoard, dominoTile &a_inUserTile);

	// check for valid moves
	virtual bool checkMove(gameBoard &a_inGameBoard);

	void setEngineFromRound(int & a_inEngine);

	dominoTile getSelectedTile();

	virtual playerHand* getHand();

	// This will return the name of the current player
	string getName();

	bool getPassed();

	void addScore(int a_inNumber);

	int getScore();

	char getSelectedSide();

	int getPassCount();

	void setUserOptions(dominoTile & a_userTile, char & a_incomingSide);

	int handTotal();

	vector <dominoTile> tilePlayOrder();

	void player::setHumanPass(bool &a_humanPassed);

	string setName(string a_inName);

protected:
	// creates a new instance of validate class
	validateInput* m_checkInput;
	// creates a new player hand
	playerHand m_currentHand;
	// creates a new dominoTile
	dominoTile m_userSelection;

	// new string variable that stores the
	// player hand
	string m_playerName;

	vector <dominoTile> m_playOrder;

	char m_whichSide;
	bool m_HumanPass;
	bool m_ComputerPass;
	bool m_validMove;

	int m_engineValue;
	int m_playerScore;
	int m_userChoice;
	int m_passCount;
	int m_totalPips;

};