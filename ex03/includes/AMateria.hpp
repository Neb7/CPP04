/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:42:27 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:04:16 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

// Forward declaration to avoid circular dependency
class ICharacter;

/**
 * @brief	Abstract class representing a Materia in the game.
 * 
 * This class serves as a base for all types of Materia, providing
 * common functionality and an interface for derived classes.
 */
class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &origin);
		AMateria			&operator=(AMateria const &other);
		virtual ~AMateria();

		std::string const	&getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target) = 0;
};

#endif
