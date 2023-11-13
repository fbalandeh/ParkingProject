/***********************************************************************
// Utils Module
// File  utils.h
// Version 0.0
// Date
// Author
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {
	bool userInput(int x);
	void strcpy(char* des, const char* src, int len = -1);
	int userInputInt(int min, int max);
	int strlen(const char* str);
	bool getCarwash();
	int strcmp(const char* s1, const char* s2);
}
#endif