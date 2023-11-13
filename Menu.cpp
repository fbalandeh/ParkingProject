/*
*****************************************************************************
                              Menu.cpp
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    : 2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <iostream>    
#include <array>
using namespace std;

namespace sdds {
    // MenuItem class:

    MenuItem::MenuItem() {                  //Construction:
        setEmpty();
    }

    MenuItem::MenuItem(const char* name) {  // setting m_name
        if (m_name == NULL) {
            strcpy(m_name, name);
        }
        else {
            setEmpty();
        }
    }
    void MenuItem::setEmpty() {            //setting to empty state
        m_name[0] = '\0';
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const { //display function 
        if (*this) {
            ostr << m_name;
        }

        return ostr;
    }
    MenuItem::operator bool() const {
        return (m_name != NULL);
    };


    // MenuItem class:
    Menu::Menu() {
        m_item = 0;
    }
    Menu::Menu(const char* title) { //setting m_title
        if (title != NULL) {
            strcpy(m_title, title);
            m_indentation = 0;
        }
    }
    Menu::Menu(const char* title, int indentation) { // setting m_title and m_indentation
        if (title != NULL) {
            strcpy(m_title, title);
            if (indentation > 0)
                m_indentation = indentation;

        }
    }
    Menu::operator bool() const { //bool cast overload
        return (m_title != NULL && m_item > 0);
    }
    Menu::operator int() const { //int cast overload
        return this->run();
    }
    bool Menu::isEmpty() {
        //returns true if the Menu is in an invalid empty State or false if it is valid and usable
        return(m_title == NULL && !m_item);
    }
    std::ostream& Menu::display(std::ostream& ostr) const { //display function
        if (*this) {

            ostr << string((m_indentation * 4), ' ') << m_title << endl;
            for (int i = 0; i < m_item; i++)
            {
                ostr << string((m_indentation * 4), ' ') << i + 1 << "- ";
                m_menuItems[i].display(ostr);
                ostr << endl;
            }
            ostr << string((m_indentation * 4), ' ') << "> ";

        }
        else if (m_item == 0) {
            ostr << m_title << endl;
            ostr << "No Items to display!" << endl;
        }
        else {
            ostr << "Invalid Menu!" << endl;
        }
        return ostr;
    }
    Menu& Menu::operator=(const char* title) { //assigned to a constant character C-string
        if (title != NULL) {
            strcpy(m_title, title);
        }
        return *this;
    }
    void Menu::clear() { //no item
        m_item = 0;
    }
    void Menu::add(const char* option) { //add items the same way as left shift operator overload 
        if (option != nullptr) {
            *this << option;
        }
        else {
            m_title[0] = '\0';
            m_item = -1;
        }
    }
    Menu& Menu::operator<<(const char* menuitemContent) { // add item 
        if (menuitemContent != nullptr && m_valid) {
            if (m_item < MAX_NO_OF_ITEMS) {
                strcpy(m_menuItems[m_item].m_name, menuitemContent);
                m_item++;

            }
        }
        else {
            m_title[0] = '\0';
            m_item = -1;
            m_valid = false;
        }
        return *this;
    }
    int Menu::run() const {
        int input = 0;

        display();
        if (*this) {
            input = userInputInt(0, m_item);
        }

        return input;
    }


}