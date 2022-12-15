#pragma once
#include "iState.h"
#include <string>
class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;
class Player;
class Enemy;
class Object;

class Game: public iState
{
public:
	
	static Game* Get();
	virtual void Update() override;
	virtual void Render() override;
	bool IsGameRunning();
	virtual void Initialise() override;
	virtual void Uninitialise() override;
	Object* CheckCollisions(Object* ent);
	bool TestBlockCollision(Object* ent, Object* ent2);

private:
	Game();
	Game(const Game&) = delete;
	static Game* s_instance;

	SDL_Window* game_window;
	SDL_Renderer* game_renderer;
	InputManager* game_inputmanager;
	Visualisation* game_visualisation;
	Player* game_player;
	Enemy* game_enemy;
	SDL_Rect* game_rect;
	SDL_Rect* Ent_rect;
	SDL_Rect* Ent_rect2;
	int image_id;
};

