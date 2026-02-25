/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:24 by pbret             #+#    #+#             */
/*   Updated: 2026/02/25 15:20:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

btcExchange::btcExchange()
{
	std::cout << "Default constructor called" << std::endl;
}

btcExchange::~btcExchange()
{
	std::cout << "Destructor called" << std::endl;
}

btcExchange::btcExchange(btcExchange const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_data = copy._data;
}

btcExchange const &	btcExchange::operator=(btcExchange const & rhs)
{
	std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs)
		this->_data = rhs._data;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////////

//int	btcExchange::_checkValue(std::string data)
//{
	

//	return (SUCCESS);
//}

//int	btcExchange::_checkDate(std::string data)
//{
	

//	return (SUCCESS);
//}

int	btcExchange::_parsingLine(std::string line)
{
	//- format date -> yyyy-mm-dd
	//- si la date existe -> annee bissextile (2012,2016,2020)
	//- valeur a virgule entre 0 - 1000
	int		posDate;
	int		posValue;
	bool	flagBar = false;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '|')
			flagBar = true;
		if (line[i] != ' ')
			posDate = i;
		if ()
	}
	std::string	date = line.substr(i, 10);
	std::string	value;

	if (_checkDate(date) != SUCCESS || _checkValue(value) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	btcExchange::_handleExchange(std::string input)
{
	std::ifstream	file(input);
	if (!file.is_open())
	{
		std::cout << "Le fichier passe en argument du programme n'a pas pu etre ouvert" << std::endl;
		return (FAILURE);
	}

	std::string	line;
	while (std::getline(file, line))
	{
		if (_parsingLine(line) == SUCCESS)
		{
			std::cout << "parsing SUCCESS\t";
		}
	}
	return (SUCCESS);	
}

void	btcExchange::_displayData()
{
	std::map<std::string, double>::const_iterator	it = _data.begin();
	std::map<std::string, double>::const_iterator	End = _data.end();
	while (it != End)
	{
		std::cout << it->first << "," << (*it).second << std::endl;
		it++;
	}
}

int	btcExchange::_initData()
{
	std::ifstream	data("./data.csv");
	if (!data.is_open())
	{
		std::cout << "Le fichier \"./data.csv/\" n'a pas pu etre ouvert" << std::endl;
		return (FAILURE);
	}
	
	std::string line;
	while(std::getline(data, line))
	{
		if (line[0] == '2') // traitement uniquement les lignes avec les dates
		{
			std::string	key = line.substr(0, 10);
			double value = std::atof(line.substr(11).c_str()); // j'ai mis du temps trouver ca
			_data.insert(std::make_pair(key, value));
		}
	}
	return (SUCCESS);
}

int	btcExchange::btcCalculate(std::string input)
{
	if (_initData() != SUCCESS)
		return (FAILURE);
	_displayData();
	_handleExchange(input);

	return (SUCCESS);
}