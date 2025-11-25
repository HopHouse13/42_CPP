/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:23:40 by pbret             #+#    #+#             */
/*   Updated: 2025/11/25 18:32:26 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}

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
