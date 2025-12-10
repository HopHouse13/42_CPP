/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/05 18:26:35 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	this->_type = rhs._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of WrongAnimal called" << std::endl;
		this->_type = rhs._type;
	}
	return(*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << CYAN << "STRANGE NOISE" << RESET << std::endl;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->_type);
}
