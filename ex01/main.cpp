#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	uppercase(std::string str)
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

std::string get_input()
{
    std::string input;

    std::cout << "What do you want to do? ADD, SEARCH or EXIT?" << std::endl;
    std::cin >> input;
    input = uppercase(input);
    std::cin.clear(); //clear error flag on cin
	std::cin.ignore(256,'\n'); //clear buffer before taking new
    return(input);
}

int main() {
    PhoneBook   phone;
    std::string input;
    int         i;

    i = 0;
    while ((input = get_input()) != "EXIT")
    {
        if (input == "ADD")
        {
            phone.Contacts[i].add_contact();
            if (++i == 8)
			    i = 0;
        }
        else if (input == "SEARCH")
            phone.search();
        else
            std::cout << "Not a valid entry" << std::endl;
    }
    return (0);
}