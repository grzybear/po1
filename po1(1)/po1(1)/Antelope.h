#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(World* world, int x, int y);
	~Antelope();
	char GetSymbol();
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
	void Action() override;
	void Collision(Organism* attacker) override;
};

