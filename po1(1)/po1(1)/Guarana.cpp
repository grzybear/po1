#include "Guarana.h"

Guarana::Guarana(World* world, int x, int y) : Plant(world, x, y) {}
Guarana::~Guarana() {}
char Guarana::GetSymbol() {
	return ':';
}
Organism* Guarana::NewOrganism(int x, int y) {
	return new Guarana(world, x, y);
}
std::string Guarana::Name() {
	return "Guarana";
}
void Guarana::Collision(Organism* attacker) {
	attacker->IncresePower(3);
	Plant::Collision(attacker);
}