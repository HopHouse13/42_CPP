/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:24:33 by pbret             #+#    #+#             */
/*   Updated: 2025/11/24 17:41:43 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawNb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & copy)
{
	std::cout << "copy constructor called" << std::endl;
	*this = copy; // utilisation de l'operateur de surcharge '='.
}

Fixed & Fixed::operator=(const Fixed & rhs)
{
	if (this != &rhs)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_rawNb = rhs.getRawBits(); // utilisation du getteur pour affecter la valeur _rawNb de l'instance "rhs" (retour de rhs.getRawBits) avec l'operateur de surcharge '=' a l'instance courante.
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRwBits member function called" << std::endl;
	return(this->_rawNb);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawNb = raw;
}
