/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:57 by pbret             #+#    #+#             */
/*   Updated: 2026/01/30 19:06:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <typeinfo>
# include <climits>

template<typename T, typename F>
void	iter(T & array, size_t len, F function)
{
	size_t	i = 0;

	while (i < len)
		function(array[i++]);
}

template<typename T>
void	modify(T var)
{
	if (typeid(T) == typeid(int))
	{
		std::cout <<"INT\n";
		decrement(*var);
	}
	else if (typeid(T) == typeid(char))
	{
		std::cout <<"char\n";
		upper(*var);
	}
}

int	decrement(int & v)
{
	if (v > INT_MIN)
		v--;
	else
		std::cout << "Error: invalid value" << std::endl;
	return (v);
}

std::string	upper(std::string & c)
{
	for(int i = 0; c[i]; i++)
		std::toupper(c[i]);
	return (c);
}

#endif