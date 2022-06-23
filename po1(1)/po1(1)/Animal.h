#pragma once
#include <stdlib.h>
#include <typeinfo>
#include "Organism.h"
#include "World.h"

class Animal : public Organism
{
protected:
	int oldX, oldY;
	void Die() override;
	void Back() override;
	virtual int GetRandomDirection();
	void NewAnimal() override;
	void FightEvent(Organism* winner);
public:
	Animal(World* w, int p, int i, int x, int y);
	virtual ~Animal() override;
	virtual void Action() override;
	virtual void Collision(Organism* attacker) override;
	virtual char GetSymbol() = 0;
};

