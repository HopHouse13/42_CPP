/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:06 by pbret             #+#    #+#             */
/*   Updated: 2026/02/05 14:48:12 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int main( void ) 
{
	/// CHAR ARRAY ///
	std::string	arrayChar[4] = {"bonjour", "j'adore quarante deux", "4 + 2 = 42", "denver a une paire de lunette de folie"};	

	std::cout << "Orignal:";
	for (int i = 0; i < 4; i++)
		std::cout << " " << arrayChar[i];
	
	iter(arrayChar, 4, upperChar);

	std::cout << std::endl << "Result :";
	for (int i = 0; i < 4; i++)
		std::cout << " " << arrayChar[i];

	/// INT ARRAY ///
	std::srand(time(NULL));

	int	len = (std::rand() % 20);
	int	arrayInt[len];

	for(int i = 0; i < len; i++)
		arrayInt[i] = (std::rand() % 10);
		
	std::cout << std::endl << "Orignal:";
	for (int i = 0; i < len; i++)
		std::cout << std::right << std::setw(3) << arrayInt[i];
	
	iter(arrayInt, len, multiplyByTwo);

	std::cout << std::endl << "Result :";
	for (int i = 0; i < len; i++)
		std::cout << std::right << std::setw(3) << arrayInt[i];
	return (0);
}
