/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:07:03 by pbret             #+#    #+#             */
/*   Updated: 2025/12/03 15:29:08 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name			= "unknown";
	this->_hp			= 100;
	this->_ep			= 100;
	this->_attackDmg	= 30;
	std::cout << "Default constructor of FragTrap " << _name << " called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hp			= 100;
	this->_ep			= 100;
	this->_attackDmg	= 30;
	std::cout << "Constructor of FragTrap " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "Copy constructor of FragTrap " << this->_name << " called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		std::cout << "Assignement operator overload of FragTrap " << this->_name << " called" << std::endl;
	}
	else
		std::cout << "The two instances are the same." << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor of FragTrap " << this->_name << " called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << MAGENTA << "FragTrap " << this->_name << " attempts a high five with the entity opposite him." << RESET << std::endl;
}
