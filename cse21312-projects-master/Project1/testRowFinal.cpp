/*************************************
* File name: testRowFinal.cpp
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* An early part of project 1 compeletion.
* It tests the overloaded friend functions
* ***********************************/

#include <iostream> 
#include <fstream> 
#include "Row.h"
using namespace std;

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char* argv[]
* Post-conditions: int
* Thi sis the main driver which tests the various over rided functions of the row class 
********************************************/
int main(int argc, char* argv[]){
  Date d1(23, 1, 2019), d2(23, 1, 2019), d3(23, 1, 2019);
  Bottle b1("Azithromycin", 45, d1);
  Bottle b2("Lisinopril", 45, d2);
  Bottle b3("Azithromycin", 50, d3);
 
  Row<Bottle> r1;
  Row<Bottle> r2;
  Row<Bottle> r3;
   
	r1.push_back(b1);
	r2.push_back(b2);
	r3.push_back(b3);

  cout << "Bottle1: " << r1.front() << endl;
  cout << "Bottle2: " << r2.front() << endl;
  cout << "Bottle3: " << r3.front() << endl;

  if (r1 < r2)
	  cout << "Queue1 < Queue2" << endl; 
  if (r1 < r3)
	  cout << "Queue1 < Queue3" << endl; 
  if (r2 < r1)
	  cout << "Queue2 < Queue1" << endl; 
  if (r2 < r3)
	  cout << "Queue2 < Queue3" << endl; 

  if (r1 > r2)
	  cout << "Queue1 > Queue2" << endl; 
  if (r1 > r3)
	  cout << "Queue1 > Queue3" << endl; 
  if (r2 > r1)
	  cout << "Queue2 > Queue1" << endl; 
  if (r2 > r3)
	  cout << "Queue2 > Queue3" << endl; 

  if (r1 != r2)
	  cout << "Queue1 != Queue2" << endl; 
  if (r1 != r3)
	  cout << "Queue1 != Queue3" << endl; 
  if (r2 != r1)
	  cout << "Queue2 != Queue1" << endl; 
  if (r2 != r3)
	  cout << "Queue2 != Queue3" << endl; 

  if (r1 == r2)
	  cout << "Queue1 == Queue2" << endl; 
  if (r1 == r3)
	  cout << "Queue1 == Queue3" << endl; 
  if (r2 == r1)
	  cout << "Queue2 == Queue1" << endl; 
  if (r2 == r3)
	  cout << "Queue2 == Queue3" << endl; 

	return 0;
}
