/**********************************************
* File: DLList.h
* Author: Jack Olmanson, Brendan Sailer, Brennan Hogan
* Email: jolmanso@nd.edu, bsailer1@nd.edu, bhogan1@nd.edu
*
* This is defines the DLList class, and the methods associated with it 
**********************************************/
#ifndef DLLIST_H
#define DLLIST_H

#include <stdexcept>
#include "DLLNode.h"
#include <string>
#define nullptr NULL
using namespace std;

template<class T>
class DLList{

public:
  Node<T> *head;
  Node<T> *tail;

  /********************************************
  * Function Name  : DLList<T>
  * Pre-conditions : none
  * Post-conditions: none
	*
  * This is the constructor 
  ********************************************/
  DLList<T>(){
	   // new Node() creates a Node will a nullptr
	   this->head = new Node<T>();
  }

  /********************************************
  * Function Name  : ~DLList<T>
  * Pre-conditions : none
  * Post-conditions: none
	*
  * This is the destructor 
  ********************************************/
  ~DLList<T>(){
	   Node<T>* current = head; // (1)
  
	   while (current != nullptr){
        Node<T>* next = current->next; // (2)
        delete current; // (3)
        current = next; // (4)
     }

     head = nullptr;
   }
 
  /********************************************
  * Function Name  : find
  * Pre-conditions : T key
  * Post-conditions: T
	*
  * This function inserts a new node 
  ********************************************/
  bool findBool(T key){
		int found = 0;
    Node<T>* temp = head;

    if (head->next == NULL){
		  //std::cout << "Can't find an element in empty list" << std::endl;
      return 0;
    }
		else if(head->data.front() == key.front()){
			return 1;
		}
		else if(tail->data.front() == key.front()){
			return 1;
		}

    while(!found){
      if(temp->data.front() == key.front()){
				return 1;
			}
			if(temp == tail)
				return 0;
			if(!found)
			  temp = temp->next;
		}
    
  }

  /********************************************
  * Function Name  : find
  * Pre-conditions : T key
  * Post-conditions: Node<T>*
  * this goes through the linked list until it returns a key value (if it has it) 
  ********************************************/
  Node<T>* find(T key){
    int found = 0;
    Node<T>* temp = head;

    if (temp->next == NULL){
		  //std::cout << "Can't find an element in empty list" << std::endl;
    }
		else if(temp->data.front() == key.front()){
      return head;
		}
		else if(tail->data.front() == key.front()){
			return tail;
		}

    while(!found){
      if(temp->data.front() == key.front()){
				return temp;
			}
			if(temp == tail)
               // T<Bottle> r1;
				return temp;
			if(!found){
			  temp = temp->next;
      }
		}
    
  }


  /********************************************
  * Function Name  : deleteNode
  * Pre-conditions : T key
  * Post-conditions: none
	*
  * This function deletes a node 
  ********************************************/
  void deleteNode(Node<T>* key){
    int found = 0;

    if(head == nullptr)
      throw std::out_of_range("invalid LinkedList Node");

    else if(head == key && tail == key){
      head->next = NULL;
    }

    else if(head == key){ // Deletes Head
      head = head->next;
      if(head != nullptr)
        head->prev = nullptr;
      return;
    }

    Node<T>* current = head;
    Node<T>* temp = head;

		while(current != tail && current != key){
      current = current->next;
			if(current == key)
				found = 1;
		}

	  if(found){
		  if(current == tail){
        tail = tail->prev;
				tail->next = nullptr;
			}
			else{
        temp = current->next;
				current = current->prev;
				current->next = temp;
				temp->prev = current;
			}
	  }
  }

  /********************************************
  * Function Name  : insertSort
  * Pre-conditions : T value
  * Post-conditions: none
	*
  * This function inserts a new node 
  ********************************************/
  void insertSort(T value){
		int inserted = 0;
    if (head->next == NULL){  // If there are no nodes, insert it at the head
       tail = head; // Case 1: (1)
       head->next = tail; // Case 1: (2)
       head->data = value; // Case 1: (3)
    }
		else if (tail == head){  // If there is a loop created by above code (AKA inserting 2nd node)
      if(value.front() > head->data.front()){  // Insert second
        head->next = new Node<T>();
				tail = head->next;
				tail->prev = head;
	      tail->data = value;
			}
			else if (value.front() < head->data.front()){ // Insert as new head (head and tail must be equal to run this)
				tail->prev = new Node<T>();
				head = tail->prev;
				head->next = tail;
        head->data = value;
			}
      else if (value.front() == head->data.front()){
        head->data.push_back(value.front()); //Puts the bottle into a row if they match
      }
			else{
        std::cout << "Something has gone horribly wrong this should never run" << std::endl; 
			}
		  tail->next = nullptr;  // Ensure it is what we think it is
		  head->prev = nullptr;
		}
		else{
    		Node<T>* temp = head;

				while(value.front() > temp->data.front()){
						if(temp->next == NULL){        // We've reached the end of list.  Insert at end
								tail->next = new Node<T>();
                tail->next->prev = tail;
								tail->next->next = nullptr;
								tail = tail->next;
								tail->data = value;
								inserted = 1;
								break;
						}						
						temp = temp->next;
				}

        if(temp->data.front() == value.front()){
          temp->data.push_back(value.front()); //Puts the bottle into a row if they match
        }

				else if(temp != head && inserted == 0){           // Value < Data -- insert the node between the prev and the current
	        Node<T>* temp2 = temp->prev;             // Now we got the temp pointer on one side and temp2 on the other

          temp2->next = new Node<T>();
					temp->prev = temp2->next;
					temp2->next->next = temp;
					temp->prev->prev = temp2;
					temp2->next->data = value;
				}
				else if(temp->prev == NULL && inserted == 0){      // If temp if the first node
					head->prev = new Node<T>();
					head->prev->next = head;
					head = head->prev;
					head->data = value;
					head->prev = nullptr;
				}
		}
  }

};

#endif
