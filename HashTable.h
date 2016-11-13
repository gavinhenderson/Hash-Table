//Gavin Henderson
//150010848

#include <iostream>

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "List.h"

using namespace std;

class HashTable{
	private:
		//Declare the fields stored in the hashtable
		int hash(string input);
		List* tableName[80];
		List* tableAddress[80];
		List* tablePostcode[80];
		List* tablePhoneNo[80];
		
	public:
		//declare the functions of the hashtable
		HashTable();
		void addToTable(Person* value);
		Person* getFromTable(string key, int choice);
		~HashTable();
};
#endif
