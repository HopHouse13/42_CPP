/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:32:29 by pbret             #+#    #+#             */
/*   Updated: 2026/01/24 15:36:22 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

#include "./Data.class.hpp"

#include <iomanip> // setw
#include <iostream> // display
#include <stdint.h> // version C de la lib car <stdint> a ete rajoute a partir de c++11

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
		
	private:
		Serializer();
		Serializer(const Serializer& rhs);
		Serializer&			operator=(const Serializer& rhs);
		~Serializer();
};

#endif