//Gavin Henderson
//150010848

#include "Person.h"

using namespace std;

//Constructor that reads the user input to fill in all the fields
Person::Person(){
	cout << "Please enter persons name: ";
	getline(cin,fullName);
	cout << "Please enter persons address: ";
	getline(cin,address);
	cout << "Please enter persons postcode: ";
	getline(cin,postcode);
	cout << "Please enter persons phone number: ";
	getline(cin,phoneNo);
}

//Constructor used in the tester that can create a person without user input
Person::Person(string newName){
	fullName = newName;
	address = "Random Address";
	postcode = "Random Postcode";
	phoneNo = "Random PhoneNumber";
}

//Set method for name field
void Person::setName(string newName){
	fullName = newName;
}

//Get method for name field
string Person::getName(){
	return fullName;
}

//Set method for address field
void Person::setAddress(string newAddress){
	address = newAddress;
}

//Get method for address field
string Person::getAddress(){
	return address;
}

//Set method for postcode field
void Person::setPostcode(string newPostcode){
	postcode = newPostcode;
}

//Get method for postcode field
string Person::getPostcode(){
	return postcode;
}

//Set method for phone number
void Person::setPhoneNo(string newPhoneNo){
	phoneNo = newPhoneNo;
}

//Get method for phone number
string Person::getPhoneNo(){
	return phoneNo;
}

//Prints out all the information stored in the person
void Person::displayPerson(){
	cout << "Name: " << fullName << endl;
	cout << "Address: " << address << endl;
	cout << "Postcode: " << postcode << endl;
	cout << "Phone Number: " << phoneNo << endl;
}

//Destructor for person that says who is being deleted
Person::~Person(){
	cout << "Deleting " << fullName << endl;
}