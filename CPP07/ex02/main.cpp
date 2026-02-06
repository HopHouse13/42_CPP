/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:39:36 by pbret             #+#    #+#             */
/*   Updated: 2026/02/06 16:01:30 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	{
		std::cout << std::endl << "/// CHAR'S TABLEAU ///" << std::endl;
		try
		{
			std::string tab[] = {"Fallout" , "Breaking Bad", "Stars Wars", "anticonstitutionnellement", "quarante deux"};
			Array<std::string> ArrayChar(5);
			unsigned int	size = ArrayChar.size();

			for (unsigned int i = 0; i < size; i++)
				ArrayChar.setArray(tab[i], i); // "setter" pour le tableau, j'ai pas compris toute suite l'utilite de l'operateur de surcharge []

			for (unsigned int i = 0; i < 5; i++)
				std::cout << "[" << i << "] " << ArrayChar[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "/// INT'S TABLEAU ///" << std::endl;
		try
		{
			Array<int>	ArrayInt(10);
			unsigned int	size = ArrayInt.size();

			for (unsigned int i = 0; i < size; i++)
				ArrayInt[i] = (i*2);

			for (unsigned int i = 0; i < 10; i++)
				std::cout << "[" << i << "] " << ArrayInt[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "/// OPERATOR CONST [] ///" << std::endl;
		try
		{
			Array<double>	ArrayDouble(3);
			unsigned int	size = ArrayDouble.size();

			ArrayDouble[0] = 4.242;
			ArrayDouble[1] = 42.42;
			ArrayDouble[2] = 424.2;

			Array<double> const  &	refConst = ArrayDouble; // init. une ref const pour pouvoir utiliser l'operateur de surcharge [] const

			for (unsigned int i = 0; i < size; i++)
				std::cout << "[" << i << "] " << refConst[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "/// DUP ///" << std::endl;
		try
		{
			Array<float>	ArrayFloat(1);

			ArrayFloat[0] = 1.1f;
			std::cout << "ArrayFloat[0]: " << ArrayFloat[0] << std::endl;

			Array<float>	ArrayFloatDup(ArrayFloat);
			std::cout << "ArrayFloatDup[0]: " << ArrayFloatDup[0] << std::endl;

			std::cout << std::endl << "/// ASSIGNMENT ///" << std::endl;

			Array<float>	ArrayFloatAssig(2);

			ArrayFloatAssig[0] = 9.9f;
			ArrayFloatAssig[1] = 8.8f;
			std::cout << "ArrayFloatAssig[0]: " << ArrayFloatAssig[0] << std::endl;
			std::cout << "ArrayFloatAssig[1]: " << ArrayFloatAssig[1] << std::endl;

			ArrayFloatAssig = ArrayFloat;
			std::cout << "ArrayFloatAssig[0]: " << ArrayFloatAssig[0] << std::endl;

			ArrayFloatAssig[1] = 0.000000f;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}