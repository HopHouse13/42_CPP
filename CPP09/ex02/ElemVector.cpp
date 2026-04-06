/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ElemV.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:49:34 by pbret             #+#    #+#             */
/*   Updated: 2026/03/29 16:00:25 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVector.hpp"

ElemV::ElemV() : _IdL(true), _idV(0)
{
	//std::cout << "Default constructor ElemV called" << std::endl;
}

ElemV::~ElemV()
{
	//std::cout << "Destructor ElemV called" << std::endl;
}

ElemV::ElemV(ElemV const & copy) : _sequence(copy._sequence), _IdL(copy._IdL) , _idV(copy._idV)
{
	//std::cout << "Copy constructor ElemV called" << std::endl;
}

ElemV const &	ElemV::operator=(ElemV const & rhs)
{
	//std::cout << "Assignment operator overload ElemV called" << std::endl;
	if (this != &rhs)
	{
		_sequence = rhs._sequence;
		_IdL = rhs._IdL;
		_idV = rhs._idV;
	}
	return (*this);
}

std::vector<int> const &	ElemV::getSequence() const
{
	return (_sequence);
}

void	ElemV::setSequence(int value)
{
	_sequence.push_back(value);
}

char const &	ElemV::getIdL() const
{
	return (_IdL);
}

void	ElemV::setIdL(char IdL)
{
	_IdL = IdL;
}

size_t const &	ElemV::getIdV() const
{
	return (_idV);
}

void	ElemV::setIdV(size_t idV)
{
	_idV = idV;
}

int	ElemV::getLastValue() const
{
	return (_sequence.back());
}
