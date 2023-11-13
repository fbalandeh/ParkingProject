/*
*****************************************************************************
							  ReadWritable.h
Full Name  : Fatemeh Balandeh
Student ID#: 174519215
Email      : fbalandeh@myseneca.ca
Date of completion    :  2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>
namespace sdds {
	class ReadWritable {
		bool m_flag;
	public:
		ReadWritable();
		virtual ~ReadWritable();

		virtual bool isCsv()const;
		virtual void setCsv(bool value);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
	};
	std::ostream& operator<<(std::ostream& os, const ReadWritable& s);
	std::istream& operator>>(std::istream& is, ReadWritable& s);
}
#endif