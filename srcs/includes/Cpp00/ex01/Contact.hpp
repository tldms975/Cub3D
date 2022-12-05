#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		~Contact();
		void	saveInfo(std::string info[5]);
		void	displayContacts(int idx);
		void	displayField(std::string field);
		void	showContact();
};

#endif
