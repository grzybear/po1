#pragma once
#include "Animal.h"

class Human : public Animal
{
	int abilityCooldown;
public:
	Human(World* world, int x, int y);
	~Human();
	void Action() override;
	bool Action(int direction) override;
	void Collision(Organism* attacker)override;
	char GetSymbol();
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
};

