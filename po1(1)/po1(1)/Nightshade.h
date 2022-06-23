#pragma once
#include "plant.h"
class Nightshade :
    public Plant
{
public:
	Nightshade(World* world, int x, int y);
	~Nightshade();
	char GetSymbol() override;
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
	void Collision(Organism* attacker);
};

