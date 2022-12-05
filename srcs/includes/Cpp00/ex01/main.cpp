#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	while (true)
	{
		std::cout << "Enter [ADD, SEARCH, EXIT]\n";
		std::cin.clear();
		std::getline(std::cin, input);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << "Wrong Input\n";
			std::exit(1);
		}
		else if (input.compare("ADD") == 0)
			phoneBook.add();
		else if (input.compare("SEARCH") == 0)
			phoneBook.search();
		else if (input.compare("EXIT") == 0)
			phoneBook.exit();
	}
}