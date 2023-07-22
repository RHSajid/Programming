#include <iostream>
#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string address;
};

std::vector<Contact> addressBook;

void addContact()
{
    Contact newContact;

    std::cout << "\n\t\tEnter name: ";
    std::getline(std::cin, newContact.name);

    std::cout << "\t\tEnter phone number: ";
    std::getline(std::cin, newContact.phoneNumber);

    std::cout << "\t\tEnter address: ";
    std::getline(std::cin, newContact.address);

    addressBook.push_back(newContact);

    std::cout << "\n\t\t\t\t\t\tContact added successfully!\n\n";
}

void displayContacts()
{
    if (addressBook.empty()) {
        std::cout << "\n\t\t\t\t\t\tAddress book is empty!\n";
        }
    else {
        std::cout << "\n\t\t\t\t\tAddress Book:\n";
        for (const auto& contact : addressBook) {
            std::cout << "\n\t\t\t\t\t\tName: " << contact.name << "\n";
            std::cout << "\t\t\t\t\t\tPhone: " << contact.phoneNumber << "\n";
            std::cout << "\t\t\t\t\t\tAddress: " << contact.address << "\n";
            std::cout << "\n\t\t\t\t\t\t\t----------------\n\n";
        }
    }
}

void searchContact()
{
    std::string searchTerm;
    std::cout << "\n\t\tEnter the name to search: ";
    std::getline(std::cin, searchTerm);

    std::vector<Contact> matchingContacts;

    for (const auto& contact : addressBook) {
        if (contact.name.find(searchTerm) != std::string::npos) {
            matchingContacts.push_back(contact);
        }
    }

    if (matchingContacts.empty()) {
        std::cout << "\n\t\t\t\t\t\tNo matching contacts found!\n\n";
        }
    else {
        std::cout << "\n\t\t\t\t\tMatching Contacts:\n";
        for (const auto& contact : matchingContacts) {
            std::cout << "\n\t\t\t\t\t\tName: " << contact.name << "\n";
            std::cout << "\t\t\t\t\t\tPhone: " << contact.phoneNumber << "\n";
            std::cout << "\t\t\t\t\t\tAddress: " << contact.address << "\n";
            std::cout << "\n\t\t\t\t\t\t\t----------------\n\n";
        }
    }
}

void editContact()
{
    std::string searchTerm;
    std::cout << "\n\t\tEnter the name of the contact to edit: ";
    std::getline(std::cin, searchTerm);

    for (auto& contact : addressBook) {
        if (contact.name == searchTerm) {
            std::cout << "\n\t\t\tEnter new phone number: ";
            std::getline(std::cin, contact.phoneNumber);

            std::cout << "\t\t\tEnter new address: ";
            std::getline(std::cin, contact.address);

            std::cout << "\n\t\t\t\t\t\tContact updated successfully!\n\n";
            return;
        }
    }

    std::cout << "\n\t\t\t\t\t\tContact not found!\n\n";
}

void deleteContact()
{
    std::string searchTerm;
    std::cout << "\n\t\tEnter the name of the contact to delete: ";
    std::getline(std::cin, searchTerm);

    for (auto it = addressBook.begin(); it != addressBook.end(); ++it) {
        if (it->name == searchTerm) {
            addressBook.erase(it);
            std::cout << "\n\t\t\t\t\t\tContact deleted successfully!\n\n";
            return;
        }
    }

    std::cout << "\n\t\t\t\t\t\tContact not found!\n\n";
}

int main()
{
    char choice;
    do {
        std::cout << "\t\t\t\t\t\tWelcome To My Addressbook!\n\t\t\t\t:) Please Choose the Action to be Done from the Menu :)\n\n";
        std::cout << "Address Book Menu:\n\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display Contacts\n";
        std::cout << "3. Search Contact\n";
        std::cout << "4. Edit Contact\n";
        std::cout << "5. Delete Contact\n";
        std::cout << "6. Exit\n";
        std::cout << "\n\tEnter your choice: ";
        std::cin >> choice;

        std::cin.ignore();

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
                std::cout << "\n\t\t\t\t\tExiting the program.....Press Enter or any key.\n";
                break;
            default:
                std::cout << "\n\t\t\t\t\t\tInvalid choice! Try again.\n\n";
        }
    } while (choice != '6');

    return 0;
}
