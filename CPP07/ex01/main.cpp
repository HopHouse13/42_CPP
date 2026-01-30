/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:06 by pbret             #+#    #+#             */
/*   Updated: 2026/01/30 18:59:49 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int main( void ) 
{
	std::string	array[4] = {"BoOnJouR", "j'aDORe", "42 !", "zoo est le roi de la Galaxie"};

	iter(array, 4, modify);
	return 0;
}
