/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:54:22 by pbret             #+#    #+#             */
/*   Updated: 2025/12/01 19:04:35 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("Unknown"), _HP(10), _EP(10), _AttackDmg(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HP(10), _EP(10), _AttackDmg(0)
{
	std::cout << "Constructor of " << _Name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << "Copy constructor of " << this->_Name << " called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
		this->_HP = rhs._HP;
		this->_EP = rhs._EP;
		this->_AttackDmg = rhs._AttackDmg;
	}
	std::cout << "Assignement operator overload of " << this->_Name << " called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor of " << this->_Name << " called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_HP > 0)
	{
		if (this->_EP > 0)
		{
			this->_EP--;
			std::cout << CYAN << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDmg << " health points." << RESET << std::endl;
		}
		else
			std::cout << YELLOW << this->_Name << " has no energy points left to attack." << RESET << std::endl;
	}
	else
		std::cout << YELLOW << this->_Name << " is KO and cannot attack." << RESET << std::endl;
	std::cout << *this << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HP > 0)
	{
		if (this->_EP > 0)
		{
			this->_EP--;
			this->_HP += amount;
			std::cout << GREEN << this->_Name << " repairs itself for " << amount << " health points." << RESET << std::endl;
		}
		else
			std::cout << YELLOW << this->_Name << " has no energy points left and cannot repair itself." << RESET << std::endl;
	}
	else
		std::cout << YELLOW << this->_Name << " is KO and cannot repair itself." << RESET << std::endl;
	std::cout << *this << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HP > 0)
	{
		if (amount >= this->_HP)
		{
			this->_HP = 0;
			std::cout << RED << "ClapTrap " << this->_Name << " takes " << amount << " points of damage and is destroyed..." << RESET << std::endl;
		}
		else
		{
			this->_HP -= amount;
			std::cout << RED << "ClapTrap " << this->_Name << " takes " << amount << " points of damage." << RESET << std::endl;
		}
	}
	else
		std::cout << YELLOW << "The inert pile of scrap metal at ClapTrap " << this->_Name << " cannot be attacked anymore." << RESET << std::endl;
	std::cout << *this << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return(this->_Name);
}

unsigned int	ClapTrap::getHP(void) const
{
	return(this->_HP);
}

unsigned int	ClapTrap::getEP(void) const
{
	return(this->_EP);
}

unsigned int	ClapTrap::getAttackDmg(void) const
{
	return(this->_AttackDmg);
}

std::ostream&	operator<<(std::ostream& os, const ClapTrap& rhs)
{
	os	<< "Name: " << rhs.getName()
		<< " | HP: " << rhs.getHP()
		<< " | EP: " << rhs.getEP()
		<< " | AttackDmg: " << rhs.getAttackDmg();
	return (os);
}