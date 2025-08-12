/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:44 by pbret             #+#    #+#             */
/*   Updated: 2025/08/12 20:23:53 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "constructor PhoneBook called" << std::endl;
}
	
PhoneBook::~PhoneBook(void)
{
	std::cout << "destructor PhoneBook called" << std::endl;
}

void	PhoneBook::program_rules()
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
