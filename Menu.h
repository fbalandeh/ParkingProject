/*
*****************************************************************************
							  Menu.h
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
namespace sdds {
	const int  MAX_CHAR = 50;
	const int  MAX_NO_OF_ITEMS = 10;
	class MenuItem {
	private:
		char m_name[MAX_CHAR + 1];

		// member functions
		MenuItem();
		MenuItem(const char* name);
		void setEmpty();
		std::ostream& display(std::ostream& ostr = std::cout) const;
		operator bool() const;
		MenuItem(const MenuItem& menuItem) = delete;
		MenuItem& operator=(const MenuItem& menuItem) = delete;
		friend class Menu;
	};
	class Menu {
		char m_title[MAX_CHAR + 1];
		MenuItem m_menuItems[MAX_NO_OF_ITEMS];
		int m_indentation = 0;
		int m_item = 0; // keep track of the number of items 
		bool m_valid = true;
	public:
		Menu();
		Menu(const char* title);
		Menu(const char* title, int indentation);
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;
		operator bool() const;
		operator int() const;
		Menu& operator=(const char* title);
		bool isEmpty();
		void clear();
		void add(const char* option);
		std::ostream& display(std::ostream& ostr = std::cout) const;
		Menu& operator<<(const char* menuitemContent);
		int run() const;
	};
}
#endif