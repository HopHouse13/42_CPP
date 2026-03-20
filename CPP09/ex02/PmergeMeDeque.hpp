/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:29 by pbret             #+#    #+#             */
/*   Updated: 2026/03/20 19:53:46 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "./PmergeMeCommon.hpp"

# include <deque>

class SortDeque
{
	public:
		SortDeque();
		SortDeque(char **raw, int nbElem, int depth);
		~SortDeque();
		SortDeque(SortDeque const & copy);
		SortDeque const  &	operator=(SortDeque const & rhs);
	
		int handleSortDeque();

	private:
		int		initMain(char **raw, int nbElem);
		void	handleOutsidePairs();

		std::deque<int>	_main;
		std::deque<int>	_pend;
		int				_nbElem;
		int				_depth;

};

#endif