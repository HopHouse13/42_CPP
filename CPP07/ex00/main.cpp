/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:06 by pbret             #+#    #+#             */
/*   Updated: 2026/01/31 17:41:23 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b ); // :: est l'operateur de resolution de portee. dans ce cas la fonction est dans l'espace Global (contratement a "std::" -> namespace std) 
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl; // instanciation explicite du template
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl; // instanciation implicite du template
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
