/*************************************
 * File name: Date.cpp
 * Author: Jack Olmanson, Brennan Hogan, Brendan Sailer
 * Email: jolmanso@nd.edu, bhogan1@nd.edu, bsailer1@nd.edu
 *
 * This file is the implementation of the Date class and
 * contains the methods necessary to work with our main
 * driver file testDate.cpp
 * SEE HEADER FILE FOR FUNCTION HEADER COMMENTS
 * ***********************************/

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;


Date::Date()  // Default Constructor
{ 
  setDate(1, 1, 1);
}

Date::Date(int d, int m, int y) // Parametrized Constructor
{
  setDate(d, m, y);
}

Date::~Date() // Destructor
{ }

void Date::setDate(int day, int month, int year)
{
  this->day = day;
  this->month = month;
  this->year = year;
  alphaMonth();  
}

int Date::getDay()
{ return day; }

int Date::getMonth()
{ return month; }

int Date::getYear()
{ return year; }

void Date::alphaMonth() // takes stored month value and converts to the 3 letter abbreviation for months
{
  string months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
  strMonth = months[month-1]; // returns the number month into letters and stores it the objects private data
}


bool Date::isBefore(Date check) // check to see if the expiration date is before the check date (basically returns 1 if expired)
                                // inputting the test date; ex: exDate.compareDates(checkDate)
{
  if (this->year > check.getYear()){ // if the check year is larger than the expiration year (and therefore is later than it) we will return 1. If they are the same, we will do more tests
 return 0; }
  else if (year - check.getYear() == 0 && month - check.getMonth() > 0) // if the check month is after, it is expired
    return 0;
  else if (month - check.getMonth() == 0 && day - check.getDay() > 0) // if the check date is the same or larger than the expiration date, then it is expired.
    return 0;
  else // if it fails all of the tests, it is expired
    return 1;
}

ostream& operator<< (ostream & os, Date & d) // Overloaded output operator
{
  if (d.day < 10)                            // format single digit dates like 02 instead of 2
    os << d.year << " " << d.strMonth << " 0" << d.day; 
  else
    os << d.year << " " << d.strMonth << " " << d.day;

  return os;
}

