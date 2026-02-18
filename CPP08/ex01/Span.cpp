/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:31:34 by pbret             #+#    #+#             */
/*   Updated: 2026/02/18 18:49:14 by pbret            ###   ########.fr       */
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
}

Span::Span(Span const & copy) : _n(copy._n), _listNumbers(copy._listNumbers) // on utlise l'operateur de surcharge '=' de vector
{
	std::cout << "Copy constructor with a maximum elements called" << std::endl;
}

Span &	Span::operator=(Span const & rhs)
{
	if(this != &rhs)
	{
		this->_n = rhs._n;
		this->_listNumbers = rhs._listNumbers;
	}
	return (*this);
}

void	Span::addNumber(unsigned int v)
{
	if (this->_listNumbers.size() >= this->_n)
		throw SpanFull();
	this->_listNumbers.push_back(v);
}

int	Span::shortestSpan() const
{
	// verif si deux elem
	// creer un vector tmp
	// trier
	// trouver le 1er ecart
	// boucle pour check chaque ecart avec condition si la valeur trouvee et plus petit que l'ecart sotcker
	// renvoyer l'ecart
	if (this->_listNumbers.size() < 2)
		throw NeedTwoElem();

	std::vector<int>	tmp = this->_listNumbers;
	std::sort(tmp.begin(), tmp.end());

	int	span = tmp[1] - tmp[0];
	int	dif;
	for (std::vector<int>::const_iterator it = tmp.begin()++; it != tmp.end() - 1; it++)
	{
		//std::cout << "Comparing: " << *(it+1) << " - " << *it << std::endl;  
		dif = *(it+1) - *it;
		if (dif < span)
		{	
			span = dif;
			//std::cout << "value Span:" << span << std::endl;
		}
	}
	return (span);
}

const char *	Span::SpanFull::what() const throw()
{
	return ("Span's list is full");
}

const char *	Span::NeedTwoElem::what() const throw()
{
	return ("Need to have at least two elements");
}



std::vector<int> const &	Span::getList() const // pas dans le sujet
{
	return (this->_listNumbers);
}
