/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:23 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 13:56:59 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructeur
Zombie::Zombie()
{
}
Zombie::Zombie(std::string name) : _name(name)
{
}

// Destructeur
Zombie::~Zombie()
{
	std::cout << "Démantèlement de l'individu nommée " << _name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
