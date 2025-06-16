/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:04:06 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/07 17:04:20 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongCat_HPP
# define WRONGWrongCat_HPP

#include "WrongAnimal.hpp"

/**
 * @brief	The WrongCat class represents a specific type of wrong animal,
 * 			inheriting from WrongAnimal.
 */
class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &origin);
		WrongCat	&operator=(WrongCat const &other);
		virtual ~WrongCat();

		void	makeSound() const;
};

#endif