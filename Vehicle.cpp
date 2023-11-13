/*
*****************************************************************************
							  Vehicle.cpp
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "ReadWritable.h"
#include "Vehicle.h"
#include "Utils.h"
#include <cstring>
#include<iostream>  
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>


using namespace std;

namespace sdds {
	Vehicle::Vehicle() {
		setEmpty();

	}
	Vehicle::Vehicle(const char* plate, const char* model) {
		if ((plate != nullptr && plate[0]) && (strlen(plate) <= 8) && (model != nullptr && model[0]) && (strlen(model) > 1)) {
			m_spotNum = 0;
			strcpy(m_plate, plate);
			strcpy(m_model, model);
		}
		else {
			setEmpty();
		}
	}
	Vehicle::~Vehicle() {

	}
	Vehicle::Vehicle(const Vehicle& vehicle) {
		setEmpty();
		*this = vehicle;
	}
	Vehicle& Vehicle::operator=(const Vehicle& vehicle) {
		if (vehicle.m_model != nullptr) {
			strcpy(m_model, vehicle.m_model);
		}
		else {
			setEmpty();
		}
		strcpy(m_plate, vehicle.m_plate);
		setCsv(vehicle.isCsv());
		m_spotNum = vehicle.m_spotNum;
		return *this;
	}
	void Vehicle::setEmpty() {
		m_plate[0] = '\0';
		m_model[0] = '\0';
		m_spotNum = 0;
	}
	bool Vehicle::isEmpty() const {
		return((m_plate[0] == '\0') && (m_model[0] == '\0') && (m_spotNum == 0));
	}
	const char* Vehicle::getLicensePlate() const {
		return m_plate;
	}
	const char* Vehicle::getMakeModel() const {
		return m_model;
	}
	int Vehicle::getParkingSpot() const {
		return m_spotNum;
	}
	void Vehicle::setMakeModel(const char* model) {

		if (model != nullptr) {
			strcpy(m_model, model);
		}
		else {
			setEmpty();
		}
	}
	Vehicle::operator const char* () const {
		return m_model;
	}
	void Vehicle::setParkingSpot(int spot) {
		if (spot > 0) {
			m_spotNum = spot;
		}
		else {
			setEmpty();
		}
	}
	bool Vehicle::operator==(const char* plate) const {
		int count = 0;
		if (strlen(plate) == strlen(m_plate)) {
			for (int i = 0; i < strlen(plate); i++) {
				if (toupper(m_plate[i]) == plate[i]) {
					count++;
				}
				else if (tolower(m_plate[i]) == plate[i]) {
					count++;
				}
			}
		}
		return (count == strlen(plate));
	}
	bool Vehicle::operator==(const Vehicle& vehicle) const {
		int count = 0;
		for (int i = 0; i < strlen(vehicle.m_plate); i++) {
			if (toupper(m_plate[i]) == vehicle.m_plate[i]) {
				count++;
			}
			else if (tolower(m_plate[i]) == vehicle.m_plate[i]) {
				count++;
			}
		}
		return (count == strlen(vehicle.m_plate));
	}
	std::ostream& Vehicle::write(std::ostream& ostr) const {
		if (isEmpty()) {
			ostr << "Invalid Vehicle Object" << endl;
		}
		else {
			if (isCsv()) {
				ostr << m_spotNum << "," << m_plate << "," << m_model << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				(m_spotNum != 0) ? ostr << m_spotNum << endl : ostr << "N/A" << endl;
				ostr << "License Plate: " << m_plate << endl;
				ostr << "Make and Model: " << m_model << endl;
			}
		}
		return ostr;
	}
	std::istream& Vehicle::read(std::istream& istr) {
		setEmpty();
		if (isCsv()) {
			// Local variables
			char plate[MAX + 1];
			char model[MAX_MODEL + 1];

			// Get the spotnum
			istr >> m_spotNum;
			istr.ignore(1, ','); // ignore comma
			istr.getline(plate, MAX, ',');

			// Turn it to uppercase
			for (int i = 0; i < strlen(plate); i++)
				plate[i] = toupper(plate[i]);

			// Get plate
			strcpy(m_plate, plate);

			// Get model
			istr.getline(model, MAX_MODEL, ',');
			strcpy(m_model, model);
		}
		else {

			setEmpty();
			char plate[10];
			char model[MAX_MODEL + 1];
			bool flag;
			cout << "Enter License Plate Number: ";
			istr.getline(plate, 10);
			do {
				if (strlen(plate) > MAX) {
					cout << "Invalid Licence Plate, try again: ";
					istr.clear();
					istr.getline(plate, 10);
					flag = true;
				}
				else {
					for (int i = 0; i < strlen(plate); i++)
						plate[i] = toupper(plate[i]);
					strcpy(m_plate, plate);
					flag = false;
				}
			} while (flag);

			cout << "Enter Make and Model: ";
			istr.getline(model, MAX_MODEL + 1);
			do {
				if (strlen(model) > MAX_MODEL || strlen(model) < 2) {
					cout << "Invalid Make and model, try again: ";
					istr.clear();
					istr.getline(model, 10);
					flag = true;
				}
				else {
					strcpy(m_model, model);
					flag = false;
				}
			} while (flag);

			if (!istr) {
				setEmpty();
			}
		}
		return istr;
	}
	std::ostream& Vehicle::writeType(std::ostream& ostr) const {

		return ostr;
	}
}