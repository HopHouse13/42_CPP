/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:35 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 16:30:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.class.hpp"

HumanB::HumanB(std::string name) : _name(name) , _weapon(nullptr)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack()
{
	if (_weapon != nullptr)
		std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with his bare hands.. good luck." << std::endl; //mains nues
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
