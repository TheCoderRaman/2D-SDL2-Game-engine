#include "Character.h"



void Character::countermove(int x, int y)
{
	if (stamina >= 20)
	{
		objectrect.x += x;
		objectrect.y += y;

		stamina -= 20;
	}


}

void Character::initcharacter()
{
	stamina = 100;
	health = 100;
	alive = true;
}


void Character::characterloop()
{
	
}

void Character::attack(int x)
{
	if (stamina >= 10)
	{
		objectrect.x += x;


		objectrect.x -= x;
		stamina -= 10;
	}
	
}

Character::Character()
{
}


Character::~Character()
{
}
