/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/08 18:49:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain; // constructeur par defaut + allocation de memoire
	std::cout << "Default constructor of Dog called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	this->_brain = new Brain(*rhs._brain); // copie profonde
	std::cout << "Copy constructor of Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		delete(this->_brain);
		this->_brain = new Brain(*rhs._brain); // copie profonde
		Animal::operator=(rhs); // si on l'enleve, _type ne sera pas initialise.
		std::cout << "Assignement operator overload of Dog called" << std::endl;
	}
	return(*this);
}

Dog::~Dog(void)
{
	delete(this->_brain);
	std::cout << "Destructor of Dog called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << RED << "WOUAFF" << RESET << std::endl;
}
