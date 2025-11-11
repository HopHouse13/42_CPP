/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:23 by pbret             #+#    #+#             */
/*   Updated: 2025/11/11 19:00:56 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// constructeur
Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

Zombie*	newZombie(std::string name)
{
	Zombie	*z;

	z = new Zombie(name);
	return (z);
}

void	randomChump(std::string name)
{
	
}

//void randomChump(std::string name)
//{
//	Zombie z3(name);
//	z3.announce();
//}