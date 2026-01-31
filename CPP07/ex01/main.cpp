/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:09:06 by pbret             #+#    #+#             */
/*   Updated: 2026/01/31 17:34:40 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int main( void ) 
{
	/// CHAR ARRAY ///
	std::string	arrayChar[4] = {"boonJour", "j'aDore quarante deuX", "4 + 2 = 42", "denver a une paire de lunette de follie"};

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
