/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:43:48 by pbret             #+#    #+#             */
/*   Updated: 2025/12/08 19:58:23 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "cat";
	this->_brain = new Brain;
	std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	this->_brain = new Brain(*rhs._brain); // copie profonde
	std::cout << "Copy constructor of Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		this->_brain = new Brain(*rhs._brain);
		Animal::operator=(rhs); // meme questionnement que cat
		std::cout << "Assignement operator overload of Cat called" << std::endl;
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

Brain&		Cat::getBrain(void) const
{
	return (*this->_brain);
} 
