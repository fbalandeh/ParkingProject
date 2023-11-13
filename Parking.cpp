/*
*****************************************************************************
                              Parking.cpp
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Menu.h"
#include "Parking.h"
#include "Motorcycle.h"
#include "Car.h"
#include "ReadWritable.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>
#include <fstream>
#include<iostream>  
using namespace std;

namespace sdds {
    Parking::Parking(const char* filename, int noOfSpots) :m_parkingMenu("Parking Menu, select an action:"), m_subMenu("Select type of the vehicle:", 1) {
        //**
        if (noOfSpots < 10 || noOfSpots > MAX_PARKING_LOT) {
            m_valid = false;
        }
        else {
            m_spotNum = noOfSpots;
            m_parkedVehicle = noOfSpots;
        }
        for (int i = 0; i < MAX_PARKING_LOT; i++)
            m_parkSpot[i] = nullptr;
        //If the string is nullptr or empty then Parking is set to an invalid empty state.
        if (filename == nullptr || filename[0] == '\0') {
            //set to an invalid empty state.
            m_valid = false;
            cout << "Error in data file" << endl;
        }
        else {
            m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
            m_subMenu.add("Car");
            m_subMenu.add("Motorcycle");
            m_subMenu.add("Cancel");
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            m_valid = true;
            loadDataFile();
        }
       
    }
    Parking::~Parking() { //incomplete
        //Call the Save Data File function (see list of member functions),
        saveDataFile();
        //and Make sure there is no memory leak when the Parking goes out of scope.
        delete[] m_filename;
        for (int i = 0; i < MAX_PARKING_LOT; i++) {
            if (m_parkSpot[i] != nullptr) {
                delete m_parkSpot[i];
            }

        }
       
    }
    int Parking::run() {
        //If the Parking is not in an invalid empty state:
        if (!isEmpty()) {
            bool valid = false;
            do {
                //The Run function calls the Parking Status function 
                parkingStatus();
                if ((m_selection = m_parkingMenu.run()) == 1) {
                    if ((m_selection = m_subMenu.run())) {
                        parkVehicle();
                    }
                    valid = true;
                }
                else if (m_selection == 2) {
                    returnVehicle();
                    valid = true;
                }
                else if (m_selection == 3) {
                    listParkedVehicles();
                    valid = true;
                }
                else if (m_selection == 4) {
                    findVehicle();
                    valid = true;
                }
                else if (m_selection == 5) {
                    valid = closeParking();
                }
                else if (m_selection == 6) {
                    valid = exitParkingApp();
                }
            } while (valid);
        }
        return 1;
    }
    bool Parking::isEmpty() {
        //returns true if the Parking is in an invalid empty State 
        //or false if the parking is valid and usable.
        return(!(m_valid));
    }
    void Parking::parkingStatus() const {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout << setw(4) << left << m_spotNum;
        cout << " *****" << endl;
    }
    void Parking::parkVehicle() {
        if (!m_spotNum) {
            cout << "Parking is full";
        }
        int temp = m_spotNum;
        if (m_selection == 1) {
            //create a car to park
            bool flag = true;
            Vehicle* car = nullptr;
            car = new Car;
            car->setCsv(false);
            car->read(cin);
            
            for (int i = 0;flag &&  i < MAX_PARKING_LOT; i++) {
                if (m_parkSpot[i] == nullptr) {
                    m_spotNum = i + 1;
                    car->setParkingSpot(m_spotNum);
                    m_parkSpot[i] = car;
                    m_spotNum = (temp - 1);
                    flag = false;
                }
            }
            cout << endl;
            cout << "Parking Ticket" << endl;
            
            car->write(cout);
            cout << endl << "Press <ENTER> to continue...." << endl;
        }
        else if (m_selection == 2) {
            //create a motorcycle to park
            bool flag = true;
            Vehicle* motorcycle = nullptr;
            motorcycle = new Motorcycle;
            motorcycle->setCsv(false);
            motorcycle->read(cin);

            for (int i = 0;flag && i < MAX_PARKING_LOT; i++) {
                if (m_parkSpot[i] == nullptr) {
                    m_spotNum = i + 1;
                    motorcycle->setParkingSpot(m_spotNum);
                    m_parkSpot[i] = motorcycle;
                    m_spotNum = (temp - 1);
                    flag = false;
                }
            }
            cout << endl;
            cout << "Parking Ticket" << endl;

            motorcycle->write(cout);
            cout << endl << "Press <ENTER> to continue...." << endl;
        }
        else if (m_selection == 3) {
            cout << "Parking Cancelled" << endl;
        }
        m_selection = 0;
    }
    void Parking::returnVehicle() {

        char plate[10];
        const char* cPlate = plate;
        bool flag;
        int numFound = 0;
        cout << "Return Vehicle" << endl;
        cout << "Enter License Plate Number: ";
        cin.getline(plate, 10);
        cout << endl;
        int lenght = strlen(plate);
        do {
            if (lenght > 8 || lenght < 1) {
                cout << "Invalid Licence Plate, try again: ";
                cout.clear();
                cin.getline(plate, 10);
                flag = true;
            }
            else {
                flag = false;
            }
        } while (flag);
        for (int i = 0; i < lenght; i++) {
            plate[i] = toupper(plate[i]);
        }

        for (int i = 0; i < m_parkedVehicle; i++) {
            if ( m_parkSpot[i] != nullptr && * (m_parkSpot[i]) == cPlate) {
                cout << "Returning:" << endl;
                m_parkSpot[i]->setCsv(false);
                m_parkSpot[i]->write(cout);
                numFound += 1;
                cout << endl;
                m_spotNum++;
                delete m_parkSpot[i];
                m_parkSpot[i] = nullptr;
            }
        }
        if (numFound == 0) {
            
            cout << "License plate " << plate << " Not found" << endl << endl;
        }
        cout << "Press <ENTER> to continue...." << endl;
    }
    void Parking::listParkedVehicles() {
        cout << "*** List of parked vehicles ***" << endl;
        for (int i = 0; i < (m_parkedVehicle); i++) {
            if (m_parkSpot[i] != nullptr) {
                m_parkSpot[i]->setCsv(false);
                m_parkSpot[i]->write(cout);
                cout << "-------------------------------" << endl;
            }
        }
        cout << "Press <ENTER> to continue...." << endl;
    }
    void Parking::findVehicle() {

        char plate[10];
        const char* cPlate = plate;
        bool flag;
        int numFound = 0;
        cout << "Vehicle Search" << endl;
        cout << "Enter Licence Plate Number: ";
        cin.getline(plate, 10);
        
        int lenght = strlen(plate);
        do {
            if (lenght > 8 || lenght < 1) {
                cout << "Invalid Licence Plate, try again: ";
                cout.clear();
                cin.getline(plate, 10);
                flag = true;
            }
            else {
                flag = false;
            }
        } while (flag);
        for (int i = 0; i < lenght; i++) {
            plate[i] = toupper(plate[i]);
        }
        
        for (int i = 0; i < m_parkedVehicle; i++) {
            if (m_parkSpot[i] != nullptr && *(m_parkSpot[i]) == cPlate) {
                cout << endl << "Vehicle found:" << endl;
                m_parkSpot[i]->setCsv(false);
                m_parkSpot[i]->write(cout);
                numFound += 1;
                cout << endl;
            }
        }
        if (numFound == 0) {
            cout << endl;
            cout << "License plate " << plate << " Not found" << endl << endl;
        }
        cout << "Press <ENTER> to continue...." << endl;
    }
    bool Parking::closeParking() {
        bool input;
        cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        input = userInput(1);
        if (!input) {
            cout << "Closing Parking" << endl << endl;
            for (int i = 0; i < m_parkedVehicle; i++) {
                if (m_parkSpot[i] != nullptr) {
                    cout << "Towing request" << endl;
                    cout << "*********************" << endl;
                    m_parkSpot[i]->setCsv(false);
                    m_parkSpot[i]->write(cout);
                    if (i != (m_parkedVehicle - 1)) {
                        cout << endl;
                    }
                    delete m_parkSpot[i];
                    m_parkSpot[i] = nullptr;
                }
            }
            return input;
        }
        else {
            return input;
        }
        

    }
    bool Parking::exitParkingApp() {
        char input;
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        input = userInput(2);
        return input;

    }
    bool Parking::loadDataFile() {
        //create a temprary vehicle pointer 
        Vehicle* temp = nullptr;

        if (!isEmpty()) {

            ifstream myfile;
            char ch;
            myfile.open(m_filename);
            if (!(myfile.is_open()) || isEmpty()) {
                return true;
            }
            else {
                for (int i = 0; myfile && i < MAX_PARKING_LOT; i++) {
                    //reading the first char
                    myfile >> ch;
                    myfile.ignore();

                    if (ch) {
                        
                        if (ch == 'M') {
                            temp = new Motorcycle;
                            temp->setCsv(true);

                        }
                        else if (ch == 'C') {
                            temp = new Car;
                            temp->setCsv(true);

                        }
                        if (!temp) {
                            return false;
                        }
                    }
                    if (temp) {
                        myfile >> *temp;
                        int m = temp->getParkingSpot();
                        
                        if (!m){
                            delete temp;
                            temp = nullptr;
                        }
                        else {
                            m_parkSpot[temp->getParkingSpot() - 1] = temp;
                            m_spotNum--;
                        }
                    }
                }
            }
            return true;
        }
        
        return false;
    }
    void Parking::saveDataFile() {
        if (!isEmpty()) {

            ofstream out_file(m_filename);
            for (int i = 0; i < m_parkedVehicle; i++) {
                if (m_parkSpot[i] != nullptr) {
                    m_parkSpot[i]->setCsv(true);
                    out_file << *m_parkSpot[i];
                }
            }
        }
    }


}