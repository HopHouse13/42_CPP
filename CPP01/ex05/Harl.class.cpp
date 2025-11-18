/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:52:13 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 15:29:44 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

void	Harl::debug(void)
{
	std::cout	<< "DEBUG:I love having extra bacon for my 7XL-double-cheese-triple"
				<< "-pickle-special-etchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "INFO:I cannot believe adding extra bacon costs more money."
				<< "You didn’t put enough bacon in my burger ! If you did,"
				<< "I wouldn’t be asking for more !" << std::endl;
	
}

void	Harl::warning(void)
{
		std::cout	<< "WARNING:I think I deserve to have some extra bacon for free."
					<< "I’ve been coming for years whereas you started working"
					<< "here since last month." << std::endl;
}

void	Harl::error(void)
{
		std::cout	<< "ERROR:This is unacceptable ! I want to speak to the manager now."
					<< std::endl;
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
