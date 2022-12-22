#include "GameOverState.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"
#include"StateManager.h"

GameOverState::GameOverState(StateManager* stateManager) :State(stateManager)
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::Update()
{
	Gameover_inputmanager->Update();
	if (Gameover_inputmanager->GetKeyDown(SDLK_s))
	{
		m_stateManager->SetState(GAME);
	}
}

void GameOverState::Render()
{
	SDL_RenderClear(Gameover_renderer);
	SDL_SetRenderDrawColor(Gameover_renderer, 0, 0, 255, 255);
	Gameover_visualisation->DrawImage(image_id, Gameover_rect);
	SDL_RenderPresent(Gameover_renderer);
	SDL_Delay(1000 / 60);
}

void GameOverState::Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL Init failed";
		return;
	}

	Gameover_window = SDL_CreateWindow("Gameover Window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);

	Gameover_renderer = SDL_CreateRenderer(Gameover_window, -1, 0);

	Gameover_inputmanager = new InputManager;
	Gameover_visualisation = Visualisation::Initialise(Gameover_renderer);
	image_id = Gameover_visualisation->AddImage(".\\bitmaps\\Gameover.bmp");
	Gameover_rect = new SDL_Rect();
	Gameover_rect->x = 640;
	Gameover_rect->y = 360;
	Gameover_rect->w = 349;
	Gameover_rect->h = 64;

}

void GameOverState::Uninitialise()
{
	SDL_DestroyRenderer(Gameover_renderer);
	SDL_DestroyWindow(Gameover_window);
	delete Gameover_visualisation;
}
