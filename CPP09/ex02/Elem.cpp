/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:49:34 by pbret             #+#    #+#             */
/*   Updated: 2026/03/25 12:37:03 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

SortDeque::Elem::Elem() : _idG(true), _idV(0)
{
	//std::cout << "Default constructor Elem called" << std::endl;
}

SortDeque::Elem::~Elem()
{
	//std::cout << "Destructor Elem called" << std::endl;
}

SortDeque::Elem::Elem(Elem const & copy) : _sequence(copy._sequence), _idG(copy._idG) , _idV(copy._idV)
{
	//std::cout << "Copy constructor Elem called" << std::endl;
}

SortDeque::Elem const &	SortDeque::Elem::operator=(Elem const & rhs)
{
	//std::cout << "Assignment operator overload Elem called" << std::endl;
	if (this != &rhs)
	{
		_sequence = rhs._sequence;
		_idG = rhs._idG;
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

bool const &	SortDeque::Elem::getIdG() const
{
	return (_idG);
}

void	SortDeque::Elem::setIdG(bool idG)
{
	_idG = idG;
}

size_t const &	SortDeque::Elem::getIdV() const
{
	return (_idV);
}

void	SortDeque::Elem::setIdV(size_t idV)
{
	_idV = idV;
}
