/*
*****************************************************************************
							  Motorcycle.h
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include "Vehicle.h"
#include "Utils.h"


namespace sdds {
	class Motorcycle : public Vehicle {
		bool m_sideCar;
	public:
		//no - argument constructor
		Motorcycle();
		//argument constructor
		Motorcycle(const char* plate, const char* model);
		//copy constrcutor
		Motorcycle(const Motorcycle& motorcycle);
		//assignment operator
		Motorcycle& operator=(const Motorcycle& motorcycle);
		//destructor
		~Motorcycle();
		//writeTpe function override
		std::ostream& writeType(std::ostream& ostr) const;
		//read function override
		std::istream& read(std::istream& istr);
		//write function override
		std::ostream& write(std::ostream& ostr) const;
	};
}
#endif