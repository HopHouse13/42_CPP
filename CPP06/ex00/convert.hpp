/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:01:48 by pbret             #+#    #+#             */
/*   Updated: 2026/01/08 18:05:16 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <climits> // MAX/MIN
#include <cstdlib> // strtol
#include <cctype> // isdigit

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter&	operator=(const ScalarConverter& rhs);
		virtual				~ScalarConverter() = 0; // destructeur abstrait pure -> class abstraite

		static void			convert(const std::string str); // pas de modif sur str
};

void	printTypes(const std::string str);
bool	isChar(const std::string str);
bool	isInt(const std::string str);
bool	isFloat(const std::string str);

#endif