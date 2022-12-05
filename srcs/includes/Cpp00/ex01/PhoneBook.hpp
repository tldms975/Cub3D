#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	private:
		Contact	contact[8];
		int		numOfContact;
	public:
		PhoneBook();
		~PhoneBook();
		void		add();
		void		search();
		void		exit();
		std::string	inputField(std::string field);
};

#endif