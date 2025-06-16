/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:10:51 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 17:10:13 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

/**
 * @brief	The Cat class represents a specific type of animal, inheriting from AAnimal.
 * 			It overrides the makeSound method to provide a cat-specific sound.
 */
class Cat : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(Cat const &origin);
		Cat				&operator=(Cat const &other);
		virtual ~Cat();

		virtual void	makeSound() const;
		Brain			*getBrain() const;
};

#endif
