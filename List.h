//Gavin Henderson
//10050848

#include <iostream>

#ifndef _LIST_H
#define _LIST_H

#include "ListNode.h"

using namespace std;

class List{
	//Declare the fields stored in the list
	private:
		int size;
		ListNode* head;
	
	//Declare the functions needed to manipulate the list
	public:
		void fullDelete();
		List(ListNode* newHead);
		ListNode* getHead();
		void addNode(ListNode* n);
		void setHead(ListNode* n);
		int getSize();
		Person* searchList(string key, int choice);
		~List(); 
};
#endif