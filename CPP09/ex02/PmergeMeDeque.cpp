/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:19:41 by pbret             #+#    #+#             */
/*   Updated: 2026/03/27 18:03:14 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeDeque.hpp"

SortDeque::SortDeque()
{
	//std::cout << "Default constructor SortDeque called" << std::endl;
}

SortDeque::SortDeque(char **raw, int nbElem, int depthMax) : _nbElem(nbElem), _depthMax(depthMax), _depth(0)
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

void	SortDeque::pushMainRestToPend(size_t sizePack)
{
	size_t	nbRest = _main.size() % sizePack; // nb d'element endehors des paires
	while (nbRest)
	{
		_pend.push_front(_main.back());
		_main.pop_back();
		nbRest--;
	}
}

void	SortDeque::pushPendToMain()
{
	if (_pend.size() == 0)
		return ;
	while (!_pend.empty())
	{
		_main.push_back(_pend.front());
		_pend.pop_front();
	}
}

void	SortDeque::labeling(size_t sizePack)
{
	size_t	sizeElem = sizePack / 2; // taille de l'element des paires
	//_labels.clear(); // clear _main pour chaque niveau de recursion
	while (!_main.empty())
	{
		_labels.push_back(Elem());
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
			_labels[i].setIdL('b');
		else
			_labels[i].setIdL('a');
		if (i % 2 != 0)
			valueId++;
	}
}

// Main: b1 + all a
// pend: all b (sauf b1)
void	SortDeque::distribution()
{
	while (!_labels.empty())
	{
		Elem current = _labels.front();

		if (current.getIdV() == 1 && (current.getIdL() == 'a' || current.getIdL() == 'b'))
			_mainLabeled.push_back(current);
		else if (current.getIdL() == 'a')
			_mainLabeled.push_back(current);
		else
			_pendLabeled.push_back(current);

		_labels.pop_front();
	}
}

void	SortDeque::insersion()
{
	while (!_pendLabeled.empty())
	{
		_mainLabeled.push_front(_pendLabeled.front());
		_pendLabeled.pop_front();
	}
	
	while (!_mainLabeled.empty())
	{
		std::deque<int>	sequenceCurrent = _mainLabeled.front().getSequence();
		while (!sequenceCurrent.empty())
		{
			_main.push_back(sequenceCurrent.front());
			sequenceCurrent.pop_front();
		}
		_mainLabeled.pop_front();
	}
}



void	SortDeque::recursion()
{
	_depth++;
	size_t	sizePack = static_cast<size_t>(pow(2, _depth)); // taille de la paire par rapport a la profondeur (1er appel -> _depth = 1(init. constructeur))
	std::cout << std::endl << std::endl << "--------------*PACK " << sizePack << "*-----------------" << std::endl;
	if (_depth < _depthMax) // _depth ne peut etre egale a Max car il commence par 1 (et non 0) donc si il devait etre egale a max, il y aurait un niveau de recursion en trop
	{
		std::cout << std::endl << "SWAP PAIRS" << std::endl;
		pushMainRestToPend(sizePack); // add les values dans _pend a chaque lvl de recursion
		handleSwap(sizePack);
		std::cout << std::endl << "sizePack: " << sizePack << std::endl << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl;
		pushPendToMain();
		recursion();
	}
	std::cout << std::endl << std::endl << "--------------*PACK " << sizePack << "*-----------------" << std::endl;

	pushMainRestToPend(sizePack); // isole les valeurs qui sont hors paires pour ne pas les labeliser
	std::cout << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl << "sizePack: " << sizePack << std::endl;

	labeling(sizePack);
	std::cout << std::endl << "LABELING" << std::endl;
	for (size_t i = 0; i < _labels.size(); i++)
	{
		if (i > 0 && i % 2 == 0)
			std::cout << " | ";
		else if (i > 0)
			std::cout << " - ";
		std::cout << _labels[i].getIdL() << _labels[i].getIdV() << "[" << _labels[i].getSequence() << "]";
	}
	distribution();
	std::cout << std::endl << std::endl << "MAIN-LABELED" << std::endl;
	for (size_t i = 0; i < _mainLabeled.size(); i++)
	{
		if (i > 0)
			std::cout << " * ";
		std::cout << _mainLabeled[i].getIdL() << _mainLabeled[i].getIdV() << "[" << _mainLabeled[i].getSequence() << "]";
	}
	std::cout << std::endl << "PEND-LABELED" << std::endl;
	for (size_t i = 0; i < _pendLabeled.size(); i++)
	{
		if (i > 0)
			std::cout << " * ";
		std::cout << _pendLabeled[i].getIdL() << _pendLabeled[i].getIdV() << "[" << _pendLabeled[i].getSequence() << "]";
	}

	insersion();

	pushPendToMain();
	std::cout << std::endl << std::endl << "sizePack: " << sizePack << std::endl << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl;
	std::cout << std::endl << std::endl << "---------------*END*------------------" << std::endl;
	//pushPendToMain();
}

int SortDeque::handleSortDeque()
{

	std::cout << "nbElem: " << _nbElem << std::endl;
	std::cout << "depthMax lvl: " << _depthMax << std::endl;

	std::cout << "Before: " << _main << std::endl;

	recursion();
	
	std::cout << std::endl << "After: " << _main << std::endl;

	return (0);
}
