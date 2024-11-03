#include <iomanip> 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Person.h"
#include "ContactsBook.h"

using namespace std;

int getConsoleWidth() {
   
    return 156; 
}


void ContactsBook::displayallcontacts() {
    if (contacts.getSize() == 0) {
        cout << "No contacts available." << endl;
        return;
    }

    
    int consoleWidth = getConsoleWidth();
    int width = (consoleWidth - 10) / 8; 

    cout << setw((consoleWidth / 2) + 10) << right << "Contacts Information" << setw((consoleWidth / 2) - 10) << "" << endl;
    cout << endl;

    cout << setfill(' ')
        << setw(width) << left << "ID"
        << setw(width) << left << "FName"
        << setw(width) << left << "LName"
        << setw(width) << left << "Classification"
        << setw(width) << left << "Fav"
        << setw(width) << left << "Address"
        << setw(width) << left << "Emails"
        << setw(width) << left << "Phone Numbers" << endl;

    cout << setfill('-') << setw(consoleWidth) << "" << endl;

    for (int i = 0; i < contacts.getSize(); i++) {
        Person& person = contacts[i];

        string address = person.getAddress().getStreetNumber() + " " +
            person.getAddress().getStreetName() + " " +
            person.getAddress().getTown() + " " + person.getAddress().getState();

        string phoneNumbers = "";
        for (int j = 0; j < person.getPhoneNumbers().getSize(); ++j) {
            phoneNumbers += person.getPhoneNumbers()[j];
            if (j < person.getPhoneNumbers().getSize() - 1) {
                phoneNumbers += ", ";
            }
        }

        string emails = "";
        for (int j = 0; j < person.getEmails().getSize(); ++j) {
            emails += person.getEmails()[j];
            if (j < person.getEmails().getSize() - 1) {
                emails += ", ";  
            }
        }

        cout << setfill(' ')
            << setw(width) << left << i + 1
            << setw(width) << left << person.getFirstName()
            << setw(width) << left << person.getLastName()
            << setw(width) << left << person.getClassification()
            << setw(width) << left << (person.isFavourite() ? "Yes" : "No")
            << setw(width) << left << address
            << setw(width) << left << emails
            << setw(width) << left << phoneNumbers
            << endl;

        cout << setfill('-') << setw(consoleWidth) << "" << endl;
    }
}

void ContactsBook::displayallFavcontacts() {
    if (contacts.getSize() == 0) {
        cout << "No contacts available." << endl;
        return;
    }


    int consoleWidth = getConsoleWidth();
    int width = (consoleWidth - 10) / 8;

    cout << setw((consoleWidth / 2) + 10) << right << "Contacts Information" << setw((consoleWidth / 2) - 10) << "" << endl;
    cout << endl;

    cout << setfill(' ')
        << setw(width) << left << "ID"
        << setw(width) << left << "FName"
        << setw(width) << left << "LName"
        << setw(width) << left << "Classification"
        << setw(width) << left << "Fav"
        << setw(width) << left << "Address"
        << setw(width) << left << "Emails"
        << setw(width) << left << "Phone Numbers" << endl;

    cout << setfill('-') << setw(consoleWidth) << "" << endl;


    for (int i = 0; i < contacts.getSize(); i++) {
        if (contacts[i].isFavourite() == 1) {
            Person& person = contacts[i];

            string address = person.getAddress().getStreetNumber() + " " +
                person.getAddress().getStreetName() + " " +
                person.getAddress().getTown() + " " + person.getAddress().getState();

            string phoneNumbers = "";
            for (int j = 0; j < person.getPhoneNumbers().getSize(); ++j) {
                phoneNumbers += person.getPhoneNumbers()[j];
                if (j < person.getPhoneNumbers().getSize() - 1) {
                    phoneNumbers += ", ";
                }
            }

            string emails = "";
            for (int j = 0; j < person.getEmails().getSize(); ++j) {
                emails += person.getEmails()[j];
                if (j < person.getEmails().getSize() - 1) {
                    emails += ", ";
                }
            }

            cout << setfill(' ')
                << setw(width) << left << i + 1
                << setw(width) << left << person.getFirstName()
                << setw(width) << left << person.getLastName()
                << setw(width) << left << person.getClassification()
                << setw(width) << left << (person.isFavourite() ? "Yes" : "No")
                << setw(width) << left << address
                << setw(width) << left << emails
                << setw(width) << left << phoneNumbers
                << endl;

            cout << setfill('-') << setw(consoleWidth) << "" << endl;
        }
        }
    }


