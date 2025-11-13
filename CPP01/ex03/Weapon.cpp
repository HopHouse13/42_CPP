/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:35 by pbret             #+#    #+#             */
/*   Updated: 2025/11/13 19:42:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

//Weapon::Weapon(std::string type) // y a t il une dif? ^
//{
//	this->setType(type); // why this-> on parle du type de l'instance?
//	return ;
//}

Weapon::~Weapon(void)
{
	return ;
}

const std::string &Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
