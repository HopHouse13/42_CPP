/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:52:13 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 15:28:36 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout	<< "DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "INFO" << std::endl;
	
}

void	Harl::warning(void)
{
		std::cout	<< "WARNING" << std::endl;
}

void	Harl::error(void)
{
		std::cout	<< "ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ft[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (level == lvl[i])
		{
			(this->*ft[i])();
			break ;
		}
		if (i == 3)
			std::cout << "level is invalid" << std::endl;
	}
}
