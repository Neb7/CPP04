/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:59:20 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 16:58:00 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

/**
 * @brief	The WrongAnimal class serves as a base class for all wrong animal types.
 * 			It is used to demonstrate polymorphism with wrong animals.
 */
class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &origin);
		WrongAnimal	&operator=(WrongAnimal const &other);
		virtual ~WrongAnimal();

		void		makeSound() const;
		std::string	getType() const;
};

#endif
