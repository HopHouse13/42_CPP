/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:24 by pbret             #+#    #+#             */
/*   Updated: 2026/03/03 15:46:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

btcExchange::btcExchange()
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
}

btcExchange const &	btcExchange::operator=(btcExchange const & rhs)
{
	//std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs)
		this->_data = rhs._data;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////////

int	btcExchange::_checkValue(std::string value)
{
	if (value.empty())
		return (FAILURE);
	for (size_t i = 0; i < value.size(); i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != ',')
		return (FAILURE);
	}
	double	v = std::atof(value.c_str());
	if (v < 0 || v > 1000)
		return (FAILURE);
	return (SUCCESS);
}


int	btcExchange::_checkDate(std::string date)
{
	bool	flag = true;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-') // check si les deux '-' sont aux bons endroits
		flag = false;

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	mouth = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8).c_str());

	std::cout << "PARSING-Date ["<< year << "][" << mouth << "][" << day << "]" << std::endl;

	if (year < 2009 || year > 2022)
		flag = false;
	if (mouth < 1 || mouth > 12)
		flag = false;

	bool	mouth30 = false;
	bool	mouth31 = false;

	if (mouth == 4 || mouth == 6 || mouth == 9 || mouth == 11)
		mouth30 = true;
	else
		mouth31 = true;

	if (mouth30 == true && (day < 1 || day > 30))
		flag = false;
	if (mouth31 == true && (day < 1 || day > 31))
		flag = false;
	if (mouth == 2 && day == 29 && year % 4 != 0)
		flag = false;

	if (flag == false)
		return (FAILURE);
	return (SUCCESS);
}

//int	btcExchange::_checkDate(std::string date)
//{
//	int		posYear;
//	int		posMouth;
//	int		posDay;
//	bool	flag = false;

//	for (size_t i = 0; i < date.size(); i++)
//	{
//		if (date[i] == '-' && flag == true)
//			flag = false;
//		else if (date[i] >= '0' && date[i] <= '9' && i < 4 && flag == false) // yyyy
//		{
//			posYear = i;
//			flag = true;
//		}
//		else if (date[i] >= '0' && date[i] <= '9' && i > 4 && i < 7 && flag == false) // mm
//		{
//			posMouth = i;
//			flag = true;
//		}
//		else if (date[i] >= '0' && date[i] <= '9' && i > 7 && flag == false) // dd
//		{
//			posDay = i;
//			flag = true;
//		}
//	}
//	// je pense que j'ai fais un truc trop complique
//	std::string	year = date.substr(posYear, 4);
//	std::string	mouth = date.substr(posMouth, 2);
//	std::string	day = date.substr(posDay);
//	std::cout << "checkDate "<< year << "-"<< mouth << "-"<< day << std::endl;
//	// "2009-01-02" "2022-03-29"
//	return (SUCCESS);
//}

int	btcExchange::_parsingLine(std::string line)
{
	//- format date -> yyyy-mm-dd
	//- si la date existe -> annee bissextile (2012,2016,2020)
	//- valeur a virgule entre 0 - 1000

	//int		posDate = 0;
	//int		posValue = 0;
	int		posDash = 0;
	//int		countDate = 0;
	//int		countValue = 0;
	int		nbPipe = 0;
	int		nbComma = 0;
	int		nbDash = 0;
	int		nbSpace = 0;
	bool	flag = true;

	if (line.size() < 14)
		flag = false;
	for (size_t i = 0; flag == true && i < line.size(); i++) //check si il y a le bon nombre d'element
	{
		if ((line[i] < '0' || line [i] > '9') && line[i] != ' ' && line[i] != '-' && line[i] != '|' && line[i] != ',')
			flag = false;
		if (line[i] == '|')
		{
			nbPipe++;
			posDash = i;
		}
		if (line[i] == ',')
			nbComma++;
		if (line[i] == '-')
			nbDash++;
		if (line[i] == ' ')
			nbSpace++;
	}
	//for (size_t i = 0; flag == true && i != posDash && i < line.size(); i++)
	//{
	//	if (line[i] == ' ')
	//		flag = false;
	//	if (((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
	//	{
	//		if (countDate == 0)
	//			posDate = i;
	//		countDate++;
	//	}
	//}
	//for (size_t i = 0; i < line.size(); i++)
	//{
	//	if ((line[i] < '0' || line [i] > '9') && line[i] != ' ' && line[i] != '-' && line[i] != '|' && line[i] != ',')
	//	{
	//		flag = false;
	//		break;
	//	}
	//	if (line[i] == '|')
	//		nbPipe++;
	//	if (line[i] == ',')
	//		nbComma++;
	//	if (line[i] == '-')
	//		nbDash++;
	//	if (((line[i] >= '0' && line[i] <= '9') || line[i] == '-' || line[i] == ' ') && flag == false)
	//	{
	//		if (countDate == 0)
	//			posDate = i;
	//		countDate++;
	//	}
	//	else if (line[i] == '|' && flag == false)
	//		flag = true;
	//	else if (((line[i] >= '0' && line[i] <= '9') || line[i] == '+' || line[i] == '-' || line[i] == ',') && flag == true)
	//	{
	//		if (countValue == 0)
	//			posValue = i;
	//		countValue++;
	//	}
	//}
	if (flag == false || nbPipe != 1 || nbComma > 1 || nbDash != 2 || nbSpace != 2)
	{
		std::cout << "Error: invalid format line" << std::endl;
		return (FAILURE);
	}
	std::string	date = line.substr(0, 10);
	std::string	value = line.substr(14);
	std::cout << "date [" << date << "] " << "value [" << value << "]\n";

	if (_checkDate(date) != SUCCESS || _checkValue(value) != SUCCESS)
		return (FAILURE);	
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
	std::getline(file, line);
	if (line.compare("date | valeur") != 0) // check le header du fichier passe en arg (premiere ligne)
	{
		std::cout << "Error: invalid header" << std::endl;
		return (FAILURE);
	}
	while (std::getline(file, line))
	{
		if (_parsingLine(line) != SUCCESS)
			std::cout << "Error: invalid format" << std::endl;
		// fonction de comparaison
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