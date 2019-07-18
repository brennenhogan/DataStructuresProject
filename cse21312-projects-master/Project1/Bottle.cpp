/*************************************
* File name: Bottle.cpp
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* Bottle implementation
* SEE HEADER FILE FOR FUNCTION HEADERS
* ***********************************/

#include <iostream>
#include <string>
#include "Bottle.h"
using namespace std;

Bottle::Bottle() 
{
  Date d(1, 1, 2019);
  setBottle("No Name", 0, d);
}

Bottle::Bottle(const Bottle &bot) // copy constructor
{
  setBottle(bot.getName(), bot.getPills(), bot.getDate());
}

Bottle::Bottle(string n, int p, Date d) // name, pills, expDate
{
  setBottle(n, p, d);
}

Bottle& Bottle::operator=(const Bottle &b) // assignment operator
{ 
  name = b.name;
  pills = b.pills;
  expDate = b.expDate;
}

void Bottle::setBottle(string n, int p, Date expD)
{
  name = n;
  pills = p;
  expDate = expD;
}

Bottle::~Bottle() 
{ }

string Bottle::getName() const
{ return name; }

Date Bottle::getDate() const
{ return expDate; }

int Bottle::getPills() const
{ return pills; }

void Bottle::removePills(int num)
{
  pills -= num; 
}

bool Bottle::isExpired(Date check)
{ return expDate.isBefore(check); }

void Bottle::printCompare(ostream &os, Date check)
{ 
  os << "The check date " << check << " "; // << operator already overloaded for Date class
  if (isExpired(check)){
    os << "is the same day or after the initial date " << expDate << endl;
		os << "The bottle is expired" << endl;
	}
  else 
    os << "is before the initial date " << expDate << endl;
}

std::ostream& operator<< (std::ostream& os, Bottle& bot)
{
  os << bot.name << ". PILLS = " << bot.pills << ". EXP: " << bot.expDate; 
}

std::istream& operator>> (std::istream& is, Bottle& bot)
{
 string name;
 int year, month, day, pills;
 is >> name >> pills >> year >> month >> day;
 Date d(day, month, year);
 bot.setBottle(name, pills, d);
}

bool Bottle::operator< (const Bottle& comp)
{
  if(this->name.compare(comp.name)<0)
    return true;
  else
    return false;
}

bool Bottle::operator> (const Bottle& comp)
{
  if(this->name.compare(comp.name)>0)
    return true;
  else
    return false;
}

bool Bottle::operator== (const Bottle& comp)
{
  if(this->name.compare(comp.name)==0)
    return true;
  else
    return false;
}

bool Bottle::operator!= (const Bottle& comp){
  if(this->name.compare(comp.name)!=0)
    return true;
  else
    return false;
}    
