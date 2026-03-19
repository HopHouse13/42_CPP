/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:19:41 by pbret             #+#    #+#             */
/*   Updated: 2026/03/19 17:01:54 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeDeque.hpp"

SortDeque::SortDeque()
{
	//std::cout << "Default constructor called" << std::endl;
}

SortDeque::~SortDeque()
{
	//std::cout << "Destructor called" << std::endl;
}

SortDeque::SortDeque(SortDeque const & copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_main = copy._main;
}

SortDeque const &	SortDeque::operator=(SortDeque const & rhs)
{
	//std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		
	}
	return (*this);
}

///////////////////////////////////////////////////////////////////////////////

int	SortDeque::initMain(char **raw, int ac)
{
	for (int i = 0; i == ac - 1; i++)
		_main.push_back(std::atoi(raw[i]));
	return (SUCCESS);
}

int SortDeque::handleSortDeque(char **raw, int ac)
{
	initMain(raw, ac);

	std::cout <<"value ac: " << ac << std::endl;
	for (int i = 0; i == ac - 1; i++)
		std::cout << "value " << i << " : " << _main.at(i) << std::endl;

	return (SUCCESS);
}
