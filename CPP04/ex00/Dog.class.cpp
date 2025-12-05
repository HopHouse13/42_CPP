/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/05 18:14:13 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog(void) : Animal(), _type("Dog")
{
	std::cout << "Default constructor of Dog called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of Dog called" << std::endl;
		Animal::operator=(rhs);
	}
	return(*this);
}

Dog::~Dog(void)
{
	std::cout << "Destructor of Dog called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << RED << "WOUAFF" << RESET << std::endl;
}
