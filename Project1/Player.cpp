#include "Player.h"
#include "Visualisation.h"
#include "SDL.h"
#include "InputManager.h"
#include "Game.h"

Player::Player(InputManager* im)
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
}

void Player::Update()
{
}
