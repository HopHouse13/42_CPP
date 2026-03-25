/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:29 by pbret             #+#    #+#             */
/*   Updated: 2026/03/25 12:27:14 by pbret            ###   ########.fr       */
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
	
		int 				handleSortDeque();

	private:
		void	handleOutsidePairs(size_t sizePack);
		void	handleSwap(size_t sizePack);
		void	swap(size_t comparePack, size_t position);
		void	recursion();
		void	labeling(size_t sizePack);
		void	pushPendToMain();

		class Elem
		{
			public:
				Elem();
				~Elem();
				Elem(Elem const & copy);
				Elem const &		operator=(Elem const & rhs);

				std::deque<int> const &	getSequence() const;
				void					setSequence(int value);
				bool const &			getIdG() const;
				void					setIdG(bool idG);
				size_t const &			getIdV() const;
				void					setIdV(size_t idV);

				
				
			private:
				std::deque<int>	_sequence;
				bool			_idG; // a -> true ; b -> false
				size_t			_idV;
		};

		std::deque<int>		_main;
		std::deque<int>		_pend;
		std::deque<Elem>	_labels;
		int					_nbElem;
		int					_depthMax;
		int					_depth;

};

std::ostream& operator<<(std::ostream& os, std::deque<int> const & list);

#endif