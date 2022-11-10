#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
    std::cout << "Constructor called" << std::endl;
    return;
}

Contact::~Contact(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

std::string Contact::getFirstname(void) {
    return (this->_firstname);
}

std::string Contact::getLastname(void) {
    return (this->_lastname);
}

std::string Contact::getNickname(void) {
    return (this->_nickname);
}

std::string Contact::getPhonenbr(void) {
    return (this->_phonenbr);
}

std::string Contact::getSecret(void) {
    return (this->_secret);
}

std::string Contact::_ask(std::string question) {
    std::string input;

    std::cout << question << std::endl << ">>";
    std::getline(std::cin, input);
    if (std::cin.fail())
        return ("");
    std::cin.clear();
    while (input.empty())
    {
        std::cout << "You must enter something" << std::endl;
        input = _ask(question);
    }
    return (input);
}

int Contact::is_not_ok(void) {
    if (this->_firstname.empty() || this->_lastname.empty() || this->_nickname.empty()
        || this->_phonenbr.empty() || this->_secret.empty())
        return (1);
    return (0);
}

void Contact::add_contact(void) {
    
    this->_firstname = _ask("What's the first name?");
    if (this->_firstname.empty())
        return;
    this->_lastname = _ask("What's the last name?");
    if (this->_lastname.empty())
        return;
    this->_nickname = _ask("What's the nick name?");
    if (this->_nickname.empty())
        return;
    this->_phonenbr = _ask("What's the phone number?");
    if (this->_phonenbr.empty())
        return;
    this->_secret = _ask("What's the darkest secret of this person?");
    if (this->_secret.empty())
        return;
}
