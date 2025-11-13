/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/13 16:14:52 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string	str	= "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "L’adresse de str: " << &str << std::endl;
	std::cout << "L’adresse stockée dans stringPTR: " << stringPTR << std::endl;
	std::cout << "L’adresse stockée dans stringREF: " << &stringREF << std::endl;

	std::cout << "La valeur de str: " << str << std::endl;
	std::cout << "La valeur pointée par stringPTR: " << *stringPTR << std::endl;
	std::cout << "La valeur pointée par stringREF: " << stringREF << std::endl;
	return (0);
}
	