/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:01:18 by pbret             #+#    #+#             */
/*   Updated: 2026/01/22 19:07:39 by pbret            ###   ########.fr       */
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
	int	type = 0;

	if (isChar(str))
		type = 1;
	if (isInt(str))
		type = 2;
	if (isFloat(str))
		type = 3;
	if (isDouble(str))
		type = 4;
	printTypes(str, type);
}

bool	isChar(const std::string str)
{
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126 && !isdigit(str[0])) // std.lenght verifie si c'est bien un seul char et pas une chaine de char
		return (true);
	return (false);
}

bool	isInt(const std::string str)
{
	long	valueLong;
	char*	ptrEnd;

	valueLong = strtol(str.c_str(), &ptrEnd, 10); // sttol mets le ptrEnd a l'adresse du char ou il a arrete la conversion
	if (*ptrEnd == '\0' && valueLong <= std::numeric_limits<int>::max() && valueLong >= std::numeric_limits<int>::min())
		return (true);
	return (false);
}

bool	isFloat(const std::string str)
{
	char*	ptrEnd;
	
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf" || str == "+nanf" || str == "-nanf") // nan -> Not a Number / inff, +nanf, -nanf existe mais ne sont pas demandes a etre geres.
		return (true);
	errno = 0;
	std::strtof(str.c_str(), &ptrEnd); // strtof arrete la converstion des au 2eme '.' ex: 4.4.4f
	if ((*ptrEnd == 'f' || *ptrEnd == 'F') && *(ptrEnd + 1) == '\0' && str.find('.') != std::string::npos && errno != ERANGE) // find "." pour eviter les 4f
		return (true);
	return (false);
}

bool	isDouble(const std::string str)
{
	char*	ptrEnd;

	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan" || str == "+nan" || str == "-nan")
		return (true);
	errno = 0; // reset de la globale pour que stdtod modifie errno si overflow/underflow
	std::strtod(str.c_str(), &ptrEnd); // strtod arrete la converstion des au 2eme '.' ex: 4.4.4 -> invalid
	if (*ptrEnd == '\0' && str.find('.') != std::string::npos && errno != ERANGE) // strtod modifie errno si overflow
		return (true);
	return (false);
}

void	printTypes(const std::string str, int type)
{
	switch (type)
	{
	case 1 : // char
		printChar(str);
		break;
	case 2 : // int
		printInt(str);
		break;
	case 3 : // float
		printFloat(str);
		break;
	case 4 : // double
		printDouble(str);
		break;
	default:
		std::cout << "Error: invalid input type. Must be of type character, integer, float or double" << std::endl; // a ameliorer
		break;
	}
}

void	printChar(const std::string str)
{
	char	c = static_cast<char>(str[0]); // static_cast est verifie lors de la compilation != dynamic_cast
	std::cout	<< "char: \'" << c << "\'" << std::endl
				<< "int: " << static_cast<int>(c) << std::endl
				<< std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl //std::fixed est une manipulateur de flux. il serre a affichier les float en deximale fixe 42.0f (!= affichage scientifique avec une exposant 42e+01f)
				<< "double: " << static_cast<double>(c) << std::endl;
}

void	printInt(const std::string str)
{
	int	i = std::atoi(str.c_str());
	if (i == 0 && str.find('0') == std::string::npos)
	{
		std::cout << "atoi failed" << std::endl;
		return ;
	}
	if (i >= 32 && i <= 126)
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else
		std::cout << "char: " << "impossible to display" << std::endl;
	std::cout	<< "int: " << i << std::endl
				<< std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl
				<< "double: " << static_cast<double>(i) << std::endl;
}

void	printFloat(const std::string str)
{
	float	f = std::strtof(str.c_str(), NULL);

	if (f >= 32 && f <= 126)
		std::cout << "char: \'" << static_cast<char>(f) << "\'" << std::endl;
	else
		std::cout << std::fixed << "char: " << "impossible to display" << std::endl;
	if (static_cast<double>(f) <= std::numeric_limits<int>::max() && static_cast<double>(f) >= std::numeric_limits<int>::min()) 
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	std::cout	<< std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl
				<< "double: " << static_cast<double>(f) << std::endl;
}

void	printDouble(const std::string str)
{
	double	d = std::strtod(str.c_str(), NULL);

	if (d >= 32 && d <= 126)
		std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;
	else
		std::cout << "char: " << "impossible to display" << std::endl;	
	if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min()) 
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl
	<< "double: " << d << std::endl;
}
