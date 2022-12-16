#include "StartState.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"
#include"StateManager.h"

StartState::StartState(StateManager *stateManager):State(stateManager)

{

}

StartState::~StartState()
{
}

void StartState::Update()
{
	start_inputmanager->Update();
	if (start_inputmanager->GetKeyDown(SDLK_s))
	{
		m_stateManager->SetState(GAME);
	}

	
}



void StartState::Render()
{
	SDL_RenderClear(start_renderer);
	SDL_SetRenderDrawColor(start_renderer, 0, 0, 255, 255);
	start_visualisation->DrawImage(image_id, start_rect);
	SDL_RenderPresent(start_renderer);
	SDL_Delay(1000 / 60);
}

void StartState::Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL Init failed";
		return;
	}

	start_window = SDL_CreateWindow("Start Window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);

	start_renderer = SDL_CreateRenderer(start_window, -1, 0);

	start_inputmanager = new InputManager;
	start_visualisation = Visualisation::Initialise(start_renderer);
	image_id = start_visualisation->AddImage(".\\bitmaps\\start.bmp");
	start_rect = new SDL_Rect();
	start_rect->x = 640;
	start_rect->y = 360;
	start_rect->w = 349;
	start_rect->h = 64;
	
}

void StartState::Uninitialise()
{
	SDL_DestroyRenderer(start_renderer);
	SDL_DestroyWindow(start_window);
	delete start_visualisation;
}


