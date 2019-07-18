/*************************************
* File name: testBottle.cpp
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* Main file for testing the bottle class.
* It declares a bottle and reads in data using fstream
* Then, it tests the bottle's date compare functions and
* dispenses pills if appropriate
* ***********************************/

#include <iostream> 
#include <fstream> 
#include "Bottle.h"
using namespace std;

/************************************************
* Function Name: createifstream()
* Preconditions: string, ifstream &
* Postconditions: bool
* 
* This checks if the ifstream can be opened 
* aka a file exists
*************************************************/
bool createifstream(string, ifstream &); 

/************************************************
* Function Name: dispensePills()
* Preconditions: Bottle &, string, int, Date
* Postconditions: void
* 
* This function takes a bottle and prescription data
* (hence the string, int, and Date) and then dispenses
* the drugs in accordance with the guidelines
*************************************************/
void dispensePills(Bottle &, string, int, Date); 

int main(int argc, char* argv[]){
	string instruction, name;
	int year, month, date, amnt;

	bool file = 0;
	if(argc == 0){
    std::cout << "Please enter a filename" << std::endl;
		return 1;
	}

  string filename = argv[1];
  ifstream ifs;

	createifstream(filename, ifs);
	if(file == 1) return 1;

  Date d1(23, 1, 2019), d2(22, 1, 2019), d3(24, 1, 2019);
  Bottle b1("Azithromycin", 45, d1);
  Bottle b2;

  cout <<  b1 << endl;
  cout <<  b2 << endl;
	cout << endl;

  getline(ifs, instruction, ' ');
  while(!ifs.eof()){
      
      if(instruction == "STOCK"){
        ifs >> b2;
				cout << "STOCK: " << b1 << endl;
		  } 
		  else if(instruction == "INSPC"){
        ifs >> year >> month >> date;
				Date d(date, month, year);
				cout << "INSPECTION on " << d << endl;
				cout << "For Bottle 1: ";
				b1.printCompare(cout, d);
				cout << "For Bottle 2: ";
				b2.printCompare(cout, d);
			}
			else if(instruction == "SCRIP"){
        ifs >> year >> month >> date;
				Date d(date, month, year);
        
				ifs >> name >> amnt;
        if(name == "Azithromycin")
				  dispensePills(b1, name, amnt, d);
        if(name == "Lisinopril")
				  dispensePills(b2, name, amnt, d);
			}
			else{
        cout << "Command not recognized: " << instruction << endl;
			}
			//ifs.ignore();
			getline(ifs, instruction, '\n'); // Read in null terminator to properly read in next input 
      getline(ifs, instruction, ' ');  // Read in next input properly
			cout << endl;
	}

	ifs.close();

  return 0;
}
 

bool createifstream(string filename, ifstream &ifs){ 
  ifs.open(filename);
  if(!ifs){
	  std::cout << "Error opening file " << filename << std::endl;
		return 1;
	} 
}

void dispensePills(Bottle &b1, string name, int numPills, Date d1){
  string drugname;
	int allPillsInBottle;
	cout << "SCRIPT! ";

  if(b1.getName() != name){ // Make sure the bottle is the right one prescribed
    cout << "The bottle doesn't match the prescribed drug " << name << " vs " << b1.getName() << endl;
  }
  else if(b1.isExpired(d1)){
    Date d = b1.getDate();
		drugname = b1.getName();
    cout << "Bottle " << drugname  << " is expired as of " << d << ". Cannot dispense pills!" << endl;
  }
  else if(!b1.isExpired(d1)){
    if(b1.getPills() >= numPills){
      allPillsInBottle = b1.getPills();
		  drugname = b1.getName();
      cout << "Sufficient stock. Currently have " << allPillsInBottle << " " << drugname << " pills.";
			cout << " Dispersing " << numPills << " " << drugname << endl;
      b1.removePills(numPills);
      cout << b1 << endl;
    }
    else{
      allPillsInBottle = b1.getPills();
      cout << "Prescription Exceeds Number of Pills in Bottle. Can only dispense " << numPills << " pills." << endl;
      numPills = numPills - b1.getPills(); //Num pills changed to unfulfilled perscription
      cout << numPills << " remain to be prescribed." << endl;
      b1.removePills(allPillsInBottle);
      cout << b1 << endl;
    }
  }
}
