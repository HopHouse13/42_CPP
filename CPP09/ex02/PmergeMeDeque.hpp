/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:29 by pbret             #+#    #+#             */
/*   Updated: 2026/03/29 00:42:18 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>

#include "./PmergeMeCommon.hpp"

	class Elem
		{
			public:
				Elem();
				~Elem();
				Elem(Elem const & copy);
				Elem const &		operator=(Elem const & rhs);

				std::deque<int> const &	getSequence() const;
				void					setSequence(int value);
				char const &			getIdL() const;
				void					setIdL(char IdL);
				size_t const &			getIdV() const;
				void					setIdV(size_t idV);

				
				
			private:
				std::deque<int>	_sequence;
				char			_IdL; // a -> true ; b -> false
				size_t			_idV;
		};

class SortDeque
{
	public:
		SortDeque();
		SortDeque(char **raw, int nbElem, int depth, std::deque<unsigned long long> suitEJ);
		~SortDeque();
		SortDeque(SortDeque const & copy);
		SortDeque const  &	operator=(SortDeque const & rhs);
	
		int 				handleSortDeque();

	private:

		void								pushMainRestToPend(size_t sizePack);
		void								pushPendToMain();
		void								handleSwap(size_t sizePack);
		void								swap(size_t comparePack, size_t position);
		void								recursion();
		void								labeling(size_t sizePack);
		void								distribution();
		std::deque<Elem>::const_iterator	findElemToInsert(std::deque<unsigned long long>::const_iterator & itSuitEJ);
		void								insersion();

		std::deque<int>					_main;
		std::deque<int>					_pend;
		std::deque<Elem>				_labels;
		std::deque<Elem>				_mainLabeled;
		std::deque<Elem>				_pendLabeled;
		int								_nbElem;
		int								_depthMax;
		int								_depth;
		std::deque<unsigned long long>	_suitEJ;

};

std::ostream& operator<<(std::ostream& os, std::deque<int> const & list);

#endif