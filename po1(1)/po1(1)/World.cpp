#include "World.h"

World::World(int x, int y) : x(x), y(y){
	map = new Organism * *[y];
	for (int i = 0; i < y; i++) {
		map[i] = new Organism * [x];
		for (int j = 0; j < x; j++) {
			map[i][j] = NULL;
		}
	}
}
World::~World(){
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (map[i][j] != NULL)delete map[i][j];
		}
		delete[] map[i];
	}
	delete[] map;
	organisms.clear();
	newOrganisms.clear();
}
void World::DrawMap(){
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (map[i][j] == NULL)std::cout << '_';
			else std::cout << map[i][j]->GetSymbol();
		}
		std::cout << '\n';
	}
	std::cout << events;
}
void World::UpdateMap() {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			map[i][j] = NULL;
		}
	}
	for (auto organism : organisms) {
		if (organism != nullptr)
			map[(organism)->GetY()][(organism)->GetX()] = organism;
	}
	for (auto organism : newOrganisms) {
		if (organism != nullptr)
			map[(organism)->GetY()][(organism)->GetX()] = organism;
	}
}
void World::CalculateTurn(){
	for (auto organism : organisms) {
		if (organism != nullptr) {
			map[organism->GetY()][organism->GetX()] = NULL;
			organism->Action();
			auto target = map[organism->GetY()][organism->GetX()];
			if (target != NULL) {
				target->Collision(organism);
			}
			UpdateMap();
		}
		DrawMap();
	}
	UpdateOrganisms();
}
void World::CalculateTurn(int direction){
	for (auto organism : organisms) {
		if (organism != nullptr) {
			map[organism->GetY()][organism->GetX()] = NULL;
			if (organism->Action(direction))organism->Action();
			auto target = map[organism->GetY()][organism->GetX()];
			if (target != NULL) {
				target->Collision(organism);
			}
			UpdateMap();
		}
		/*DrawMap();
		std::this_thread::sleep_for(std::chrono::nanoseconds(50000000));*/
	}
	UpdateOrganisms();
}
void World::AddNewOrganism(Organism* organism) {
	newOrganisms.push_back(organism);
	map[organism->GetY()][organism->GetX()] = organism;
}
void World::DeleteOrganism(Organism* organism) {
	bool endFlag = false;
	for (int i = 0; i < y and !endFlag; i++) {
		for (int j = 0; j < x; j++) {
			if (map[i][j] == organism) {
				endFlag = true;
				map[i][j] = NULL;
				break;
			}
		}
	}
	if (!DeleteOrganismFromList(organism))
		DeleteOrganismFromNewList(organism);
}
bool World::DeleteOrganismFromList(Organism* organism) {
	std::list<Organism*>::iterator i = organisms.begin();
	do {
		if (*i == organism) {
			Organism* dying = *i;
			*i = nullptr;
			delete[] dying;
			return true;
		}
		else ++i;
	} while (i != organisms.end());
	return false;
}
void World::DeleteOrganismFromNewList(Organism* organism) {
	std::list<Organism*>::iterator i = newOrganisms.begin();
	do {
		if (*i == organism) {
			Organism* dying = *i;
			*i = nullptr;
			delete[] dying;
			return;
		}
		else ++i;
	} while (i != newOrganisms.end());
}
void World::UpdateOrganisms() {
	auto i = organisms.begin();
	while (i != organisms.end()) {
		if (*i == nullptr)organisms.erase(i++);
		else i++;
	}
	while (newOrganisms.size() > 0) {
		Organism* newOrganism;
		newOrganism = newOrganisms.front();
		if (newOrganism != nullptr)AddOrganismToMainList(newOrganism);
		newOrganisms.pop_front();
	}
}
void World::AddOrganismToMainList(Organism* organism) {
	if (organisms.size() > 0) {
		auto i = organisms.begin();
		while (i != organisms.end()) {
			if ((organism)->HasTargetLowerInitiative(*i)) {
				organisms.insert(i, organism);
				return;
			}
			i++;
		}
	}
	organisms.push_back(organism);
}
int World::GetX()const {
	return x;
}
int World::GetY()const {
	return y;
}
int World::GetEmptyFieldDirection(int x, int y) {
	char nearbyFields[5] = "1111";
	/*--+---+---+
	|   | 0 |   |
	+---+---+---+
	| 3 |   | 1 |
	+---+---+---+
	|   | 2 |   |
	+---+---+--*/
	int posibleFields = 4;
	if (y == 0 or map[y - 1][x] != NULL) {
		nearbyFields[0] = '0';
		posibleFields--;
	}
	if (x == this->x - 1 or map[y][x + 1] != NULL) {
		nearbyFields[1] = '0';
		posibleFields--;
	}
	if (y == this->y - 1 or map[y + 1][x] != NULL) {
		nearbyFields[2] = '0';
		posibleFields--;
	}
	if (x == 0 or map[y][x - 1] != NULL) {
		nearbyFields[3] = '0';
		posibleFields--;
	}
	if (posibleFields == 0)return 5;
	int direction = rand() % posibleFields;
	for (int i = 0; i <= direction; i++) {
		if (i > 4)break;
		if (nearbyFields[i] == '0') direction++;
	}
	return direction;
}
bool World::IsEmpty(int x, int y) {
	return map[y][x] == NULL;
}
void World::AddEvent(std::string a) {
	events.Add(a);
}
Organism* World::GetOrganism(int x, int y) const {
	if (x >= 0 and y >= 0 and y < this->y and x < this->x)
		return map[y][x];
	else return nullptr;
}
