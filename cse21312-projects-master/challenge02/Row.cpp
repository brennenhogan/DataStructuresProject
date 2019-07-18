/*************************************
* File name: Row.cpp
* Author: Brennen Hogan, Brendan Sailer, Jack Olmanson
* Email: bhogan1@nd.edu, bsailer1@nd.edu, jolmanso@nd.edu
*
* Row implementation for the wrapper. Uses the built in functions for the 
* queue class to build the row functions
* SEE HEADER FILE FOR FUNCTION HEADERS
* ***********************************/
#include <iostream>
#include <queue>
#include "Row.h"

Row::Row()
{
   
}

Row::~Row() { }

bool Row::empty()
{
  return myqueue.empty(); 
}

int Row::size(){
  return myqueue.size();
}

Bottle Row::front(){
  return myqueue.front();
}

Bottle& Row::front_ref(){
  return myqueue.front();
}

Bottle Row::back(){
  return myqueue.back();
}

void Row::push_back(Bottle b){
  myqueue.push(b);
}

void Row::pop_front(){
  myqueue.pop();
}

