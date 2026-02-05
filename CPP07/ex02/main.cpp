/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:39:36 by pbret             #+#    #+#             */
/*   Updated: 2026/02/05 15:02:24 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	//std::cout << "--- Suject main ---" << std::endl;
	//Array<int> numbers(MAX_VAL);
	//int* mirror = new int[MAX_VAL];
	//srand(time(NULL));
	//for (int i = 0; i < MAX_VAL; i++)
	//{
	//	const int value = rand();
	//	numbers[i] = value;
	//	mirror[i] = value;
	//}
	////SCOPE
	//{
	//	Array<int> tmp = numbers;
	//	Array<int> test(tmp);
	//}

	//for (int i = 0; i < MAX_VAL; i++)
	//{
	//	if (mirror[i] != numbers[i])
	//	{
	//		std::cerr << "didn't save the same value!!" << std::endl;
	//		return 1;
	//	}
	//}
	//try
	//{
	//	numbers[-2] = 0;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
	//try
	//{
	//	numbers[MAX_VAL] = 0;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}

	//for (int i = 0; i < MAX_VAL; i++)
	//{
	//	numbers[i] = rand();
	//}
	//delete [] mirror;//
	{
		std::cout << std::endl << "/// CHAR'S TABLEAU ///" << std::endl;
		
		std::string tab[] = {"Fallout" , "Breaking Bad", "Stars Wars", "anticonstitutionnellement", "quarante deux"};
		Array<std::string> ArrayChar(5);
		unsigned int	size = ArrayChar.size();
		
		for (unsigned int i = 0; i < size; i++)
			ArrayChar.setArray(tab[i], i); // "setter" pour le tableau, j'ai pas compris toute suite l'utilite de l'operateur de surcharge []
		
		for (unsigned int i = 0; i < 5; i++)
			std::cout << "[" << i <<"] " << ArrayChar[i] << std::endl;
	}
	{
		std::cout << std::endl << "/// INT'S TABLEAU ///" << std::endl;
		
		Array<int>	ArrayInt(10);
		unsigned int	size = ArrayInt.size();
		
		for (unsigned int i = 0; i < size; i++)
			ArrayInt[i] = (i*2); // operateur de surcharge []
		
		for (unsigned int i = 0; i < 10; i++)
			std::cout << "[" << i <<"] " << ArrayInt[i] << std::endl;
	}
	{
		std::cout << std::endl << "/// DOUBLE'S TABLEAU ///" << std::endl;

		Array<double>	ArrayDouble(3);
		unsigned int	size = ArrayDouble.size();
		
		ArrayDouble[0] = 4.242;
		ArrayDouble[1] = 42.42;
		ArrayDouble[2] = 424.2;
		
		Array<double> const  &	refConst = ArrayDouble; // init. une ref const pour poouvoir utiliser l'operateur de surcharge [] const
		
		for (unsigned int i = 0; i < size; i++)
			std::cout << "[" << i <<"] " << refConst[i] << std::endl;
	}
	return (0);
}