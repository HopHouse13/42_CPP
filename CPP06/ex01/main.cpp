/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:47:40 by pbret             #+#    #+#             */
/*   Updated: 2026/01/24 16:15:40 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"

int	main()
{
	std::cout << "--- ORIGINE ---" << std::endl << std::endl;
	Data*		ptrDataOrigine = new Data();

	std::cout	<< std::left <<std::setw(12) << "adress ptr: " << ptrDataOrigine << std::endl
				<< std::left <<std::setw(12) <<"_value:" << ptrDataOrigine->getValue() << std::endl
				<< std::left <<std::setw(12) <<"_character:" << ptrDataOrigine->getChar() << std::endl;

	uintptr_t	ptrDataSerial = 0;

	ptrDataSerial = Serializer::serialize(ptrDataOrigine);

	std::cout	<< std::endl << "--- SERIALIZER ---" << std::endl << std::endl
				<< std::left <<std::setw(12) << "ptr serial: " << ptrDataSerial << std::endl;

	//Data*		ptrDataFinal = NULL;

	Data*		ptrDataFinal = Serializer::deserialize(ptrDataSerial);
	
	std::cout	<< std::endl << "--- FINAL ---" << std::endl << std::endl
				<< std::left <<std::setw(12) << "adress ptr: " << ptrDataFinal << std::endl
				<< std::left <<std::setw(12) << "_value:" << ptrDataFinal->getValue() << std::endl
				<< std::left <<std::setw(12) << "_character:" << ptrDataFinal->getChar() << std::endl;

	delete (ptrDataOrigine);
	return (0);
}