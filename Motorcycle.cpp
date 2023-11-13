/*
*****************************************************************************
							  Motorcycle.cpp
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Motorcycle.h"
#include "Utils.h"
#include <cstring>
#include <string.h>
#include <iostream>  
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

namespace sdds {
	//no - argument constructor
	Motorcycle::Motorcycle() {
		m_sideCar = false;
	}
	//argument constructor
	Motorcycle::Motorcycle(const char* plate, const char* model) : Vehicle(plate, model) {

	}
	//copy constrcutor
	Motorcycle::Motorcycle(const Motorcycle& motorcycle) : Vehicle(motorcycle) {
		m_sideCar = false;
		*this = motorcycle;
	}
	//assignment operator
	Motorcycle& Motorcycle::operator=(const Motorcycle& motorcycle) {
		if (this != &motorcycle) {
			// Base class assignment 
			(Vehicle&)*this = motorcycle;
			m_sideCar = motorcycle.m_sideCar;
		}
		return*this;
	}
	//destructor
	Motorcycle::~Motorcycle() {

	}
	//writeTpe function override
	std::ostream& Motorcycle::writeType(std::ostream& ostr) const {
		if (isCsv()) {
			ostr << "M,";
		}
		else {
			ostr << "Vehicle type: Motorcycle" << endl;
		}
		return ostr;
	}
	std::istream& Motorcycle::read(std::istream& istr) {
		//Comma Separated mode
		if (isCsv()) {
			Vehicle::read(istr);
			istr >> m_sideCar;
			istr.ignore(1000, '\n');
		}
		//Not Comma Separated
		else {
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			m_sideCar = getCarwash();
		}
		return istr;
	}
	//write function override
	std::ostream& Motorcycle::write(std::ostream& ostr) const {
		//Invalid empty state
		if (isEmpty()) {
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else {
			writeType(ostr);
			Vehicle::write(ostr);
			//Comma Separated mode
			if (isCsv()) {
				ostr << m_sideCar << endl;
			}
			//Not Comma Separated 
			else {
				if (m_sideCar) {
					ostr << "With Sidecar" << endl;
				}
			}
		}
		return ostr;
	};
}