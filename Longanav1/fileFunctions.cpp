#include "stdafx.h"
#include "fileFunctions.h"


fileFunctions::fileFunctions()
{
	m_tempValid = new validateInput;
}

string fileFunctions::getInputFile()
{
	string fileName;
	cout << "Enter name of the file that you want to load from" << endl;
	cout << "Filename: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> fileName;

	while (m_tempValid->validFileName(fileName) != true)
	{
		cout << "Invalid Filename - Please enter a valid filename" << endl;
		cout << "Filename: ";
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> fileName;
		cout << endl;
	}
	/*----Get File Info----*/

	/*----Check for '.txt' in filename----*/
	fileName = appendTxt(fileName);
	/*----Check for '.txt' in filename----*/

	// return the fileName
	return fileName;
}

string fileFunctions::appendTxt(string a_inFileName)
{
	string outputFile = a_inFileName;
	regex fileEnding("(.txt$)");
	/*----Check for '.txt' in filename----*/
	if (regex_match(outputFile, fileEnding) != true)
	{
		outputFile.append(".txt");
	}
	/*----Check for '.txt' in filename----*/

	return outputFile;
}

string fileFunctions::getOutputFile()
{
	string fileName;
	cout << "Enter name of the file that you want to save to: ";
	cout << "Filename: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> fileName;

	while (m_tempValid->validFileName(fileName) != true)
	{
		cout << "Invalid Filename - Please enter a valid filename" << endl;
		cout << "Filename: ";
		//clear the error state
		cin.clear();
		//ignore all characters left in the buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> fileName;
		cout << endl;
	}

	/*----Check for '.txt' in filename----*/
	fileName = appendTxt(fileName);
	/*----Check for '.txt' in filename----*/

	// return the fileName
	return fileName;
}

fileFunctions::~fileFunctions()
{
}
