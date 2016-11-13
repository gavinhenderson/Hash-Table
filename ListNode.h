//Gavin Henderson
//150010848

#include <iostream>

#ifndef _LISTNODE_H
#define _LISTNODE_H

#include "Person.h"

using namespace std;

class ListNode{
	//Declare the variables in the listnode
	private:
		Person* data;
		ListNode* next;
	
	//The functions used to manipulate the class
	public:
		void fullDelete();
		ListNode();
		ListNode* getNext();
		void setNext(ListNode* n);
		Person* getData();
		void setData(Person* p);
};
#endif
