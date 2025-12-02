/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:24:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 14:04:06 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public :
		Fixed();								// 1) Sinon le compilateur utilise le sien
		Fixed(const int value);					// converit un int en virgule fixe.
		Fixed(const float value);				// converit un float en virgule fixe.
		Fixed(const Fixed &other);				// 3) Copie de la reference other
		Fixed& operator=(const Fixed& rhs);		// 4) que faire si Fixed b = Fixed a
		~Fixed();								// 2) Sinon le compilateur utilise le sien

		int			getRawBits() const;
		void		setRawBits(int const raw);
		int			toInt() const;
		float		toFloat() const;

	private:
		int					_rawNb;				// nombre a virgule 
		int const static	_bits = 8;			// contient la partie decimale en bits (8) (pas sur de tout ca)
};

std::ostream&	operator<<(std::ostream& os, Fixed const& rhs);


#endif 
