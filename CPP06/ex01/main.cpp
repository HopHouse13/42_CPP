/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:47:40 by pbret             #+#    #+#             */
/*   Updated: 2026/01/23 18:26:59 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.class.hpp"
#include "Serializer.class.hpp"

int	main()
{
	Data*	data = new Data();
	
	std::cout	<< "value adress ptr: " << &data << std::endl
				<< "value _value:" << data->getValue() << std::endl
				<< "value _character:" << data->getChar() << std::endl;
	
				
	delete (data);
	return (0);
}