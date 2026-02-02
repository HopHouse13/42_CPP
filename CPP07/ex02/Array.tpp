/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:39:23 by pbret             #+#    #+#             */
/*   Updated: 2026/02/02 14:29:06 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Array.hpp"

template<typename T>
Array<T>::Array() : _size(0), _array(new T[_size])
{
	std::cout << "Default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(Array<T> rhs)