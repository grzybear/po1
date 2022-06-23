#pragma once
#include "plant.h"

class Guarana : public Plant
{
public:
	Guarana(World* world, int x, int y);
	~Guarana();
	char GetSymbol() override;
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
	void Collision(Organism* attacker) override;
};

