/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:38:15 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:25:42 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#define ASSERT_TEST(passed, message) \
	if (passed) { std::cout << GREEN << "TEST PASSED" << NC << std::endl; } \
	else { std::cout << RED << "TEST FAILED: " << message << NC << std::endl; }

#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define CYAN		"\033[0;36m"
#define NC			"\033[0m"


int main()
{
	{
		std::cout << std::endl << CYAN << "MANDATORY" << NC << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		ASSERT_TEST(tmp != NULL, "Materia should not be nullptr");

		delete bob;
		delete me;
		delete src;
	}

	/*
	* TEST UNEQUIP
	*/
	{
		std::cout << std::endl << CYAN << "TEST UNEQUIP" << NC << std::endl;
		const int ICE_SLOT = 0;
		const int CURE_SLOT = 1;
		const int SECOND_ICE_SLOT = 2;
		
		IMateriaSource * src = new MateriaSource();
		if (!src)
			return -1;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter * me = new Character("me");
		if (!me) {
			delete src;
			src = NULL;
			return -1;
		}
		
		AMateria * iceMateria = src->createMateria("ice");
		if (iceMateria)
			me->equip(iceMateria);

		AMateria * cureMateria = src->createMateria("cure");
		if (cureMateria)
			me->equip(cureMateria);

		AMateria * secondIceMateria = src->createMateria("ice");
		if (secondIceMateria)
			me->equip(secondIceMateria);
		
		ICharacter * bob = new Character("bob");
		if (!bob) {
			delete me;
			me = NULL;
			delete src;
			src = NULL;
			return -1;
		}
		me->unequip(CURE_SLOT);
		me->use(ICE_SLOT, *bob);
		me->use(CURE_SLOT, *bob);
		me->use(SECOND_ICE_SLOT, *bob);
;
		delete bob;
		bob = NULL;

		delete me;
		me = NULL;

		delete src;
		src = NULL;
		
		/*  Clean up if not equipped  */
		if (cureMateria) {
			delete cureMateria;
			cureMateria = NULL;
		}
	}

	/*
	* TEST MATERIA
	*/
	{
		std::cout << std::endl << CYAN << "TEST MATERIA SOURCE INITIALIZATION AND ASSIGNMENT" << NC << std::endl;
		MateriaSource srcDefault;
		MateriaSource srcCopy(srcDefault);
		MateriaSource srcAssigned;
		srcAssigned = srcDefault;
	}

	/*
	* TEST CURE
	*/
	{
    	std::cout << std::endl << CYAN << "TEST CURE CLASS CONSTRUCTORS AND ASSIGNMENT" << NC << std::endl;

		Cure cureDefault;
		ASSERT_TEST(cureDefault.getType() == "cure", "Default Cure should have type 'cure'");
		std::cout << "Cure default constructor test OK" << std::endl;

		Cure cureCopy(cureDefault);
		ASSERT_TEST(cureCopy.getType() == "cure", "Copy of Cure should have type 'cure'");
		std::cout << "Cure copy constructor test OK" << std::endl;

		Cure cureAssigned;
		cureAssigned = cureDefault;
		ASSERT_TEST(cureAssigned.getType() == "cure", "Assigned Cure should have type 'cure'");
		std::cout << "Cure assignment operator test OK" << std::endl;
	}

	/*
	* TEST ICE
	*/
	{
	    std::cout << std::endl << CYAN << "TEST ICE CLASS CONSTRUCTORS AND ASSIGNMENT" << NC << std::endl;

		Ice iceDefault;
		ASSERT_TEST(iceDefault.getType() == "ice", "Default Ice should have type 'ice'");
		std::cout << "Ice default constructor test OK" << std::endl;

		Ice iceCopy(iceDefault);
		ASSERT_TEST(iceCopy.getType() == "ice", "Copy of Ice should have type 'ice'");
		std::cout << "Ice copy constructor test OK" << std::endl;

		Ice iceAssigned;
		iceAssigned = iceDefault;
		ASSERT_TEST(iceAssigned.getType() == "ice", "Assigned Ice should have type 'ice'");
		std::cout << "Ice assignment operator test OK" << std::endl;
	}

	/*
	* TEST CHARACTER
	*/
	{
		std::cout << std::endl << CYAN << "TEST CHARACTER CLASS CONSTRUCTORS AND ASSIGNMENT" << NC << std::endl;
		
		Character charDefault("Default");
		ASSERT_TEST(charDefault.getName() == "Default", "Default Character should have the given name");
		std::cout << "Character default constructor test OK" << std::endl;

		Character charCopy(charDefault);
		ASSERT_TEST(charCopy.getName() == "Default", "Copy of Character should have the same name");
		std::cout << "Character copy constructor test OK" << std::endl;

		Character charAssigned("Assigned");
		charAssigned = charDefault;
		ASSERT_TEST(charAssigned.getName() == "Default", "Assigned Character should have the copied name");
		std::cout << "Character assignment operator test OK" << std::endl;
	}

	/*
	* MATERIAL INVENTORY TEST
	*/
	{
		std::cout << std::endl << CYAN << "MATERIAL INVENTORY TEST" << NC << std::endl;

		MateriaSource source;
		source.learnMateria(new Ice());
		source.learnMateria(new Cure());

		Character character("Hero");

		// Test l'équipement de Materia dans les emplacements vides dans l'ordre
		AMateria* ice = source.createMateria("ice");
		AMateria* cure = source.createMateria("cure");
		AMateria* extraIce = source.createMateria("ice");
		AMateria* overflow = source.createMateria("cure");
		AMateria* fifthMateria = source.createMateria("ice"); // Cinquième Materia pour tester l'inventaire plein

		character.equip(ice);       // Doit aller dans le slot 0
		character.equip(cure);      // Doit aller dans le slot 1
		character.equip(extraIce);  // Doit aller dans le slot 2
		character.equip(overflow);  // Devrait aller dans le slot 3

		ASSERT_TEST(character.getMateria(0) == ice, "Ice should be in slot 0");
		ASSERT_TEST(character.getMateria(1) == cure, "Cure should be in slot 1");
		ASSERT_TEST(character.getMateria(2) == extraIce, "Extra ice should be in slot 2");
		ASSERT_TEST(character.getMateria(3) == overflow, "Overflow cure should be in slot 3");

		// Tenter d'équiper une cinquième Materia quand l'inventaire est plein
		character.equip(fifthMateria);
		ASSERT_TEST(character.getMateria(4) == NULL, "No fifth slot should be available");

		// Test l'utilisation d'une Materia inexistante
		character.use(4, character);  // Ne devrait rien faire, slot inexistant

		// Test de déséquipement de Materia inexistante
		character.unequip(4);  // Ne devrait rien faire, slot inexistant

		// Nettoyage
		character.unequip(0); // Déséquiper ice
		character.unequip(1); // Déséquiper cure
		character.unequip(2); // Déséquiper extra ice
		character.unequip(3); // Déséquiper overflow

		delete ice;
		delete cure;
		delete extraIce;
		delete overflow;
		delete fifthMateria; // Cinquième Materia jamais équipée doit être supprimée manuellement
	}

	/*
	* TEST DEEP COPY OF CHARACTER WITH MATERIA
	*/	
	{
		std::cout << std::endl << CYAN << "TESTING DEEP COPY OF CHARACTER WITH MATERIA" << NC << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* original = new Character("Original");
		AMateria* originalIce = src->createMateria("ice");
		AMateria* originalCure = src->createMateria("cure");
		original->equip(originalIce);
		original->equip(originalCure);

		ICharacter* copy = new Character(*dynamic_cast<Character*>(original));  // Copie profonde
		ICharacter* target = new Character("Target");
		// Tester l'utilisation pour vérifier l'identifiant unique et le type

		// Assertion Tests to ensure deep copy
		ASSERT_TEST(originalIce->getType() == dynamic_cast<Character*>(copy)->getMateria(0)->getType() && originalIce != dynamic_cast<Character*>(copy)->getMateria(0), "Ice materia deep copied correctly");
		ASSERT_TEST(originalCure->getType() == dynamic_cast<Character*>(copy)->getMateria(1)->getType() && originalCure != dynamic_cast<Character*>(copy)->getMateria(1), "Cure materia deep copied correctly");

		std::cout << "Original uses on Copy:" << std::endl;
		original->use(0, *copy);
		original->use(1, *copy);

		delete original;
		std::cout << std::endl << "Copy uses on Original:" << std::endl;
		copy->use(0, *target);
		copy->use(1, *target);

		delete src;
		delete target;
		delete copy;
		
	}	
	
	std::cout << std::endl << "All tests executed." << std::endl;	

	return 0;
}
