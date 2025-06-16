/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:26:59 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:04:42 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"


/**
 * @brief	Ice class representing an ice materia in the game.
 * 
 * This class inherits from AMateria and implements the clone and use methods
 * specific to the Ice materia.
 */
class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &origin);
		Ice					&operator=(Ice const &other);
		virtual ~Ice();

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
