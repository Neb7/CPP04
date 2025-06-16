/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:38:22 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:14:21 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/**
 * @brief	Default constructor for MateriaSource class.
 */
MateriaSource::MateriaSource()
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
	}
}

/**
 * @brief	Copy constructor for MateriaSource class.
 * 
 * @param	origin The MateriaSource object to copy from.
 */
MateriaSource::MateriaSource(MateriaSource const &origin)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		_materia[i] = (origin._materia[i] != NULL) ? origin._materia[i]->clone() : NULL;
	}
}

/**
 * @brief	Assignment operator for MateriaSource class.
 * 
 * @param	other The MateriaSource object to assign from.
 * @return	Reference to the current MateriaSource object.
 */
MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	int	i;

	if (this != &other)
	{
		for (i = 0; i < 4; i++)
		{
			if (_materia[i] != NULL)
				delete _materia[i];
			_materia[i] = (other._materia[i] != NULL) ? other._materia[i]->clone() : NULL;
		}
	}
	return (*this);
}

/**
 * @brief	Destructor for MateriaSource class.
 */
MateriaSource::~MateriaSource()
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (_materia[i] != NULL)
		{
			delete _materia[i];
			_materia[i] = NULL;
		}
	}
}

/**
 * @brief	Get the materia at a specific index in the MateriaSource's inventory.
 * 
 * @param	idx The index of the materia to retrieve.
 * @return	Pointer to the materia at the specified index, or NULL if invalid.
 */
AMateria		*MateriaSource::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
	{
		return (_materia[idx]);
	}
	return (NULL);
}

/**
 * @brief	Learn a new materia and add it to the MateriaSource's inventory.
 * 
 * @param	m Pointer to the materia to learn.
 */
void			MateriaSource::learnMateria(AMateria *m)
{
	int	i = -1;

	while (++i < 4)
	{
		if (!_materia[i])
		{
			_materia[i] = m;
			break ;
		}
	}
	if (i >= 4)
	{
		std::cout << "You're MateriaSource inventory is full. Can't add "
				  << m->getType() << std::endl;
	}
}

/**
 * @brief	Create a materia of a specific type.
 * 
 * @param	type The type of the materia to create.
 * @return	A pointer to the newly created materia, or NULL if not found.
 */
AMateria		*MateriaSource::createMateria(std::string const &type)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (_materia[i] != NULL && _materia[i]->getType() == type)
		{
			return (_materia[i]->clone());
		}
	}
	return (0);
}
