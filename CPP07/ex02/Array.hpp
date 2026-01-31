/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:38:59 by pbret             #+#    #+#             */
/*   Updated: 2026/01/31 17:18:12 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & rhs);
		Array &	operator=(Array const & rhs);
		~Array();
		
	private:
		T *	_array;
};



#endif