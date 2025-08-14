/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:44 by pbret             #+#    #+#             */
/*   Updated: 2025/08/14 18:27:21 by pbret            ###   ########.fr       */
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

void	PhoneBook::programRules(void)
{	
	std::cout	<< "\033[93m"
				<< std::setfill('-') << std::setw(34) << "" << std::setfill(' ') << std::endl
				<< "|" << std::left << std::setw(6) << "" << "FUNPHONEBOOK MENU" << std::right << std::setw(10) << "|" << std::endl
				<< std::setfill('-') << std::setw(34) << "" << std::setfill(' ') << std::endl
				<< "|" << std::left << std::setw(10) << "\"ADD\"" << "Add a new contact" << std::right << std::setw(6) << "|" << std::endl
				<< "|" << std::left << std::setw(10) << "\"SEARCH\"" << "Display saved contacts" << "|" << std::endl
				<< "|" << std::left << std::setw(10) << "\"EXIT\"" << "Close the FunPhoneBook" << "|" << std::endl
				<< std::setfill('-') << std::setw(34) << "" << std::setfill(' ') << std::endl
				<< "\033[0m";
}

void	PhoneBook::addCmd(void)
{
/* 	if (8 contact) -> supp le older
	{

	}
	else */
	{
		std::cout << "Demmarons l'ajout d'un nouveau contacte." << std::endl;
		this->_repertory[_nbC].addContact();
		this->_nbC++;
	}
}

bool	PhoneBook::exitCmd(void)
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
