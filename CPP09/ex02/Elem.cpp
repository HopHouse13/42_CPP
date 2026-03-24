/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:49:34 by pbret             #+#    #+#             */
/*   Updated: 2026/03/24 20:04:00 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

SortDeque::Elem::Elem() : _idV(0), _idL('\0')
{
	//std::cout << "Default constructor Elem called" << std::endl;
}

SortDeque::Elem::~Elem()
{
	//std::cout << "Destructor Elem called" << std::endl;
}

SortDeque::Elem::Elem(Elem const & copy) : _sequence(copy._sequence), _idV(copy._idV), _idL(copy._idL)
{
	//std::cout << "Copy constructor Elem called" << std::endl;
}

SortDeque::Elem const &	SortDeque::Elem::operator=(Elem const & rhs)
{
	//std::cout << "Assignment operator overload Elem called" << std::endl;
	if (this != &rhs)
	{
		_sequence = rhs._sequence;
		_idV = rhs._idV;
		_idL = rhs._idL;
	}
	return (*this);
}

std::deque<int> const &	SortDeque::Elem::getSequence() const
{
	return (_sequence);
}

void	SortDeque::Elem::setSequence(int value)
{
	_sequence.push_back(value);
}

char const &	SortDeque::Elem::getIdL() const
{
	return (_idL);
}

size_t const &	SortDeque::Elem::getIdV() const
{
	return (_idV);
}