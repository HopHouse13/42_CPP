/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:34:44 by pbret             #+#    #+#             */
/*   Updated: 2026/02/20 17:56:44 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack.hpp"

		template<typename T, typename Container>
		MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() //  Notre constructeur appelle le constructeur de stack, et comme c'est un constructeur template, on lui spécifie les types transmis.
		{
			std::cout << "Default Constructor called" << std::endl;
		}

		template<typename T, typename Container>
		MutantStack<T, Container>::~MutantStack()
		{
			std::cout << "Destructor called" << std::endl;
		}
		template<typename T, typename Container>
		MutantStack<T, Container>::MutantStack(MutantStack const & copy) : std::stack<T, Container>(copy)
		{
			std::cout << "copy constructor called" << std::endl;
		}

		template<typename T, typename Container>
		MutantStack<T, Container> const & MutantStack<T, Container>::operator=(MutantStack const & rhs)
		{
			if (this != &rhs)
				std::stack<T, Container>::operator=(rhs);
			return (*this);
		}
		
		template<typename T, typename Container>
		typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
		{
			return (this->c.begin());
		}
		
		template<typename T, typename Container>
		typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
		{
			return (this->c.end());
		}

		template<typename T, typename Container>
		typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin() const
		{
			return (this->c.begin());
		}
		
		template<typename T, typename Container>
		typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end() const
		{
			return (this->c.end());
		}	
