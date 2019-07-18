#include <fstream>
#include <iostream>
#include "DLList.h"
#include "Row.h"
using namespace std;

int main(int argc, char **argv){
  DLList<Row<Bottle> > theList;

  Date d1(23, 1, 2019), d2(23, 1, 2019), d3(23, 1, 2019);
  Bottle b1("Azithromycin", 45, d1);
  Bottle b2("Lisinopril", 45, d2);
  Bottle b3("Zedilith", 50, d3);
  Bottle b4("Bithromycin", 1, d1);
 
  Row<Bottle> r1;
  Row<Bottle> r2;
  Row<Bottle> r3;
  Row<Bottle> TEST;
	r1.push_back(b1);
	r2.push_back(b2);
	r3.push_back(b3);
	TEST.push_back(b4);
  cout << "Bottle1: " << r1.front() << endl;
  cout << "Bottle2: " << r2.front() << endl;
  cout << "Bottle3: " << r3.front() << endl;
  cout << "BottleTEST: " << TEST.front() << endl;

	theList.insertSort(r1);
	theList.insertSort(r2);
	theList.insertSort(r3);
  Node<Row<Bottle> >* x;
 	
  if(theList.findBool(TEST)){
    x = theList.find(TEST);
    cout << x << endl << endl;
    cout << x->data.front() << endl;
    x->data.push_back(TEST.front());
  }
  else{
    theList.insertSort(TEST);
    x = theList.find(TEST);
  }
 
  x->data.pop_front();

  if(x->data.empty()){
    cout << "Row is empty!" << endl;
  }
  else{
    cout << x->data.front() << endl;
  }

	return 0;
}
