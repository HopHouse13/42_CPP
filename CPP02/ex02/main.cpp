/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:23:40 by pbret             #+#    #+#             */
/*   Updated: 2025/11/27 19:13:56 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// epsilon

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "--Main perso--" << std::endl;

	Fixed	c(10.5f);
	Fixed	d(5);

	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << std::endl << "--opérateurs de arithmétiques--" << std::endl;
	std::cout << (c + d) << std::endl;
	std::cout << (c - d) << std::endl;
	std::cout << (c * d) << std::endl;
	std::cout << (c / d) << std::endl;

	std::cout << std::endl << "--opérateurs d’incrémentation--" << std::endl;
	std::cout << c << std::endl;
	std::cout << ++c << "\t<-pre-incrementation" << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << "\t<-post-incrementation" << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << "\t<-post-decrementation" << std::endl;
	std::cout << c << std::endl;
	std::cout << --c << "\t<-pre-decrementation" << std::endl;
	std::cout << c << std::endl;

	std::cout << std::endl << "--opérateur de comparaison--" << std::endl;
	const Fixed	e(42.5f);
	const Fixed	f(43);
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << Fixed::min(e, f) << std::endl;
	std::cout << Fixed::max(e, f) << std::endl;

	std::cout << "[1]" << (c < d) << std::endl;
	std::cout << "[2]" << (c <= d) << std::endl;
	std::cout << "[3]" << (c >= d) << std::endl;
	std::cout << "[4]" << (c > d) << std::endl;
	std::cout << "[5]" << (c == d) << std::endl;
	std::cout << "[6]" << (c != d) << std::endl;

return (0);
}

