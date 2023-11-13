/*v
*****************************************************************************
							  Car.h
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include "Utils.h"


namespace sdds {
	class Car : public Vehicle {
		bool m_carWash;
	public:
		//no - argument constructor
		Car();
		//argument constructor
		Car(const char* plate, const char* model);
		//copy constrcutor
		Car(const Car& car);
		//assignment operator
		Car& operator=(const Car& car);
		//destructor
		~Car();
		//writeTpe function override
		std::ostream& writeType(std::ostream& ostr) const;
		//read function override
		std::istream& read(std::istream& istr);
		//write function override
		std::ostream& write(std::ostream& ostr) const;
	};
}
#endif