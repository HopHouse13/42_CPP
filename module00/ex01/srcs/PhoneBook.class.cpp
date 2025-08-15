/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:44 by pbret             #+#    #+#             */
/*   Updated: 2025/08/15 14:03:27 by pbret            ###   ########.fr       */
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
	std::cout	<< "\033[93m"
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl
				<< "|" << std::left << std::setw(13) << "" << "FUNPHONEBOOK MENU" << std::right << std::setw(14) << "|" << std::endl
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl
				<< "|" << std::left << std::setw(13) << "\"ADD\"" << "Add a new contact" << std::right << std::setw(14) << "|" << std::endl
				<< "|" << std::left << std::setw(13) << "\"SEARCH\"" << "Display saved contacts" << std::right << std::setw(9) << "|" << std::endl
				<< "|" << std::left << std::setw(13) << "\"EXIT\"" << "Close the FunPhoneBook" << std::right << std::setw(9) << "|" << std::endl
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl
				<< "\033[0m";
}

void	PhoneBook::addCmd(void)
{
/* 	if (8 contact) -> remplace le older
	{

	}
	else */
	{
		std::cout << "Demmarons l'ajout d'un nouveau contacte." << std::endl;
		this->_contact[_nbC].addContact();
		this->_nbC++;
	}
}

void	PhoneBook::displayRepertory(void) const
{
	std::cout	<< "\033[93m" 
				<< " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl
				<< "|" << std::right << std::setw(10) << "Index" << "|";
	for (int i = 0; i < 3; i++)
		std::cout << std::right << std::setw(10) << _contact[i].getField(i) << "|";
	for(int i = 0; i < 8 && i < this->_nbC; i++)
	{
		std::cout << std::endl;
		if (i == 0)
			std::cout << " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl;
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		for(int y = 0; y < 3; y++)	
			std::cout << std::right << std::setw(10) << _contact[i].getValue(y) << "|";
	}
	std::cout << std::endl << " " << std::setfill('-') << std::setw(43) << "" << std::setfill(' ') << std::endl;
}

void	PhoneBook::searchCmd(void) const
{
	PhoneBook::displayRepertory();
}

bool	PhoneBook::exitCmd(void) const
{
	std::string confirmation;
	
	std::cout << GOLD << "Close FunPhoneBook and delete all contacts?" << std::endl;
	while(true)
	{
		std::cout	<< "Confirm exit [y/n]" << std::endl
					<< WHITE "> ";
		if (!std::getline(std::cin, confirmation) || (confirmation == "y" || confirmation == "Y"))
			return (true);
		else if (confirmation == "n" || confirmation == "N")
			return (false);
		else
			std::cout << GOLD << "Invalid input. Please type 'y' or 'n'." << std::endl;
	}
}

void	PhoneBook::exitMess(void)
{
	std::cout	<< GOLD << "Thank you for using FunPhoneBook!" << std::endl
				<< "See you soon 😉" << RESET << std::endl;
}
