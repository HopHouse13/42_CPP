/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:31:34 by pbret             #+#    #+#             */
/*   Updated: 2026/02/21 14:37:23 by pbret            ###   ########.fr       */
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
	std::cout << "Assignment operator overload called" << std::endl;
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
	if (this->_listNumbers.size() < 2)
		throw NeedTwoElem();

	std::vector<int>	tmp = this->_listNumbers;
	
	std::sort(tmp.begin(), tmp.end());

	int	span = tmp.at(1) - tmp.at(0);
	for (unsigned int i = 0; i < tmp.size() -1; i++)
	{
		int dif = tmp.at(i+1) - tmp.at(i);
		if (dif < span)
			span = dif;
	}
	return (span);
}

int	Span::longestSpan() const
{
	if (this->_listNumbers.size() < 2)
		throw NeedTwoElem();

	std::vector<int>	tmp = this->_listNumbers;

	std::sort(tmp.begin(), tmp.end());

	int	span = tmp.at(1) - tmp.at(0);
	for (unsigned int i = 0; i < tmp.size() -1; i++)
	{
		int dif = tmp.at(i+1) - tmp.at(i);
		if (dif > span)
			span = dif;
	}
	return (span);
}

void	Span::generateList(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end)
{
	//std::cout << "value add new elem: " << (end - start) << std::endl;
	//std::cout << "value size old elem: " << this->_listNumbers.size() << std::endl;
	//std::cout << "value total elem: " << ((end - start) + this->_listNumbers.size()) << std::endl;
	if (((end - start) + this->_listNumbers.size()) > this->_n) // dans vector tu peux faire la difference entre deux iterateurs qui donnera le nombre d'elem entre les deux.
		throw SpanFull();
	this->_listNumbers.insert(this->_listNumbers.end(), start, end);
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
	return (this->_listNumbers); // non protege car un contener meme vide est valide par contre si tu essaies d'acceder a une value -> seg fault
}
