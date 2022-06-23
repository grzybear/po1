#pragma once
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include "Organism.h"
#include "EventList.h"

class World
{
private:
	std::list<Organism*> organisms;
	std::list<Organism*> newOrganisms;
	EventList events;
	Organism*** map;
	int x;
	int y;
public:
	World(int x, int y);
	~World();
	void DrawMap();
	void UpdateMap();
	void CalculateTurn();
	void CalculateTurn(int direction);
	void AddNewOrganism(Organism* organism);
	void DeleteOrganism(Organism* organism);
	bool DeleteOrganismFromList(Organism* organism);
	void DeleteOrganismFromNewList(Organism* organism);
	void UpdateOrganisms();
	void AddOrganismToMainList(Organism* organism);
	int GetX()const;
	int GetY()const;
	int GetEmptyFieldDirection(int x, int y);
	bool IsEmpty(int x, int y);
	void AddEvent(std::string a);
	Organism* GetOrganism(int x, int y) const;
	std::list<Organism*>* GetList() {
		return &organisms;
	}
};

