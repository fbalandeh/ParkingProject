/*
*****************************************************************************
							  Vehicle.h
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include "ReadWritable.h"
#include "Utils.h"


namespace sdds {
	int const MAX = 8;
	int const MAX_MODEL = 60;
	class Vehicle : public ReadWritable {
	private:
		char m_plate[MAX + 1];
		char m_model[MAX_MODEL + 1];
		int m_spotNum;
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char* model);
	public:
		Vehicle();
		Vehicle(const char* plate, const char* model);
		~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int spot);
		Vehicle(const Vehicle& vehicle);
		Vehicle& operator=(const Vehicle& vehicle);
		bool operator==(const char* plate) const;
		bool operator==(const Vehicle& vehicle) const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		virtual std::ostream& writeType(std::ostream& ostr) const = 0;
		operator const char* () const;

	};
}
#endif