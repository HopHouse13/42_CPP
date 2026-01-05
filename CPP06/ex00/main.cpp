/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:30:57 by pbret             #+#    #+#             */
/*   Updated: 2026/01/05 17:38:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int	main()
{
	ScalarConverter bon;
	ScalarConverter bonjour(bon);
	ScalarConverter bonsoir;

	bonsoir = bonjour;
	
	return (0);
}