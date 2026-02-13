/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:41:44 by pbret             #+#    #+#             */
/*   Updated: 2026/02/13 17:14:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./easyfind.hpp"

//std::list<int>

//std::vector<int>::iterator
template<typename T>
typename T::const_iterator	easyfind(T const & contener, int const & value)
{
	typename T::const_iterator	it = std::find(contener.begin(), contener.end(), value);

	if(it != contener.end())
	{
		std::cout << "One occurrence was detected with the value: " << value << " at element " << std::distance(contener.begin(), it) << std::endl;
		return (it);
	}
	else
		throw std::out_of_range("No occurrences were detected");
}