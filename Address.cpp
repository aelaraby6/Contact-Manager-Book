#include "Address.h"

Address::Address(string streetNumber, string streetName, string town, string state)
    : streetNumber(streetNumber), streetName(streetName), town(town), state(state) {}

void Address::setStreetNumber(string newStreetNumber) {
    streetNumber = newStreetNumber;
}

void Address::setStreetName(string newStreetName) {
    streetName = newStreetName;
}

void Address::setTown(string newTown) {
    town = newTown;
}

void Address::setState(string newState) {
    state = newState;
}

string Address::getStreetNumber() const {
    return streetNumber;
}

string Address::getStreetName() const {
    return streetName;
}

string Address::getTown() const {
    return town;
}

string Address::getState() const {
    return state;
}

void Address::printAddress() const {
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "| Address Information |" << endl;
    cout << "-----------------------" << endl;
    cout << endl;
    cout << "State: " << state << endl;
    cout << "Town: " << town << endl;
    cout << "Street Number: " << streetNumber << endl;
    cout << "Street Name: " << streetName << endl;
}
