/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:35 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 16:42:00 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string &Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)	
{
	this->_type = type;
}
