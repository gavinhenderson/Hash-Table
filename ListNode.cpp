//Gavin Henderson
//10040848

#include "ListNode.h"

using namespace std;

//Constructor that sets the next to null
ListNode::ListNode(){
	next = NULL;
}

//Get method for the pointer to next
ListNode* ListNode::getNext(){
	return next;
}

//Set what the list node points to as next
void ListNode::setNext(ListNode* n){
	next = n;
}

//Get the person that is stored in the list node
Person* ListNode::getData(){
	return data;
}

//Set the person that is stored in the list node
void ListNode::setData(Person* p){
	data = p;
}

//Destructed that deletes the person stored in the list node
//This isnt the main destructor as sometimes i will have already
//deleted the person stored in the node
void ListNode::fullDelete(){
	delete data;
}