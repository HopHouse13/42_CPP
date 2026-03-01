/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:24 by pbret             #+#    #+#             */
/*   Updated: 2026/03/01 20:26:58 by pbret            ###   ########.fr       */
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

//int	btcExchange::_checkValue(std::string value)
//{
	

//	return (SUCCESS);
//}


int	btcExchange::_checkDate(std::string date)
{
	bool	flag = true;

	if ((date[4] != '-' || date[7] != '-')) // check si les deux '-' sont aux bons endroits
		flag = false;

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	mouth = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8).c_str());

	std::cout << "checkDate "<< year << "-" << mouth << "-" << day << std::endl;

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

	if ((mouth30 == true && day > 30) && day < 1)
		flag = false;
	if ((mouth31 == true && day > 31) && day < 1)
		flag = false;
	if (mouth == 2 && day == 29 && year % 4 != 0)
		flag = false;

	if (flag == false)
	{
		std::cout << "Error: invalid date" << std::endl;
		return (FAILURE);
	}
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

	int		posDate = -1;
	int		posValue = -1;
	int		flag = 0;
	
	for (size_t i = 0; i < line.size(); i++)
	{
		if ((line[i] < '0' || line [i] > '9') && line[i] != ' ' && line[i] != '-' && line[i] != '|' && line[i] != ',')
		{
			flag = 0;
			break;
		}
		if (line[i] >= '0' && line[i] <= '9' && flag == 0)
		{
			posDate = i;
			flag = 1;
		}
		else if (line[i] == '|' && flag == 1)
			flag = 2;
		else if (((line[i] >= '0' && line[i] <= '9') || line[i] == '+' || line[i] == '-') && flag == 2)
		{
			posValue = i;
			flag = 3;
		}
	}
	if (flag != 3)
	{
		std::cout << "Error: invalid format line" << std::endl;
		return (FAILURE);
	}
		std::string	date = line.substr(posDate, 10);
		std::string	value = line.substr(posValue);
		//std::cout << "date: " << date << "\t" << "value: " << value << "\n";

		if (_checkDate(date) != SUCCESS)/* || _checkValue(value) != SUCCESS)*/
			return (FAILURE);
		std::cout << "checkDate -> SUCCESS\n";
		
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