/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:29 by pbret             #+#    #+#             */
/*   Updated: 2026/04/05 12:47:57 by pab              ###   ########.fr       */
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
				int						getLastValue() const;
				
				
			private:
				std::deque<int>	_sequence;
				char			_IdL; // a -> true ; b -> false
				size_t			_idV;
		};

class SortDeque
{
	public:
		SortDeque();
		SortDeque(char **raw, int nbElem, int depth, std::deque<unsigned long long> suitJ);
		~SortDeque();
		SortDeque(SortDeque const & copy);
		SortDeque const  &	operator=(SortDeque const & rhs);
	
		int 				handleSortDeque();

	private:

		void	isolateOrphanValuesPair(size_t sizePack);
		void	isolateOrphanValuesElem(size_t sizePack);
		void	pushPendToMain();
		void	handleSwap(size_t sizePack);
		void	swap(size_t comparePack, size_t position);
		void	recursion();
		void	labeling(size_t sizePack);
		void	distribution();
		//bool	startPendL(std::deque<Elem>::iterator & it_pendL, std::deque<unsigned long long>::iterator & it_suitJ);
		//bool	startMainL(std::deque<Elem>::iterator & it_mainL, std::deque<unsigned long long>::iterator & it_suitJ);
		int		borderPendL(unsigned long long valueJ);
		int		borderMainL(unsigned long long valueJ);

		void	insertion();

		std::deque<int>					_main;
		std::deque<int>					_pend;
		std::deque<Elem>				_labels;
		std::deque<Elem>				_mainLabeled;
		std::deque<Elem>				_pendLabeled;
		int								_nbElem;
		int								_depthMax;
		int								_depth;
		std::deque<unsigned long long>	_suitJacob;
		unsigned long long				_vJacob;

};

std::ostream& operator<<(std::ostream& os, std::deque<int> const & list);
std::ostream& operator<<(std::ostream& os, std::deque<Elem> const & list);


#endif