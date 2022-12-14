#include "Game.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"

Game* Game::s_instance = nullptr;

Game* Game::Get()
{
	if (s_instance == nullptr)
	{
		s_instance = new Game;
		return s_instance;
	}

	return s_instance;
}


void Game::Update()
{
	game_inputmanager->Update();
	game_player->Update();
	game_enemy->Update(game_player);
	if (game_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
	}

	Render();

}

void Game::Render()
{
	SDL_RenderClear(game_renderer);
	SDL_SetRenderDrawColor(game_renderer, 0, 0, 255, 255);
	game_player->Render();
	game_enemy->Render();
	SDL_RenderPresent(game_renderer);
	SDL_Delay(1000 / 60);
}

bool Game::IsGameRunning()
{
	return true;
}

void Game::Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL Init failed";
		return;
	}

	game_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);

	game_renderer = SDL_CreateRenderer(game_window, -1, 0);

	game_inputmanager = new InputManager;
	game_visualisation->Initialise(game_renderer);

	game_player = new Player("Player",100, 5, game_inputmanager);
	game_enemy = new Enemy("Enemy", 100, 5);
	game_player->Initialise();
	game_enemy->Initialise();
}

void Game::Uninitialise()
{
	SDL_DestroyRenderer(game_renderer);
	SDL_DestroyWindow(game_window);
	delete game_visualisation;
}

std::string Game::CheckCollisions(Entity* ent)
{
	bool collision_checked = false;
	
	while (collision_checked == false)
	{
		if (TestBlockCollision(ent, game_enemy))
		{
			return game_enemy->GetName();
		}
		return "";
	}
}

bool Game::TestBlockCollision(Entity* ent, Entity* ent2)
{
	Ent_rect = ent->GetLocation();
	Ent_rect2 = ent2->GetLocation();

	int EntminX = Ent_rect->x;
	int EntminY = Ent_rect->y;
	int EntmaxX = Ent_rect->x + Ent_rect->w;
	int EntmaxY = Ent_rect->y + Ent_rect->h;

	int Ent2minX = Ent_rect2->x;
	int Ent2minY = Ent_rect2->y;
	int Ent2maxX = Ent_rect2->x + Ent_rect2->w;
	int Ent2maxY = Ent_rect2->y + Ent_rect2->h;

	if (EntminY > Ent2maxY)
	{
		return false;
	}

	if (EntmaxY < Ent2minY)
	{
		return false;
	}

	if (Ent2minX > EntmaxX)
	{
		return false;
	}

	if (Ent2maxX < EntminX)
	{
		return false;
	}

	return true;
}

Game::Game()
{
}
