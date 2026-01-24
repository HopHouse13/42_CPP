/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:55:45 by pbret             #+#    #+#             */
/*   Updated: 2026/01/24 15:10:47 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Data.class.hpp"

Data::Data() : _value(42), _character('Z')
{
	//std::cout << "Default constructor Data called" << std::endl;
}

Data::Data(const Data& rhs) : _value(rhs._value), _character(rhs._character)
{
	//std::cout << "Copy constructor Data called" << std::endl;
}

Data&	Data::operator=(const Data& rhs)
{
	//std::cout << "Assignment operator Data called" << std::endl;
	if (this != &rhs)
	{
		this->_value = rhs._value;
		this->_character = rhs._character;
	}
	return (*this);
}

Data::~Data()
{
	//std::cout << "Destructor Data called" << std::endl;
}

int	Data::getValue() const
{
	return (this->_value);
}

char	Data::getChar() const
{
	return (this->_character);
}
