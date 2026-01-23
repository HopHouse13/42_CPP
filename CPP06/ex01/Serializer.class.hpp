/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:32:29 by pbret             #+#    #+#             */
/*   Updated: 2026/01/23 18:27:36 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

#include "./Data.class.hpp"

#include <iostream>

class Serializer
{
	public:
		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer& rhs);
		Serializer&	operator=(const Serializer& rhs);
		~Serializer();
		
};

#endif