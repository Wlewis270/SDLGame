#include "Score.h"
#include "SDL.h"
#include"SDL_ttf.h"
#include <iostream>
#include "Visualisation.h"

Score* Score::s_instance = nullptr;

	
Score* Score::Get()
{
	if (s_instance == nullptr)
	{
		s_instance = new Score();
		return s_instance;
	}
	return s_instance;
}

void Score::Update()
{
	Render();
	
}

void Score::Render()
{
	SDL_RenderClear(Score_renderer);
	SDL_SetRenderDrawColor(Score_renderer, 0, 0, 0, 255);
	SDL_RenderCopy(Score_renderer, ScoreTexture, NULL, Score_rect);
	SDL_RenderPresent(Score_renderer);
	

	
	
}

void Score::Initialise()
{
	Score_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);

	Score_renderer = SDL_CreateRenderer(Score_window, -1, 0);
	TTF_Font* Sa = TTF_OpenFont(".\\font\\Mario-Kart-DS.ttf", 24);
	SDL_Color White = { 255, 255, 255 };
	surfaceScore = new SDL_Surface;
	conver = std::to_string(m_Score);
	surfaceScore=TTF_RenderText_Solid(Sa, conver.c_str(), White);
	ScoreTexture = SDL_CreateTextureFromSurface(Score_renderer, surfaceScore);

	Score_rect = new SDL_Rect; //create a rect
	Score_rect->x = 30;  //controls the rect's x coordinate 
	Score_rect->y = 30; // controls the rect's y coordinte
	Score_rect->w = 100; // controls the width of the rect
	Score_rect->h = 100; // controls the height of the rect
 }

void Score::Uninitialise()
{
	// Don't forget to free your surface and texture
	SDL_FreeSurface(surfaceScore);
	SDL_DestroyTexture(ScoreTexture);
}

int Score::GetScore()
{
	return m_Score;
}

void Score::SetScore(int score)
{
	m_Score = score;
}

Score::Score()
{
}

Score::~Score()
{
}
