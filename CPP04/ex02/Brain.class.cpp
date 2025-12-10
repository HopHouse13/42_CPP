/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:32:30 by pbret             #+#    #+#             */
/*   Updated: 2025/12/09 17:16:16 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain()
{
	std::cout << "Default constructor of Brain called" << std::endl;
}
	
Brain::Brain(const Brain& rhs)
{
	std::cout << "Copy constructor of Brain called" << std::endl;
	for(int i = 0; i <= 99; i++)
	{
		this->_ideas[i] = rhs._ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of Brain called" << std::endl;
		for(int i = 0; i <= 99; i++)
		{
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

void	Brain::setIdea(const unsigned int idx, const std::string idea)
{
	if(idx >= 0 && idx <= 99)
		this->_ideas[idx] = idea;
	else
		std::cout << "Invalid index" << std::endl;
}
const std::string	Brain::getIdea(const unsigned int idx) const
{
	if(idx >= 0 && idx <= 99)
		return(this->_ideas[idx]);
	else
		return("Invalid index");
}
