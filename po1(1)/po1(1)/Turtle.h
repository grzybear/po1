#pragma once
#include "Animal.h"
class Turtle : public Animal
{
public:
	Turtle(World* world, int x, int y);
	~Turtle();
	char GetSymbol();
	Organism* NewOrganism(int x, int y);
	std::string Name() override;
	void Action() override;
	void Collision(Organism* attacker) override;
};

