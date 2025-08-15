/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:39 by pbret             #+#    #+#             */
/*   Updated: 2025/08/15 12:39:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Contact.class.hpp"
#include "../includes/PhoneBook.class.hpp"
/* std::string	_firstName;
				std::string	_lastName;
				std::string _nickName;
				std::string	_phoneNumber;
				std::string	_darknestSecret; */
Contact::Contact(void)// : _idx(0)
{
	std::cout << "constructor Contact called" << std::endl;
	_field[0] = "First name";
	_field[1] = "Last name";
	_field[2] = "Nickname";
	_field[3] = "Phone number";
	_field[4] = "Darkest secret";
	
	for(int i = 0; i < 5; i++)
		_value[i] = "";
}

Contact::~Contact(void)
{
	std::cout << "desstructor Contact called" << std::endl;
}

std::string	Contact::getField(int idx) const
{
	return (this->_field[idx]);
}

std::string	Contact::getValue(int idx) const
{
	return (this->_value[idx]);
}

void	Contact::addContact(void)
{
	for(int i = 0; i < 5; i++)
	{
		std::cout << "- " << _field[i] << " : ";
		if(!std::getline(std::cin, _value[i]))
			break ;
	}
}
