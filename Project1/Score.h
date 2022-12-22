#pragma once
class InputManager;
class Visualisation;
class SDL_Renderer;
class SDL_Rect;
class SDL_Surface;
class SDL_Texture;
class SDL_Window;

class SDL_Color;
class Score
{
public:
	
	static Score* Get();
	void Update();
	void Render();
	void Initialise();
	void Uninitialise();
	const char* GetScore();
	void SetScore(const char* score);
	
private:
	static Score* s_instance;
	const char* m_Score;
	SDL_Renderer* Score_renderer;
	SDL_Window* Score_window;
	InputManager* Score_inputmanager;
	Visualisation* Score_visualisation;
	SDL_Surface* surfaceScore;
	SDL_Texture* ScoreTexture;
	SDL_Rect* Score_rect;
	SDL_Color* White;
	Score();
	~Score();
};

