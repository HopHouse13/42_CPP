/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:30:28 by pbret             #+#    #+#             */
/*   Updated: 2026/02/16 19:33:30 by pbret            ###   ########.fr       */
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

		void	addNumber(unsigned int v); 
	private:
		unsigned int	_n;
};

#endif