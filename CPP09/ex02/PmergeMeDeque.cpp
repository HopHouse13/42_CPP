/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:19:41 by pbret             #+#    #+#             */
/*   Updated: 2026/03/22 18:16:03 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeDeque.hpp"

SortDeque::SortDeque()
{
	//std::cout << "Default constructor called" << std::endl;
}

SortDeque::SortDeque(char **raw, int nbElem, int depthMax) : _nbElem(nbElem), _depthMax(depthMax), _depth(1)
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

std::ostream& operator<<(std::ostream& os, std::deque<int> const& list) // operateur de surcharge sur << et avec le flux std::cout
{
	for (size_t i = 0; i < list.size(); i++)
		os << (i ? " " : "") << list.at(i);
	return (os);
}

void	SortDeque::swap(size_t sizePack, size_t position)
{
	int		tmp;
	size_t	nbSwap = sizePack; // nb d'elements a swap

	while (nbSwap)
	{
		tmp = _main.at(position);
		_main.at(position) = _main.at(position + sizePack);
		_main.at(position + sizePack) = tmp;
		position--;
		nbSwap--;
	}
}

void	SortDeque::handleSwap()
{
	size_t	sizePack = pow(2,_depth - 1); // depth commence a 1, la taille de 1er paquet doit etre de 1. 2^1 = 2 et on veut 1 donc 2^0 = 1
 
	for (size_t i = sizePack - 1; i + sizePack < _main.size(); i += sizePack * 2) // -1 a sizePack car i est un index donc au lvl 1 on veut comparer idx 0 avec idx 1 puis au lvl 2 on compare idx1 avec idx 3 etc
	{
		if (_main[i] > _main[i + sizePack])
			swap(sizePack, i);
	}
}

void	SortDeque::handleOutsidePairs()
{
	size_t	sizePair = static_cast<size_t>(pow(2, _depth)); // taille de la paire par rapport a la profo+ndeur
	size_t	nbOut = _main.size() % sizePair; // nb d'element endehors des paires

	while (nbOut)
	{
		_pend.push_front(_main.back());
		_main.pop_back();
		nbOut--;
	}
	std::cout << "values pend: " << _pend << std::endl;
}

void	SortDeque::recursion()
{
	if (_depth <= _depthMax)
	{
		handleOutsidePairs(); // add les values dans _pend a chaque lvl de recursion
		handleSwap();
		_depth++;
		recursion();
	}
}


int SortDeque::handleSortDeque()
{

	std::cout << "nbElem: " << _nbElem << std::endl;
	std::cout << "depthMax lvl: " << _depthMax << std::endl;

	std::cout << "Before: " << _main << std::endl;

	recursion();
	
	std::cout << "After: " << _main << std::endl;

	return (SUCCESS);
}
