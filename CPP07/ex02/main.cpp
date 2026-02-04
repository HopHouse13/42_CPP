/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:39:36 by pbret             #+#    #+#             */
/*   Updated: 2026/02/04 20:08:25 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	std::cout << "--- Suject main ---" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	
	std::cout	<< "--- My main ---" << std::endl;
	Array<int>	ArrayInt(10);

	for (int i = 0; i < 10; i++)
		/*ArrayInt.setArray(i, (i*2));*/ ArrayInt[i] = (i*2);
	for (int i = 0; i < 10; i++)
		std::cout << "[" << i <<"] " << ArrayInt[i] << std::endl;

	std::string tab[] = {"Fallout" , "Breaking Bad", "Stars Wars", "anticonstitutionnellement", "quarante deux"};
	Array<std::string> ArrayChar(5);
	
	for (int i = 0; i < 5; i++)
		ArrayChar.setArray(tab[i], i);
	for (int i = 0; i < 5; i++)
		std::cout << "[" << i <<"] " << ArrayChar[i] << std::endl;
	return (0);
}