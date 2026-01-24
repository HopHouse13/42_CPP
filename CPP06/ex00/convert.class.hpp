/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:01:48 by pbret             #+#    #+#             */
/*   Updated: 2026/01/23 14:44:48 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_CLASS_HPP
# define CONVERT_CLASS_HPP

#include <iostream>
#include <string>
#include <cstdlib> // strtol // stryod
#include <cctype> // isdigit
#include <iomanip> // fixed, setpressision
#include <cerrno> // errno
#include <limits>

class ScalarConverter
{
	public:
		static void			convert(const std::string str); // pas de modif sur str

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter&	operator=(const ScalarConverter& rhs);
		virtual				~ScalarConverter() = 0; // destructeur abstrait pure -> class abstraite
};

void	printTypes(const std::string str, int type);
bool	isChar(const std::string str);
bool	isInt(const std::string str);
bool	isFloat(const std::string str);
bool	isDouble(const std::string str);
void	printChar(const std::string str);
void	printInt(const std::string str);
void	printFloat(const std::string str);
void	printDouble(const std::string str);

#endif