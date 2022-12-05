#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->numOfContact = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string	PhoneBook::inputField(const std::string field)
{
	std::string	str;

	while (true)
	{
		std::cout << "Enter the " << field << ": ";
		std::cin.clear();
		std::getline(std::cin, str);
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << "Wrong Input\n";
			std::exit(1);
		}
		if (str.length() == 0)
		{
			std::cout << "Empty input is not allowed!\n";
			//std::cin.ignore(1, '\n');
		}
		else
			break ;
	}
	return (str);
}

void	PhoneBook::add()
{
	std::string info[5];

	info[0] = inputField("first name");
	info[1] = inputField("last name");
	info[2] = inputField("Nickname");
	info[3] = inputField("Phone Number");
	info[4] = inputField("Darkest Secret");
	contact[numOfContact % 8].saveInfo(info);
	numOfContact++;
	if (numOfContact > 8)
		numOfContact = 8;
	std::cout << "\nSuccessfully Added!\n\n";
}

void	PhoneBook::search()
{
	std::string	contour = "-------------------------------------------\n";
	std::string	showLine = "###########################################\n";
	int	idx = 0;

	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "FirstName" << "|";
	std::cout << std::setw(10) << std::right << "LastName" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "\n";
	std::cout << contour;
	for (int i = 0; i < numOfContact; i++)
	{
		contact[i].displayContacts(i);
		std::cout << contour;
	}
	std::cout << "Input the index of the contact you want to see: ";
	std::cin.clear();
	std::cin >> idx;
	while (std::cin.fail())
	{
		std::cout << idx << "Wrong Input. Please input the index number\n";
		std::exit(1);
	}
	while ((idx < 0 || idx > 8) || (idx >= numOfContact))
	{
		std::cout << "Out of Range! You can choose a only vaild index\n";
		std::cin.clear();
		std::cin >> idx;
	}
	std::cout << "\n" << showLine;
	contact[idx].showContact();
	std::cout << showLine << "\n";
	std::cin.ignore(1, '\n');
}

void	PhoneBook::exit()
{
	std::exit(0);
}