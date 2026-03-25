/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:49:34 by pbret             #+#    #+#             */
/*   Updated: 2026/03/25 14:09:19 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

SortDeque::Elem::Elem() : _IdL(true), _idV(0)
{
	//std::cout << "Default constructor Elem called" << std::endl;
}

SortDeque::Elem::~Elem()
{
	//std::cout << "Destructor Elem called" << std::endl;
}

SortDeque::Elem::Elem(Elem const & copy) : _sequence(copy._sequence), _IdL(copy._IdL) , _idV(copy._idV)
{
	//std::cout << "Copy constructor Elem called" << std::endl;
}

SortDeque::Elem const &	SortDeque::Elem::operator=(Elem const & rhs)
{
	//std::cout << "Assignment operator overload Elem called" << std::endl;
	if (this != &rhs)
	{
		_sequence = rhs._sequence;
		_IdL = rhs._IdL;
		_idV = rhs._idV;
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
	return (_IdL);
}

void	SortDeque::Elem::setIdL(char IdL)
{
	_IdL = IdL;
}

size_t const &	SortDeque::Elem::getIdV() const
{
	return (_idV);
}

void	SortDeque::Elem::setIdV(size_t idV)
{
	_idV = idV;
}
