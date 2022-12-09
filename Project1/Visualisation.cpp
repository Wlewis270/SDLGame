#include "Visualisation.h"
#include <SDL.h>

Visualisation* Visualisation::s_instance = nullptr;

Visualisation::Visualisation(SDL_Renderer* renderer) :m_renderer(renderer)
{
}

Visualisation* Visualisation::Get()
{
	return s_instance;
}

Visualisation* Visualisation::Initialise(SDL_Renderer* renderer)
{
	s_instance = new Visualisation(renderer);
	return s_instance;
}

Visualisation::~Visualisation()
{
	for (int i = 0; i < texture_vec.size(); i++)
	{
		SDL_DestroyTexture(texture_vec[i]);
	}
	texture_vec.clear();

}

int Visualisation::AddImage(std::string str)
{
	m_surface = SDL_LoadBMP(str.c_str());
	SDL_SetColorKey(m_surface, SDL_TRUE, SDL_MapRGB(m_surface->format, 255, 0, 255));
	if (m_surface != NULL)
	{
		SDL_Texture* temp = SDL_CreateTextureFromSurface(m_renderer, m_surface);

		int texture_ID = texture_vec.size();
		texture_vec.push_back(temp);

		SDL_FreeSurface(m_surface);

		return texture_ID;
	}
	else
	{
		return -1;
	}
}

void Visualisation::DrawImage(int i, SDL_Rect* rec)
{
	SDL_RenderCopy(m_renderer, texture_vec[i], NULL, rec);
}
