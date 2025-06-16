/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:33:05 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:06:30 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

/**
 * @brief	MateriaSource class representing a source of Materia in the game.
 * 
 * This class implements the IMateriaSource interface and manages a collection
 * of Materia objects. It allows learning new Materia and creating them based
 * on their type.
 */
class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materia[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &origin);
		MateriaSource		&operator=(MateriaSource const &other);
		virtual ~MateriaSource();
		
		AMateria			*getMateria(int idx) const;

		virtual void		learnMateria(AMateria*);
		virtual AMateria	*createMateria(std::string const &type);
};

#endif
