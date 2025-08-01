/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erika.class_instance.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:36:38 by pbret             #+#    #+#             */
/*   Updated: 2025/08/01 16:27:35 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Erika.class.hpp"

Erika::Erika(char alix1, int alix2, float alix3, std::alix4) : seb1(alix1), seb2(alix2), seb3(alix3), seb4(alix4)
{
	std::cout << "conctructor called" << std::endl;
	//this->seb4 = "PIKACHU";
	return ;
}

Erika::~Erika(void)
{
	std::cout << "destructor called" << std::endl;
	return ;
}


void	Erika::ft_write(void)
{
	std::cout << this->seb1 << std::endl;
	std::cout << this->seb2 << std::endl;
	std::cout << this->seb3 << std::endl;
	std::cout << this->seb4 << std::endl;
	return ;
}
