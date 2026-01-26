/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:05:35 by pbret             #+#    #+#             */
/*   Updated: 2026/01/26 18:40:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Base.class.hpp"

int	main()
{
	std::srand(static_cast<unsigned int>(time(NULL))); // initiliser la seed du random

	Base*	p = generate();
	Base&	r = *p;

	if (p != NULL)
	{
		identify(p);
		identify(r);
	}
	delete (p);
	return (0);
}