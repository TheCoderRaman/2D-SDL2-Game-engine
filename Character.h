#pragma once
#include "EngineObject.h"
class Character : public EngineObject
{
public:
	short health;
	short stamina;
	void countermove(int x, int y);
	void initcharacter();
	bool alive;
	void characterloop();
	void attack(int x);
	Character();
	~Character();
};

