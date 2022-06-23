#include "Wolf.h"

Wolf::Wolf(World* world, int x, int y) : Animal(world, 9, 5, x, y) {};
Wolf::~Wolf() {};
char Wolf::GetSymbol() {
	return 'w';
}
Organism* Wolf::NewOrganism(int x, int y) {
	return new Wolf(world, x, y);
}
std::string Wolf::Name() {
	return "Wolf";
}