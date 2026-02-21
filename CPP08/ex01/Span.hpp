/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:28 by pbret             #+#    #+#             */
/*   Updated: 2026/02/21 15:54:23 by pbret            ###   ########.fr       */
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
		int							shortestSpan() const;
		int							longestSpan() const;
		void						generateList(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);
		std::vector<int> const &	getList() const; // non demande par le sujet -> afficher les containers
		
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
		unsigned int		_n; // nb max d'elements dans le container
		std::vector<int>	_listNumbers; // le container en question
};

#endif