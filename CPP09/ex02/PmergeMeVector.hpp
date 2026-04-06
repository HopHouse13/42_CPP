/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:40:24 by pbret             #+#    #+#             */
/*   Updated: 2026/04/06 16:30:01 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEVERCTOR_HPP
# define PMERGEMEVERCTOR_HPP

# include "./PmergeMeCommon.hpp"

class ElemV
{
	public:
		ElemV();
		~ElemV();
		ElemV(ElemV const & copy);
		ElemV const &		operator=(ElemV const & rhs);

		std::vector<int> const &	getSequence() const;
		void						setSequence(int value);
		char const &				getIdL() const;
		void						setIdL(char IdL);
		size_t const &				getIdV() const;
		void						setIdV(size_t idV);
		int							getLastValue() const;
		
	private:
		std::vector<int>	_sequence;
		char				_IdL;
		size_t				_idV;
};

class SortVector
{
	public:
		SortVector();
		SortVector(char **raw, int nbElem, int depth, std::deque<unsigned long long> suitJ);
		~SortVector();
		SortVector(SortVector const & copy);
		SortVector const  &	operator=(SortVector const & rhs);
	
		int 				handleSortVector();

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

		std::vector<int>				_main;
		std::vector<int>				_pend;
		std::vector<ElemV>				_labels;
		std::vector<ElemV>				_mainLabeled;
		std::vector<ElemV>				_pendLabeled;
		int								_depthMax;
		int								_depth;
		std::deque<unsigned long long>	_suitJacob;

};

std::ostream& operator<<(std::ostream& os, std::vector<int> const & list);
std::ostream& operator<<(std::ostream& os, std::vector<ElemV> const & list);



#endif