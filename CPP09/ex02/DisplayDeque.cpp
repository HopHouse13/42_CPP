/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:55:16 by pbret             #+#    #+#             */
/*   Updated: 2026/04/06 14:35:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

std::ostream& operator<<(std::ostream& os, std::deque<int> const & list) // operateur de surcharge sur << et avec le flux std::cout
{
	for (size_t i = 0; i < list.size(); i++)
		os << (i ? " " : "") << list.at(i);
	return (os);
}

std::ostream& operator<<(std::ostream& os, std::deque<ElemD> const & list)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (i > 0)
			os << " * ";
		os << list.at(i).getIdL() << list.at(i).getIdV() << "[" << list.at(i).getSequence() << "]";
	}
	return (os);
}
