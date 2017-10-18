/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once

class fileFunctions
{
public:
	// Default constructor
	fileFunctions();

	// Function to ask the user for input
	void askForFile(string a_inMessage);

	// Checks to see if the entered filename is valid
	bool validFileName(string a_inFileName);

	// Function to append .txt to the end of a given filename
	string appendTxt(string a_inFileName);

	// This function will return a valid filename that the user
	// requested in the correct format ready for reading or writing
	string getFile(string a_inMessage);

	// Default destructor
	~fileFunctions();

private:
	string m_fileName;
};

