#include "Enemy.h"
#include "Visualisation.h"
#include "SDL.h"
#include "InputManager.h"
#include "Game.h"
#include "Entity.h"
#include "Player.h"

Enemy::Enemy(std::string Name, int maxhp, int attackvalue):Entity(Name, maxhp, attackvalue)
{
  
}

std::string Enemy::Getname()
{
	return "Enemy";
}

void Enemy::Initialise()
{
    ent_visualisation = Visualisation::Get();
    ent_rect = new SDL_Rect;
    ent_game = Game::Get();

    ent_rect->x = 100;
    ent_rect->y = 300;
    ent_rect->w = 64;
    ent_rect->h = 64;

    image_id = ent_visualisation->AddImage(".\\bitmaps\\enemy.bmp");
}

void Enemy::Update(Player* player)
{
    if (player->GetLocation()->x < GetLocation()->x)
    {
        ent_rect->x = ent_rect->x - 1;
    }
    if (player->GetLocation()->x > GetLocation()->x)
    {
        ent_rect->x = ent_rect->x + 1;
    }
}