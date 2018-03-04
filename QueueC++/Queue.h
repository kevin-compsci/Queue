//Kevin Nguyen

class Queue {
	private: //private access functions
		//node structure
		typedef struct node {
			int data; //actual value
			node* next; //point to next node
			node* previous; //point to previous node
		}* nodePtr; //predefine pointer for future declarations

		nodePtr head;
		nodePtr current;
		nodePtr temp;
		nodePtr previous;

	public: //public access functions
		//constructor
		Queue();
		//add to list
		void push(int newData);
		//removes from end of list
		void pop();
		//remove from list
		void remove(int badData);
		//peeks at tail of list
		void peek();
		//print list
		void printQueue();
		//get size of list
		int size();
		//find data inside list
		int findData(int tgtData);
};