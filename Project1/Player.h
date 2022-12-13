#pragma once
#include "Entity.h"
#include <string>

class SDL_Rect;
class Visualisation;
class InputManager;
class SDL_Renderer;
class Game;

class Player : public Entity
{
public:
	Player(InputManager* im);
	std::string Getname();
	void Initialise();
	void Update();
private:
	
	InputManager* ent_input_manager;
	Game* ent_game = nullptr;

};

