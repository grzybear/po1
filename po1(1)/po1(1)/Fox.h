#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(World* world, int x, int y);
	~Fox();
	char GetSymbol();
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
	int GetRandomDirection() override;
};

