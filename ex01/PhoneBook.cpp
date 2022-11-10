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

std::string PhoneBook::_get_input()
{
    std::string input;

    std::cout << "What do you want to do? ADD, SEARCH or EXIT?" << std::endl << ">>";
    std::getline(std::cin, input);
    input = _uppercase(input);
    return(input);
}

std::string	PhoneBook::_uppercase(std::string str)
{
	int i;

	i = 0;
	while (str[i])
    {
		str[i] = toupper(str[i]);
        i++;
    }
	return (str);
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


int PhoneBook::_search(void) {
    std::string input;
    int index;

    if (_display_contacts())
    {
        std::cout << "Please enter the index of the chosen one" << std::endl << ">>";
        std::getline(std::cin, input);
        if (std::cin.fail())
            return (1);
        index = strtol(input.c_str(), NULL, 10);
        if (!input.empty())
            _display_the_one(index);
        else
        {
            std::cout << "Oops you did't enter something!!" << std::endl << std::endl;
            if (_search())
                return (1);
        }
    }
    return (0);
}

void PhoneBook::loop(void) {
    std::string input;
    int         i;

    i = 0;
    while ((input = _get_input()) != "EXIT")
    {
        if (std::cin.fail())
            break;
        std::cin.clear(); //clear error flag on cin
        if (input == "ADD")
        {
            this->Contacts[i].add_contact();
            if (this->Contacts[i].is_not_ok())
                break;
            if (++i == 8)
			    i = 0;
        }
        else if (input == "SEARCH")
        {
            if (this->_search())
                break;
        }
        else
            std::cout << "Not a valid entry" << std::endl;
    }
}
