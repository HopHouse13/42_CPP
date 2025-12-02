/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:54:22 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 13:59:29 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unknown"), _hp(10), _ep(10), _attackDmg(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _attackDmg(0)
{
	std::cout << "Constructor of " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << "Copy constructor of " << this->_name << " called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_attackDmg = rhs._attackDmg;
	}
	std::cout << "Assignement operator overload of " << this->_name << " called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor of " << this->_name << " called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp > 0)
	{
		if (this->_ep > 0)
		{
			this->_ep--;
			std::cout << CYAN << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " health points." << RESET << std::endl;
		}
		else
			std::cout << YELLOW << this->_name << " has no energy points left to attack." << RESET << std::endl;
	}
	else
		std::cout << YELLOW << this->_name << " is KO and cannot attack." << RESET << std::endl;
	std::cout << *this << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp > 0)
	{
		if (this->_ep > 0)
		{
			this->_ep--;
			this->_hp += amount;
			std::cout << GREEN << this->_name << " repairs itself for " << amount << " health points." << RESET << std::endl;
		}
		else
			std::cout << YELLOW << this->_name << " has no energy points left and cannot repair itself." << RESET << std::endl;
	}
	else
		std::cout << YELLOW << this->_name << " is KO and cannot repair itself." << RESET << std::endl;
	std::cout << *this << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		if (amount >= this->_hp)
		{
			this->_hp = 0;
			std::cout << RED << "ClapTrap " << this->_name << " takes " << amount << " points of damage and is destroyed..." << RESET << std::endl;
		}
		else
		{
			this->_hp -= amount;
			std::cout << RED << "ClapTrap " << this->_name << " takes " << amount << " points of damage." << RESET << std::endl;
		}
	}
	else
		std::cout << YELLOW << "The inert pile of scrap metal who is ClapTrap " << this->_name << " cannot be attacked anymore." << RESET << std::endl;
	std::cout << *this << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return(this->_name);
}

unsigned int	ClapTrap::getHP(void) const
{
	return(this->_hp);
}

unsigned int	ClapTrap::getEP(void) const
{
	return(this->_ep);
}

unsigned int	ClapTrap::getAttackDmg(void) const
{
	return(this->_attackDmg);
}

std::ostream&	operator<<(std::ostream& os, const ClapTrap& rhs)
{
	os	<< "Name: " << rhs.getName()
		<< " | HP: " << rhs.getHP()
		<< " | EP: " << rhs.getEP()
		<< " | AttackDmg: " << rhs.getAttackDmg();
	return (os);
}