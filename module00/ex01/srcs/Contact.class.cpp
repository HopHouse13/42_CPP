/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:39 by pbret             #+#    #+#             */
/*   Updated: 2025/08/19 02:02:59 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.class.hpp"

Contact::Contact(void)// : _idx(0)
{
	// std::cout << "constructor Contact called" << std::endl;
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
	//std::cout << "desstructor Contact called" << std::endl;
}

std::string	Contact::getField(int idx) const
{
	return (this->_field[idx]);
}

std::string	Contact::getValue(int idx) const
{
	return (this->_value[idx]);
}

bool	Contact::addContact(void)
{
	std::cout << std::endl;
	for(int i = 0; i < 5; i++)
	{
		std::cout <<GOLD << std::right << std::setw(15) << _field[i] << RESET << "\t";
		if(!std::getline(std::cin, _value[i]))
		{
			std::cout << std::endl;
			return (false);
		}
	}
	return (true);
}
