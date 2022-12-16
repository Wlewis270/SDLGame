#pragma once
#include "State.h"
#include <string>
#include <vector>
class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;
class Player;
class Enemy;
class Object;

class Game: public State
{
public:
	static Game* init(StateManager* stateManager);
	static Game* Get();
	 void Update();
	 void Render() ;
	bool IsGameRunning();
	 void Initialise() ;
	 void Uninitialise();
	Object* CheckCollisions(Object* ent);
	bool TestBlockCollision(Object* ent, Object* ent2);
	void SpawnEnemy(Enemy* enemy);
	bool EnemyOnScreen();

private:
	Game(StateManager* stateManager);
	Game(const Game&) = delete;
	static Game* s_instance;

	SDL_Window* game_window;
	SDL_Renderer* game_renderer;
	InputManager* game_inputmanager;
	Visualisation* game_visualisation;
	Player* game_player;
	Enemy* game_left_enemy[4];
	Enemy* game_right_enemy[4];
	std::vector<Enemy*> game_enemies;
	SDL_Rect* game_rect;
	SDL_Rect* Ent_rect;
	SDL_Rect* Ent_rect2;
	int image_id;
	bool enemies_on_screen;
};

