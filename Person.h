#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "Address.h"
#include "DynamicArray.h"

using namespace std;

class Person {
private:
    string first_name;
    string last_name;
    DynamicArray<string> phone;
    DynamicArray<string> email;
    string classification;
    bool favourite;
    Address address;

public:
    Person(string first_name = "", string last_name = "",
        DynamicArray<string> phone = DynamicArray<string>(),
        DynamicArray<string> email = DynamicArray<string>(),
        string classification = "", bool favourite = false,
        Address address = Address());

    Person(const Person& other)
        : first_name(other.first_name),
        last_name(other.last_name),
        phone(other.phone), 
        email(other.email), 
        classification(other.classification),
        favourite(other.favourite),
        address(other.address) {}

    string getFirstName() const;
    string getLastName() const;
    DynamicArray<string> getPhoneNumbers() const;
    DynamicArray<string> getEmails() const;
    string getClassification() const;
    bool isFavourite() const;
    Address getAddress() const;
    void setFirstName(string newName);
    void setLastName(string newName);
    void addPhoneNumber(string newPhone);
    void addEmail(string newEmail);
    void setClassification(string newClassification);
    void setFavourite(bool newFavourite);
    void setAddress(Address newAddress);

    void printPerson() const;

    bool operator==(const Person& other) const;
    Person& operator=(const Person& other) {
        if (this != &other) { 
            first_name = other.first_name;
            last_name = other.last_name;
            phone = other.phone;
            email = other.email;
            classification = other.classification;
            favourite = other.favourite;
            address = other.address;
        }
        return *this; 
    }

};

#endif // PERSON_H
