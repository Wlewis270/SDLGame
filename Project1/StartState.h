#pragma once
#include "iState.h"
class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;
class StartState: public iState
{
public:
	
	virtual void Update() override;
	virtual void Render() override;
	virtual void Initialise() override;
	virtual void Uninitialise() override;
private:
	SDL_Window* start_window;
	SDL_Renderer* start_renderer;
	InputManager* start_inputmanager;
	Visualisation* start_visualisation;
	SDL_Rect* start_rect;
	int image_id;
};

