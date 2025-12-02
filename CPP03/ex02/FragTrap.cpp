/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:07:03 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 19:12:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void) : ClapTrap()
{
	this->_name = "unknown";
	this->_hp = 100;
	this->_ep = 100;
	this->_attackDmg = 30;
	std::cout << "Default constructor of FlagTrap " << _name << " called" << std::endl;
}

FlagTrap::FlagTrap(const std::string& name) : ClapTrap(name)
{
	this->_name			= "unknown";
	this->_hp			= 100;
	this->_ep			= 100;
	this->_attackDmg	= 30;
	std::cout << "Default constructor of FlagTrap " << this->_name << " called" << std::endl;
}