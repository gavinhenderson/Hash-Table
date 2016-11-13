//Gavin Henderson
//150010848

#include "HashTable.h"

using namespace std;

//main method
int main(){
	//sets up variables and explains hashtable
	Person* newPerson;
	HashTable* table = new HashTable();
	cout << "**********************************************************" << endl;
	cout << "This tester makes various people in the hashtable" << endl;
	cout << "Some will cause collisions and some wont" << endl;
	cout << "It will also display some people and then delete the table" << endl;
	cout << "**********************************************************" << endl;
	
	//Creates person 'Gavin'
	newPerson = new Person("Gavin");
	table->addToTable(newPerson);
	cout << endl;
	
	//Creates person 'Daniel'
	newPerson = new Person("Daniel");
	table->addToTable(newPerson);
	cout << endl;
	
	//Creates person 'Conor'
	newPerson = new Person("Conor");
	table->addToTable(newPerson);
	cout << endl;
	
	//Creates person 'Ainslie'
	newPerson = new Person("Ainslie");
	table->addToTable(newPerson);
	cout << endl;
	
	//Creates person '>'
	newPerson = new Person(">");
	table->addToTable(newPerson);
	cout << endl;
	
	//Creates person '<' that will collide with '>'
	newPerson = new Person("<");
	table->addToTable(newPerson);
	cout << endl;
	
	//Displays person
	newPerson = table->getFromTable("Daniel",1);
	newPerson->displayPerson();
	cout << endl;
	
	//Displays person
	newPerson = table->getFromTable("Gavin",1);
	newPerson->displayPerson();
	cout << endl;
	
	//Displays person
	newPerson = table->getFromTable(">",1);
	newPerson->displayPerson();
	cout << endl;
	
	//Displays person
	newPerson = table->getFromTable("<",1);
	newPerson->displayPerson();
	cout << endl;
	
	//Displays person
	newPerson = table->getFromTable("Ainslie", 1);
	newPerson->displayPerson();
	cout << endl;
	
	//Displays person
	newPerson = table->getFromTable("Conor", 1);
	newPerson->displayPerson();
	cout << endl;
	
	//Deletes table
	delete table;
}