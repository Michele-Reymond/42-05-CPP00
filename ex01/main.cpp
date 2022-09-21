#include <iostream>
#include "PhoneBook.hpp"

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

    std::cout << "What do you want to do? Add, Search or exit?" << std::endl;
    std::cin >> input;
    input = uppercase(input);
    std::cin.clear();
	std::cin.ignore(256,'\n');
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
            phone.Contacts[i].get_infos();
        else if (input == "SEARCH")
            phone.Contacts[i].search();
        else
            std::cout << "Not a valid entry\n" << std::endl;
        if (++i == 8)
			i = 0;
    }
    return (0);
}