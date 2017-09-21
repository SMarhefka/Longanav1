#include "stdafx.h"
#include "validateInput.h"

bool validateInput::validateSelection(string a_input, int a_numOptions)
{
	if (atoi(a_input.c_str()) < 1 || atoi(a_input.c_str()) > a_numOptions)
	{
		return false;
	}
	return true;
}
