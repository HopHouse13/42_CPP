/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:19:41 by pbret             #+#    #+#             */
/*   Updated: 2026/04/05 13:00:59 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeDeque.hpp"

SortDeque::SortDeque()
{
	//std::cout << "Default constructor SortDeque called" << std::endl;
}

SortDeque::SortDeque(char **raw, int nbElem, int depthMax, std::deque<unsigned long long> suitJ)
: _nbElem(nbElem), _depthMax(depthMax), _depth(0) , _suitJacob(suitJ), _vJacob(0)
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

void	SortDeque::swap(size_t elemSize, size_t position)
{
	int		tmp;
	size_t	nbSwap = elemSize; // nb de valeur a swap (la totalite des index d'un element de la paire)

	while (nbSwap)
	{
		tmp = _main.at(position); // stock dans tmp la valeur de l'index le plus a droite de la premiere partie
		_main.at(position) = _main.at(position + elemSize); // cette meme index prend la valeur du "meme" index de la 2eme partie
		_main.at(position + elemSize) = tmp; // l'index le plus a droite de la seconde partie prend la valeur de l'index le plus a droite du premiere partie.
		position--; // decremente de 1 l'index a swap
		nbSwap--; // decremente de 1 le nombre de swap a effectuer
	}
}

void	SortDeque::handleSwap(size_t sizePair)
{
	size_t	elemSize = sizePair / 2; // /2 car on veut comparer l'index le plus a droite de la premiere partie de la paire a l'index le plus a droite de la seconde partie de la paire : [3 2 | 7 1][9 6 | 42 4] on va comparer 2->1 puis 6->4 
	for (size_t i = elemSize - 1; i + elemSize < _main.size(); i += elemSize * 2) // -1 a elemSize car i est un index et elemSize est une taille
	{
		if (_main[i] > _main[i + elemSize]) // comparaison entre la valeur del'index le plus a droite de la premiere partie de la paire avec la vleur de l'index a meme posisiton de la 2eme partie de la paire
			swap(elemSize, i);
	} // incrementation de i de elemSize * 2 pour passer la comparaison de la paires suivantes
}

void	SortDeque::isolateOrphanValuesPair(size_t sizePair)
{
	size_t	nbRest = _main.size() % sizePair; // nb d'element endehors des paires
	std::cout << "sizePair: "<< sizePair << std::endl << "nbRest: "<< nbRest << std::endl;
	while (nbRest)
	{
		_pend.push_front(_main.back());
		_main.pop_back();
		nbRest--;
	}
}

void	SortDeque::isolateOrphanValuesElem(size_t sizePair)
{
	size_t	nbRest = _main.size() % (sizePair / 2); // nb d'element endehors des elements
	std::cout << "sizeElem: "<< sizePair / 2 << std::endl << "nbRest: "<< nbRest << std::endl;
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

void	SortDeque::labeling(size_t sizePair)
{
	size_t	sizeElem = sizePair / 2; // taille de l'element des paires
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

int	SortDeque::borderMainL(unsigned long long valueJacob)
{
	int	i = 0;

	if (_mainLabeled.empty())
		return (-1);
	if (_vJacob > 0)
		return (_vJacob);
	while (i < static_cast<int>(_mainLabeled.size()))
	{
		if (_mainLabeled[i].getIdL() == 'a' && _mainLabeled[i].getIdV() == valueJacob) // assure que l'id est bien 'a'et la valeur de la suite J
			return (i);
		i++;
	}
	return (static_cast<int>(_mainLabeled.size() - 1));
}

int	SortDeque::borderPendL(unsigned long long valueJacob)
{
	int	i = 0;

	if (_pendLabeled.empty())
		return (-1);
	if (_vJacob > 0)
		return (_vJacob);
	while (i < static_cast<int>(_pendLabeled.size()))
	{
		if (_pendLabeled[i].getIdV() == valueJacob)
			return (i);
		i++;
	}
	return (static_cast<int>(_pendLabeled.size() - 1)); // si _pendLabeled a plus que des elem id qui ne correspond pas a une valeur de la suit J -> return l'index du dernier elem
}

void	SortDeque::insertion()
{

	int	idxJ = 0; // suitJ
	int	idxP = 0; // _pendLabeled
	int idxM = 0; // _mainLabeled
	int	toErase = 0; // save pose trash

	while (!_pendLabeled.empty() /*&& idxJ < static_cast<int>(_suitJacob.size())*/)
	{
		//idxP = borderPendL(_suitJacob[idxJ]);
		//idxM = borderMainL(_suitJacob[idxJ]);
		if (idxJ < static_cast<int>(_suitJacob.size())) // incrementation sur la prochaine valeur de la suite Jacob
			handleValueJacob(int idxJ++);
		// std::cout << std::endl << "--- Jacob LVL: " << _suitJacob.at(idxJ) << std::endl;
		while (idxP >= 0) // tant que l'ensemble des elem de la plage _pendLabeled vide
		{
			if (idxM >= 0 && _pendLabeled[idxP].getLastValue() < _mainLabeled[idxM].getLastValue()) // si idxM est a 0 -> aucun emplacement pour l'insertion a ete trouvé -> forcement l'elem courant doit se retrouver en premiere position de _mainLabeled
			{
				// std::cout << std::endl << idxP << " " << _pendLabeled[idxP].getIdL() <<  _pendLabeled[idxP].getIdV() << "[" <<  _pendLabeled[idxP].getSequence() << "]" << " < " << idxM << " " << _mainLabeled[idxM].getIdL() << _mainLabeled[idxM].getIdV() << "["<< _mainLabeled[idxM].getSequence() << "]";
				idxM--;
				continue;
			}
			// std::cout << std::endl << idxP << " " << _pendLabeled[idxP].getIdL() <<  _pendLabeled[idxP].getIdV() << "[" <<  _pendLabeled[idxP].getSequence() << "] -> insertion there" << std::endl;
			if (idxM >= 0)
				// std::cout << idxP << " " << _pendLabeled[idxP].getIdL() <<  _pendLabeled[idxP].getIdV() << "[" <<  _pendLabeled[idxP].getSequence() << "]" << " > " << idxM << " " << _mainLabeled[idxM].getIdL() << _mainLabeled[idxM].getIdV() << "["<< _mainLabeled[idxM].getSequence() << "]" << std::endl;
			_mainLabeled.insert(_mainLabeled.begin() + idxM + 1,  _pendLabeled[idxP]); // insertion de l'elem courant a la position a droite de l'elem comparé (dans _mainLabeled)
			toErase = idxP;
			idxP--; // elem suivant du _pendLabeled a inserer
			_pendLabeled.erase(_pendLabeled. begin() + toErase);
			idxM = borderMainL(_suitJacob[idxJ]); // recalcule de la plage avec le nouvel element tout juste insere
			// std::cout << std::endl << "MAIN-LABELED: " << _mainLabeled << std::endl << "PEND-LABELED: " << _pendLabeled << std::endl;
		}
		//if (idxJ < static_cast<int>(_suitJacob.size())) // incrementation sur la prochaine valeur de la suite Jacob
		//	idxJ++;
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
	_depth++; // pour chaque appelle  de recursion -> 1 nouveau niveau de recursion
	size_t	sizePair = static_cast<size_t>(pow(2, _depth)); // taille de la paire par rapport a la profondeur (1er appel -> _depth = 1(init. constructeur))
		
	if (_depth <= _depthMax)
	{
		std::cout << std::endl << std::endl << "--------------*SIZE PAIR " << sizePair << "*-----------------" << std::endl;
		std::cout << std::endl << "sizePair: " << sizePair << std::endl << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl;
		std::cout << std::endl << "SWAP PAIRS" << std::endl;
		isolateOrphanValuesPair(sizePair); // add les values dans _pend a chaque lvl de recursion
		handleSwap(sizePair);
		//pushPendToMain(); // inutile je pense
		std::cout << std::endl << std::endl << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl;
		recursion();
	}
	std::cout << std::endl << std::endl << "--------------*SIZE PAIR " << sizePair << "*-----------------" << std::endl;
	
	pushPendToMain();

	//if ((sizePair * 2) <=  _main.size()) // si on peut pas avoir au moins deux paires, le proccessus d'insertion ne fera aucun changement
	//{
		std::cout << "BEFORE ISOLATION"<< std::endl << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl;

		isolateOrphanValuesElem(sizePair); // isole les valeurs avec les quelles un elem ne peux pas etre constitué. Elles ne seront pas labelisées/inserées
	
		std::cout << "AFTER ISOLATION"<< std::endl << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl;

		labeling(sizePair);

		std::cout << std::endl << "LABELING: " << _labels << std::endl;
	
		distribution();
	
		std::cout << std::endl << "MAIN-LABELED: " << _mainLabeled << std::endl << "PEND-LABELED: " << _pendLabeled << std::endl << std::endl;

		insertion();

		pushPendToMain();
	//}
	std::cout << std::endl << std::endl << "_main: " << _main << std::endl << "_pend: " << _pend << std::endl;
	std::cout << std::endl << "------------------*END*---------------------" << std::endl;
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
