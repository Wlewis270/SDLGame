#include "Object.h"
#include "Visualisation.h"
#include "SDL.h"

std::string Object::Getname()
{
	return "";
}

void Object::Initialise()
{
	ent_visualisation = Visualisation::Get();
	ent_rect = new SDL_Rect;
}

void Object::Uninitialise()
{
	delete ent_rect;
}

void Object::Render()
{
	ent_visualisation->DrawImage(image_id, ent_rect);
}

void Object::Update()
{
}

SDL_Rect* Object::GetLocation()
{
	return ent_rect;
}