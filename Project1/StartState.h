#pragma once
#include"State.h"



class InputManager;
class Visualisation;
class SDL_Window;
class SDL_Renderer;
class SDL_Rect;

class StartState
{
public:
	 void Update() ;
	 void Render();
	void Initialise() ;
	 void Uninitialise() ;
	
private:
	SDL_Window* start_window;
	SDL_Renderer* start_renderer;
	InputManager* start_inputmanager;
	Visualisation* start_visualisation;
	SDL_Rect* start_rect;
	int image_id;

	
};

