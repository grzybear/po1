#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(World* world, int x, int y);
	~Sheep();
	char GetSymbol();
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
};

