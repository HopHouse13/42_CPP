/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:24:33 by pbret             #+#    #+#             */
/*   Updated: 2025/11/25 19:10:20 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawNb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)										// converi un entier en virgule fixe.
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawNb = (value << this->_bits);
}

Fixed::Fixed(const float value)										// converi un nombre decimale en virgule fixe.
{
	std::cout << "Float constructor called" << std::endl;
	_rawNb = static_cast<int>(roundf(value * (1 << this->_bits)));	// cast du retour de 'roundf' (float arrondi). 'roundf' prend le produit du float d'entree et 1 avec un decalage de '_bits'(8) bits -> 1*2^8 = 256
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "copy constructor called" << std::endl;
	*this = copy;													// utilisation de l'operateur de surcharge '='.
}

Fixed& Fixed::operator=(const Fixed& rhs)							// opérateur d'affectation : copie un Fixed dans l'instance courante. prend un objet de type Fixed en REF
{
	if (this != &rhs)												// protection contre l'auto-affectation ex : a = a
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_rawNb = rhs._rawNb;									// copie la valeur '_rawNb' du Fixed source 'rhs' dans l'attribut _rawNb de l'objet courant
	}
	return (*this);													// retourne l'objet courant pour permettre ca : a = b = c
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

int	Fixed::toInt(void) const
{
	return (this->_rawNb >> this->_bits);
}

float	Fixed::toFloat(void) const									// toFloat() divise le nombre fixe _rawNb par (1 << this->_bits) pour obtenir la valeur flottante.
{
	return (static_cast<float>(this->_rawNb) / (1 << this->_bits));	// besoin de cast _rawNb en float pour retourner forcement un float et pas un int si _rawNb etait un int.
}
std::ostream&	operator<<(std::ostream& os, Fixed const& rhs)		// os -> flux de sorti en REF; rhs l’objet Fixed à afficher, passé par référence constante.
{
	os << rhs.toFloat();											// envoie dans le flux la resultante de toFloat qui converit _rawNb en float
	return (os); 													// retourne l'objet flux
}
