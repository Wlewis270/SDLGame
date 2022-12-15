#include "Bullet.h"
#include "Visualisation.h"
#include "SDL.h"
#include "Game.h"
#include "Entity.h"

Bullet::Bullet(Entity* player)
{
}

std::string Bullet::Getname()
{
	return "Bullet";
}

void Bullet::Initialise()
{
    ent_visualisation = Visualisation::Get();
    ent_rect = new SDL_Rect;
    ent_game = Game::Get();

    ent_rect->x = 500;
    ent_rect->y = 300;
    ent_rect->w = 64;
    ent_rect->h = 64;
}

void Bullet::Update()
{
}