void ContactsBook::addcontact(Person contact) {
    contacts.append(contact);
}

void ContactsBook::deletecontact(int index) {
    if (index != -1) {
        contacts.Delete(index);
    }
    else {
        cout << "Contact not found!" << endl;
    }
}

void ContactsBook::SerachByLN(string Ln) {
    bool flag = 0;
    for (size_t i = 0; i < contacts.getSize(); i++)
    {
        if (contacts[i].getLastName() == Ln) {
            flag = 1;
            contacts[i].printPerson();
        }
    }
    if (!flag) {
        cout << "Not Found " << endl;
    }

}

void ContactsBook::SerachByClass(string classification) {
    bool flag = 0;
    for (size_t i = 0; i < contacts.getSize(); i++)
    {
        if (contacts[i].getClassification() == classification) {
            flag = 1;
            contacts[i].printPerson();
        }
    }
    if (!flag) {
        cout << "Not Found " << endl;
    }
}



int ContactsBook::searchIndex(Person contact) {
    for (int i = 0; i < contacts.getSize(); i++) {
        if (contacts.get(i) == contact) {
            return i;
        }
    }
    return -1;
}

void ContactsBook::ReverseContacts()
{
    contacts.reverse();
}

Person& ContactsBook::getContact(int index){
    if (index < 0 || index >= contacts.getSize()) {
        throw out_of_range("Index out of range");
    }
    return contacts[index];  
}

void ContactsBook::saveContactsToFile(const string& filename)
{
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return;
    }

    for (size_t i = 0; i < contacts.getSize(); i++) {
        outFile << "First Name: " <<contacts[i].getFirstName() << endl;
        outFile << "Last Name: " << contacts[i].getLastName() << endl;

        // Save phone numbers
        outFile << "Phone Numbers: ";
        for (size_t j = 0; j < contacts[i].getPhoneNumbers().getSize(); j++) {
            outFile << contacts[i].getPhoneNumbers()[j];
            if (j < contacts[i].getPhoneNumbers().getSize() - 1) outFile << ", ";
        }
        outFile << endl;

        outFile << "Emails: ";
        for (size_t j = 0; j < contacts[i].getEmails().getSize(); j++) {
            outFile << contacts[i].getEmails()[j];
            if (j < contacts[i].getEmails().getSize() - 1) outFile << ", ";
        }
        outFile << endl;

        outFile << "Classification: " << contacts[i].getClassification() << endl;
        outFile << "Favourite: " << (contacts[i].isFavourite() ? "Yes" : "No") << endl;
        outFile << "--- Address Info --- "<<endl;
        outFile << "StreetNumber: " << contacts[i].getAddress().getStreetNumber() << endl;
        outFile << "StreetName: " << contacts[i].getAddress().getStreetName()<<endl;
        outFile << "Town: " << contacts[i].getAddress().getTown()<< endl;
        outFile << "State: " << contacts[i].getAddress().getState() << endl;
        outFile << endl << "----------------------" << endl;
    }

    outFile.close();
    cout << "Contacts saved successfully to " << filename << endl;

}

void ContactsBook::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file for reading!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue; 

        if (line == "----------------------") {
            break;
        }

        if (line.find("First Name: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("Last Name: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("Phone Numbers: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("Emails: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("Classification: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("Favourite: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("StreetNumber: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("StreetName: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("Town: ") == 0) {
            cout << line << endl; 
        }
        else if (line.find("State: ") == 0) {
            cout << line << endl; 
        }
    }

    inFile.close();
    cout << "Contact loaded successfully from " << filename << endl;
}