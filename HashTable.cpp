//Gavin Henderson
//150010848

#include "HashTable.h"

using namespace std;

//Constructor that initialises all the arrays to NULL
HashTable::HashTable(){
	//Loop through array and null it
	for(int i=0; i<80; i++){
		tableName[i] = NULL;
		tableAddress[i] = NULL;
		tablePhoneNo[i] = NULL;
		tablePostcode[i] = NULL;
	}
}

//Destructor that deletes all the lists in the arrays
HashTable::~HashTable(){
	//Loop all 80 times
	for(int i=0; i<80; i++){
		//Delete the people in the name table
		if(tableName[i] != NULL){
			tableName[i]->fullDelete();
		}
		//Delete the nodes in the address table
		if(tableAddress[i] != NULL){
			delete tableAddress[i];
		}
		//Delete the nodes in the postcode table
		if(tablePostcode[i] != NULL){
			delete tablePostcode[i];
		}
		//Delete the nodes in the phone number table
		if(tablePhoneNo[i] != NULL){
			delete tablePhoneNo[i];
		}
	}
}

//Takes in a string and then returns a number between 0 and 79
int HashTable::hash(string input){
	int hash=0;
	
	//Adds together all the ascii values of the characters
    for(int i=0; i<input.length(); i++){
    	hash += (int)input[i];
    }
    
    //Divides by 2 until its less than 160
    while(hash>=160)
    {
    	hash = hash/2;
    }
    hash -= 80;
    
    //If the hash is out of the scope for some reason give it a default value
    if(hash<0 or hash>=80){
    	hash=50;
    }
    
    cout << "The hash value for '" << input << "' is: " << hash << endl;
    return hash;
}

//Adds a person to the table
void HashTable::addToTable(Person* value){
	//Gets the hash value for each field of person
	int nameHash = hash(value->getName());
	int addressHash = hash(value->getAddress());
	int phoneNoHash = hash(value->getPhoneNo());
	int postcodeHash = hash(value->getPostcode());
	
	//Creates list nodes to add and sets the data
	ListNode* nameNode = new ListNode();
	ListNode* addressNode = new ListNode();
	ListNode* postcodeNode = new ListNode();
	ListNode* phoneNoNode = new ListNode();
	nameNode->setData(value);
	addressNode->setData(value);
	postcodeNode->setData(value);
	phoneNoNode->setData(value);
	
	//Creates new list if no collision
	if(tableName[nameHash]==NULL)
	{
		List* myList = new List(nameNode);
		tableName[nameHash] = myList;
		cout << value->getName() << " has been added to the name" << endl;	
	//adds to existing list if there is a collision		
	}else{
		tableName[nameHash]->addNode(nameNode);
		cout << "COLLISION(name)! Node still added" << endl;
	}
	
	//Creates new list if no collision
	if(tableAddress[addressHash]==NULL)
	{
		List* myList = new List(addressNode);
		tableAddress[addressHash] = myList;
		cout << value->getName() << " has been added to the address table" << endl;			
	//adds to existing list if there is a collision
	}else{
		tableAddress[addressHash]->addNode(addressNode);
		cout << "COLLISION(address)! Node still added" << endl;
	}
	
	//Creates new list if no collision
	if(tablePostcode[postcodeHash]==NULL)
	{
		List* myList = new List(postcodeNode);
		tablePostcode[postcodeHash] = myList;
		cout << value->getName() << " has been added to the postcode table" << endl;
	//adds to existing list if there is a collision			
	}else{
		tablePostcode[postcodeHash]->addNode(postcodeNode);
		cout << "COLLISION(postcode)! Node still added" << endl;
	}
	
	//Creates new list if no collision
	if(tablePhoneNo[phoneNoHash]==NULL)
	{
		List* myList = new List(phoneNoNode);
		tablePhoneNo[phoneNoHash] = myList;
		cout << value->getName() << " has been added to the phone number table" << endl;
	//adds to existing list if there is a collision		
	}else{
		tablePhoneNo[phoneNoHash]->addNode(phoneNoNode);
		cout << "COLLISION(phone number)! Node still added" << endl;
	}
}

//Gets user from the hash table bassed on a string and a category to search by.
//choice == 1 search by name
//choice == 2 search by address
//choice == 3 search by postcode
//choice == 4 search by phone no
Person* HashTable::getFromTable(string key, int choice){
	//Gets hashvalue for key
	int myHash = hash(key);
	
	//Gets the list from the corresponding table
	List* myList;
	switch (choice)  
    {  
		case 1:  
            myList = tableName[myHash]; 
            break;  
        case 2:  
    		myList = tableAddress[myHash];  
            break;
        case 3:  
    		myList = tablePostcode[myHash];  
            break;
        case 4:  
    		myList = tablePhoneNo[myHash];  
            break;    
    }  
	
	//If the list is null then the person cant exist
	if(myList==NULL){
		cout << "Person doesnt exist" << endl;
		return NULL;
	//Otherwise search the table for the key
	}else{
		Person* myPerson = myList->searchList(key, choice);
		return myPerson;
	}
}
