
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

public:
    PhoneBook(void);
    ~PhoneBook(void);

    void        loop(void);

private:
    Contact Contacts[8];

    int         _search(void);
    int         _display_contacts(void);
    void        _display_the_one(int index);
    void        _print_column(std::string str);
    std::string _get_input();
    std::string	_uppercase(std::string str);
};

#endif