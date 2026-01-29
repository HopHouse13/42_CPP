/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:08:06 by pbret             #+#    #+#             */
/*   Updated: 2026/01/29 19:12:14 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T & a, T & b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T	min(T a, T b)
{
	return ((b <= a) ? b : a); // je tente le ternaire, c'est rigolo
}

template<typename T>
T	max(T a, T b)
{
	return ((b >= a ? b : a));
}
#endif