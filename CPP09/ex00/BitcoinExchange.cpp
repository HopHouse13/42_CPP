/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:24 by pbret             #+#    #+#             */
/*   Updated: 2026/02/26 14:06:30 by pab              ###   ########.fr       */
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

int	btcExchange::_checkDate(std::string data)
{
	int	posYear;
	int	posMouth;
	int	posDay;
	int	flag;

	for (int i = 0; i < data.size(); i++)
	{
		
	}

	if (data < "2009-01-02" || data > "2022-03-29")
	std::cout << ""
	return (SUCCESS);
}

int	btcExchange::_parsingLine(std::string line)
{
	//- format date -> yyyy-mm-dd
	//- si la date existe -> annee bissextile (2012,2016,2020)
	//- valeur a virgule entre 0 - 1000
	
	int		posDate = -1;
	int		posValue = -1;
	int		flag = 0;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == '|' && flag == 1)
			flag = 2;
		if (line[i] >= '0' && line[i] <= '9' && flag == 0)
		{
			posDate = i;
			flag = 1;
		}
		if (((line[i] >= '0' && line[i] <= '9') || line[i] == '+' || line[i] == '-') && flag == 2)
		{
			posValue = i;
			flag = 3;
		}
	}
	if (posDate == -1 || posValue == -1)
	{
		std::cout << "Error: invalid format line" << std::endl;
		return (FAILURE);
	}
	{
		//std::cout << "date flag: " << line[posDate] << "\t" << "value flag: " << line[posValue] << "\n";
		std::string	date = line.substr(posDate, 10);
		std::string	value = line.substr(posValue);
		std::cout << "date: " << date << "\t" << "value: " << value << "\n";

		//if (_checkDate(date) != SUCCESS || _checkValue(value) != SUCCESS)
		//	return (FAILURE);
	}
	return (SUCCESS);
}

int	btcExchange::_handleExchange(std::string input)
{
	std::ifstream	file(input.c_str());
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
			//std::cout << "parsing SUCCESS\n";
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
	//_displayData();
	_handleExchange(input);

	return (SUCCESS);
}