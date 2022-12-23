#pragma once
#include"State.h"
class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;
class GameWinState: public State
{
public:
	GameWinState(StateManager* stateManager);
	~GameWinState();
	void Update();
	void Render();
	void Initialise();
	void Uninitialise();

private:
	SDL_Window* Gamewin_window;
	SDL_Renderer* Gamewin_renderer;
	InputManager* Gamewin_inputmanager;
	Visualisation* Gamewin_visualisation;
	SDL_Rect* Gamewin_rect;

	int image_id;
};

