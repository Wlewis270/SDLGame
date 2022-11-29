#pragma once
#include <string>
#include <vector>

class SDL_Texture;
class SDL_Renderer;
class SDL_Rect;
class SDL_Surface;

class Visualisation
{
public:
	Visualisation(SDL_Renderer* renderer);
	~Visualisation();
	int AddImage(std::string str);
	void DrawImage(int i, SDL_Rect* rec);

private:
	std::vector<SDL_Texture*> texture_vec;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;
};

