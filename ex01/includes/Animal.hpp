/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:07:50 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 16:51:54 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/**
 * @brief	The Animal class serves as a base class for all animal types.
 */
class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(Animal const &origin);
		Animal	&operator=(Animal const &other);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif
