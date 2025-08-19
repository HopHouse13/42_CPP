/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:39 by pbret             #+#    #+#             */
/*   Updated: 2025/08/19 17:00:09 by pab              ###   ########.fr       */
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
	
	for (int i = 0; i < 5; i++)
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
	for (int i = 0; i < 5; i++)
	{
		std::cout << GOLD << std::right << std::setw(15) << _field[i] << RESET << "\t";
		if (!std::getline(std::cin, this->_value[i]))
		{
			std::cout << std::endl;
			return (false);
		}
		else if (((i == 0 || i == 1) && !this->areAlphas(this->_value[i]))
				|| (i == 3 && !this->areDigitsPlus(this->_value[i])))
		{	
			while (true)
			{
				std::cout << GOLD << "⚠️" << std::right << std::setw(14) << _field[i] << "\t" << RESET;
				if (!std::getline(std::cin, this->_value[i]))
				{
					std::cout << std::endl;
					return (false);
				}
				else if (((i == 0 || i == 1) && this->areAlphas(this->_value[i]))
						|| (i == 3 && this->areDigitsPlus(this->_value[i])))
					break ;
			}
			// std::cout << "⚠️   	";
			// if (i == 0 || i == 1)
			// 	std::cout << GOLD << std::right << std::setw(15) << "⚠️ " << _field[i] << " doit contenir uniquement des lettres et '-'." << std::endl;
			// if (i == 3)
			// 	std::cout << GOLD << std::right << std::setw(15) << "⚠️ " << _field[i] << " doit contenir uniquement des chiffre et '+'." << std::endl;
			// i--;
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

bool	Contact::areDigitsPlus(std::string str) const
{
	for (int i = 0; str[i]; i++)
		if (!std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '+')
			return (false);
	return (true);
}