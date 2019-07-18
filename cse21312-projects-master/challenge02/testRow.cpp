/*************************************
* File name: testRow.cpp
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* The main file for testing the row class
* Reads in the data from a file using the fstream
* Then uses the functions to test the Row of Bottles
* by dispensing pills and popping bottles out from the row
* ***********************************/

#include <iostream> 
#include <fstream> 
#include "Row.h" // Bottle.h is included in Row.h and Date.h is included in Bottle.h so we are good
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
* Preconditions: Row *, string, int, Date
* Postconditions: void
* 
* This function takes a pointer to a Row and prescription data
* (hence the string, int, and Date) and then dispenses
* the drugs in accordance with the guidelines using the rows
* which store all of the bottles
*************************************************/
void dispensePills(Row *, string, int, Date); 

int main(int argc, char* argv[]){  
	string instruction, name, tempName;
	int year, month, day, amnt;
  
	Bottle b1, b2;
  Row Azithromycin, Lisinopril, Copy;
  Date tempDate;

	bool file = 0;
	if(argc == 0){
    std::cout << "Please enter a filename" << std::endl;
		return 1;
	}

  string filename = argv[1];
  ifstream ifs;

	createifstream(filename, ifs);
	if(file == 1) return 1;
  
  Row *ptrRow;
	ptrRow = &Lisinopril;

  getline(ifs, instruction, ' ');
  while(!ifs.eof()){
      
      if(instruction == "STOCK"){
        ifs >> b1;
				std::cout << "STOCK: Attempting to stock new bottle " << b1 << std::endl;
				if(Lisinopril.empty()){
				  Lisinopril.push_back(b1);
					std::cout << "Successful stock!" << std::endl;
				}
				else{
          name = Lisinopril.front().getName();
          tempName = b1.getName();
          if(name != b1.getName()){
            std::cout << "This row is not for " << tempName << ". Cannot be stocked." << std::endl;
					}
					else{
					  Lisinopril.push_back(b1);
					  std::cout << "Successful stock!" << std::endl;
					}
				}
		  }	 
		  else if(instruction == "INSPC"){
        ifs >> year >> month >> day;
				Date d(day, month, year);

				std::cout << "INSPECTION on " << d << std::endl;
        if(Lisinopril.empty()){
          std::cout << "Row is empty! No bottles to inspect." << std::endl;
				}
				else{
						tempDate=Lisinopril.front().getDate();
          if(!(tempDate.isBefore(d))){ 
            std::cout << "Bottle in front of Lisinopril with EXP: " << tempDate << " passes inspection!!" << std::endl; 
					}
					else{
		    std::cout << "The front bottle is expired as of " << tempDate << std::endl;
					}
				}
			}
			else if(instruction == "SCRIP"){
        ifs >> year >> month >> day;
				Date d(day, month, year);
        
				ifs >> name >> amnt;
				dispensePills(ptrRow, name, amnt, d);
			}
			else{
        std::cout << "Command not recognized: " << instruction << std::endl;
			}
			getline(ifs, instruction, '\n'); // Read in null terminator to properly read in next input 
      getline(ifs, instruction, ' ');  // Read in next input properly
			std::cout << std::endl;
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

void dispensePills(Row *row, string name, int prePills, Date d1){ // prePills = prescription pill number
  string drugname;
	int pills;
  
	std::cout << "SCRIPT! ";
  if(row->empty()){
		std::cout << "Patient brought in a prescription on " << d1 << " for " << prePills << " " << name << std::endl;
    std::cout << "The row is empty, and the medication cannot be dispersed" << std::endl;
	}
  else if(row->front().getName() != name){ // Make sure the bottle is the right one prescribed
    std::cout << "The row is not for " << name << ". Cannot be dispersed." << std::endl;
  }
  else{ // Names match and row isn't empty
		std::cout << "Patient brought in a prescription on " << d1 << " for " << prePills << " " << name << std::endl;
  if (!((row->front()).isExpired(d1))) {
   	std::cout << "Front botttle of " << name << " not expired and has pills." << std::endl;
  }
    while((prePills > 0) && !(row->empty())){
      if(row->front().isExpired(d1)){
        Date d = row->front().getDate();
		    drugname = row->front().getName();
        std::cout << "Front bottle " << drugname  << " is expired as of " << d1 << ". Removed from row!" << std::endl;
				row->pop_front();
		  }
		  else{
        pills = row->front().getPills(); // get number of pills in bottle
        if(pills < prePills){
          std::cout << "Prescription Exceeds Number of Pills in Bottle.  Can only dispense " << pills << " pills from front bottle." << std::endl;
          prePills = prePills - pills; //Num pills changed to unfulfilled perscription
          // row->front_ref().removePills(pills); // already popping it next line, so pills are not needed to be removed
					row->pop_front();
        }
				else{
		      drugname = row->front().getName();
          std::cout << "Sufficient stock in front bottle. Currently have " << pills << " " << drugname << ".";
			    std::cout << " Dispersing " << prePills << " " << drugname << std::endl;
          row->front_ref().removePills(prePills);
					prePills=0;
				}
			}
		}
    if(prePills > 0){ // If the loop has run and ended (no bottles left in row) and there are still pills left to be dispensed
        std::cout << "The number of pills in the prescription was larger than the number of pills in the row." << std::endl;
				std::cout << "The pharmacy is out of " << name << " and the patient still needs " << prePills << std::endl;
		}
	}
}
