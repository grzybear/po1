#include "plant.h"

Plant::Plant(World* w, int x, int y) : Organism(w, 0, 0, x, y) {};
Plant::~Plant() {};
void Plant::Action() {
	int random = rand() % 10;
	if (!random) {
		int newX = x, newY = y;
		int direction = world->GetEmptyFieldDirection(x, y);
		if (direction < 4) {
			UpdateCoordinates(direction, newX, newY);
			world->AddNewOrganism(NewOrganism(newX, newY));
		}
	}
}
void Plant::Collision(Organism* attacker) {
	FightEvent(attacker);
	Die();
}
void Plant::Die() {
	world->DeleteOrganism(this);
}
void Plant::FightEvent(Organism* winner) {
	std::string event = winner->Name();
	event.append(" ate ");
	event.append(Name());
	world->AddEvent(event);
}
void Plant::NewAnimal() {};
void Plant::Back() {};
