/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/09 17:17:34 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain; // constructeur par defaut + allocation de memoire
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	this->_brain = new Brain(*rhs._brain); // copie profonde
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of Dog called" << std::endl;
		Animal::operator=(rhs); // si on l'enleve, _type ne sera pas initialise.
		delete(this->_brain);
		this->_brain = new Brain(*rhs._brain); // copie profonde
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

void	Dog::setIdea(const unsigned int idx, const std::string idea)
{
	this->_brain->setIdea(idx, idea);
}
const std::string	Dog::getIdea(const unsigned int idx) const
{
	return(this->_brain->getIdea(idx));
}

const Brain*		Dog::getAddressBrain(void) const
{
	return (this->_brain);
}