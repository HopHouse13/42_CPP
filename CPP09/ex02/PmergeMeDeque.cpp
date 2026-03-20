/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:19:41 by pbret             #+#    #+#             */
/*   Updated: 2026/03/20 20:12:21 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeDeque.hpp"

SortDeque::SortDeque()
{
	//std::cout << "Default constructor called" << std::endl;
}

SortDeque::SortDeque(char **raw, int nbElem, int depth) : _nbElem(nbElem), _depth(depth)
{
	//std::cout << "Default constructor called" << std::endl;
	for (int i = 1; i <= nbElem; i++)
		_main.push_back(std::atoi(raw[i]));
}

SortDeque::~SortDeque()
{
	//std::cout << "Destructor called" << std::endl;
}

SortDeque::SortDeque(SortDeque const & copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_main = copy._main;
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

void	SortDeque::handleOutsidePairs()
{
	size_t	sizePair = static_cast<size_t>(pow(2, _depth)); // taille de la paire par rapport a la profondeur
	size_t	nbOut = _nbElem % sizePair; // nb d'element endehors des paires

	while (nbOut) // _nbElem est une quantite != i est un index
	{
		_pend.push_front(_main.back());
		_main.pop_back();
		nbOut--;
	}
	std::cout << "value pend: " << _pend[0] << std::endl;
}


int SortDeque::handleSortDeque()
{
	
	std::cout << "value nbElem: " << _nbElem << std::endl;
	for (int i = 0; i < _nbElem; i++)
		std::cout << "value " << i << " : " << _main.at(i) << std::endl;

	handleOutsidePairs();
	
	return (SUCCESS);
}
