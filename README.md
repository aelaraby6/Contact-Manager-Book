![uml](https://github.com/user-attachments/assets/e6f65070-c4a3-4604-bd8e-a8c87db75eac)

Contact Manager Book Project
Overview
The Contact Manager Book is a command-line application designed to help users manage their contacts efficiently. Built using Object-Oriented Programming (OOP) principles, this project utilizes a dynamic array class to handle a variable number of contacts, providing functionalities such as adding, updating, deleting, searching, and saving contacts to a file. The project emphasizes modularity and data management, making it easy to maintain and extend.

Features
Add new contacts with multiple phone numbers and emails.
Search contacts by last name or classification (friend, work, family, other).
Display all contacts or favorite contacts.
Update and delete existing contacts.
Save contacts to a text file and load from a file.
Reverse the order of contacts.
Classes Overview
1. Address Class
Purpose: Represents the address details of a contact.
Attributes:
streetNumber: The street number of the contact's address.
streetName: The street name of the contact's address.
town: The town of the contact's address.
state: The state of the contact's address.
Methods:
Constructors and setters/getters for each attribute.
printAddress(): Outputs the address in a readable format.
2. Person Class
Purpose: Represents an individual contact.
Attributes:
first_name: The first name of the contact.
last_name: The last name of the contact.
phone: A dynamic array holding multiple phone numbers.
email: A dynamic array holding multiple email addresses.
classification: Classification of the contact (e.g., friend, work).
favourite: Boolean indicating if the contact is a favorite.
address: An instance of the Address class for storing address details.
Methods:
Constructors, copy constructor, and assignment operator.
Getters and setters for each attribute.
printPerson(): Outputs contact details in a readable format.
operator==: Compares two Person objects.
3. DynamicArray Class
Purpose: A template class that implements a dynamic array to hold elements of any data type.
Attributes:
arr: Pointer to the dynamic array.
size: Current number of elements in the array.
capacity: Total capacity of the array.
Methods:
Constructors and destructors to manage memory.
append(): Adds an element to the array.
Delete(): Removes an element at a specified index.
getSize(): Returns the current size of the array.
get(): Retrieves an element at a specified index.
reverse(): Reverses the elements of the array.
display(): Outputs all elements in the array.
4. ContactsBook Class
Purpose: Manages a collection of Person objects.
Attributes:
contacts: A dynamic array holding all contacts.
Methods:
addcontact(): Adds a new contact to the collection.
deletecontact(): Deletes a contact based on its index.
displayallcontacts(): Displays all contacts in the collection.
displayallFavcontacts(): Displays favorite contacts.
SerachByLN(): Searches for contacts by last name.
SerachByClass(): Searches for contacts by classification.
searchIndex(): Finds the index of a specific contact.
ReverseContacts(): Reverses the order of the contact list.
getContact(): Retrieves a contact at a specified index.
saveContactsToFile(): Saves contacts to a specified file.
loadFromFile(): Loads contacts from a specified file.
How to Run
Ensure you have a C++ compiler installed (e.g., g++, Visual Studio).
Clone or download the project repository.
Compile the code using a C++ compiler.
Run the executable file produced to start the application.
Conclusion
This Contact Manager project demonstrates the application of OOP concepts and data structures in C++. It provides a solid foundation for managing contact information while allowing for further enhancements and scalability.


