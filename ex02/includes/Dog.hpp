/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:17:43 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 17:10:21 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

/**
 * @brief	The Dog class represents a specific type of animal, inheriting from AAnimal.
 * 			It overrides the makeSound method to provide a dog-specific sound.
 */
class Dog : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(Dog const &origin);
		Dog				&operator=(Dog const &other);
		virtual ~Dog();

		virtual void	makeSound() const;
		Brain			*getBrain() const;
};

#endif
