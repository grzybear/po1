#include "Organism.h"

Organism::Organism(World* w, int p, int i, int x, int y) : world(w), power(p), initiative(i), x(x), y(y) {};
Organism::~Organism() {};
bool Organism::Action(int direction) {
	return true;
}
bool Organism::HasTargetHigherPower(Organism* target) const {
	if (target == nullptr) return false;
	return target->power > this->power;
}
bool Organism::HasTargetLowerPower(Organism* target) const {
	if (target == nullptr) return false;
	return target->power < this->power;
}
bool Organism::HasTargetLowerInitiative(const Organism* target) const {
	return target->initiative < this->initiative;
}
bool Organism::IsTargetOnSameField(Organism* target) const {
	if (this->x == target->x and
		this->y == target->y) {
		return true;
	}
	else return false;
}
int Organism::GetX() const {
	return x;
}
int Organism::GetY() const {
	return y;
}
int Organism::GetPower() const {
	return power;
}
void Organism::UpdateCoordinates(int direction, int& x, int& y) {
	switch (direction) {
	case 0: //góra
		y--;
		break;
	case 1: //prawo
		x++;
		break;
	case 2: //dół
		y++;
		break;
	case 3: //lewo
		x--;
		break;
	}
}
void Organism::SetPosition(int x, int y) {
	this->x = x;
	this->y = y;
}
void Organism::IncresePower(int x) {
	this->power += x;
}
