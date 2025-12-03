/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:57:39 by pbret             #+#    #+#             */
/*   Updated: 2025/12/03 15:03:19 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name			= "unknown";
	this->_hp			= 100;
	this->_ep			= 50;
	this->_attackDmg	= 20;
	std::cout << "Default constructor of ScavTrap " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->_hp			= 100;
	this->_ep			= 50;
	this->_attackDmg	= 20;
	std::cout << "Constructor of ScavTrap " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "Copy constructor of ScavTrap " << this->_name << " called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		std::cout << "Assignement operator overload of ScavTrap " << this->_name << " called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << this->_name << " called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hp > 0)
	{
		if (this->_ep > 0)
		{
			this->_ep--;
			std::cout << CYAN << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " health points." << RESET << std::endl;
		}
		else
			std::cout << YELLOW << "ScavTrap " << this->_name << " has no energy points left to attack." << RESET << std::endl;
	}
	else
		std::cout << YELLOW << "ScavTrap " << this->_name << " is KO and cannot attack." << RESET << std::endl;
	std::cout << *this << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << MAGENTA << "ScavTrap " << this->_name << " goes into Gate keeper mode." << RESET << std::endl;
}

