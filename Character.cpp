/*******************************************************************
   Copyright 2018 Mehmet ÖZGÜN

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
***********************************************************************/
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
