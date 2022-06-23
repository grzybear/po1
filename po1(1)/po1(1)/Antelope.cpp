#include "Antelope.h"

Antelope::Antelope(World* world, int x, int y) : Animal(world, 4, 4, x, y) {};
Antelope::~Antelope() {};
char Antelope::GetSymbol() {
	return 'a';
}
Organism* Antelope::NewOrganism(int x, int y) {
	return new Antelope(world, x, y);
}
std::string Antelope::Name() {
	return "Antelope";
}
void Antelope::Action() {
	for (int i = 0; i < 2; i++) {
		Animal::Action();
	}
}
void Antelope::Collision(Organism* attacker) {
	if (typeid(*attacker) == typeid(*this)) {
		attacker->Back();
		attacker->NewAnimal();
		world->AddEvent("new animal");
		return;
	}
	int random = rand() % 2;
	random = 1;
	if (random) {
		int direction = world->GetEmptyFieldDirection(x, y);
		if (direction < 4) {
			Animal::UpdateCoordinates(direction, x, y);
			std::string event = Name();
			event.append(" fled from ");
			event.append(attacker->Name());
			world->AddEvent(event);
			return;
		}
	}
	Animal::Collision(attacker);
}