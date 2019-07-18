/*************************************
* File name: testBottleFinal.cpp
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* An early part of project 1 compeletion.
* It tests the overloaded friend functions
* ***********************************/

#include <iostream> 
#include <fstream> 
#include "Bottle.h"
using namespace std;

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char* argv[]
* Post-conditions: int
* This is the main driver, which tests the various over rided functions of the Row class 
********************************************/
int main(int argc, char* argv[]){
  Date d1(23, 1, 2019), d2(23, 1, 2019), d3(23, 1, 2019);
  Bottle b1("Azithromycin", 45, d1);
  Bottle b2("Lisinopril", 45, d2);
  Bottle b3("Azithromycin", 50, d3);

  cout << "Bottle1: " << b1 << endl;
  cout << "Bottle2: " << b2 << endl;
  cout << "Bottle3: " << b3 << endl;

  if(b1 < b2)
    cout << "Bottle 1 < Bottle 2" << endl;
  if(b1 < b3)
    cout << "Bottle 1 < Bottle 3" << endl;
  if(b2 < b1)
    cout << "Bottle 2 < Bottle 1" << endl;
  if(b2 < b3)
    cout << "Bottle 2 > Bottle 3" << endl;
  
  if(b1 > b2)
    cout << "Bottle 1 > Bottle 2" << endl;
  if(b1 > b3)
    cout << "Bottle 1 > Bottle 3" << endl;
  if(b2 > b1)
    cout << "Bottle 2 > Bottle 1" << endl;
  if(b2 > b3)
    cout << "Bottle 2 > Bottle 3" << endl;

  if(b1 != b2)
    cout << "Bottle 1 != Bottle 2" << endl;
  if(b1 != b3)
    cout << "Bottle 1 != Bottle 3" << endl;
  if(b2 != b1)
    cout << "Bottle 2 != Bottle 1" << endl;
  if(b2 != b3)
    cout << "Bottle 2 != Bottle 3" << endl;
  
  if(b1 == b2)
    cout << "Bottle 1 == Bottle 2" << endl;
  if(b1 == b3)
    cout << "Bottle 1 == Bottle 3" << endl;
  if(b2 == b1)
    cout << "Bottle 2 == Bottle 1" << endl;
  if(b2 == b3)
    cout << "Bottle 2 == Bottle 3" << endl;
  
	return 0;
}
