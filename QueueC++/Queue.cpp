//Kevin Nguyen
//kudos to Mr. Paul, Mr. Thompson, and Mr. Scott for teaching me how data structures work (such as Queues) in C++ during 2015



#include <cstdlib>
#include <iostream>
#include "Queue.h"
using namespace std;

//constructor
Queue::Queue() {
	head = NULL;
	current = NULL;
	previous = NULL;
	temp = NULL;
}

// function defs

//Push node onto list
void Queue::push(int newData) { //addNode(int addData) {
	//local declarations
	nodePtr n = new node; //create node with node ptr from struct definition
	n->data = newData; //point to data
	n->next = NULL; //point to next data
	n->previous = NULL;
	//list must exist! else list is nothing in memory!
	if(head != NULL) {
		current = head; //current points to same as head;
		while (current->next != NULL) { //not at end yet then keep iterating
			current = current->next; //update ptr to next one in list
		}
		temp = current; //temp to be current
		current->next = n; //add to end of list!
		current = current->next; //move current to next node
		current->previous = temp; //set previous to be temp (where current use to be)
	}
	else {
		head = n; //set head to be the new node; marks the beginning of the linkedlist
	}
}

//removes from tail of the list
void Queue::pop() {
	//loop through until end of list
	while (current->next != NULL) {
		current = current->next;
	}
	temp = current->previous; //go back one node
	temp->next = NULL; current = head; //set next node to null 
}

//remove data from list
void Queue::remove(int badData) {
	/* local declarations */
	nodePtr deletePtr = NULL; //start with nothing; fill it up when target is found!
	temp = head; current = head; //point to beginning of list
	//current is null or already at target then loop should stop
	while (current != NULL && current->data != badData) {
		temp  = current; //temp ptr points to current
		current = current->next; //traverse list
	}
	//found in list somewhere; otherwise target to remove was not found! 
	if (current != NULL) {
		deletePtr = current; //current node is at the target
		current = current->next; //go to next one
		temp->next = current; //break chain of the original list and set ptr past the target
		//found as beginning of list?
		if (deletePtr == head) { 
			head = head->next; //just set head pointer to point to the next one
			temp = NULL;
		}
	}
	else {
		//not in list!
		cout << "NOT IN LIST..UNABLE TO REMOVE : " << badData << "\n";
	}
	delete deletePtr; //clean memory; this becomes a useless pointer after fuction as run
}

//peeks at the tail of the list
void Queue::peek() {
	while (current->next != NULL) {
		current = current->next;
	}
	cout << "Last Element is " << current->data << endl;
}

//prints entire list in order from head to tail
void Queue::printQueue() {
	//local declaration
	current = head;
	//iterate over linkedlist and print out data from each node
	while (current != NULL) {
		cout << current->data;
		current = current->next; //iterate through nodes in memory!
		if(current == NULL) { //conditional for formatting the string output
			cout << endl; //newline
		}
		else {
			cout << " -> "; //arrow
		}
	}
}

//gets the number of nodes in a linked list
int Queue::size() {
	//local declaration
	int counter = 0;
	//iterate over linkedlist and count the size!
	while (current != NULL) {
		counter++;
		current = current->next; //traverse and point to next node in memory!
	}
}

//finds item in list
int Queue::findData(int tgtData) {
	//local declaration
	int found = 0; //determines whether target data was found or not
	current =  head; //ptr back to beginning of list
	//iterate through list
	while(current != NULL) {
		//if target was found then update variable
		if(current->data == tgtData) {
			found = 1;
			break; //get out of loop
		}
		current = current->next; //traverse through list
	}
	//what to do if found? return 1 as true 0 as false
	if(found == 1) {
		cout << tgtData << " does exist in list!\n";
	}
	else {
		cout << tgtData << " does not exist in list!\n";
	}
	return found;
}