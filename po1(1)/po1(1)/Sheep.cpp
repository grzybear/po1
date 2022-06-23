#include "Sheep.h"

Sheep::Sheep(World* world, int x, int y) : Animal(world, 4, 4, x, y) {};
Sheep::~Sheep() {};
char Sheep::GetSymbol() {
	return 's';
}
Organism* Sheep::NewOrganism(int x, int y) {
	return new Sheep(world, x, y);
}
std::string Sheep::Name() {
	return "Sheep";
}
