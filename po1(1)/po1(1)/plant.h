#pragma once
#include <stdlib.h>
#include "Organism.h"
#include "World.h"

class Plant : public Organism
{
public:
	Plant(World* w, int x, int y);
	virtual ~Plant();
	virtual void Action() override;
	virtual void Collision(Organism* attacker) override;
	void Die() override;
	void FightEvent(Organism* winner) override;
	void NewAnimal();
	void Back();
};

