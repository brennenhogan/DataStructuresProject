/*************************************
* File name: testDate.ccp
* Author: Brendan Sailer, Brennen Hogan, Jack Olmanson
* Email: bsailer1@nd.edu, bhogan1@nd.edu, jolmanso@nd.edu
*
* The code in this file is the main driver function for
* challenge01 as outlined in the directions provided by
* Dr. Morrison on Sakai in the Project 1 PDF.
* ***********************************/

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

bool compare(Date init, Date check, ostream &);

/************************************************
* Function Name: main()
* Preconditions: int argc, char *argv[]
* Postconditions: int
*
* main() initializes 4 objects of the Date class
* and then calls one function three times to compare
* the dates.  That function outputs the status of
* the medication to the screen in this case (cout)
*************************************************/
int main(int argc, char *argv[]){
  
  Date init(23, 1, 2019), check1(18, 1, 2019), check2(23, 1, 2019), check3(25, 1, 2019);  // Instantiate objects of the Date class

  compare(init, check1, cout);
  compare(init, check2, cout);
  compare(init, check3, cout);
  
  return 0;
}

/************************************************
* Function Name: compare()
* Preconditions: Date init, Date check, ostream &os
* Postconditions: bool expired
*
* The function uses the isBefore method contained
* within the Date class to compare the two dates
* and then uses the overloaded output operator 
* friend function to output the correct response 
* to the screen (or file) depending on the passed
* ostream.  It returns a bool to make part 2 easier later on
*************************************************/
bool compare(Date init, Date check, ostream &os)
{
  bool expired = init.isBefore(check); // if true, then it is expired
  
  if (!expired) {
    os << "The check date " << check << " is before the initial date " << init << endl;
  } else {
    os << "The check date " << check << " is the same day or after the initial date " << init << endl;
  }

  return expired;   // It returns a bool per Dr. Morrison's advice in Office Hours for part 2 of the project 
}
