/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/05 17:49:50 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void) : Animal(), _type("Cat")
{
	std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of Cat called" << std::endl;
		Animal::operator=(rhs);
	}
	return(*this);
}

Cat::~Cat(void)
{
	std::cout << "Destructor of Cat called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN << "MIAOUU" << RESET << std::endl;
}
