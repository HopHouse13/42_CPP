/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:01:18 by pbret             #+#    #+#             */
/*   Updated: 2026/01/19 17:51:43 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void)rhs;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	std::cout << "Assignment operator overlead called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

void	ScalarConverter::convert(const std::string str)
{
	//if (isInt(str))
	// if (isChar(str))
	std::cout << "result" << isFloat(str) << std::endl;

}

//void	printTypes(const std::string str)
//{
	
//}
bool	isChar(const std::string str)
{
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126 && !isdigit(str[0]))
		return (true);
	return (false);
}

bool	isInt(const std::string str)
{
	long	valueLong;
	char*	ptrEnd;

	valueLong = strtol(str.c_str(), &ptrEnd, 10); // sttol mets le ptrEnd a l'adresse du char ou il a arrete la conversion
	if (*ptrEnd == '\0' && valueLong <= INT_MAX && valueLong >= INT_MIN)
		return (true);
	return (false);
}

bool isFloat(const std::string str)
{
	char*	ptrEnd;

	// voir pour inff- inf+ nanf
	std::strtof(str.c_str(), &ptrEnd); // strtof arrete la converstion des au 2eme '.' ex: 4.4.3f
	std::cout << ">>> " << *ptrEnd << std::endl; // aSupp
	if ((*ptrEnd == 'f' || *ptrEnd == 'F') && *(ptrEnd + 1) == '\0' /*&& *(ptrEnd - 1) != '.'*/) // cela ne fonctionne pas pour 4.f voir paul
		return (true);
	return (false);
}