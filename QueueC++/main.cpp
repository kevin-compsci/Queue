//Kevin Nguyen

/*
How to run (linux):
	1.) open command line and cd into directory folder of where this code is
	2.) type in "g++ *.cpp" to compile c++ files
	3.) type in "a.out" to run out file
*/

#include <cstdlib>
#include <iostream>
#include "Queue.h"

using namespace std;

//main driver
int main(int argc, char** argv) {
	//local declarations
	Queue myList;
	//test runs below
	myList.push(4);
	myList.push(2);
	myList.push(5);
	myList.push(1);
	myList.push(13);
	myList.peek();
	myList.pop();
	myList.pop();
	myList.peek();
	myList.findData(2);
	myList.findData(4); //doesn't exist at this point
	myList.printQueue();
}