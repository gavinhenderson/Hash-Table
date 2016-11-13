//Gavin Henderson
//150010848

#include <iostream>

#ifndef _PERSON_H
#define _PERSON_H

using namespace std;

class Person{
	//Declare all the variables of the Person class
	private:
		string fullName;
		string address;
		string postcode;
		string phoneNo;
	
	//Declare functions accessible by the whole program
	public:
		~Person();
		Person();
		Person(string newName);
		string getName();
		void setName(string newName);
		string getAddress();
		void setAddress(string newAddress);
		string getPostcode();
		void setPostcode(string newPostcode);
		string getPhoneNo();
		void setPhoneNo(string newPhoneNo);
		void displayPerson();
};
#endif