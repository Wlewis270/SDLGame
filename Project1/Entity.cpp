#include "Entity.h"
#include "Visualisation.h"
#include "SDL.h"

std::string Entity::Getname()
{
	return "";
}

void Entity::Initialise()
{
	ent_visualisation = Visualisation::Get();
	ent_rect = new SDL_Rect;
}

void Entity::Uninitialise()
{
	delete ent_rect;
}

void Entity::Render()
{
	ent_visualisation->DrawImage(image_id, ent_rect);
}

void Entity::Update()
{
}

SDL_Rect* Entity::GetLocation()
{
	return ent_rect;
}