#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(World* world, int x, int y);
	~Wolf();
	char GetSymbol();
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
};