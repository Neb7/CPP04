/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:09:11 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:04:32 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

/**
 * @brief	Cure class representing a healing materia in the game.
 * 
 * This class inherits from AMateria and implements the clone and use methods
 * specific to the Cure materia.
 */
class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &origin);
		Cure				&operator=(Cure const &other);
		virtual ~Cure();

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
