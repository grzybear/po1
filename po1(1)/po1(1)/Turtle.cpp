#include "Turtle.h"

Turtle::Turtle(World* world, int x, int y) : Animal(world, 2, 1, x, y) {};
Turtle::~Turtle() {};
char Turtle::GetSymbol() {
	return 't';
}
Organism* Turtle::NewOrganism(int x, int y) {
	return new Turtle(world, x, y);
}
std::string Turtle::Name(){
	return "Turtle";
}
void Turtle::Action() {
	int random = rand() % 4;
	if (!random)Animal::Action();
}
void Turtle::Collision(Organism* attacker) {
	if (typeid(*attacker) == typeid(*this)) {
		attacker->Back();
		attacker->NewAnimal();
	}
	else if (attacker->GetPower() < 5) {
		std::string event = Name();
		event.append(" self-defended from ");
		event.append(attacker->Name());
		world->AddEvent(event);
		attacker->Back();
	}
	else Animal::Collision(attacker);
}
