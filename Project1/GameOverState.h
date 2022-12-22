#pragma once
#include"State.h"
class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;
class GameOverState :public State
{
public:
	GameOverState(StateManager* stateManager);
	~GameOverState();
	void Update();
	void Render();
	void Initialise();
	void Uninitialise();

private:
	SDL_Window* Gameover_window;
	SDL_Renderer* Gameover_renderer;
	InputManager* Gameover_inputmanager;
	Visualisation* Gameover_visualisation;
	SDL_Rect* Gameover_rect;

	int image_id;
};

