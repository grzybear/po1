#include "Animal.h"

Animal::Animal(World* w, int p, int i, int x, int y) : Organism(w, p, i, x, y) { oldX = 0; oldY = 0; };
Animal::~Animal(){};
void Animal::Action(){
	oldX = x;
	oldY = y;
	int direction = GetRandomDirection();
	if (direction < 4)UpdateCoordinates(direction, x, y);
}
void Animal::Collision(Organism* attacker){
	if (typeid(*attacker) == typeid(*this)) {
		attacker->Back();
		attacker->NewAnimal();
	}
	else if (HasTargetLowerPower(attacker)) {
		attacker->FightEvent(this);
		attacker->Die();
	}
	else {
		this->FightEvent(attacker);
		this->Die();
	}
}
void Animal::Die(){
	world->DeleteOrganism(this);
}
void Animal::Back(){
	x = oldX;
	y = oldY;
}
int Animal::GetRandomDirection() {
	int posibleMoves = 4;
	char moves[5] = "1111";
	if (y == 0) {					//up
		moves[0] = '0';
		posibleMoves--;
	}
	if (x == world->GetX() - 1) {	//right
		moves[1] = '0';
		posibleMoves--;
	}
	if (y == world->GetY() - 1) {	//down
		moves[2] = '0';
		posibleMoves--;
	}
	if (x == 0) {					//left
		moves[3] = '0';
		posibleMoves--;
	}
	int direction = rand() % posibleMoves;
	for (int i = 0; i <= direction; i++) {
		if (i > 4)break;
		if (moves[i] == '0') direction++;
	}
	return direction;
}
void Animal::NewAnimal(){
	int newX = x, newY = y;
	int direction = world->GetEmptyFieldDirection(x, y);
	if (direction < 4) {
		UpdateCoordinates(direction, newX, newY);
		//animal constructor
		Organism* newOrganism = NewOrganism(newX, newY);
		world->AddNewOrganism(newOrganism);

		std::string event = Name();
		event.append(" has spawned");
		world->AddEvent(event);
	}
}
void Animal::FightEvent(Organism* winner) {
	std::string event = this->Name();
	event.append(" has been slain by ");
	event.append(winner->Name());
	world->AddEvent(event);
}
