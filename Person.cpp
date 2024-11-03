#include "Person.h"

Person::Person(string first_name, string last_name, DynamicArray<string> phone,
    DynamicArray<string> email, string classification, bool favourite,
    Address address)
    : first_name(first_name), last_name(last_name), phone(phone), email(email),
    classification(classification), favourite(favourite), address(address) {
}

string Person::getFirstName() const {
    return first_name;
}

string Person::getLastName() const {
    return last_name;
}

DynamicArray<string> Person::getPhoneNumbers() const {
    return phone;
}

DynamicArray<string> Person::getEmails() const {
    return email;
}

string Person::getClassification() const {
    return classification;
}

bool Person::isFavourite() const {
    return favourite;
}

Address Person::getAddress() const {
    return address;
}

void Person::setFirstName(string newName) {
    first_name = newName;
}

void Person::setLastName(string newName) {
    last_name = newName;
}

void Person::addPhoneNumber(string newPhone) {
    phone.append(newPhone);
}

void Person::addEmail(string newEmail) {
    email.append(newEmail);
}

void Person::setClassification(string newClassification) {
    classification = newClassification;
}

void Person::setFavourite(bool newFavourite) {
    favourite = newFavourite;
}

void Person::setAddress(Address newAddress) {
    address = newAddress;
}

void Person::printPerson() const {
    cout << endl;
    cout << "----------------------" << endl;
    cout << "| Person Information |" << endl;
    cout << "----------------------" << endl;
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;

    cout << "Phone Numbers: ";
    for (int i = 0; i < phone.getSize(); ++i) {
        cout << phone[i] << " ";
    }
    cout << endl;

    cout << "Emails: ";
    for (int i = 0; i < email.getSize(); ++i) {
        cout << email[i] << " ";
    }
    cout << endl;

    cout << "Classification: " << classification << endl;
    cout << "Favourite: " << (favourite ? "Yes" : "No") << endl;

    address.printAddress();
}

bool Person::operator==(const Person& other) const {
    return this->first_name == other.first_name &&
        this->last_name == other.last_name;
}
