#include "Game.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"

void Game::Update()
{
	game_inputmanager->Update();

	if (game_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
	}
}

void Game::Render()
{
	SDL_RenderClear(game_renderer);
	SDL_RenderPresent(game_renderer);
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
}

void Game::Uninitialise()
{
	SDL_DestroyRenderer(game_renderer);
	SDL_DestroyWindow(game_window);
	delete game_visualisation;
}