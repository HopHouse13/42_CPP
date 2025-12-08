/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:32:30 by pbret             #+#    #+#             */
/*   Updated: 2025/12/08 19:44:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain()
{
	std::cout << "Default constructor of Brain called" << std::endl;
}
	
Brain::Brain(const Brain& rhs)
{
	// this->_ideas = rhs._ideas; ca fonctionne po
	for(int i = 0; i <= 99; i++)
	{
		this->_ideas[i] = rhs._ideas[i];
	}
	std::cout << "Copy constructor of Brain called" << std::endl;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for(int i = 0; i <= 99; i++)
		{
			this->_ideas[i] = rhs._ideas[i];
		}
		std::cout << "Assignement operator overload of Brain called" << std::endl;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

void	Brain::setIdea(const unsigned int idx, const std::string idea)
{
	this->_ideas[idx] = idea;
}
const std::string	Brain::getIdea(const unsigned int idx) const
{
	return(this->_ideas[idx]);
}
