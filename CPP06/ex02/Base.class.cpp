/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:55:50 by pbret             #+#    #+#             */
/*   Updated: 2026/01/24 18:25:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Base.class.hpp"

Base::~Base()
{
	std::cout << "Destrucor Base called" << std::endl;
}

Base*	generate()
{
	int	idx = 0;

	idx = (std::rand() % 3);
	switch (idx)
	{
	case 1:

		break;

	case 2:

		break;

	case 3:

		break;

	default:
		break;
	}
}







void	identify(Base* p);
void	identify(Base& p);