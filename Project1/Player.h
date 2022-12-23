#pragma once
#include "Entity.h"
#include <string>

class InputManager;
class Game;
class Bullet;

class Player : public Entity
{
public:
	Player(std::string Name, int maxhp, int attackvalue, InputManager* im);
	std::string Getname();
	void Initialise();
	void Update();
	void CreateBullet(std::string dir);
	void Render();
private:
	InputManager* ent_input_manager;
	Game* ent_game = nullptr;
	Bullet* ent_bullet;
	bool bullet_deleted;
	std::string direction;
};

