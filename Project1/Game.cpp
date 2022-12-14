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

Game::Game()
{
}
