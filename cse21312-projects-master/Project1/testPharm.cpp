/*************************************
* File name: testPharm.cpp
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* The main file for testing the Pharmacy
* Reads in the data from a file using the fstream
* Then uses the functions to test the Row of Bottles
* by dispensing pills and popping bottles out from the row
* ***********************************/

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "DLList.h"
#include "Row.h" // Bottle.h is included in Row.h and Date.h is included in Bottle.h so we are good
#include <algorithm>
#include <vector>
using namespace std;

/********************************************
* Function Name  : createifstream
* Pre-conditions : char*, ifstream &
* Post-conditions: bool
* Opens an ifstream so we can read in the file 
********************************************/
bool createifstream(char*, ifstream &);
/********************************************
* Function Name  : dispensePills
* Pre-conditions : Node<Row<Bottle> > *row, string name, int prePills, Date d1
* Post-conditions: bool
* This function takes in a node pointer and uses it to dispense pills from it 
********************************************/
bool dispensePills(Node<Row<Bottle> > *row, string name, int prePills, Date d1); 
/********************************************
* Function Name  : compare
* Pre-conditions : Date init, Date check
* Post-conditions: bool
* compares two dates and outputs the result 
********************************************/
bool compare(Date init, Date check);

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char* argv[]
* Post-conditions: int
* this is the main driver 
********************************************/
int main(int argc, char* argv[]){  
  DLList<Row<Bottle> > theList;
  Node<Row<Bottle> >* x; 	
  vector<string> names;

	string instruction, name, tempName;
	int year, month, day, amnt;
   
  Date tempDate;
	Bottle b1, b2;

	if(argc == 0){
    std::cout << "Please enter a filename" << std::endl;
		return 1;
	}

  std::ifstream ifs;
	createifstream(argv[1], ifs);
  
  Row<Bottle> *ptrRow;

  ifs >> instruction;
  while(!ifs.eof()){
      if(instruction == "STOCK"){
        ifs >> b1;
	      Row<Bottle> tempA;
        tempA.push_back(b1);
				std::cout << "STOCK: Attempting to stock new bottle " << b1 << std::endl;
        if(theList.findBool(tempA)){
          x = theList.find(tempA);
          x->data.push_back(tempA.front());
          string newBot = b1.getName();
          cout << "Putting bottle in existing row of: " << newBot << endl;
        }
        else{
          theList.insertSort(tempA);
          x = theList.find(tempA);
          cout << "Successful stock of new bottle type: " << x->data.front() << endl;
          
          names.push_back(b1.getName());
          sort(names.begin(),names.end());
          names.erase(unique(names.begin(),names.end()),names.end());
        }
		 }
		 else if(instruction == "INSPC"){
       ifs >> year >> month >> day;
			 Date d(day, month, year);
       cout << "INSPECTION ON " << d << endl;
			 if (theList.head->next == NULL) {// check if pharmacy is empty
						  std::cout << "No medication in pharmacy to inspect." << std::endl;
			 }
			 else {
        // for(string name: names){
         for(auto it = names.begin(); it != names.end(); it++){
        
           Bottle b1(*it,1,d);
           Row<Bottle> tempA;
           tempA.push_back(b1);
           if(theList.findBool(tempA)){
             cout << "Inspecting " << *it << "..." << endl;
             x = theList.find(tempA);
             while(x->data.front().isExpired(d)){ //Inspection fails
               Date dBot = x->data.front().getDate();
               compare(dBot, d);
               cout << "Bottle in front of " << *it << " with EXP: " << dBot << " is expired......Bottle in front of Removed" << endl;
               x->data.pop_front();
               if(x->data.empty()){
                 theList.deleteNode(x);
                 cout << "Row is now empty! No more bottles to inspect." << endl;
                 break;
               }
             }
             if(!x->data.front().isExpired(d)){ //Inspection passes
               Date dBot = x->data.front().getDate();
               cout << "Bottle in front of " << *it << " with EXP: " << dBot << " passes inspection!!" << endl;
             }
			     }
         }
       }
      }
			else if(instruction == "SCRIP"){
        ifs >> year >> month >> day;
		    Date d1(day, month, year);
          
			  ifs >> name >> amnt;
        Bottle b(name, amnt, d1);
        Row<Bottle> r;
        r.push_back(b);
        if(theList.findBool(r)){
          x = theList.find(r);
        }
        bool empty = dispensePills(x, name, amnt, d1);
        if(empty){
          theList.deleteNode(x);
        }
			}
	  	else if (instruction == "INVEN") {
        cout << "INVEN: Printing the inventory for the first bottle in each row..." << endl;
        int emptyPharm = 1;
        for(auto it = names.begin(); it != names.end(); it++){
          Date d1(1,1,1);
          Bottle b1(*it,1,d1);
          Row<Bottle> tempA;
          tempA.push_back(b1);
          if(theList.findBool(tempA)){
            x = theList.find(tempA);
            cout << x->data.front() << endl;
            emptyPharm=0;
          }
	      }
        if(emptyPharm == 1)
          cout << "No medication in Pharmacy." << endl;
      }
		 	else{
        std::cout << "Command not recognized: " << instruction << std::endl;
			}
    ifs >> instruction;
	  std::cout << std::endl;
  }

	ifs.close();  
  return 0;
}

