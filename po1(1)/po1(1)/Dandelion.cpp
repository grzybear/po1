#include "Dandelion.h"

Dandelion::Dandelion(World* world, int x, int y) : Plant(world, x, y) {}
Dandelion::~Dandelion() {}
char Dandelion::GetSymbol() {
	return '*';
}
Organism* Dandelion::NewOrganism(int x, int y) {
	return new Dandelion(world, x, y);
}
std::string Dandelion::Name() {
	return "Dandelion";
}
void Dandelion::Action() {
	for (int i = 0; i < 3; i++) {
		Plant::Action();
	}
}