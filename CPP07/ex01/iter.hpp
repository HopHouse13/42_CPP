/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:57 by pbret             #+#    #+#             */
/*   Updated: 2026/02/11 14:20:08 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cstdlib>
# include <ctime>
#include <iomanip>

template<typename T, typename F>
void	iter(T *array, size_t len, F function)
{
	size_t	i = 0;

	while (i < len)
		function(array[i++]);
}

void	multiplyByTwo(int & v)
{
		v *= 2;
}

void	upperChar(std::string & s)
{
	for(size_t i = 0; i < s.length(); i++)
	{
		if (i % 2)
			s[i] = std::tolower(s[i]);
		else
			s[i] = std::toupper(s[i]);
	}
}

#endif