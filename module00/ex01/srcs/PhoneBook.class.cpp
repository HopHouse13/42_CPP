/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:44 by pbret             #+#    #+#             */
/*   Updated: 2025/08/19 01:55:28 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _nbC(0)
{
	// std::cout << "constructor PhoneBook called" << std::endl;
}
	
PhoneBook::~PhoneBook(void)
{
	// std::cout << "destructor PhoneBook called" << std::endl;
}

void	PhoneBook::programRules(void) const
{	
	std::cout	<< GOLD << std::endl
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl
				<< "|" << BOLD << std::left << std::setw(13) << "" << "FUNPHONEBOOK MENU" << RESET << GOLD << std::right << std::setw(14) << "|" << std::endl
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl
				<< "|" << std::right << std::setw(12) << "ADD" << " | " << "Add a new contact" << std::right << std::setw(12) << "|" << std::endl
				<< "|" << std::right << std::setw(12) << "SEARCH" << " | " << "Display a saved contact" << std::right << std::setw(6) << "|" << std::endl
				<< "|" << std::right << std::setw(12) << "EXIT" << " | " << "Close the FunPhoneBook" << std::right << std::setw(7) << "|" << std::endl
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl << std::endl
				<< RESET;
}

bool	PhoneBook::addCmd(void)
{
	std::string confirmation = "";
	
	if (this->_nbC >= 8)
	{
		std::cout	<< GOLD << "Warning: the phonebook is full." << std::endl
					<< "The contact [" << this->_contact[this->_nbC % 8].getValue(0) << "] will be replaced." << std::endl;
		while (true)
		{
			std::cout	<< "Confirm replace [y/n]" << std::endl
						<< WHITE "> ";
			if (!std::getline(std::cin, confirmation))
			{
				std::cout << std::endl;
				return (false);
			}
			else if (confirmation == "n" || confirmation == "N")
			{
				std::cout << GOLD << "No worries! The contact was not added." << std::endl;
				return (true);
			}
			else if (confirmation == "y" || confirmation == "Y")
			{
				if (!this->_contact[this->_nbC % 8].addContact())
					return (false);
				this->_nbC++;
				return (true);
			}
			else
				std::cout << GOLD << "Invalid input. Please type 'y' or 'n'." << std::endl;
		}
	}
	else
	{
		std::cout << GOLD << "Let's start adding a new contact!" << std::endl;
		if (!this->_contact[_nbC].addContact())
			return (false);
		this->_nbC++;
		return (true);
	}
}

// "static_cast<unsigned char>" est la pour s'assurer que isdigit prendra bien une valeur ASCII positive.
bool	PhoneBook::searchCmd(void) const
{
	std::string		idx = "";
	
	if (this->_nbC == 0)
		std::cout << GOLD << "FunPhoneBook is empty currently." << std::endl;
	else if (this->_nbC == 1)
	{
		std::cout 	<< GOLD << "Here's just one contact in the FunPhoneBook :" << std::endl;
		PhoneBook::displayContact(0);
	}
	else if (this->_nbC > 1)
	{
		PhoneBook::displayRepertory();
		std::cout << GOLD << "Which contact do you want to check out?" << std::endl;
		while (true)
		{
			std::cout 	<< "Enter the index of the contact :" << std::endl
						<< WHITE "> ";
			if (!std::getline(std::cin, idx))
			{
				std::cout << std::endl;
				return (false);
			}
			else if (idx.length() == 1
					&& std::isdigit(static_cast<unsigned char>(idx[0]))
					&& (static_cast<int>(idx[0]) - '0') < this->_nbC)
				{
					PhoneBook::displayContact(static_cast<int>(idx[0]) - '0');
					break ;
				}
				
			else
				std::cout 	<< GOLD << "Oops! That’s not a valid index." << std::endl
							<< "Please enter a valid index." << std::endl;
		}
	}	
	return (true);
}

void	PhoneBook::displayRepertory(void) const
{
	std::cout	<< GOLD << std::endl
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl
				<< "|" << std::right << std::setw(10) << "Index" << "|";
	for (int i = 0; i < 3; i++)
		std::cout << std::right << std::setw(10) << this->_contact[i].getField(i) << "|";
	for(int i = 0; i < 8 && i < this->_nbC; i++)
	{
		std::cout << std::endl;
		if (i == 0)
			std::cout << " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl;
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		for(int y = 0; y < 3; y++)	
			std::cout << std::right << std::setw(10) << _contact[i].getValue(y) << "|";
	}
	std::cout << std::endl << " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl << std::endl;
}

void	PhoneBook::displayContact(int idx) const
{
	std::cout	<< std::endl;
	for(int i = 0; i < 5; i++)
		std::cout << GOLD << std::right << std::setw(15) << this->_contact[idx].getField(i) << "\t" << RESET << this->_contact[idx].getValue(i) << std::endl;
}

bool	PhoneBook::exitCmd(void) const
{
	std::string confirmation = "";
	
	std::cout << GOLD << "Close FunPhoneBook and delete all contacts?" << std::endl;
	while(true)
	{
		std::cout	<< "Confirm exit [y/n]" << std::endl
					<< WHITE "> ";
		if (!std::getline(std::cin, confirmation) || (confirmation == "y" || confirmation == "Y"))
			return (false);
		else if (confirmation == "n" || confirmation == "N")
			return (true);
		else
			std::cout << GOLD << "Invalid input. Please type 'y' or 'n'." << std::endl;
	}
}

void	PhoneBook::exitMess(void) const
{
	std::cout	<< std::endl << GOLD << "Thank you for using FunPhoneBook!" << std::endl
				<< "See you soon 😉" << RESET << std::endl;
}


/* todo
- parsing inputs ADD
- gestion +10 caracteres*/