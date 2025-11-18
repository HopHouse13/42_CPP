/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:23 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 16:47:35 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
// Constructeur
Zombie::Zombie(std::string name) : _name(name)
{
	return ;
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
