#include "WorldGenerator.h"

void WorldGenerator::Randomize(int& x, int& y) {
	do {
		x = rand() % world->GetX();
		y = rand() % world->GetY();
	} while (world->GetOrganism(x, y) != nullptr);
}
WorldGenerator::WorldGenerator() {
		world = new World(40, 25);
	}
WorldGenerator::~WorldGenerator() {
		delete world;
	}
World* WorldGenerator::Generate() {
		int x, y;
		Randomize(x, y);
		world->AddNewOrganism(new Human(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Wolf(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Wolf(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Sheep(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Sheep(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Fox(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Fox(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Turtle(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Turtle(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Antelope(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Antelope(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Grass(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Grass(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Dandelion(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Dandelion(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Guarana(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Guarana(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Nightshade(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new Nightshade(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new SosnowskysHogweed(world, x, y));
		Randomize(x, y);
		world->AddNewOrganism(new SosnowskysHogweed(world, x, y));
		world->CalculateTurn();
		return world;
	}
void WorldGenerator::Save() {
	std::ofstream output("organisms.txt");
	std::list<Organism*>* organisms = world->GetList();
	for (auto organism : *organisms) {
		output << organism->GetSymbol() << " " << organism->GetX() << " " << organism->GetY() << "\n";
	}
	output.close();
	world->AddEvent("[GAME SAVED]");
}
void WorldGenerator::Read() {
	delete world;
	world = new World(40, 25);
	std::ifstream input("organisms.txt");
	int x, y;
	char t;
	while (!input.eof()) {
		input >> t >> x >> y;
		std::cout << t << x << y;
		if (t == 'H')world->AddNewOrganism(new Human(world, x, y));
		else if (t == 'a')world->AddNewOrganism(new Antelope(world, x, y));
		else if (t == '*')world->AddNewOrganism(new Dandelion(world, x, y));
		else if (t == 'f')world->AddNewOrganism(new Fox(world, x, y));
		else if (t == 'w')world->AddNewOrganism(new Wolf(world, x, y));
		else if (t == 's')world->AddNewOrganism(new Sheep(world, x, y));
		else if (t == 't')world->AddNewOrganism(new Turtle(world, x, y));
		else if (t == ':')world->AddNewOrganism(new Guarana(world, x, y));
		else if (t == '.')world->AddNewOrganism(new Nightshade(world, x, y));
		else if (t == '#')world->AddNewOrganism(new SosnowskysHogweed(world, x, y));
		else if (t == ',')world->AddNewOrganism(new Grass(world, x, y));
	}
	world->AddEvent("[GAME LOADED]");
}