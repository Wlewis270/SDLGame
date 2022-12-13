#include "Player.h"
#include "Visualisation.h"
#include "SDL.h"
#include "InputManager.h"
#include "Game.h"
#include"Entity.h"

Player::Player(std::string Name, int maxhp, int attackvalue, InputManager*im):Entity(Name,maxhp,attackvalue)
{
    ent_input_manager = im;
}

std::string Player::Getname()
{
    return "Player";
}

void Player::Initialise()
{
    ent_visualisation = Visualisation::Get();
    ent_rect = new SDL_Rect;
    ent_game = Game::Get();

    ent_rect->x = 100;
    ent_rect->y = 100;
    ent_rect->w = 64;
    ent_rect->h = 64;

    image_id = ent_visualisation->AddImage(".\\bitmaps\\player.bmp");
}

void Player::Update()
{

	int playerX = GetLocation()->x;
	int playerY = GetLocation()->y;

	if (ent_input_manager->GetKeyHeld(SDLK_a))
	{
		ent_rect->x = ent_rect->x + 5;
	}

	if (ent_input_manager->GetKeyHeld(SDLK_d))
	{
		ent_rect->x = ent_rect->x - 5;
	}
}
