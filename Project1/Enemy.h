#pragma once
#include "Entity.h"
#include <string>

class Game;

class Enemy : public Entity
{
public:
	Enemy(std::string Name, int maxhp, int attackvalue);
	std::string Getname();
	void Initialise();
	void Update();
private:
	Game* ent_game = nullptr;
};

