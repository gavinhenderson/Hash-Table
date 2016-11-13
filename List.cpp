//Gavin Henderson
//10050848

#include "List.h"

using namespace std;

//Constructer that takes in a node and sets it to the head
//Also sets the size to 1
List::List(ListNode* newHead){
	head = newHead;
	size = 1;
}

//Get method for the head of the list
ListNode* List::getHead(){
	return head;
}

//Set method for the head of the list
void List::setHead(ListNode* n){
	head = n;
}

//Adds a node to the start of the list that is passed in
void List::addNode(ListNode* n){
	ListNode* oldHead = head;
	head = n;
	head->setNext(oldHead);
	size++;
}

//gets the size of the list
int List::getSize(){
	return size;
}

//List destructor that will delete all the nodes in the list but not the people
//stored whithin the nodes
List::~List(){
	//Sets up a variable called current and next
	ListNode* current = head;
	ListNode* next = current;
	
	//Loops through the array until it reaches the end
	for(int i=0; i<size; i++){
		next = current->getNext();
		delete current;
		current = next;
	}
}

//This deletes the people stored in each node
void List::fullDelete(){
	//Sets up a variable called current and next
	ListNode* current = head;
	ListNode* next = current;
	
	//Loops through the array until it reaches the end
	for(int i=0; i<size; i++){
		next = current->getNext();
		current->fullDelete();
		current = next;
	}
}


/*
Searches the list with the given key and tries to match it with the
field that is indicated by the choice field. Here are the options choice
gives.
choice == 1 - search by name
choice == 2 - search by address
choice == 3 - search by postcode
choice == 4 - search by phone no
*/
Person* List::searchList(string key, int choice){
	//Loops through all the nodes in the list
	ListNode* current = head;
	for(int i=0;i<size; i++){
		if(choice==1){
			if(current->getData()->getName()==key){
				return current->getData();
			}
		}else if(choice==2){
			if(current->getData()->getAddress()==key){
				return current->getData();
			}
		}else if(choice==3){
			if(current->getData()->getPostcode()==key){
				return current->getData();
			}
		}else if(choice==4){
			if(current->getData()->getPhoneNo()==key){
				return current->getData();
			}
		}
		current=current->getNext();
	}
	cout << "Person doesnt exist" << endl;
	return NULL;
}