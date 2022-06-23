#include "Fox.h"

Fox::Fox(World* world, int x, int y) : Animal(world, 3, 7, x, y) {};
Fox::~Fox() {};
char Fox::GetSymbol() {
	return 'f';
}
Organism* Fox::NewOrganism(int x, int y) {
	return new Fox(world, x, y);
}
std::string Fox::Name() {
	return "Fox";
}
int Fox::GetRandomDirection() {
	int posibleMoves = 4;
	char moves[5] = "1111";
	if (y == 0 or HasTargetHigherPower(world->GetOrganism(x, y - 1))) {					//up
		moves[0] = '0';
		posibleMoves--;
	}
	if (x == world->GetX() - 1 or HasTargetHigherPower(world->GetOrganism(x + 1, y))) {	//right
		moves[1] = '0';
		posibleMoves--;
	}
	if (y == world->GetY() - 1 or HasTargetHigherPower(world->GetOrganism(x, y + 1))) {	//down
		moves[2] = '0';
		posibleMoves--;
	}
	if (x == 0 or HasTargetHigherPower(world->GetOrganism(x - 1, y))) {					//left
		moves[3] = '0';
		posibleMoves--;
	}
	if (posibleMoves == 0)return 4;
	int direction = rand() % posibleMoves;
	for (int i = 0; i <= direction; i++) {
		if (i > 4)break;
		if (moves[i] == '0') direction++;
	}
	return direction;
}