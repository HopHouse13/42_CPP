/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:39 by pbret             #+#    #+#             */
/*   Updated: 2025/11/10 19:43:36 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

Contact::Contact(void)// : _idx(0)
{
	// std::cout << "constructor Contact called" << std::endl;
	_field[0] = "First name";
	_field[1] = "Last name";
	_field[2] = "Nickname";
	_field[3] = "Phone number";
	_field[4] = "Darkest secret";
	
	for (int i = 0; i < 5; i++)
		_value[i] = "";
	return ;
}

Contact::~Contact(void)
{
	//std::cout << "desstructor Contact called" << std::endl;
	return ;
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
	bool	flag = false;
	
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (flag == false)
			std::cout << GOLD << std::right << std::setw(15) << _field[i] << RESET << "    ";
		else if (flag == true)
		{	
			std::cout << GOLD << std::right << std::setw(15) << _field[i] << RESET << " ⚠️  ";
			flag = false;
		}
		if (!std::getline(std::cin, this->_value[i]))
		{
			std::cout << std::endl;
			return (false);
		}
		else if (!this->isFull(this->_value[i])
				|| ((i == 0 || i == 1) && !this->areAlphas(this->_value[i]))
				|| ((i == 2 || i == 4) && !this->areAlNum(this->_value[i]))
				|| (i == 3 && !this->areDigitsPlus(this->_value[i])))
		{
			flag = true;
			i--;
		}
	}
	return (true);
}

// Le '+' est un operateur de surcharge. Ca a l'air de simplifier grandement.
std::string	Contact::getFormattedValue(std::string str) const
{
	std::string	result = str;

	if (str.length() > 10)
		result = str.substr(0, 9) + ".";
	return (result);
}

bool	Contact::areAlphas(std::string str) const
{
	for (int i = 0; str[i]; i++)
		if (!std::isalpha(static_cast<unsigned char>(str[i])) && str[i] != '-')
			return (false);
	return (true);
}

bool	Contact::areAlNum(std::string str) const
{
	for (int i = 0; str[i]; i++)
		if (!std::isalnum(static_cast<unsigned char>(str[i])) && str[i] != '-')
			return (false);
	return (true);
}

bool	Contact::areDigitsPlus(std::string str) const
{
	for (int i = 0; str[i]; i++)
		if (!std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '+' && str[i] != ' ')
			return (false);
	return (true);
}

bool	Contact::isFull(std::string str) const
{
	bool	flag = false;
	
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			flag = true;
	return (flag);
}
