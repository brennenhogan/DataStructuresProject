/**********************************************
* File: DLLNode.h
* Author: Jack Olmanson, Brendan Sailer, Brennan Hogan
* Email: jolmanso@nd.edu, bsailer1@nd.edu, bhogan1@nd.edu
* This is the class header of the Node class 
**********************************************/

#ifndef DLLNODE_H
#define DLLNODE_H

template<class T>
struct Node {
  T    data;
	Node *next;
	Node *prev;
};


#endif


