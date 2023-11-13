/*
*****************************************************************************
							  Parking.h
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    : 11/4/2022??
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
#include "Menu.h"
#include "Vehicle.h"
namespace sdds {
	//last milestone modification
	const int MAX_PARKING_LOT = 100;
	class Parking {
	private:
		char* m_filename{};
		Menu m_parkingMenu;
		Menu m_subMenu;
		bool m_valid;
		int m_selection;
		//last milestone modification
		int m_spotNum;
		Vehicle* m_parkSpot[MAX_PARKING_LOT];
		int m_parkedVehicle;
		//Private Member function
		bool isEmpty();
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles();
		void findVehicle();
		bool closeParking();
		bool exitParkingApp(); 
		bool loadDataFile(); 
		void saveDataFile(); 



	public:
		//last milestone modification
		Parking(const char* filename, int noOfSpots);
		~Parking();
		Parking(const Parking& parking) = delete;
		Parking& operator=(const Parking& parking) = delete;
		int run();
	};
}
#endif