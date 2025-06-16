/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:05:50 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:11:37 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

/**
 * @brief	Default constructor for Character class.
 */
Character::Character() : _name("Unknow")
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

/**
 * @brief	Constructor for Character class with a name.
 * 
 * @param	name The name of the character.
 */
Character::Character(std::string name) : _name(name)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

/**
 * @brief	Copy constructor for Character class.
 * 
 * @param	origin The character to copy from.
 */
Character::Character(Character const &origin) : _name(origin._name)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		_inventory[i] = (origin._inventory[i] != NULL) ? \
						origin._inventory[i]->clone() : NULL;
	}
}

/**
 * @brief	Assignment operator for Character class.
 * 
 * @param	other The character to assign from.
 * @return	Reference to the current character.
 */
Character	&Character::operator=(Character const &other)
{
	int	i;

	if (this != &other)
	{
		_name = other._name;
		for (i= 0; i < 4; i++)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			_inventory[i] = (other._inventory[i] != NULL) ? \
							other._inventory[i]->clone() : NULL;
		}
	}
	return (*this);
}

/**
 * @brief	Destructor for Character class.
 */
Character::~Character()
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

/**
 * @brief	Get the name of the character.
 * 
 * @return	Reference to the character's name.
 */
std::string const	&Character::getName() const
{
	return (this->_name);
}

/**
 * @brief	Get the materia at a specific index in the character's inventory.
 * 
 * @param	idx The index of the materia to retrieve.
 * @return	Pointer to the materia at the specified index, or NULL if invalid.
 */
AMateria	*Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
	{
		return (this->_inventory[idx]);
	}
	return (NULL);
}

/**
 * @brief	Equip a materia to the character's inventory.
 * 
 * @param	m Pointer to the materia to equip.
 */
void	Character::equip(AMateria *m)
{
	int	i = -1;

	while (++i < 4)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped at index "
					  << i << std::endl;
			break;
		}
	}
	if (i >= 4)
	{
		std::cout << "You're Character inventory is full. Can't add "
				  << m->getType() << std::endl;
	}
}

/**
 * @brief	Unequip a materia from the character's inventory at a specific index.
 * 
 * @param	idx The index of the materia to unequip.
 */
void		Character::unequip(int idx)
{
	if (idx >=0 && idx < 4)
	{
		if (_inventory[idx] == NULL)
		{
			std::cout << "No materia to unequip at index " << idx << std::endl;
			return ;
		}
		std::cout << "Materia " << _inventory[idx]->getType()
				  << " unequipped from index " << idx << std::endl;
		_inventory[idx] = NULL;
	}
}

/**
 * @brief	Use a materia from the character's inventory at a specific index on
 * 			a target character.
 * 
 * @param	idx The index of the materia to use.
 * @param	target The target character to use the materia on.
 */
void		Character::use(int idx, ICharacter &target)
{
	if (idx >=0 && idx < 4)
	{
		if (_inventory[idx] != NULL)
			_inventory[idx]->use(target);
		else
		{
			std::cout << "No materia to use at index " << idx << std::endl;
		}
	}
}
