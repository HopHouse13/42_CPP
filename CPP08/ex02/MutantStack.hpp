/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:34:37 by pbret             #+#    #+#             */
/*   Updated: 2026/02/20 18:51:08 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include <iomanip>

# include <deque>
# include <stack>
# include <list>
# include <vector>

template< typename T, typename Container = std::deque<T> > // La class heritee "MutantStack" doit avoir les memes parametres que la class de base (stack): UN TYPE, UN CONTAINER SOUS-JACENT 
class MutantStack : public std::stack<T, Container> // "Container" est le conteneur sous-jacent avec qui stack va interagir
{
	public:

		typedef typename Container::iterator		iterator; // 
		typedef typename Container::const_iterator	const_iterator;

		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const & copy);
		MutantStack const & operator=(MutantStack const & rhs);

		typename MutantStack<T, Container>::iterator		begin();
		typename MutantStack<T, Container>::iterator		end();
		typename MutantStack<T, Container>::const_iterator	begin() const;
		typename MutantStack<T, Container>::const_iterator	end() const;
};

#include "MutantStack.tpp" // car c'est une class template et le compilateur a besoin d'avoir l'impelentation pour pouvoir instancier les template.

#endif