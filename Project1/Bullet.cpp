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
    
    ent_rect->x = ent_player->GetLocation()->x;
    ent_rect->y = ent_player->GetLocation()->y;
    ent_rect->h = 25;
    ent_rect->w = 25;

    image_id = ent_visualisation->AddImage(".\\bitmaps\\bullet.bmp");
}

void Bullet::Update()
{
    ent_rect->x = ent_rect->x + 6;
}

bool Bullet::Collision()
{
    Object* bullet_collision = ent_game->CheckCollisions(this);
    if (bullet_collision != nullptr && bullet_collision != ent_player)
    {
        ent_game->DeleteEnemy(bullet_collision);
        return true;
    }
    return false;
}

