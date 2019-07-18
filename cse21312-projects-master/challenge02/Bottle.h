/*************************************
* File name: Bottle.h
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* Bottle header
* ***********************************/

#include "Date.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bottle {
friend std::ostream& operator<<(ostream&, Bottle&);
friend std::istream& operator>>(istream&, Bottle&);
public:

  /************************************************
  * Function Name: Bottle()
  * Preconditions: none
  * Postconditions: Object of Bottle class
  * 
  * This is the default constructor
  *************************************************/
  Bottle();

  
  /************************************************
  * Function Name: Bottle()
  * Preconditions: Bottle
  * Postconditions: Object of Bottle class
  * This is the copy constructor
  *************************************************/
  Bottle(const Bottle&); // copy constructor
	
  /************************************************
  * Function Name: Bottle()
  * Preconditions: string, int, date
  * Postconditions: Object of Bottle class
  * 
  * This is the initialization constructor 
  *************************************************/
  Bottle(string, int, Date);
  
  /************************************************
  * Function Name: ~Bottle()
  * Preconditions: none
  * Postconditions: none
  * This is the destructor
  *************************************************/
	~Bottle();

  /************************************************
  * Function Name: Bottle()
  * Preconditions: Bottle
  * Postconditions: Object of Bottle class
  * This is the assignment operator
  *************************************************/
  
  Bottle& operator=(const Bottle &);

  /************************************************
  * Function Name: setBottle()
  * Preconditions: string, int, Date
  * Postconditions: void
  * 
  * This sets all 3 elements of the private data
  *************************************************/
  void setBottle(string, int, Date);

  /************************************************
  * Function Name: getName()
  * Preconditions: none
  * Postconditions: string
  * 
  * This function is used to access the Name private data
  *************************************************/
  string getName() const;

  /************************************************
  * Function Name: getDate()
  * Preconditions: none
  * Postconditions: Date
  * 
  * This function is used to access the Date private data
	* that is when the bottle expires
  *************************************************/
  Date getDate() const;

  /************************************************
  * Function Name: getPills()
  * Preconditions: none
  * Postconditions: int
  * 
  * This function is used to access the number of
	* pills which is private data
  *************************************************/
  int getPills() const;

  
  /************************************************
  * Function Name: removePills()
  * Preconditions: int
  * Postconditions: void
  * 
  * This function is used to remove pills from a bottle
  *************************************************/
  void removePills(int); 

  /************************************************
  * Function Name: isExpired()
  * Preconditions: Date
  * Postconditions: bool
  * 
  * This function is used to compare two dates to check
	* if a bottle has expired elements
  *************************************************/
  bool isExpired(Date);
  
	/************************************************
  * Function Name: printCompare()
  * Preconditions: ostream &, Date
  * Postconditions: void
  * 
  * This function is used to print if a bottle is expire
	* and is only used in testBottle.cpp
  *************************************************/
  void printCompare(ostream &, Date);
  

private:
  string name; // name of the drug
  Date expDate; // expiration date
  int pills; // number of pills in the bottle aka lot number

};
