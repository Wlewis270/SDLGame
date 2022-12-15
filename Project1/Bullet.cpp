#include "Bullet.h"
#include "Visualisation.h"
#include "SDL.h"
#include "Game.h"
#include "Entity.h"
#include "Object.h"
#include"Player.h"

Bullet::Bullet(Player* player)
{
    ent_player = player;
}

Bullet::~Bullet()
{
    delete ent_rect;
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
    
    ent_rect = ent_player->GetLocation();
    ent_rect->h = 25;
    ent_rect->w = 25;

    image_id = ent_visualisation->AddImage(".\\bitmaps\\bullet.bmp");
}

void Bullet::Update()
{
    ent_rect->x = ent_rect->x + 6;
}

