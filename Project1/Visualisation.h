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
	static Visualisation* Get();
	static Visualisation* Initialise(SDL_Renderer* renderer);

	~Visualisation();
	int AddImage(std::string str);
	void DrawImage(int i, SDL_Rect* rec);

private:
	Visualisation(SDL_Renderer* renderer);
	Visualisation(const Visualisation&) = delete;
	static Visualisation* s_instance;

	std::vector<SDL_Texture*> texture_vec;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;
};

