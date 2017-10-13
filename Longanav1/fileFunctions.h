#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>
#include <cstring>
#include "validateInput.h"

using namespace std;

class fileFunctions
{
public:
	fileFunctions();
	~fileFunctions();

	// gets the input file from the user
	string getInputFile();
	// gets the output file from the user
	string getOutputFile();
	// function to append .txt to the end of a given filename
	string appendTxt(string a_inFileName);

private:
	validateInput* m_tempValid;
};

