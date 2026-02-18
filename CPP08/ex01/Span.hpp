/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:28 by pbret             #+#    #+#             */
/*   Updated: 2026/02/18 16:47:36 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	public:
		Span();
		~Span();
		Span(unsigned int n);
		Span(Span const & copy);
		Span &	operator=(Span const & rhs);

		void						addNumber(unsigned int v);
		int	shortestSpan() const;
		//int	longestSpan() const; // const inutile vu qu'il y a pas de param a modifier sauf si ca fonctionne aussi pour les variables privees
		std::vector<int> const &	getList() const;
		
		class SpanFull : public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};

		class NeedTwoElem : public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};
		
	private:
		unsigned int		_n;
		std::vector<int>	_listNumbers;
};

#endif