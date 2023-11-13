/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.0
// Date
// Author Fatemeh Balandeh
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Utils.h"
#include <iostream>
using namespace std;
namespace sdds {
	bool userInput(int x) {
		char input;
		bool test;
		bool validate = false;
		while (validate == false)
		{
			cin >> input;
			if ((input == 'y' || input == 'Y') && x == 1) {
				cin.clear();
				cin.ignore(1000, '\n');
				validate = true;
				test = false;
			}
			else if ((input == 'n' || input == 'N') && x == 1) {
				cin.clear();
				cin.ignore(1000, '\n');
				validate = true;
				test = true;
			}
			else if ((input == 'y' || input == 'Y') && x == 2) {
				cout << "Exiting program!" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				validate = true;
				test = false;
			}
			else if ((input == 'n' || input == 'N') && x == 2) {
				cin.clear();
				cin.ignore(1000, '\n');
				validate = true;
				test = true;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin.clear();
				cin.ignore(1000, '\n');
				validate = false;
				test = true;
			}
		}
		return test;
	}
	void strcpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; src[i] && (len < 0 || i < len); i++) {
			des[i] = src[i];
		}
		des[i] = 0;
	}
	int strlen(const char* str) {
        int len = 0;
        while (str[len]) {
            len++;
        }
        return len;
    }
	int userInputInt(int min, int max) { //valdidating user input to be in the desired range
		int input;
		bool validate = false;

		while (validate == false)
		{
			cin >> input;
			if (!cin) {
				cout << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				validate = false;
			}
			else if (input <= min || input > max) {
				cout << "Invalid selection, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				validate = false;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				validate = true;
			}

		}

		return input;
	}
	bool getCarwash() {
		std::string temp;
		bool ret;
		bool validate = false;
		while (validate == false)
		{
			cin >> temp;

			if (temp == "y" || temp == "Y") {
				cin.clear();
				cin.ignore(1000, '\n');
				ret = true;
				validate = true;
			}
			else if (temp == "n" || temp == "N") {
				cin.clear();
				cin.ignore(1000, '\n');
				ret = false;
				validate = true;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				validate = false;
			}

		}
		return ret;
	}
	int strcmp(const char* s1, const char* s2) {
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}
}