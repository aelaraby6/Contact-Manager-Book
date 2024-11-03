#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>

using namespace std;

class Address {
private:
    string streetNumber;       
    string streetName;         
    string town;              
    string state;             

public:
    Address(string streetNumber = "", string streetName = "", string town = "", string state = "");

    void setStreetNumber(string newStreetNumber);
    void setStreetName(string newStreetName);
    void setTown(string newTown);
    void setState(string newState);

    string getStreetNumber() const;
    string getStreetName() const;
    string getTown() const;
    string getState() const;

    void printAddress() const;
};

#endif
