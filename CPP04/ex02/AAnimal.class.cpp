/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/10 12:26:38 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "Default constructor of Animal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& rhs)
{
	std::cout << "Copy constructor of Animal called" << std::endl;
	this->_type = rhs._type;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of Animal called" << std::endl;
		this->_type = rhs._type;
	}
	return(*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor of Animal called" << std::endl;
}

const std::string&	AAnimal::getType(void) const
{
	return (this->_type);
}
