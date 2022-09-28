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
    std::cin.clear();
    while (input.empty())
    {
        std::cout << "You must enter something" << std::endl;
        input = _ask(question);
    }
    return (input);
}

void Contact::add_contact(void) {
    
    this->_firstname = _ask("What's the first name?");
    this->_lastname = _ask("What's the last name?");
    this->_nickname = _ask("What's the nick name?");
    this->_phonenbr = _ask("What's the phone number?");
    this->_secret = _ask("What's the darkest secret of this person?");
}
