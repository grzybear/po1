#pragma once
#include <string>

class World;

class Organism
{
protected:
	int power;
	int initiative;
	World* world;
	int x, y; 
public:
	Organism(World* w, int p, int i, int x, int y);
	virtual ~Organism();
	virtual char GetSymbol() = 0;
	virtual void Action() = 0;
	virtual void Collision(Organism* attacker) = 0;
	virtual bool Action(int direction);
	virtual void Die() = 0;

	virtual void Back() = 0;
	virtual void UpdateCoordinates(int direction, int& x, int& y);
	virtual Organism* NewOrganism(int x, int y) = 0;
	virtual void NewAnimal() = 0;
	virtual std::string Name() = 0;
	virtual void FightEvent(Organism* winner) = 0;
	void SetPosition(int x, int y);
	void IncresePower(int x);
	int GetX() const;
	int GetY() const;
	int GetPower() const;
	bool HasTargetHigherPower(Organism* target) const;
	bool HasTargetLowerPower(Organism* target) const;
	bool HasTargetLowerInitiative(const Organism* target) const;
	bool IsTargetOnSameField(Organism* target) const;
};

