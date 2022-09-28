#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) {
    std::cout << "Constructor called" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

void PhoneBook::_print_column(std::string str) {
    unsigned int    len;
    int             i;

    i = 0;
    len = str.length();
    if (len == 10)
        std::cout << str << '|';
    else if (len < 10)
    {
        while (len < 10)
        {
            std::cout << ' ';
            len++;
        }
        std::cout << str << '|';
    }
    else
    {
        while (i < 9)
        {
            std::cout << str[i];
            i++;
        }
        std::cout << '.' << '|';
    }
}

int PhoneBook::_display_contacts(void) {
    int i;

    i = 0;
    if (this->Contacts[i].getFirstname().empty())
    {
        std::cout << "No entry!" << std::endl;
        return 0;
    }
    std::cout << "*****************************************************" << std::endl;
    std::cout << "                  ALL CONTACTS" << std::endl;
    std::cout << "*****************************************************" << std::endl;
    _print_column("index");
    _print_column("First name");
    _print_column("Last name");
    _print_column("Nickname");
    std::cout << std::endl;
    std::cout << "     ---------------------------------------" << std::endl;
    while (i < 8)
    {
        if (!this->Contacts[i].getFirstname().empty())
        {
            std::cout << "         " << i + 1 << '|';
            _print_column(this->Contacts[i].getFirstname());
            _print_column(this->Contacts[i].getLastname());
            _print_column(this->Contacts[i].getNickname());
            std::cout << std::endl;
            std::cout << "     ---------------------------------------" << std::endl;
        }
        i++;
    }
    std::cout << "*****************************************************" << std::endl;
    return 1;
}

void PhoneBook::_display_the_one(int index) {
    
    if (index > 8 || index < 1 || this->Contacts[index - 1].getFirstname().empty()) {
        std::cout << "Oops wrong index!" << std::endl;
        return;
    } else {
        std::cout << "First name: " << this->Contacts[index - 1].getFirstname() << std::endl;
        std::cout << "Last name: " << this->Contacts[index - 1].getLastname() << std::endl;
        std::cout << "Nickname: " << this->Contacts[index - 1].getNickname() << std::endl;
        std::cout << "Phone number: " << this->Contacts[index - 1].getPhonenbr() << std::endl;
        std::cout << "Darkest secret: " << this->Contacts[index - 1].getSecret() << std::endl;
    }

    return;
}

void PhoneBook::search(void) {
    int input;

    if (_display_contacts())
    {
        std::cout << "Please enter the index of the chosen one" << std::endl << ">>";
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        _display_the_one(input);
    }
}
