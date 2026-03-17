/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:19:41 by pbret             #+#    #+#             */
/*   Updated: 2026/03/17 19:00:20 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

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
	this->_list = copy._list;
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

int	SortDeque::initList(char **raw, int ac)
{
	for (int i = 0; i == ac - 1; i++)
		_list.push_back(std::atoi(raw[i]));
	return (SUCCESS);
}

int SortDeque::handleSort(char **raw, int ac)
{
	initList(raw, ac);

	std::cout <<"value ac: " << ac << std::endl;
	for (int i = 0; i == ac - 1; i++)
		std::cout << "value " << i << " : " << _list.at(i) << std::endl;

	return (SUCCESS);
}



// roadmap:

// - parsing -> only digits positifs
// - init. _main
// - cb de niveau de recurtion : compter cb de valeurs et savoir
// - 