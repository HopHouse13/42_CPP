/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:42:56 by pbret             #+#    #+#             */
/*   Updated: 2026/01/24 15:11:06 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.class.hpp"

Serializer::Serializer()
{
	//std::cout << "Default constructeur Serializer called" << std::endl;
}

Serializer::Serializer(const Serializer& rhs)
{
	(void)rhs;
	//std::cout << "Copy constructeur Serializer called" << std::endl;
}

Serializer&	Serializer::operator=(const Serializer& rhs)
{
	(void)rhs;
	//std::cout << "Assignment operator overlead Serializer called" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	//std::cout << "Destructor Serializer called" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
