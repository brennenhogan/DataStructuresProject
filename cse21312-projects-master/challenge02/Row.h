/*************************************
* File name: Row.h
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* Row header file for the wrapper
* ***********************************/
#include "Bottle.h"
#include <iostream>
#include <queue>

using namespace std;

class Row
{
public:
  /************************************************
  * Function Name: Row()
  * Preconditions: none
  * Postconditions: Object of the Row class
  * 
  * This is the default constructor
  *************************************************/
	Row();

  /************************************************
  * Function Name: ~Row()
  * Preconditions: none
  * Postconditions: none
  * 
  * This is the destructor
  *************************************************/
	~Row();

  /************************************************
  * Function Name: Bottle()
  * Preconditions: none
  * Postconditions: none
  * 
  * This is the default constructor
  *************************************************/
  bool empty();

  /************************************************
  * Function Name: size()
  * Preconditions: none
  * Postconditions: int
  * 
  * This returns the size of the queue (aka the number
	* of elements in the queue)
  *************************************************/
	int size();

  /************************************************
  * Function Name: front()
  * Preconditions: none
  * Postconditions: Bottle
  * 
  * This returns the front element by value
  *************************************************/
	Bottle front();

  /************************************************
  * Function Name: front_ref()
  * Preconditions: none
  * Postconditions: Bottle
  * 
  * This returns the front element by reference
  *************************************************/
	Bottle& front_ref();

  /************************************************
  * Function Name: back()
  * Preconditions: none
  * Postconditions: Bottle
  * 
  * This returns the last element by value
  *************************************************/
	Bottle back();

  /************************************************
  * Function Name: push_back()
  * Preconditions: Bottle
  * Postconditions: void
  * 
  * This adds an element to the back of the queue
	* which is first in, first out
  *************************************************/
	void push_back(Bottle);

  /************************************************
  * Function Name: pop_front()
  * Preconditions: none
  * Postconditions: void
  * 
  * This deletes the top element from the queue
  *************************************************/
  void pop_front();


private:
	queue<Bottle> myqueue;
};
