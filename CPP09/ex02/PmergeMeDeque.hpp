/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:29 by pbret             #+#    #+#             */
/*   Updated: 2026/03/23 14:55:39 by pbret            ###   ########.fr       */
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
		void	handleOutsidePairs();
		void	handleSwap();
		void	swap(size_t sizePack, size_t position);
		void	recursion();
		void	pushPendToMain();


		std::deque<int>	_main;
		std::deque<int>	_pend;
		int				_nbElem;
		int				_depthMax;
		int				_depth;

};

std::ostream& operator<<(std::ostream& os, std::deque<int> const& d);

#endif