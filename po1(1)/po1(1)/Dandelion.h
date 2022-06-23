#pragma once
#include "plant.h"
class Dandelion : public Plant
{
public:
	Dandelion(World* world, int x, int y);
	~Dandelion();
	char GetSymbol() override;
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
	void Action() override;
};

