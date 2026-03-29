/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:49:34 by pbret             #+#    #+#             */
/*   Updated: 2026/03/29 16:00:25 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

Elem::Elem() : _IdL(true), _idV(0)
{
	//std::cout << "Default constructor Elem called" << std::endl;
}

Elem::~Elem()
{
	//std::cout << "Destructor Elem called" << std::endl;
}

Elem::Elem(Elem const & copy) : _sequence(copy._sequence), _IdL(copy._IdL) , _idV(copy._idV)
{
	//std::cout << "Copy constructor Elem called" << std::endl;
}

Elem const &	Elem::operator=(Elem const & rhs)
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

std::deque<int> const &	Elem::getSequence() const
{
	return (_sequence);
}

void	Elem::setSequence(int value)
{
	_sequence.push_back(value);
}

char const &	Elem::getIdL() const
{
	return (_IdL);
}

void	Elem::setIdL(char IdL)
{
	_IdL = IdL;
}

size_t const &	Elem::getIdV() const
{
	return (_idV);
}

void	Elem::setIdV(size_t idV)
{
	_idV = idV;
}

int	Elem::getLastValue() const
{
	return (_sequence.back());
}
