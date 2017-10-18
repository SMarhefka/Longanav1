/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#include "stdafx.h"
#include "fileFunctions.h"

/************************************************************************
Function Name: fileFunctions()
Purpose: Default constructor

Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm:
1. Set the private variable m_fileName to an empty string
Assistance Received: None
************************************************************************/
fileFunctions::fileFunctions()
{
	m_fileName = "";
}

/************************************************************************
Function Name: getFile(string a_inMessage)
Purpose: Return a valid filename that the user requested in the correct
		 format ready for reading or writing

Parameters:
string a_inMessage --> the message to be diplayed to the user

Return Value: string
Local Variables: None
Algorithm:
1. Call the askForFile(a_inMessage) function which will ask the user
   for a fileName.
2. Once given a valid fileName call appendTxt() to see if a .txt
   extension needs to be added onto the fileName
3. Return the updated fileName to the caller function

Assistance Received: None
************************************************************************/
string fileFunctions::getFile(string a_inMessage)
{
	askForFile(a_inMessage);
	appendTxt(m_fileName);
	return m_fileName;
}

/************************************************************************
Function Name: askForFile(string a_inMessage)
Purpose: Function to ask the user for input
Parameters:
string a_inMessage --> the message to be diplayed to the user

Return Value: None
Local Variables:
string fileName --> stores the name of the file given to us by the user

Algorithm:
1. Print out the message stored in a_inMessage for the user
2. Clear the input buffer and wait for user input
3. Once user provides an input check to see if it is valid by calling
   the validFileName(fileName) function.  If the user input is not valid
   display an error message and wait for new input
4. Once a valid filename is given then set it to the private 
   variable m_fileName

Assistance Received: None
************************************************************************/
void fileFunctions::askForFile(string a_inMessage)
{
	string fileName = "";
	cout << a_inMessage << endl;
	cout << "Filename: ";

	//getline(cin, fileName).clear();
	getline(cin, fileName);

	while (validFileName(fileName) != true || fileName.length() == 0)
	{
		//clear the error state
		cin.clear();
		cout << endl;
		cout << "Invalid Filename - Please enter a valid filename" << endl;
		cout << "Filename: ";

		getline(cin, fileName);
		cout << endl;
	}

	m_fileName = fileName;
}

/************************************************************************
Function Name: validFileName(string a_inFileName)
Purpose: Checks to see if the entered filename is valid
Parameters:
string a_inFileName --> the fileName that needs to be checked

Return Value: bool
Local Variables: None
Algorithm:
1. Set the invalidPattern to check against the file. An invalid file
   is any string that has a symbol before any alphabetical values
2. If regex_match returns true then the filename given is invalid.
   Otherwise it is safe to assume that the filename given is valid.

Assistance Received: None
************************************************************************/
bool fileFunctions::validFileName(string a_inFileName)
{
	regex invalidPatten("(([^\\w]+)(.*))");
	if (regex_match(a_inFileName, invalidPatten))
	{
		return false;
	}
	return true;
}

/************************************************************************
Function Name: appendTxt(string a_inMessage)
Purpose: Function to append .txt to the end of a given filename
Parameters:
string a_inFileName --> the fileName that needs to be checked

Return Value: String
Local Variables: None
Algorithm:
1. Set the search pattern to .txt at the end of a string
2. Set m_fileName to a_inMessage
3. If regex_match returns false then .txt has to be added to the end of
   the filename string. Otherwise nothing needs to be done.
4. Return the m_fileName.  This is used when the append function is being
   called from the gameRound or tournament class.
Assistance Received: None
************************************************************************/
string fileFunctions::appendTxt(string a_inMessage)
{
	regex fileEnding("(.txt$)");
	m_fileName = a_inMessage;
	if (regex_match(m_fileName, fileEnding) != true)
	{
		m_fileName.append(".txt");
	}
	return m_fileName;
}

/************************************************************************
Function Name: ~fileFunctions()
Purpose: Default Destructor
Parameters: None
Return Value: Constructor
Local Variables: None
Algorithm: None
Assistance Received: None
************************************************************************/
fileFunctions::~fileFunctions()
{
}