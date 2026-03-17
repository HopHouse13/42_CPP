/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:29 by pbret             #+#    #+#             */
/*   Updated: 2026/03/17 16:56:02 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>

# define SUCCESS 0
# define FAILURE 1

class SortDeque
{
	public:
		SortDeque();
		~SortDeque();
		SortDeque(SortDeque const & copy);
		SortDeque const  &	operator=(SortDeque const & rhs);
	
		int handleSort(char **raw, int ac);

	private:
		int	initList(char **raw, int ac);

		//char**			_raw;
		//int				_ac;
		std::deque<int>	_list;

};

#endif