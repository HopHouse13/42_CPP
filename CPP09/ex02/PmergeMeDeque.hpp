/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:29 by pbret             #+#    #+#             */
/*   Updated: 2026/04/06 14:34:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "./PmergeMeCommon.hpp"

class ElemD
{
	public:
		ElemD();
		~ElemD();
		ElemD(ElemD const & copy);
		ElemD const &		operator=(ElemD const & rhs);

		std::deque<int> const &	getSequence() const;
		void					setSequence(int value);
		char const &			getIdL() const;
		void					setIdL(char IdL);
		size_t const &			getIdV() const;
		void					setIdV(size_t idV);
		int						getLastValue() const;
		
		
	private:
		std::deque<int>	_sequence;
		char			_IdL;
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
		void	RangesJacob(int idxJ,int *idxP, int *idxM);
		void	recalculateRange(int *idxP, int *idxM);

		void	insertion();

		std::deque<int>					_main;
		std::deque<int>					_pend;
		std::deque<ElemD>				_labels;
		std::deque<ElemD>				_mainLabeled;
		std::deque<ElemD>				_pendLabeled;
		int								_nbElem;
		int								_depthMax;
		int								_depth;
		std::deque<unsigned long long>	_suitJacob;

};

std::ostream& operator<<(std::ostream& os, std::deque<int> const & list);
std::ostream& operator<<(std::ostream& os, std::deque<ElemD> const & list);


#endif