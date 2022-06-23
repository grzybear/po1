#pragma once
#include "plant.h"

class Grass : public Plant
{
public:
	Grass(World* world, int x, int y);
	~Grass();
	char GetSymbol() override;
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
};

