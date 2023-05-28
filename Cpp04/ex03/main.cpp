#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	{
		Cure cure = Cure("cure");
		Cure cure2 = cure;
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->unequip(3);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->equip(tmp->clone());
		tmp = src->createMateria("wrong");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(5, *bob);
		me->use(2, *me);
		me->unequip(1);
		me->unequip(5);
		me->use(1, *me);
		delete bob;
		delete me;
		delete src;
		return 0;
	}
}