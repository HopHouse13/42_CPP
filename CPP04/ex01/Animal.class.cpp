/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/05 18:23:33 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Default constructor of Animal called" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	std::cout << "Copy constructor of Animal called" << std::endl;
	this->_type = rhs._type;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of Animal called" << std::endl;
		this->_type = rhs._type;
	}
	return(*this);
}

Animal::~Animal(void)
{
	std::cout << "Destructor of Animal called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << CYAN << "STRANGE NOISE" << RESET << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (this->_type);
}
