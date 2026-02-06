/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:38:59 by pbret             #+#    #+#             */
/*   Updated: 2026/02/06 15:21:27 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & copy);
		Array &					operator=(Array const & rhs);
		~Array();

		T &						operator[](unsigned int index);
		T const &				operator[](unsigned int index) const;
		unsigned int const &	size() const;
		void					setArray(T value, unsigned int index);

		class Index : public std::exception
		{
			public:

			virtual const char * what() const throw();
		};

	private:
		unsigned int	_size;
		T *				_array;
};

#include "Array.tpp"

#endif