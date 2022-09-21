
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

public:

    Contact Contacts[8];

    PhoneBook(void);
    ~PhoneBook(void);

};

#endif