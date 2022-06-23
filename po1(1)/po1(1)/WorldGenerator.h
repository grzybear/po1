#pragma once
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Human.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "SosnowskysHogweed.h"

class WorldGenerator
{
private:
	World* world;
	void Randomize(int& x, int& y);
public:
	WorldGenerator();
	~WorldGenerator();
	World* Generate();
	void Save();
	void Read();
};

