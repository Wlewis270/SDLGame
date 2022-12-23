#include "GameWinState.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"
#include"StateManager.h"

GameWinState::GameWinState(StateManager* stateManager) :State(stateManager)
{
}

GameWinState::~GameWinState()
{
	
}

void GameWinState::Update()
{
	Gamewin_inputmanager->Update();
	if (Gamewin_inputmanager->GetKeyDown(SDLK_g))
	{
		m_stateManager->SetState(START);
	}
	if (Gamewin_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
	}
}

void GameWinState::Render()
{
	SDL_RenderClear(Gamewin_renderer);
	SDL_SetRenderDrawColor(Gamewin_renderer, 0, 0, 255, 255);
	Gamewin_visualisation->DrawImage(image_id, Gamewin_rect);
	SDL_RenderPresent(Gamewin_renderer);
	SDL_Delay(1000 / 60);
}

void GameWinState::Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL Init failed";
		return;
	}

	Gamewin_window = SDL_CreateWindow("Gamewin Window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);

	Gamewin_renderer = SDL_CreateRenderer(Gamewin_window, -1, 0);

	Gamewin_inputmanager = new InputManager;
	Gamewin_visualisation = Visualisation::Initialise(Gamewin_renderer);
	image_id = Gamewin_visualisation->AddImage(".\\bitmaps\\Gamewin.bmp");
	Gamewin_rect = new SDL_Rect();
	Gamewin_rect->x = 640;
	Gamewin_rect->y = 360;
	Gamewin_rect->w = 349;
	Gamewin_rect->h = 64;

}

void GameWinState::Uninitialise()
{
	SDL_DestroyRenderer(Gamewin_renderer);
	SDL_DestroyWindow(Gamewin_window);
	delete Gamewin_visualisation;
}
