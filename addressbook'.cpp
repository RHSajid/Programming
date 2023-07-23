#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string address;
};

vector<Contact> addressBook;
const string contactsFile = "contacts.txt";

void loadContactsFromFile()
{
    ifstream file(contactsFile);
    if (file.is_open()) {
        Contact contact;
        while (getline(file, contact.name) &&
               getline(file, contact.phoneNumber) &&
               getline(file, contact.address)) {
            addressBook.push_back(contact);
        }
        file.close();
    }
}

void saveContactsToFile()
{
    ofstream file(contactsFile);
    if (file.is_open()) {
        for (const auto& contact : addressBook) {
            file << contact.name << '\n';
            file << contact.phoneNumber << '\n';
            file << contact.address << '\n';
        }
        file.close();
    }
}

void addContact()
{
    Contact newContact;

    cout << "\n\t\tEnter name: ";
    getline(cin, newContact.name);

    cout << "\t\tEnter phone number: ";
    getline(cin, newContact.phoneNumber);

    cout << "\t\tEnter address: ";
    getline(cin, newContact.address);

    addressBook.push_back(newContact);
    saveContactsToFile();

    cout << "\n\t\t\t\t\t\tContact added successfully!\n\n";
}

void displayContacts()
{
    if (addressBook.empty()) {
        cout << "\n\t\t\t\t\t\tAddress book is empty!\n";
    }
    else {
        cout << "\n\t\t\t\t\tAddress Book:\n";
        for (const auto& contact : addressBook) {
            cout << "\n\t\t\t\t\t\tName: " << contact.name << "\n";
            cout << "\t\t\t\t\t\tPhone: " << contact.phoneNumber << "\n";
            cout << "\t\t\t\t\t\tAddress: " << contact.address << "\n";
            cout << "\n\t\t\t\t\t\t\t----------------\n\n";
        }
    }
}

void searchContact()
{
    string searchTerm;
    cout << "\n\t\tEnter the name to search: ";
    getline(cin, searchTerm);

    vector<Contact> matchingContacts;

    for (const auto& contact : addressBook) {
        if (contact.name.find(searchTerm) != string::npos) {
            matchingContacts.push_back(contact);
        }
    }

    if (matchingContacts.empty()) {
        cout << "\n\t\t\t\t\t\tNo matching contacts found!\n\n";
    }
    else {
        cout << "\n\t\t\t\t\tMatching Contacts:\n";
        for (const auto& contact : matchingContacts) {
            cout << "\n\t\t\t\t\t\tName: " << contact.name << "\n";
            cout << "\t\t\t\t\t\tPhone: " << contact.phoneNumber << "\n";
            cout << "\t\t\t\t\t\tAddress: " << contact.address << "\n";
            cout << "\n\t\t\t\t\t\t\t----------------\n\n";
        }
    }
}

void editContact()
{
    string searchTerm;
    cout << "\n\t\tEnter the name of the contact to edit: ";
    getline(cin, searchTerm);

    for (auto& contact : addressBook) {
        if (contact.name == searchTerm) {
            cout << "\n\t\t\tEnter new phone number: ";
            getline(cin, contact.phoneNumber);

            cout << "\t\t\tEnter new address: ";
            getline(cin, contact.address);

            saveContactsToFile();

            cout << "\n\t\t\t\t\t\tContact updated successfully!\n\n";
            return;
        }
    }

    cout << "\n\t\t\t\t\t\tContact not found!\n\n";
}

void deleteContact()
{
    string searchTerm;
    cout << "\n\t\tEnter the name of the contact to delete: ";
    getline(cin, searchTerm);

    for (auto it = addressBook.begin(); it != addressBook.end(); ++it) {
        if (it->name == searchTerm) {
            addressBook.erase(it);
            saveContactsToFile();

            cout << "\n\t\t\t\t\t\tContact deleted successfully!\n\n";
            return;
        }
    }

    cout << "\n\t\t\t\t\t\tContact not found!\n\n";
}

int main()
{
    loadContactsFromFile();

    char choice;
    do {
        cout << "\t\t\t\t\t\tWelcome To My Addressbook!\n\t\t\t\t:) Please Choose the Action to be Done from the Menu :)\n\n";
        cout << "Address Book Menu:\n\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
            case '1':
                addContact();
                break;
            case '2':
                displayContacts();
                break;
            case '3':
                searchContact();
                break;
            case '4':
                editContact();
                break;
            case '5':
                deleteContact();
                break;
            case '6':
                cout << "\n\t\t\t\t\tExiting the program.....Press Enter or any key.\n";
                break;
            default:
                cout << "\n\t\t\t\t\t\tInvalid choice! Try again.\n\n";
        }
    } while (choice != '6');

    return 0;
}
