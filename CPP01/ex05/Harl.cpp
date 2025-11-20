/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:52:13 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 17:19:09 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout	<< "msg DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "msg INFO" << std::endl;
	
}

void	Harl::warning(void)
{
		std::cout	<< "msg WARNING" << std::endl;
}

void	Harl::error(void)
{
		std::cout	<< "msg ERROR" << std::endl;
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
