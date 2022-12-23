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

void Bullet::Initialise(std::string dir)
{
    ent_visualisation = Visualisation::Get();
    ent_rect = new SDL_Rect;
    ent_game = Game::Get();
    direction = dir;
    ent_rect->x = ent_player->GetLocation()->x;
    ent_rect->y = ent_player->GetLocation()->y;
    ent_rect->h = 25;
    ent_rect->w = 25;

    image_id = ent_visualisation->AddImage(".\\bitmaps\\bullet.bmp");
}

void Bullet::Update()
{
    if (direction == "Right")
    {
        ent_rect->x = ent_rect->x + 6;
    }
    else
    {
        ent_rect->x = ent_rect->x - 6;
    }
    
}

bool Bullet::Collision()
{
    Object* bullet_collision = ent_game->CheckCollisions(this);
    return  bullet_collision != nullptr && bullet_collision != ent_player;
    
}

