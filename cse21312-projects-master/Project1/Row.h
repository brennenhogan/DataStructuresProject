/*************************************
* File name: Row.h
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* Row class for the queue wrapper
* ***********************************/
#include "Bottle.h"
#include <iostream>
#include <queue>

using namespace std;

template <class T>
class Row
{
public:
  /********************************************
  * Function Name  : Row
  * Pre-conditions : none
  * Post-conditions: none
  * This is the constructor 
  ********************************************/
  Row(){ }

  /********************************************
  * Function Name  : ~Row
  * Pre-conditions : none
  * Post-conditions: none
  * This is the destructor 
  ********************************************/
  ~Row() { }

  /********************************************
  * Function Name  : empty
  * Pre-conditions : none
  * Post-conditions: bool
  * This checks to see if the row is empty 
  ********************************************/
  bool empty(){
    return myqueue.empty(); 
  }

  /********************************************
  * Function Name  : size
  * Pre-conditions : none
  * Post-conditions: int
  * This returns the number of bottles in the row 
  ********************************************/
  int size(){
    return myqueue.size();
  }

  /********************************************
  * Function Name  : front
  * Pre-conditions : none
  * Post-conditions: T&
  * This returns the first elemement of the row  
  ********************************************/
  T& front(){
    return myqueue.front();
  }

  /********************************************
  * Function Name  : front_ref
  * Pre-conditions : none
  * Post-conditions: T&
  * This returns the first element of the row by reference 
  ********************************************/
  T& front_ref(){
    return myqueue.front();
  }

  /********************************************
  * Function Name  : back
  * Pre-conditions : none
  * Post-conditions: T
  * This returns the last element in the row 
  ********************************************/
  T back(){
    return myqueue.back();
  }

  /********************************************
  * Function Name  : push_back
  * Pre-conditions : T name
  * Post-conditions: none
  * This puts the input to the last element of the row 
  ********************************************/
  void push_back(T name){
    myqueue.push(name);
  }

  /********************************************
  * Function Name  : pop_front
  * Pre-conditions : none
  * Post-conditions: none
  * This pops the first element of the row 
  ********************************************/
  void pop_front(){
    myqueue.pop();
  }

  /********************************************
  * Function Name  : operator<
  * Pre-conditions : const Row<T>& comp
  * Post-conditions: bool
  * This tests if the first element of the row is alphabetically before the inputted value 
  ********************************************/
  bool operator< (const Row<T>& comp){
    return myqueue.front() < comp.myqueue.front();
  }  

  /********************************************
  * Function Name  : operator>
  * Pre-conditions : const Row<T>& comp
  * Post-conditions: bool
  * This tests if the first element of the row is alphabetically after the inputted value 
  ********************************************/
  bool operator> (const Row<T>& comp){
    return myqueue.front() > comp.myqueue.front();
  }

  /********************************************
  * Function Name  : operator==
  * Pre-conditions : const Row<T>& comp
  * Post-conditions: bool
  * This tests if the first element of the row is alphabetically the same as  the inputted value 
  ********************************************/
  bool operator== (const Row<T>& comp){
    return myqueue.front() == comp.myqueue.front();
  }
  
  /********************************************
  * Function Name  : operator!=
  * Pre-conditions : const Row<T>& comp
  * Post-conditions: bool
  * This tests if the first element of the row is alphabetically the same as  the inputted value 
  ********************************************/
  bool operator!= (const Row<T>& comp){
    return myqueue.front() != comp.myqueue.front();
  }

private:
	queue<T> myqueue;
};
