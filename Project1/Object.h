#pragma once
#include <string>

class SDL_Rect;
class Visualisation;
class SDL_Renderer;

class Object
{
public:
	std::string Getname();
	void Initialise();
	void Uninitialise();
	void Render();
	void Update();
	SDL_Rect* GetLocation();
protected:
	int image_id;
	SDL_Rect* ent_rect;
	Visualisation* ent_visualisation = nullptr;
};