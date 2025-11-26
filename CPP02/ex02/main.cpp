/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:23:40 by pbret             #+#    #+#             */
/*   Updated: 2025/11/26 18:23:57 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main (void)
{
	Fixed	paul(5);
	Fixed	alix(6);
	Fixed	max(20);

	std::cout << "PAUL: " << paul.toInt() << std::endl;
	std::cout << "ALIX: " << alix.toInt() << std::endl;
	std::cout << "MAX: " << max.toInt() << std::endl;
	
	std::cout << "PAUL > MAX: " << (paul > max) << std::endl;
	std::cout << "PAUL < MAX: " << (paul < max) << std::endl;
	std::cout << "PAUL >= ALIX: " << (paul >= alix) << std::endl;
	std::cout << "PAUL <= ALIX: " << (paul <= alix) << std::endl;
	std::cout << "PAUL == ALIX: " << (paul == alix) << std::endl;
	std::cout << "PAUL != ALIX: " << (paul != alix) << std::endl;

	std::cout << "PAUL: " << paul << std::endl;
	paul++;
	std::cout << "PAUL: " << paul << std::endl;
	paul--;
	std::cout << "PAUL: " << paul << std::endl;
	return (0);
}
//int main( void ) {
//Fixed a;
//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//std::cout << a << std::endl;
//std::cout << ++a << std::endl;
//std::cout << a << std::endl;
//std::cout << a++ << std::endl;
//std::cout << a << std::endl;
//std::cout << b << std::endl;
//std::cout << Fixed::max( a, b ) << std::endl;
//return (0);
//}

//int main( void )
//{
//	Fixed	peter(42);
//	std::cout << "int >> virgule fixe:" << peter.getRawBits() << std::endl;
//	Fixed	alix(42.5f);
//	std::cout << "float >> virgule fixe:" << alix.getRawBits() << std::endl;
//	Fixed	paul(22);
//	std::cout << "paul is " << paul.toInt() << " as integer" << std::endl;
//	Fixed	ma(42.42f);
//	std::cout << "ma is " << ma.toFloat() << " as float" << std::endl;

//	Fixed	c(0.078125f);
//	Fixed	d(10.1016f);
//	Fixed	e;
//	Fixed	f;
//	std::cout << c << std::endl;
//	std::cout << d << std::endl;

//	//e = c * d;
//	//f = d / c;
//	std::cout << e << std::endl;
//	std::cout << f << std::endl;
	
//}
