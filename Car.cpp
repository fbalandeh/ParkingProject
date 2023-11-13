/*
*****************************************************************************
							  Car.cpp
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Car.h"
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
	Car::Car() {
		m_carWash = false;
	}
	//argument constructor
	Car::Car(const char* plate, const char* model) : Vehicle(plate, model) {

	}
	//copy constrcutor
	Car::Car(const Car& car) : Vehicle(car) {
		m_carWash = false;
		*this = car;
	}
	//assignment operator
	Car& Car::operator=(const Car& car) {
		if (this != &car) {
			// Base class assignment 
			(Vehicle&)*this = car;
			m_carWash = car.m_carWash;
		}
		return*this;
	}
	//destructor
	Car::~Car() {

	}
	//writeTpe function override
	std::ostream& Car::writeType(std::ostream& ostr) const {
		if (isCsv()) {
			ostr << "C,";
		}
		else {
			ostr << "Vehicle type: Car" << endl;
		}
		return ostr;
	}
	std::istream& Car::read(std::istream& istr) {
		//Comma Separated mode
		if (isCsv()) {
			Vehicle::read(istr);
			istr >> m_carWash;
			istr.ignore(1000, '\n');
		}
		//Not Comma Separated
		else {
			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			m_carWash = getCarwash();
		}
		return istr;
	}
	//write function override
	std::ostream& Car::write(std::ostream& ostr) const {
		//Invalid empty state
		if (isEmpty()) {
			ostr << "Invalid Car Object" << endl;
		}
		else {
			writeType(ostr);
			Vehicle::write(ostr);
			//Comma Separated mode
			if (isCsv()) {
				ostr << m_carWash << endl;
			}
			//Not Comma Separated 
			else {
				if (m_carWash) {
					ostr << "With Carwash" << endl;
				}
				else {
					ostr << "Without Carwash" << endl;
				}
			}
		}
		return ostr;
	};
}