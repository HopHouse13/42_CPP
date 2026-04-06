/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ElemD.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:49:34 by pbret             #+#    #+#             */
/*   Updated: 2026/03/29 16:00:25 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

ElemD::ElemD() : _IdL(true), _idV(0)
{
	//std::cout << "Default constructor ElemD called" << std::endl;
}

ElemD::~ElemD()
{
	//std::cout << "Destructor ElemD called" << std::endl;
}

ElemD::ElemD(ElemD const & copy) : _sequence(copy._sequence), _IdL(copy._IdL) , _idV(copy._idV)
{
	//std::cout << "Copy constructor ElemD called" << std::endl;
}

ElemD const &	ElemD::operator=(ElemD const & rhs)
{
	//std::cout << "Assignment operator overload ElemD called" << std::endl;
	if (this != &rhs)
	{
		_sequence = rhs._sequence;
		_IdL = rhs._IdL;
		_idV = rhs._idV;
	}
	return (*this);
}

std::deque<int> const &	ElemD::getSequence() const
{
	return (_sequence);
}

void	ElemD::setSequence(int value)
{
	_sequence.push_back(value);
}

char const &	ElemD::getIdL() const
{
	return (_IdL);
}

void	ElemD::setIdL(char IdL)
{
	_IdL = IdL;
}

size_t const &	ElemD::getIdV() const
{
	return (_idV);
}

void	ElemD::setIdV(size_t idV)
{
	_idV = idV;
}

int	ElemD::getLastValue() const
{
	return (_sequence.back());
}
