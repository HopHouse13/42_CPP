/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:38:59 by pbret             #+#    #+#             */
/*   Updated: 2026/02/04 19:40:40 by pab              ###   ########.fr       */
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
		Array &	operator=(Array const & rhs);
		T &		operator[](unsigned int index);	
		~Array();

		unsigned int const &	size() const;
		void		setArray(T value, unsigned int index);
		void		setArray(T value, unsigned int index) const;
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