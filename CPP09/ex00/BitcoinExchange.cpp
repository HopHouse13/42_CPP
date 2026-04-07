/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:08:07 by pbret             #+#    #+#             */
/*   Updated: 2026/04/07 12:46:46 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

btcExchange::btcExchange() : _date(""), _value(-1)
{
	//std::cout << "Default constructor called" << std::endl;
}

btcExchange::~btcExchange()
{
	//std::cout << "Destructor called" << std::endl;
}

btcExchange::btcExchange(btcExchange const & copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_data = copy._data;
	this->_date = copy._date;
	this->_value = copy._value;
}

btcExchange const &	btcExchange::operator=(btcExchange const & rhs)
{
	//std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		this->_data = rhs._data;
		this->_date = rhs._date;
		this->_value = rhs._value;
	}
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////////

int	btcExchange::_checkValue(std::string value)
{
	std::string	tmpV = value;
	for (size_t i = 0; i < tmpV.size(); i++)
	{
		if (tmpV[i] == '-' && (i != 0 || i + 1 >= tmpV.size()))
		{
			std::cout << "Error: invalid number [" << value << "]" << std::endl;
			return (FAILURE);
		}
		//if (tmpV[i] == ',')
		//	tmpV[i] = '.'; // atof comprends uniquement '.'
	}

	double	v = std::atof(tmpV.c_str());

	if (v < 0 || v > 1000)
	{
		if (v < 0)
			std::cout << "Error: not a positive number [" << value << "]" << std::endl;
		else
			std::cout << "Error: too large a number [" << value << "]" << std::endl;
		return (FAILURE);
	}
	this->_value = v;
	return (SUCCESS);
}

int	btcExchange::_checkDate(std::string date)
{
	bool	flag = true;
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') // check si les deux '-' sont aux bons endroits
		flag = false;

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8).c_str());

	if (year < 2009/* || year > 2022*/)
		flag = false;
	if (month < 1 || month > 12)
		flag = false;

	bool	month30 = false;
	bool	month31 = false;
	bool	february = false;

	if (month == 4 || month == 6 || month == 9 || month == 11)
		month30 = true;
	else if (month == 2)
		february = true;
	else
		month31 = true;

	if (february == true && (day < 1 || day > 29 || (day == 29 && year % 4 != 0 )))
		flag = false;
	else if (month30 == true && (day < 1 || day > 30))
		flag = false;
	else if (month31 == true && (day < 1 || day > 31))
		flag = false;

	if (flag == false)
	{
		std::cout << "Error: invalid date [" << date << "]" << std::endl;
		return (FAILURE);
	}
	this->_date = date;
	return (SUCCESS);
}

//- format date -> yyyy-mm-dd
//- si la date existe -> annee bissextile (2012,2016,2020)
//- valeur a virgule entre 0 - 1000
int	btcExchange::_parsingLine(std::string line)
{

	int		nbPipe = 0;
	int		nbComma = 0;
	int		nbDash = 0;
	int		nbSpace = 0;
	size_t	posPipe = 0;
	bool	flag = true;

	if (line.size() < 14)
		flag = false;

	for (size_t i = 0; flag == true && i < line.size(); i++) //check si il y a le bon nombre d'element
	{
		if ((line[i] < '0' || line [i] > '9') && line[i] != ' ' && line[i] != '-' && line[i] != '|' && line[i] != '.')
			flag = false;
		if (line[i] == '|')
		{
			if (line[i -1] != ' ' || line[i + 1] != ' ')
				flag = false;
			posPipe = i;
			nbPipe++;
		}
		if (line[i] == ',')
			nbComma++;
		if (line[i] == '-')
			nbDash++;
		if (line[i] == ' ')
			nbSpace++;
	}

	if (flag == false || nbPipe != 1 || nbComma > 1 || nbDash > 3 || nbSpace != 2)
	{
		std::cout << "Error: bad input [" << line << "]" << std::endl;
		return (FAILURE);
	}

	std::string	date = line.substr(0, posPipe - 1);
	std::string	value = line.substr(posPipe + 2);

	if (_checkDate(date) != SUCCESS)
		return (FAILURE);
	if (_checkValue(value) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

void	btcExchange::_calculate()
{
	std::map<std::string, double>::iterator	it = _data.lower_bound(_date);

	if (it == _data.end())
		it--;
	else if ((it != _data.begin() && it->first != _date)) // fist donne la cle (date) de l 'element <map> : cle(fisrt) -> valeur(second)
		it--;

	std::ostringstream oss; // oss est un flux de sortie
	oss << std::fixed << std::setprecision(2) << (_value * it->second); // le produit de la multiplication est traité avec différents "filtres" pour le formater correctement
	std::string	product = oss.str(); // le flux de sortie est converti en string et stocké dans 'product'
	//std::replace(product.begin(), product.end(), '.', ','); // Puis dans la string, les '.' sont remplacés par ','

	std::cout << _date << " => " << _value << " = " << product << std::endl;
}

int	btcExchange::_handleExchange(std::string input)
{
	std::ifstream	file(input.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open input file" << std::endl;
		return (FAILURE);
	}

	std::string	line;
	std::getline(file, line);
	if (line != "date | value") // check le header du fichier passe en arg (premiere ligne)
	{
		std::cout << "Error: invalid header" << std::endl;
		return (FAILURE);
	}
	while (std::getline(file, line))
	{
		if (line.empty() == true)
			continue;
		if (_parsingLine(line) != SUCCESS)
			continue;
		_calculate();
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
		std::cout << "Error: could not open file \"./data.csv\"" << std::endl;
		return (FAILURE);
	}
	
	std::string line;
	while(std::getline(data, line))
	{
		if (line.empty() == false && line[0] == '2') // traitement uniquement les lignes avec les dates
		{
			std::string	key = line.substr(0, 10);
			double value = std::atof(line.substr(11).c_str()); // j'ai mis du temps trouver ca
			_data.insert(std::make_pair(key, value));
		}
	}
	if (_data.empty())
	{
		std::cout << "Error: the database is empty" << std::endl;
		return (FAILURE);
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