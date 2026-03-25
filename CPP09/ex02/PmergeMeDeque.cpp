/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:19:41 by pbret             #+#    #+#             */
/*   Updated: 2026/03/25 12:40:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeDeque.hpp"

SortDeque::SortDeque()
{
	//std::cout << "Default constructor SortDeque called" << std::endl;
}

SortDeque::SortDeque(char **raw, int nbElem, int depthMax) : _nbElem(nbElem), _depthMax(depthMax), _depth(1)
{
	//std::cout << "Default constructor SortDeque called" << std::endl;
	for (int i = 1; i <= nbElem; i++)
		_main.push_back(std::atoi(raw[i]));
}

SortDeque::~SortDeque()
{
	//std::cout << "Destructor SortDeque called" << std::endl;
}

SortDeque::SortDeque(SortDeque const & copy)
{
	//std::cout << "Copy constructor SortDeque called" << std::endl;
	this->_main = copy._main;
}

SortDeque const &	SortDeque::operator=(SortDeque const & rhs)
{
	//std::cout << "Assignment operator overload SortDeque called" << std::endl;
	if (this != &rhs)
	{
		
	}
	return (*this);
}

//////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, std::deque<int> const & list)
{
	for (size_t i = 0; i < list.size(); i++)
		os << (i ? " " : "") << list.at(i);
	return (os);
}

void	SortDeque::swap(size_t compareSize, size_t position)
{
	int		tmp;
	size_t	nbSwap = compareSize; // nb d'elements a swap (la totalite des index de chaque partie de la paire)

	while (nbSwap)
	{
		tmp = _main.at(position); // stock dans tmp la valeur de l'index le plus a droite de la premiere partie
		_main.at(position) = _main.at(position + compareSize); // cette meme index prend la valeur du "meme" index de la 2eme partie
		_main.at(position + compareSize) = tmp; // l'index le plus a droite de la seconde partie prend la valeur de l'index le plus a droite du premiere partie.
		position--; // decremente de 1 l'index a swap
		nbSwap--; // decremente de 1 le nombre de swap a effectuer
	}
}

void	SortDeque::handleSwap(size_t sizePack)
{
	size_t	compareSize = sizePack / 2; // /2 car on veut comparer l'index le plus a droite de la premiere partie de la paire a l'index le plus a droite de la seconde partie de la paire : [3 2 | 7 1][9 6 | 42 4] on va comparer 2->1 puis 6->4 
	for (size_t i = compareSize - 1; i + compareSize < _main.size(); i += compareSize * 2) // -1 a compareSize car i est un index et compareSize est une taille
	{
		if (_main[i] > _main[i + compareSize]) // comparaison entre la valeur del'index le plus a droite de la premiere partie de la paire avec la vleur de l'index a meme posisiton de la 2eme partie de la paire
			swap(compareSize, i);
	} // incrementation de i de compareSize * 2 pour passer la comparaison de la paires suivantes
}

void	SortDeque::handleOutsidePairs(size_t sizePack)
{
	size_t	nbOut = _main.size() % sizePack; // nb d'element endehors des paires

	while (nbOut)
	{
		_pend.push_front(_main.back());
		_main.pop_back();
		nbOut--;
	}
	std::cout << "values pend: " << _pend << std::endl;
}

void	SortDeque::labeling(size_t sizePack)
{
	size_t	sizeElem = sizePack / 2; // taille de l'element
	_labels.clear(); // clear _main pour chaque niveau de recursion
	while (!_main.empty())
	{
		_labels.push_back(Elem());
		std::cout << "value sizeElem: " << sizeElem << std::endl;
		for (size_t i = 0; i < sizeElem && !_main.empty(); i++)
		{
			_labels.back().setSequence(_main.front());
			_main.pop_front(); // _main est clear au fur et a mesure pour pouvoir inserer dans le bon ordre apres
		}
	}

	size_t	valueId = 1;
	for (size_t i = 0; i < _labels.size(); i++)
	{
		_labels[i].setIdV(valueId);
		if (i % 2 == 0)
			_labels[i].setIdG(false);
		else
			_labels[i].setIdG(true);
		if (i % 2 != 0)
			valueId++;
	}
	for (size_t i = 0; i < _labels.size(); i++)
		std::cout << "value labels "<< i << ": " << _labels[i].getSequence() << "\tidL: " << _labels[i].getIdG() << "\tidV: " << _labels[i].getIdV() << std::endl;
}

//void	SortDeque::pushPendToMain()
//{
//	if (_pend.size() == 0)
//		return ;
//	while (_pend.size() != 0)
//	{
//		_main.push_back(_pend.front());
//		_pend.pop_front();
//	}
//}

void	SortDeque::recursion()
{
	size_t	sizePack = static_cast<size_t>(pow(2, _depth)); // taille de la paire par rapport a la profondeur (1er appel -> _depth = 1(init. constructeur))
	if (_depth <= _depthMax)
	{
		handleOutsidePairs(sizePack); // add les values dans _pend a chaque lvl de recursion
		handleSwap(sizePack);
		_depth++;
		std::cout << _main << std::endl;
		recursion();
	}
	labeling(sizePack);
	//pushPendToMain();
	//insersion();
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
