#include"person.h"
#include<iostream>

using namespace std;

class ContactsBook
{
private:
	DynamicArray<Person>contacts;
public:
	void addcontact(Person contact);
	void deletecontact(int);
	void displayallcontacts();
	void displayallFavcontacts();
	void SerachByLN(string);
	void SerachByClass(string);
	int searchIndex(Person contact);
	void ReverseContacts();
	Person &getContact(int index);
	void saveContactsToFile(const string& filename);
	void loadFromFile(const string& filename);

};

