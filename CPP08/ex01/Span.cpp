/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:31:34 by pbret             #+#    #+#             */
/*   Updated: 2026/02/17 19:55:28 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

Span::Span() : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Constructor with a maximum elements called" << std::endl;
	this->_listNumbers.reserve(this->_n); // comme un new
}

Span::Span(Span const & copy) : _n(copy._n), _listNumbers(copy._listNumbers)
{
	std::cout << "Copy constructor with a maximum elements called" << std::endl;
	//this->_listNumbers.reserve(this->_n); 
	//for (std::vector<int>::iterator it = copy._listNumbers.begin(); )
}

Span &	Span::operator=(Span const & rhs)
{
	if(this != &rhs) // rappel: &rhs est l'adresse de la ref. rhs   Right paul?
	{
		this->_n = rhs._n;
		//this->_listNumbers = rhs._listNumbers;
		this->_listNumbers.assign(rhs._listNumbers.begin(), rhs._listNumbers.end());
	}
	return (*this);
}

void	Span::addNumber(unsigned int v)
{
	this->_listNumbers.push_back(v);
}

std::vector<int> const &	Span::getList() const
{
	return (this->_listNumbers);
}
