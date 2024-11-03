#include <iostream>
#include <windows.h>
#include "ContactsBook.h"

using namespace std;


void main_menu() {
    cout << "\t\t\t\t\t\t================================================" << endl;
    cout << "\t\t\t\t\t\t|               Contacts Book Menu             |" << endl;
    cout << "\t\t\t\t\t\t================================================" << endl;
    cout << "\t\t\t\t\t\t1. Add a new Contact" << endl;
    cout << "\t\t\t\t\t\t2. Search by Last Name (Enter LastName correctly)" << endl;
    cout << "\t\t\t\t\t\t3. Search by Classification (friend, work, family, other)" << endl;
    cout << "\t\t\t\t\t\t4. Print All Contacts" << endl;
    cout << "\t\t\t\t\t\t5. Print Fav Contacts" << endl;
    cout << "\t\t\t\t\t\t6. Save to File" << endl;
    cout << "\t\t\t\t\t\t7. Load from File" << endl;
    cout << "\t\t\t\t\t\t8. Delete Contact" << endl;
    cout << "\t\t\t\t\t\t9. Update Contact Information" << endl;
    cout << "\t\t\t\t\t\t10. Reverse contacts book" << endl;
    cout << "\t\t\t\t\t\t11. Exit" << endl;
    cout << "\t\t\t\t\t\t================================================" << endl;
}


int main()
{
    bool running = true;
    int choice;
    ContactsBook contacts;

    while (running)
    {
        main_menu();
        cout << "Enter Your Choice : " ;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1: {
            cout << "\t\t\t\t\t\t--- Add a New Contact ---" << endl;

            string firstName, lastName, classification;
            bool favourite;

            cout << "First Name: ";
            cin >> firstName;

            cout << "Last Name: ";
            cin >> lastName;

            cout << "Class (Friend, work, family, other): ";
            cin >> classification;

            cout << "Set as Fav (Press 1 for fav or 0 for Not): ";
            cin >> favourite;

            int phoneCount;
            DynamicArray<string> phoneNumbers;
            cout << "How many numbers: ";
            cin >> phoneCount;

            for (int i = 0; i < phoneCount; i++) {
                string phoneNumber;
                cout << "Phone #" << (i + 1) << ": ";
                cin >> phoneNumber;
                phoneNumbers.append(phoneNumber);
            }

            int emailCount;
            DynamicArray<string> emails;
            cout << "How many mails: ";
            cin >> emailCount;

            for (int i = 0; i < emailCount; i++) {
                string email;
                cout << "Mail #" << (i + 1) << ": ";
                cin >> email;
                emails.append(email);
            }

            string streetNumber, streetName, town, state;
            cout << "---Enter Address details---" << endl;
            cout << endl;
            cout << "Street number: ";
            cin >> streetNumber;
            cout << "Street name: ";
            cin >> streetName;
            cout << "Town: ";
            cin >> town;
            cout << "State: ";
            cin >> state;

            Address newAddress(streetNumber, streetName, town, state);
            Person newContact(firstName, lastName, phoneNumbers, emails, classification, favourite, newAddress);

            contacts.addcontact(newContact);

            cout << "Contact added successfully!" << endl;
            system("cls");
            break;
        }

        case 2 :
        {
            string lastname;
            cout << "Enter Last Name : ";
            cin >> lastname;
            system("cls");

            contacts.SerachByLN(lastname);
            break;

        }

        case 3:
        {
            string classification;
            cout << "Enter Classification : ";
            cin >> classification;
            system("cls");
            contacts.SerachByClass(classification);
            break;
        }

        case 4:
        {
            contacts.displayallcontacts();

            break;
        }
        case 5:
        {
            contacts.displayallFavcontacts();
            break;
        }
        case 6:
        {
            string FileName = "OutData.txt";
            system("cls");

            contacts.saveContactsToFile(FileName);
            break;
        }

        case 7:
        {
            string FileName = "InputData.txt";
            system("cls");
            contacts.loadFromFile(FileName);
            break;
        }
        case 8:
        {
            int index = 0;
            cout << "Enter Index : ";
            cin >> index;
            contacts.deletecontact(index - 1);
            system("cls");

            break;
        }

        case 9:
        {
            int index = 0;
            cout << "Enter Index of Contact to Update: ";
            cin >> index;

            Person& contact = contacts.getContact(index - 1);

            string firstName, lastName, classification;
            bool favourite;

            cout << "First Name: ";
            cin >> firstName;

            cout << "Last Name: ";
            cin >> lastName;

            cout << "Class (Friend, work, family, other): ";
            cin >> classification;

            cout << "Set as Fav (Press 1 for fav or 0 for Not): ";
            cin >> favourite;

            int phoneCount;
            DynamicArray<string> phoneNumbers;
            cout << "How many numbers: ";
            cin >> phoneCount;

            for (int i = 0; i < phoneCount; i++) {
                string phoneNumber;
                cout << "Phone #" << (i + 1) << ": ";
                cin >> phoneNumber;
                phoneNumbers.append(phoneNumber);
            }

            int emailCount;
            DynamicArray<string> emails;
            cout << "How many mails: ";
            cin >> emailCount;

            for (int i = 0; i < emailCount; i++) {
                string email;
                cout << "Mail #" << (i + 1) << ": ";
                cin >> email;
                emails.append(email);
            }

            string streetNumber, streetName, town, state;
            cout << "---Enter Address details---" << endl;
            cout << endl;
            cout << "Street number: ";
            cin >> streetNumber;
            cout << "Street name: ";
            cin >> streetName;
            cout << "Town: ";
            cin >> town;
            cout << "State: ";
            cin >> state;

            Address newAddress(streetNumber, streetName, town, state);
            Person newContact(firstName, lastName, phoneNumbers, emails, classification, favourite, newAddress);
            contact = newContact;
            system("cls");

            cout << "Contact updated successfully!" << endl;
            break;
        }

        case 10:
        {
            contacts.ReverseContacts();
            cout << "Contacts Reversed successfully " << endl;
            break;
        }

        default:
           
            break;
        }

    }
   
    return 0;
}
