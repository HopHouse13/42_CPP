/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:39:23 by pbret             #+#    #+#             */
/*   Updated: 2026/02/04 19:40:30 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Array.hpp"

template<typename T>
Array<T>::Array() : _size(0), _array(new T[this->_size])
{
	std::cout << "Default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[this->_size])
{
	std::cout << "Constructor with arguments called" << std::endl;
}

template<typename T>
Array<T>::Array(Array const & copy) : _size(copy._size), _array(new T[this->_size])  // pourquoi on identifie pas le type <T> de copy comment pour l'instance que nous sommes entrain d'instancier?
{
	std::cout << "Copy constructor called" << std::endl;
	for(unsigned int i = 0; i < copy._size; i++)
		this->_array[i] = copy._array[i];
}

template<typename T>
Array<T> &	Array<T>::operator=(Array const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		if (this->_array)
			delete [] this->_array;
		this->_size = rhs._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	//if (this->_array)
		delete [] this->_array;
}

template<typename T>
T &		Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Index();
	return (this->_array[index]);
}

template<typename T>
char const * Array<T>::Index::what() const throw()
{
	return ("Error: index out of bounds	");
}

template<typename T>
unsigned int const &	Array<T>::size() const
{
	return(this->_size);
}

template<typename T>
void	Array<T>::setArray(T value, unsigned int index)
{
	if (index < this->_size)
		this->_array[index] = value; // est ce que j'utlise l'operateur de surcharge =? PAUL AIDE MOI
}

template<typename T>
void	Array<T>::setArray(T const value, unsigned int const index) const
{
	if (index < this->_size)
		this->_array[index] = value;
}
