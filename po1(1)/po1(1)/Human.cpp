#include "Human.h"

Human::Human(World* world, int x, int y) : Animal(world, 5, 4, x, y), abilityCooldown(0) {}
Human::~Human() {};
void Human::Action() {
	if (abilityCooldown)abilityCooldown--;
}
bool Human::Action(int direction) {
	if (abilityCooldown)abilityCooldown--;
	if (direction < 4) {
		oldX = x;
		oldY = y;
		UpdateCoordinates(direction, x, y);
		if (x < 0)x = 0;
		else if (x > world->GetX() - 1)x = world->GetX() - 1;
		if (y < 0)y = 0;
		else if (y > world->GetY() - 1)y = world->GetY() - 1;
	}
	else {
		if (!abilityCooldown)abilityCooldown = 10;
	}
	return false;
}
void Human::Collision(Organism* attacker) {
	if (abilityCooldown > 5) {
		int newX = x, newY = y;
		int direction = world->GetEmptyFieldDirection(x, y);
		UpdateCoordinates(direction, newX, newY);
		attacker->SetPosition(newX, newY);
	}
	else {
		Animal::Collision(attacker);
	}
}
char Human::GetSymbol() {
	if (abilityCooldown > 5) return '$';
	return 'H';
}
Organism* Human::NewOrganism(int x, int y) { return nullptr; }
std::string Human::Name() {
	return "Human";
}
