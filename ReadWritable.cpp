/*
*****************************************************************************
							  ReadWritable.cpp
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "ReadWritable.h"
#include "Utils.h"
#include <cstring>
#include<iostream>  
using namespace std;

namespace sdds {
	ReadWritable::ReadWritable() {
		m_flag = false;
	}
	ReadWritable::~ReadWritable() {

	}
	bool ReadWritable::isCsv()const {
		return m_flag;
	}
	void ReadWritable::setCsv(bool value) {
		m_flag = value;
	}
	std::ostream& operator<<(std::ostream& os, const ReadWritable& s) {
		return s.write(os);
	}
	std::istream& operator>>(std::istream& is, ReadWritable& s) {
		return (s.read(is));
	}
}