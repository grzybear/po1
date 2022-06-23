#include "SosnowskysHogweed.h"

SosnowskysHogweed::SosnowskysHogweed(World* world, int x, int y) : Plant(world, x, y) {
	power = 10;
}
SosnowskysHogweed::~SosnowskysHogweed() {}
char SosnowskysHogweed::GetSymbol() {
	return '#';
}
Organism* SosnowskysHogweed::NewOrganism(int x, int y) {
	return new SosnowskysHogweed(world, x, y);
}
std::string SosnowskysHogweed::Name() {
	return "SosnowskysHogweed";
}
void SosnowskysHogweed::Action() {
	Kill(world->GetOrganism(x - 1, y));
	Kill(world->GetOrganism(x, y - 1));
	Kill(world->GetOrganism(x + 1, y));
	Kill(world->GetOrganism(x, y + 1));
	Plant::Action();
}
void SosnowskysHogweed::Collision(Organism* attacker) {
	std::string event = Name();
	event.append(" killed ");
	event.append(attacker->Name());
	world->AddEvent(event);
	attacker->Die();
	Die();
}
void SosnowskysHogweed::Kill(Organism* organism) {
	if (organism == nullptr)return;
	else if (dynamic_cast<Animal*>(organism)) {
		std::string event = Name();
		event.append(" killed ");
		event.append(organism->Name());
		world->AddEvent(event);
		organism->Die();
	}
}