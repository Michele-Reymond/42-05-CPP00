
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

public:
    Contact Contacts[8];
    
    PhoneBook(void);
    ~PhoneBook(void);

    void search(void);

private:

    int _display_contacts(void);
    void _display_the_one(int index);
    void _print_column(std::string str);
};

#endif