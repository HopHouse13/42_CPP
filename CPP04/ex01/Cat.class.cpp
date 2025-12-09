/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/09 17:17:01 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Default constructor of Cat called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	this->_brain = new Brain(*rhs._brain); // copie profonde
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of Cat called" << std::endl;
		Animal::operator=(rhs);
		delete _brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return(*this);
}

Cat::~Cat(void)
{
	delete(this->_brain);
	std::cout << "Destructor of Cat called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN << "MIAOUU" << RESET << std::endl;
}

void	Cat::setIdea(const unsigned int idx, const std::string idea)
{
	this->_brain->setIdea(idx, idea);
}
const std::string	Cat::getIdea(const unsigned int idx) const
{
	return(this->_brain->getIdea(idx));
}

const Brain*		Cat::getAddressBrain(void) const
{
	return (this->_brain);
}
