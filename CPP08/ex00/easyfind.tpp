/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:41:44 by pbret             #+#    #+#             */
/*   Updated: 2026/02/21 17:09:59 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./easyfind.hpp"

template<typename T>
typename T::const_iterator	easyfind(T const & container, int const & value)
{
	typename T::const_iterator	it = std::find(container.begin(), container.end(), value); // si aucune occurrence, find retour l'iterateur de fin (container.end)

	if(it != container.end())
	{
		std::cout << "One occurrence was found with the value: " << value << " at element " << std::distance(container.begin(), it) << std::endl;
		return (it);
	}
	else
		throw std::out_of_range("No occurrences were found");
}