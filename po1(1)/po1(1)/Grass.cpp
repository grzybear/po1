#include "Grass.h"

Grass::Grass(World* world, int x, int y) : Plant(world, x, y) {}
Grass::~Grass() {}
char Grass::GetSymbol() {
	return ',';
}
Organism* Grass::NewOrganism(int x, int y) {
	return new Grass(world, x, y);
}
std::string Grass::Name() {
	return "Grass";
}