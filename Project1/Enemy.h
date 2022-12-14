#pragma once
#include "Entity.h"
#include <string>

class Game;
class Player;

class Enemy : public Entity
{
public:
	Enemy(std::string Name, int maxhp, int attackvalue);
	std::string Getname();
	void Initialise();
	void Update(Player* player);
private:
	Game* ent_game = nullptr;
};

