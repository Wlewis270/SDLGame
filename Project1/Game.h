#pragma once
#include <string>
class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;
class Player;
class Enemy;
class Entity;

class Game
{
public:
	static Game* Get();
	void Update();
	void Render();
	bool IsGameRunning();
	void Initialise();
	void Uninitialise();
	Entity* CheckCollisions(Entity* ent);
	bool TestBlockCollision(Entity* ent, Entity* ent2);

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

