//Gavin Henderson
//150010848

#include "HashTable.h"

using namespace std;

//Main method that shows menue
int main(){
	//Creates hashtable
	HashTable* hashTable = new HashTable();
	
	//Sets up a loop that will run until its make to stop
	bool cont = true;
	while(cont){
		//Display user options
		cout << "1) Add a Person to the table" << endl;
		cout << "2) Display a person by name" << endl;
		cout << "3) Display a person by address" << endl;
		cout << "4) Display a person by postcode" << endl;
		cout << "5) Display a person by phone number" << endl;
		cout << "0) Quit" << endl;
		
		//Take input and validates it
		bool valid = false;
		int choice = 0;
		while(!valid){
			cout << "Enter a choice: ";
			cin >> choice;
			cin.ignore();
			if(choice<0 || choice>5){
				cout << "Invalid choice! Try again" << endl;
			}else{
				valid = true;
			}
		}
		
		//Adds a node to the table
		if(choice==1){
			Person* newPerson = new Person();
			hashTable->addToTable(newPerson);
		//searches by name
		}else if(choice==2){
			string searchName;
			cout << "Enter the search name: ";
			getline(cin, searchName);
			Person* myPerson = hashTable->getFromTable(searchName, 1);
			if(myPerson!=NULL){
				myPerson->displayPerson();
			}
		//searches by address
		}else if(choice==3){
			string searchAddress;
			cout << "Enter the search address: ";
			getline(cin, searchAddress);
			Person* myPerson = hashTable->getFromTable(searchAddress, 2);
			if(myPerson!=NULL){
				myPerson->displayPerson();
			}
		//searches by postcode
		}else if(choice==4){
			string searchPostcode;
			cout << "Enter the search postcode: ";
			getline(cin, searchPostcode);
			Person* myPerson = hashTable->getFromTable(searchPostcode, 3);
			if(myPerson!=NULL){
				myPerson->displayPerson();
			}
		//searches by phone number
		}else if(choice==5){
			string searchPhoneNo;
			cout << "Enter the search phone number: ";
			getline(cin, searchPhoneNo);
			Person* myPerson = hashTable->getFromTable(searchPhoneNo, 4);
			if(myPerson!=NULL){
				myPerson->displayPerson();
			}
		//closes the program
		}else if(choice==0){
			delete hashTable;
			cont = false;
		}
	}
}