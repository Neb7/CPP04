/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:07:50 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/08 16:06:26 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

/**
 * @brief	The AAnimal class serves as an abstract base class for all animal
 * 			types. It cannot be instantiated directly and requires derived
 * 			classes to implement the makeSound method.
 */
class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(AAnimal const &origin);
		AAnimal	&operator=(AAnimal const &other);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif
