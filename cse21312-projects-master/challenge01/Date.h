/*************************************
 * File name: Date.h
 * Author: Jack Olmanson, Brennan Hogan, Brendan Sailer
 * Email: jolmanso@nd.edu, bhogan1@nd.edu, bsailer1@nd.edu
 * 
 * This is the header file for the Date class
 * See the implementation (Date.cpp) for more info
 * ***********************************/

#include <string>
using namespace std;


class Date 
{
/************************************************
* Function Name: operator<< overload
* Preconditions: ostream &, Date &
* Postconditions: ostream&
* 
* This friend function overloads the << output
* operator which is useful in the main driver
*************************************************/
friend ostream& operator<< (ostream &, Date &);
private:
  int day, month, year;
  string strMonth;
public:
  /************************************************
  * Function Name: Default Constructor
  * Preconditions: none
  * Postconditions: Object of the date class
  * 
  * This default constructor ensures that no objects
  * is instantiated without the necessary private data
  *************************************************/
  Date();

  /************************************************
  * Function Name: Parametrized Constructor
  * Preconditions: int day, int month, int year
  * Postconditions: Object of the date class
  * 
  * This parametrized constructor instantiates an object
  * with the passed data.
  *************************************************/
  Date(int day, int month, int year);


  /************************************************
  * Function Name: Deconstructor
  * Preconditions: none
  * Postconditions: none
  * 
  * This deconstructor deletes objects 
  *************************************************/
  ~Date();
  
  /************************************************
  * Function Name: setDate()
  * Preconditions: int day, int month, int year
  * Postconditions: void
  * 
  * This function allows private data of an object
  * to be set
  *************************************************/
  void setDate(int day, int month, int year);
  
  /************************************************
  * Function Name: getDay()
  * Preconditions: none
  * Postconditions: int
  * 
  * This function allows access to the day private data
  *************************************************/
  int getDay();

  /************************************************
  * Function Name: getMonth()
  * Preconditions: none
  * Postconditions: int
  * 
  * This function allows access to the month private data
  *************************************************/
  int getMonth();

  /************************************************
  * Function Name: getYear()
  * Preconditions: none
  * Postconditions: int
  * 
  * This function allows access to the year private data
  *************************************************/
  int getYear();

  /************************************************
  * Function Name: isBefore()
  * Preconditions: Date object
  * Postconditions: bool
  * 
  * This function checks if the passed date is before or after
  * the date it is called upon. 
  * USE: seeing if medication is expired
  *************************************************/
  bool isBefore(Date);

  /************************************************
  * Function Name: alphaMonth()
  * Preconditions: none
  * Postconditions: void
  * 
  * This function is used to convert an integer
  * to the corresponding month
  *************************************************/
  void alphaMonth();
};

