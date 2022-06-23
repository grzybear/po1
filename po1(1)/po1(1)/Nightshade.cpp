#include "Nightshade.h"

Nightshade::Nightshade(World* world, int x, int y) : Plant(world, x, y) {
	power = 99;
}
Nightshade::~Nightshade() {}
char Nightshade::GetSymbol() {
	return '.';
}
Organism* Nightshade::NewOrganism(int x, int y) {
	return new Nightshade(world, x, y);
}
std::string Nightshade::Name() {
	return "Nightshade";
}
void Nightshade::Collision(Organism* attacker) {
	std::string event = Name();
	event.append(" killed ");
	event.append(attacker->Name());
	world->AddEvent(event);
	attacker->Die();
	Die();
}