bool createifstream(char* filename, ifstream &ifs){ 
  ifs.open(filename);

  if(!ifs.is_open()){
	  std::cerr << "Error opening file!  Exiting program!" << std::endl;
		exit(-1);
	} 
}

bool dispensePills(Node<Row<Bottle> > *rowNode, string name, int prePills, Date d1){ // prePills = prescription pill number
  string drugname;
	int pills;

	std::cout << "SCRIPT! ";
  if(rowNode->data.empty()){
		std::cout << "Patient brought in a prescription on " << d1 << " for " << prePills << " " << name << std::endl;
    std::cout << "The row is empty, and the medication cannot be dispersed" << std::endl;
	}
  else if(rowNode->data.front().getName() != name){ // Make sure the bottle is the right one prescribed
    std::cout << "The row is not for " << name << ". Cannot be dispersed." << std::endl;
  }
  else{ // Names match and row isn't empty
		std::cout << "Patient brought in a prescription on " << d1 << " for " << prePills << " " << name << std::endl;
  if (!((rowNode->data.front()).isExpired(d1))) {
    string nameBot = rowNode->data.front().getName();
    cout << "The pharmacy has " << nameBot << " in stock." << endl;
   	std::cout << "Front botttle of " << name << " not expired and has pills." << std::endl;
  }
    while((prePills > 0) && !(rowNode->data.empty())){
      if(rowNode->data.front().isExpired(d1)){
        Date d = rowNode->data.front().getDate();
		    drugname = rowNode->data.front().getName();
        std::cout << "Front bottle " << drugname  << " is expired as of " << d1 << ". Removed from row!" << std::endl;
				rowNode->data.pop_front();
		  }
		  else{
        pills = rowNode->data.front().getPills(); // get number of pills in bottle
        if(pills < prePills){ //TODO
          std::cout << "Prescription Exceeds Number of Pills in Bottle.  Can only dispense " << pills << " pills from front bottle." << std::endl;
          prePills = prePills - pills; //Num pills changed to unfulfilled perscription
          // row->front_ref().removePills(pills); // already popping it next line, so pills are not needed to be removed
					rowNode->data.pop_front();
        }
				else{
		      drugname = rowNode->data.front().getName();
          std::cout << "Sufficient stock in front bottle. Currently have " << pills << " " << drugname << ".";
			    std::cout << " Dispersing " << prePills << " " << drugname << std::endl;
          rowNode->data.front_ref().removePills(prePills);
					prePills=0;
				}
			}
		}
    if(prePills > 0){ // If the loop has run and ended (no bottles left in row) and there are still pills left to be dispensed
        std::cout << "The number of pills in the prescription was larger than the number of pills in the row." << std::endl;
				std::cout << "The pharmacy is out of " << name << " and the patient still needs " << prePills << std::endl;
        return 1;
		}
    else if (!rowNode->data.front().getPills()){
      return 1;
    }
    else{
      return 0;
    }
	}
}

bool compare(Date init, Date check){
  bool expired = init.isBefore(check);
  if(!expired){
    cout << "The check date " << check << " is before the initial date " << init << endl;
  }
  else
    cout << "The check date " << check << " is the same day of after the initial date " << init << endl;
}
