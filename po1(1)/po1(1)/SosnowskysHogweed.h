#pragma once
#include "plant.h"
#include "Animal.h"

class SosnowskysHogweed :
    public Plant
{
public:
	SosnowskysHogweed(World* world, int x, int y);
	~SosnowskysHogweed();
	char GetSymbol() override;
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
	void Action() override;
	void Collision(Organism* attacker) override;
	void Kill(Organism* organism);
};

