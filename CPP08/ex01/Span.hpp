/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:28 by pbret             #+#    #+#             */
/*   Updated: 2026/02/17 13:51:14 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(Span const & copy);
		Span &	operator=(Span const & rhs);
		~Span();

		void			addNumber(unsigned int v);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const; // const inutile vu qu'il y a pas de param a modifier sauf si ca fonctionne aussi pour les variables privees

	private:
		unsigned int	_n;
};

#endif