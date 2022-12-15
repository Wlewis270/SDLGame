#include "Player.h"
#include "Visualisation.h"
#include "SDL.h"
#include "InputManager.h"
#include "Game.h"
#include "Bullet.h"
#include "Entity.h"

Player::Player(std::string Name, int maxhp, int attackvalue, InputManager*im):Entity(Name,maxhp,attackvalue)
{
    ent_input_manager = im;
}

std::string Player::Getname()
{
    return m_name;
}

void Player::Initialise()
{
    ent_visualisation = Visualisation::Get();
    ent_rect = new SDL_Rect;
    ent_game = Game::Get();
	ent_bullet = new Bullet(this);

    ent_rect->x = 500;
    ent_rect->y = 300;
    ent_rect->w = 64;
    ent_rect->h = 64;

    image_id = ent_visualisation->AddImage(".\\bitmaps\\player.bmp");

	bullet_deleted = true;
}

void Player::Update()
{
	int playerX = GetLocation()->x;

	if (ent_input_manager->GetKeyHeld(SDLK_d))
	{
		ent_rect->x = ent_rect->x + 5;
	}

	if (ent_input_manager->GetKeyHeld(SDLK_a))
	{
		ent_rect->x = ent_rect->x - 5;
	}

	if (ent_input_manager->GetKeyHeld(SDLK_SPACE) && bullet_deleted == true)
	{
		bullet_deleted = false;
		ent_bullet = new Bullet(this);
		ent_bullet->Render();
	}

	Object* player_collision = ent_game->CheckCollisions(ent_bullet);
	
	if (bullet_deleted == false)
	{
		if (player_collision != nullptr && player_collision != this)
		{
			delete ent_bullet;
			bullet_deleted = true;
		}
	}
	
	player_collision = ent_game->CheckCollisions(this);

	if (player_collision != nullptr && player_collision != ent_bullet)
	{
		if (ent_rect->x < player_collision->GetLocation()->x)
		{
			ent_rect->x = ent_rect->x - 10;
		}

		if (ent_rect->x > player_collision->GetLocation()->x)
		{
			ent_rect->x = ent_rect->x + 10;
		}
	}
}
